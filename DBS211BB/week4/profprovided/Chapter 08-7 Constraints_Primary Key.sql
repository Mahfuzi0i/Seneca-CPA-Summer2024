-- Create c8_employees Table 

-- No Primary Key
DROP TABLE c8_employees;
CREATE TABLE c8_employees (
    employee_id  INTEGER,  
    first_name   VARCHAR (20),
    last_name    VARCHAR (20) );

INSERT INTO c8_employees
  VALUES (101, 'Betty', 'O''Brien'),
         (102, 'Peter', 'Jackson'),
         (103, 'Janet', 'Jones'),
         (101, 'Sally', 'Allen'); -- Two employees with the same employee_id

SELECT * FROM c8_employees;


-- Defining PRIMARY KEY

-- Method 1
-- Primary Key defined at column level
DROP TABLE c8_employees;
CREATE TABLE c8_employees (
    employee_id  INTEGER PRIMARY KEY, -- Primary Key defined at column level
    first_name   VARCHAR (20),
    last_name    VARCHAR (20) );

-- Method 2
-- Primary Key defined at table level
DROP TABLE c8_employees;
CREATE TABLE c8_employees (
    employee_id  INTEGER,
    first_name   VARCHAR (20),
    last_name    VARCHAR (20),
  PRIMARY KEY ( employee_id )           -- Primary Key defined at table level              
);

-- Examine constraint name for primary key


-- Method 3
-- Primary Key defined at table level with constraint name
DROP TABLE c8_employees;
CREATE TABLE c8_employees (
    employee_id  INTEGER,
    first_name   VARCHAR (20),
    last_name    VARCHAR (20),
  CONSTRAINT c8_employees_pk
    PRIMARY KEY ( employee_id ) );       -- Primary Key defined at table level with constraint name         

-- Examine constraint name for primary key


-- Method 4
-- Primary Key defined with ALTER TABLE statement

DROP TABLE c8_employees;
CREATE TABLE c8_employees (
    employee_id  INTEGER,
    first_name   VARCHAR (20),
    last_name    VARCHAR (20) ); 

ALTER TABLE c8_employees
  ADD CONSTRAINT c8_employees_pk
    PRIMARY KEY ( employee_id );
	
------------------------------------------------------
-- PK Constraint Testing
--Validate primary key constraint on employee_id

INSERT INTO c8_employees
  VALUES (101, 'Betty', 'O''Brien'),
         (102, 'Peter', 'Jackson'),
         (103, 'Janet', 'Jones');
		 
SELECT * FROM c8_employees;

-- Duplicate key error
INSERT INTO c8_employees
  VALUES (101, 'Sally', 'Allen');
-- [SQL0803] Duplicate key value specified.
		 
SELECT * FROM c8_employees;

----------------------------------------------------
-- DROP a PRIMARY KEY constraint

ALTER TABLE c8_employees
  DROP PRIMARY KEY;           -- DROP primary Key
  	