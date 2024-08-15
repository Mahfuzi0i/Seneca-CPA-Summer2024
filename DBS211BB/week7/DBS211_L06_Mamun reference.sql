-- ***********************
-- Name: Abdulla Al Mamun
-- ID: 148541220
-- Date: 20th June 2024
-- Purpose: Lab 06 DBS211
-- ***********************

-- Q1 Solution --
/*
    Four ways a transaction can be started
    1. The user has established a new connection to the server and has a blank sheet ready to go
    2. Using the BEGIN statement in Oracle SQL
    3. Executing a COMMIT statement
    4. Executing any DDL statement such as CREATE, ALTER, DROP
 
*/

-- Q2 Solution --
CREATE TABLE newEmployees (
    employeeNumber INTEGER NOT NULL,
    lastName VARCHAR(30) NOT NULL,
    firstName VARCHAR(30) NOT NULL,
    extension VARCHAR(10)NOT NULL,
    email   VARCHAR(50) NOT NULL,
    officecode  VARCHAR(10) NOT NULL,
    reportsTo   INTEGER,
    jobTitle    VARCHAR(50) NOT NULL,
    PRIMARY KEY (employeeNumber)
);

-- Q3 Solution --
SET AUTOCOMMIT OFF;
SET TRANSACTION READ WRITE;

-- Q4 Solution --
INSERT ALL
    INTO newEmployees VALUES (100, 'Patel', 'Ralph', '22333', 'rpatel@mail.com', '1', NULL, 'Sales Rep')
    INTO newEmployees VALUES (101, 'Denis', 'Betty', '33444', 'bdenis@mail.com', '4', NULL, 'Sales Rep')
    INTO newEmployees VALUES (102, 'Biri', 'Ben', '44555', 'bbirir@mail.com', '2', NULL, 'Sales Rep')
    INTO newEmployees VALUES (103, 'Newman', 'Chad', '66777', 'cnewman@mail.com', '3', NULL, 'Sales Rep')
    INTO newEmployees VALUES (104, 'Ropeburn', 'Audrey', '77888', 'aropebur@mail.com', '1', NULL, 'Sales Rep')
SELECT * FROM dual;

-- Q5 Solution --
SELECT * FROM newEmployees;
-- 5 rows are selected --

-- Q6 Solution --
ROLLBACK;
SELECT * FROM newEmployees;
-- There are no rows selected as ROLLBACK undoes the previous executed transaction

-- Q7 Solution --
INSERT ALL
    INTO newEmployees VALUES (100, 'Patel', 'Ralph', '22333', 'rpatel@mail.com', '1', NULL, 'Sales Rep')
    INTO newEmployees VALUES (101, 'Denis', 'Betty', '33444', 'bdenis@mail.com', '4', NULL, 'Sales Rep')
    INTO newEmployees VALUES (102, 'Biri', 'Ben', '44555', 'bbirir@mail.com', '2', NULL, 'Sales Rep')
    INTO newEmployees VALUES (103, 'Newman', 'Chad', '66777', 'cnewman@mail.com', '3', NULL, 'Sales Rep')
    INTO newEmployees VALUES (104, 'Ropeburn', 'Audrey', '77888', 'aropebur@mail.com', '1', NULL, 'Sales Rep')
SELECT * FROM dual;
COMMIT;
-- Commit makes changes permanently --

ROLLBACK;
SELECT * FROM newEmployees;
-- Now it selects 5 rows even after ROLLBACK is executed

-- Q8 Solution --
UPDATE newEmployees
SET jobtitle = 'Unknown';

-- Q9 Solution --
COMMIT;

-- Q10 Solution --
ROLLBACK;

SELECT * FROM newEmployees
WHERE jobtitle = 'Unknown';

-- The rollback command here doesn't work because a permanent change was made in Q9 and rollback was not possible
-- In Q6, the rollback command work because the insert command was only executed and not committed hence no permanent changes were made

-- Q11 Solution --
COMMIT; -- Start a new transaction

DELETE FROM newEmployees;

-- Q12 Solution --
CREATE VIEW vwNewEmps AS
SELECT * FROM newEmployees
ORDER BY lastname, firstname;

-- Q13 Solution --
ROLLBACK;

SELECT * FROM newEmployees;

-- There are no employees in the table.
-- This is because when a DDL statement is executed, it is committed automatically that makes permanenet changes to the table
-- But in our case the previous statement was a CREATE view statement which automatically committed the DELETE command as well hence rollbakc didnt work

-- Q14 Solution --
COMMIT;
INSERT ALL
    INTO newEmployees VALUES (100, 'Patel', 'Ralph', '22333', 'rpatel@mail.com', '1', NULL, 'Sales Rep')
    INTO newEmployees VALUES (101, 'Denis', 'Betty', '33444', 'bdenis@mail.com', '4', NULL, 'Sales Rep')
    INTO newEmployees VALUES (102, 'Biri', 'Ben', '44555', 'bbirir@mail.com', '2', NULL, 'Sales Rep')
    INTO newEmployees VALUES (103, 'Newman', 'Chad', '66777', 'cnewman@mail.com', '3', NULL, 'Sales Rep')
    INTO newEmployees VALUES (104, 'Ropeburn', 'Audrey', '77888', 'aropebur@mail.com', '1', NULL, 'Sales Rep')
SELECT * FROM dual;

-- Q15 Solution --
SAVEPOINT insertion;

-- Q16 Solution --
UPDATE newEmployees
SET jobtitle = 'Unknown';

SELECT * FROM newEmployees;

-- Q17 Solution --
ROLLBACK TO insertion;

SELECT * FROM newEmployees;

-- The job title is rolled back to Sales Rep where it was saved, instead of Unknown as a savepoint was created before the UPDATE statement

-- Q18 Solution --
ROLLBACK;

SELECT * FROM newEmployees;

-- There are no employees data in the table
-- The rollback in Q17 took us to the insertion
-- Another rollback on it returned us to Q11 with the DELETE statement that was committed in Q12 using the DDL CREATE statement

-- Q19 Solution --
REVOKE ALL ON newEmployees FROM PUBLIC;

-- Q20 Solution --
GRANT SELECT ON newEmployees TO classmate;
-- user or role 'CLASSMATE' does not exist

-- Q21 Solution --
GRANT INSERT, UPDATE, DELETE ON newEmployees TO classmate;
-- user or role 'MY_CLASSMATE' does not exist

-- Q22 Solution --
REVOKE ALL ON newEmployees FROM classmate;
-- user or role 'CLASSMATE' does not exist

-- Q23 Solution --
DROP VIEW vwNewEmps;
DROP TABLE newEmployees;
COMMIT; -- Make permanent changes