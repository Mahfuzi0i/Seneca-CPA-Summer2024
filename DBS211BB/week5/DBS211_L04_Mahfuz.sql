-- ***********************
-- Name: Abdullah Al Mahfuz
-- ID: 180377236
-- Date: 05 June 2024 (Wednesday)
-- Purpose: Lab 04 DBS211
-- ***********************

SET AUTOCOMMIT ON;

--Q1 Solution --
CREATE TABLE employee2 AS
SELECT *
FROM dbs211_employees;

// copying the primary key of dbs211_employees into employee2
ALTER TABLE employee2
ADD CONSTRAINT emp_no_pk
PRIMARY KEY(employeenumber);

// copying the foreign keys of dbs211_employees into employee2
ALTER TABLE employee2
ADD CONSTRAINT office_code_fk
FOREIGN KEY(officecode)
REFERENCES dbs211_offices(officecode);

ALTER TABLE employee2
ADD CONSTRAINT reportsto_fk
FOREIGN KEY(reportsto)
REFERENCES employee2(employeenumber);

--Q2 Solution --
ALTER TABLE employee2
ADD username varchar(50);

--Q3 Solution
DELETE 
FROM employee2;

--Q4 Solution --
INSERT INTO employee2(Employeenumber, Lastname, Firstname, Extension, Email, Officecode, Reportsto, Jobtitle)
SELECT Employeenumber, Lastname, Firstname, Extension, Email, Officecode, Reportsto, Jobtitle
FROM dbs211_employees;

--Q5 Solution --
INSERT 
INTO employee2 
VALUES (1703, 'Mahfuz', 'Abdullah Al', 'x2222', 'aamahfuz@myseneca.ca', '4', 1088, 'Cashier', NULL);

--Q6 Solution --
SELECT *
FROM employee2
WHERE employeenumber = 1703;

--Q7 Solution --
UPDATE employee2
SET jobtitle = 'Head Cashier'
WHERE employeenumber = 1703;

--Q8 Solution --
INSERT
INTO employee2
VALUES (1899, 'Sebastian', 'Linus', 'x4223', 'sebastian22@icloud.com', '4', 1703, 'Cashier', NULL);

--Q9 Solution --
DELETE
FROM employee2
WHERE employeenumber = 1703; // It did not WORK!!
/*
the error i got is- Error report -
ORA-02292: integrity constraint (DBS211_242ZBB17.REPORTSTO_FK) violated - child record found
The statement did not work as there is a foreign key constraint that refers to my data in the table employee2.
*/

--Q10 Solution --
DELETE 
FROM employee2
WHERE employeenumber = 1899; // The fake employee

DELETE
FROM employee2
WHERE employeenumber = 1703; // My info
/* After deleting the fake employee, the removal of my data worked.
As after deleting the fake employee, it does not refer to my data anymore with the help of foreign key constraint.
Hence we could delete my data from the table after deleting the fake employee.
*/

--Q11 Solution --
INSERT ALL
INTO employee2
VALUES (1703, 'Mahfuz', 'Abdullah Al', 'x2222', 'aamahfuz@myseneca.ca', '4', 1088, 'Cashier', NULL)
INTO employee2
VALUES (1899, 'Sebastian', 'Linus', 'x4223', 'sebastian22@icloud.com', '4', 1088, 'Cashier', NULL)
SELECT *
FROM dual;

--Q12 Solution --
DELETE 
FROM employee2
WHERE employeenumber IN (1703, 1899);

--Q13 Solution --
UPDATE employee2 
SET username = LOWER(SUBSTR(firstname, 1, 1)) || LOWER(lastname);

--Q14 Solution --
DELETE
FROM employee2
WHERE officecode = '4'; // It failed
/*
Error report -
ORA-02292: integrity constraint (DBS211_242ZBB17.REPORTSTO_FK) violated - child record found
Reason - Officecode is a foreign key that and reportsto refers 
to the same table employeenumber row. Trying to delete this row would leave the the rows orphaned. 
The database enforces referential integrity, so it prevents the deletion of a parent row if there are any child rows that depend on it.
*/

--Q15 Solution --
DROP TABLE employee2;


