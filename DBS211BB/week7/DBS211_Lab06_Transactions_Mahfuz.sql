-- ***********************
-- Name: Abdullah Al Mahfuz
-- ID: 180377236
-- Date: 21 June 2024 (Friday)
-- Purpose: Lab 06 DBS211
-- ***********************

-- PART A - Transactions --
-- Q1 Solution
/*
The 4 ways that we know about how a transaction can be started-
    1. The user establishes a new connection to the SQL server and has a blank SQL worksheet ready to work on.
    2. Using the BEGIN statement in Oracle SQL.
    3. Executing the COMMIT statement
    4. Executiong any of the DDL statements(i.e. CREATE, ALTER, DROP).
*/

--Q2 Solution
CREATE TABLE newEmployees(
    employeeNumber INTEGER PRIMARY KEY,
    lastname VARCHAR(50) NOT NULL,
    firstname VARCHAR(50) NOT NULL,
    extension VARCHAR(10) NOT NULL,
    email Varchar(50) NOT NULL,
    OfficeCode INTEGER NOT NULL,
    reportsTo INTEGER,
    jobTitle VARCHAR(50) NOT NULL
    );
    
--Q3 Solution
SET AUTOCOMMIT OFF;
SET TRANSACTION READ WRITE;

--Q4 Solution
INSERT ALL 
    INTO newEmployees VALUES (100, 'Patel', 'Ralph', '22333', 'rpatel@mail.com', 1, NULL, 'Sales Rep')
    INTO newEmployees VALUES (101, 'Denis', 'Betty', '33444', 'bdenis@mail.com', 4, NULL, 'Sales Rep')
    INTO newEmployees VALUES (102, 'Biri', 'Ben', '44555', 'bbirir@mail.com', 2, NULL, 'Sales Rep')
    INTO newEmployees VALUES (103, 'Newman', 'Chad', '66777', 'cnewman@mail.com', 3, NULL, 'Sales Rep')
    INTO newEmployees VALUES (104, 'Ropeburn', 'Audrey', '77888', 'aropebur@mail.com', 1, NULL, 'Sales Rep')
SELECT * FROM DUAL;

--Q5 Solution
SELECT *
FROM newEmployees;  -- 5 rows were selected

--Q6 Solution
ROLLBACK;
SELECT *
FROM newEmployees;  -- There are no rows! all the data gone! ROLLBACK statemnt undid the previously executed transaction

--Q7 Solution
INSERT ALL 
    INTO newEmployees VALUES (100, 'Patel', 'Ralph', '22333', 'rpatel@mail.com', 1, NULL, 'Sales Rep')
    INTO newEmployees VALUES (101, 'Denis', 'Betty', '33444', 'bdenis@mail.com', 4, NULL, 'Sales Rep')
    INTO newEmployees VALUES (102, 'Biri', 'Ben', '44555', 'bbirir@mail.com', 2, NULL, 'Sales Rep')
    INTO newEmployees VALUES (103, 'Newman', 'Chad', '66777', 'cnewman@mail.com', 3, NULL, 'Sales Rep')
    INTO newEmployees VALUES (104, 'Ropeburn', 'Audrey', '77888', 'aropebur@mail.com', 1, NULL, 'Sales Rep')
SELECT * FROM DUAL;

// Make the insertion permanant
COMMIT;

ROLLBACK;
SELECT *
FROM newEmployees;  -- 5 rows selected even after executing ROLLBACK. Because the commit statement made the previous transaction permanant

--Q8 Solution
UPDATE newEmployees
SET jobTitle = 'unknown';

--Q9 Solution
COMMIT;

--Q10 Solution
ROLLBACK;

-- solution a)
SELECT *
FROM newEmployees
WHERE jobTitle = 'unknown'; -- All the rows are still updated
--solution b)- The rollback command was not effective because a permanant change was made using commit command and rollback to the previous transaction is not possible.
--solution c)- In Task6, the rollback command worked because the insert command was only executed and not committed hence no permanent changes were made. thus the rollback could set it back to its previous state

--Q11 Solution
COMMIT; -- Starts a new Transaction

DELETE
FROM newEmployees;

--Q12 Solution
CREATE VIEW vwNewEmps AS
SELECT *
FROM newEmployees
ORDER BY lastname, firstname;

--Q13 Solution
ROLLBACK;

//Checking the employee data
SELECT *
FROM newEmployees; --a) There are no rows in the newEmployees table

-- b) This is because when a DDL statement is executed, it is committed automatically. Which makes permanenet changes to the table
--    But in our case the previous statement was a CREATE view statement which automatically committed the DELETE command as well. hence rollback wasn't effective

--Q14 Solution
COMMIT; // starts a new transaction
INSERT ALL 
    INTO newEmployees VALUES (100, 'Patel', 'Ralph', '22333', 'rpatel@mail.com', 1, NULL, 'Sales Rep')
    INTO newEmployees VALUES (101, 'Denis', 'Betty', '33444', 'bdenis@mail.com', 4, NULL, 'Sales Rep')
    INTO newEmployees VALUES (102, 'Biri', 'Ben', '44555', 'bbirir@mail.com', 2, NULL, 'Sales Rep')
    INTO newEmployees VALUES (103, 'Newman', 'Chad', '66777', 'cnewman@mail.com', 3, NULL, 'Sales Rep')
    INTO newEmployees VALUES (104, 'Ropeburn', 'Audrey', '77888', 'aropebur@mail.com', 1, NULL, 'Sales Rep')
SELECT * FROM DUAL;

--Q15 Solution
SAVEPOINT insertion;

--Q16 Solution
UPDATE newEmployees
SET jobTitle = 'unknown';

SELECT *
FROM newEmployees;

--Q17 Solution
ROLLBACK TO insertion;

SELECT *
FROM newEmployees;
/*
The job title is rolled back to 'Sales Rep' where it was saved using the SAVEPOINT command, 
instead of unknown. Because a savepoint was created before the UPDATE statement which allowed the ROLLBACK 
to go to the savepoint state.
*/

--Q18 Solution
ROLLBACK;

SELECT *
FROM newEmployees;
/*
There are no employees data in the table.
The rollback in Q17 took us to the insertion.
Another rollback on it returned us to Q11 with the DELETE statement that was committed in Q12 using the DDL CREATE statement.
Thus the table now has no rows.
*/

-- PART B - Permissions --

--Q19 Solution
--Deny all access for the public users
REVOKE ALL ON newEmployees FROM PUBLIC;

--Q20 Solution
GRANT SELECT ON newEmployees TO classmate;
-- I got error - Cause - There is not a user or role by that name(classmate). classmate does not exist

--Q21 Solution
GRANT INSERT, UPDATE, DELETE ON newEmployees TO classmate;
-- I got error - Cause - There is not a user or role by that name(classmate). classmate does not exist

--Q22 Solution
REVOKE ALL ON newEmployees FROM classmate;
-- I got error - Cause - There is not a user or role by that name(classmate). classmate does not exist

-- PART C - Clean up
--Q23 Solution
DROP VIEW vwnewEmps;
DROP TABLE newEmployees;

// MAKE the Deletion permanant
COMMIT;

