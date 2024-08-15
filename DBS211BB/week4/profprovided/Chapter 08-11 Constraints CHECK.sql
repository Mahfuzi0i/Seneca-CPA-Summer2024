-----------------------------------------------------------
-- Limit Check
-- Method 1 - CHECK constraint at column level

DROP TABLE c8_employees;
CREATE TABLE c8_employees (
  employee_id INTEGER      NOT NULL,
  first_name  VARCHAR (15) NOT NULL,
  last_name   VARCHAR (15) NOT NULL,
  salary      DECIMAL(7,0) CHECK ( salary < 92000.00 ) );

-- View constraint name

--------------------------------------------------------------
-- Method 2 - CHECK constraint at table level

DROP TABLE c8_employees;
CREATE TABLE c8_employees (
  employee_id INTEGER      NOT NULL,
  first_name  VARCHAR (15) NOT NULL,
  last_name   VARCHAR (15) NOT NULL,
  salary      DECIMAL(7,0),
  CHECK ( salary < 92000.00 ) );    -- No constraint name

--------------------------------------------------------------
-- Method 3 - CHECK constraint at table level with constraint name

DROP TABLE c8_employees;
CREATE TABLE c8_employees (
  employee_id INTEGER      NOT NULL,
  first_name  VARCHAR (15) NOT NULL,
  last_name   VARCHAR (15) NOT NULL,
  salary      DECIMAL(7,0),
CONSTRAINT c8_employees_salary_ck
  CHECK ( salary < 92000.00 ) );

--------------------------------------------------------------
-- Method 4 - CHECK constraint using ALTER TABLE

DROP TABLE c8_employees;
CREATE TABLE c8_employees (
  employee_id INTEGER      NOT NULL,
  first_name  VARCHAR (15) NOT NULL,
  last_name   VARCHAR (15) NOT NULL,
  salary      DECIMAL(7,0) );

ALTER TABLE c8_employees
  ADD CONSTRAINT c8_employees_salary_ck
  CHECK ( salary < 92000.00 );

INSERT INTO c8_employees
VALUES ( 101, 'Sally', 'Jones', 74500 ),
       ( 102, 'Peter', 'Allen', 42000 );

INSERT INTO c8_employees
VALUES ( 103, 'Betty', 'Jackson', 92500 ); -- Invalid salary
-- [SQL0545] INSERT, UPDATE, or MERGE not allowed by CHECK constraint.

SELECT * FROM c8_employees;

--------------------------------------------------------------
-- Adding a constraint that violates existing rows

DROP TABLE c8_employees;
CREATE TABLE c8_employees (
  employee_id INTEGER     NOT NULL,
  first_name  VARCHAR(15) NOT NULL,
  last_name   VARCHAR(15) NOT NULL,
  salary      DECIMAL(7,0) );

INSERT INTO c8_employees
VALUES ( 101, 'Sally', 'Jones', 150000 ),
       ( 102, 'Peter', 'Allen', 42000  );

SELECT * FROM c8_employees;

ALTER TABLE c8_employees
  ADD CONSTRAINT c8_employees_salary_ck
  CHECK ( salary <= 92000.00 ); -- table contains a value > 92000.00
-- [SQL0544] CHECK constraint c8_employees_SALARY_CK cannot be added.

SELECT * FROM c8_employees;

--------------------------------------------------------------
-- Limit Check - 2nd Example

DROP TABLE c8_employees;
CREATE TABLE c8_employees (
  employee_id INTEGER NOT NULL,
  birth_date  DATE    NOT NULL );

ALTER TABLE c8_employees
  ADD CONSTRAINT c8_employees_birth_date_ck
  CHECK ( birth_date > '1985-01-01' );

-- Constraint testing
INSERT INTO c8_employees -- valid
  VALUES ( 101, '1990-05-01' ),
         ( 102, '2000-09-15' );

SELECT * FROM c8_employees;

INSERT INTO c8_employees
  VALUES ( 103, '1980-05-15' ); -- Invalid birth date
-- [SQL0545] INSERT, UPDATE, or MERGE not allowed by CHECK constraint.

SELECT * FROM c8_employees;

--------------------------------------------------------------
-- Range Check

DROP TABLE c8_employees;
CREATE TABLE c8_employees (
  employee_id INTEGER      NOT NULL,
  hourly_rate DECIMAL(7,2) NOT NULL );

ALTER TABLE c8_employees
ADD CONSTRAINT c8_employees_hourly_rate_ck
CHECK ( hourly_rate BETWEEN 15.75 AND 46.75 );

INSERT INTO c8_employees
  VALUES ( 101, 15.75 ),
         ( 102, 46.75 ),
         ( 103, 42.00 );

SELECT * FROM c8_employees;

INSERT INTO c8_employees
  VALUES ( 104, 46.80 ); -- hourly_rate outside range
-- [SQL0545] INSERT, UPDATE, or MERGE not allowed by CHECK constraint.

--------------------------------------------------------------
-- Compare Two Columns

DROP TABLE c8_employees;
CREATE TABLE c8_employees (
  employee_id INTEGER NOT NULL,
  birth_date  DATE    NOT NULL,
  hire_date   DATE    NOT NULL );

ALTER TABLE c8_employees
ADD CONSTRAINT c8_employees_birth_hire_dates_ck
CHECK ( hire_date > birth_date );

INSERT INTO c8_employees
  VALUES ( 101, '1990-05-01', '2005-12-15' ),
         ( 102, '1995-09-15', '2015-08-10' );

SELECT * FROM c8_employees;

INSERT INTO c8_employees
  VALUES ( 103, '2000-05-15', '1980-04-18' ); -- Dates are reversed
-- [SQL0545] INSERT, UPDATE, or MERGE not allowed by CHECK constraint.

SELECT * FROM c8_employees;

-- 2nd Example - Compare Two Columns

ALTER TABLE c8_employees
  ADD CONSTRAINT c8_employees_comm_salary_ck
  CHECK ( salary > commission );

--------------------------------------------------------------
-- Compare to list of values

DROP TABLE c8_employees;
CREATE TABLE c8_employees (
  employee_id INTEGER    NOT NULL,
  job_class   VARCHAR(1) NOT NULL );

ALTER TABLE c8_employees
  ADD CONSTRAINT c8_employees_job_class_ck
  CHECK ( job_class IN ( 'T', 'J', 'C', 'M') );

INSERT INTO c8_employees
  VALUES ( 101, 'T' ),
         ( 102, 'J' ),
         ( 103, 'C' ),
         ( 104, 'M' );

SELECT * FROM c8_employees;

INSERT INTO c8_employees
  VALUES ( 106, 'A' ); -- Invalid job class
-- [SQL0545] INSERT, UPDATE, or MERGE not allowed by CHECK constraint.

INSERT INTO c8_employees
  VALUES ( 106, 't' ); -- Invalid job class
-- [SQL0545] INSERT, UPDATE, or MERGE not allowed by CHECK constraint.

SELECT * FROM c8_employees;

--------------------------------------------------------------
-- 2nd Example - Compare to list of values

ALTER TABLE c8_employees
ADD CONSTRAINT c8_employees_sex_ck
CHECK ( sex IN ( 'F', 'M' ) );

--------------------------------------------------------------
-- Boolean Data Type - Using INTEGER data type

DROP TABLE c8_employees;
CREATE TABLE c8_employees (
  employee_id INTEGER NOT NULL,
  status      INTEGER NOT NULL DEFAULT 1 );

ALTER TABLE c8_employees
ADD CONSTRAINT c8_employees_status_ck
CHECK ( status IN ( 0, 1 ) );

INSERT INTO c8_employees
  VALUES (101, 1), -- Active employee
         (102, 0), -- Inactive employee
         (103, DEFAULT); -- Just hired, and defaults to active

SELECT * FROM c8_employees;

--------------------------------------------------------------
-- Boolean Data Type - Using VARCHAR data type

DROP TABLE c8_employees;
CREATE TABLE c8_employees (
  employee_id INTEGER    NOT NULL,
  status      VARCHAR(1) NOT NULL DEFAULT 'Y' );

ALTER TABLE c8_employees
ADD CONSTRAINT c8_employees_status_ck
CHECK ( status IN ( 'Y', 'N' ) );

INSERT INTO c8_employees
  VALUES ( 101, 'Y' ), -- Active employee
         ( 102, 'N' ), -- Inactive employee
         ( 103, DEFAULT ); -- Just hired, and defaults to active

SELECT * FROM c8_employees;

INSERT INTO c8_employees
  VALUES ( 104, 'y' ); -- Lower case 'y' is not allowed
-- [SQL0545] INSERT, UPDATE, or MERGE not allowed by CHECK constraint.

SELECT * FROM c8_employees;

--------------------------------------------------------------
-- Must be a value for one of two columns

DROP TABLE c8_employees;
CREATE TABLE c8_employees (
  employee_id    INTEGER     NOT NULL,
  commission     DECIMAL(5)  NOT NULL,
  bonus          DECIMAL(5)  NOT NULL );

ALTER TABLE c8_employees
  ADD CONSTRAINT c8_employees_comm_bonus_ck
  CHECK ( commission > 0 OR bonus > 0 );

INSERT INTO c8_employees
  VALUES ( 101, 555, 0 ),     -- Commission only
         ( 102,   0, 1555 );  -- Bonus only

SELECT * FROM c8_employees;

INSERT INTO c8_employees
  VALUES ( 103, 0, 0 );  -- Constraint violation
-- [SQL0545] INSERT, UPDATE, or MERGE not allowed by CHECK constraint.

INSERT INTO c8_employees
  VALUES ( 104, 500, 1000 );  -- Constraint violation - Inserting values in both columns - Is this what we want?
-- [SQL0545] INSERT, UPDATE, or MERGE not allowed by CHECK constraint.
  
SELECT * FROM c8_employees;  

  
--------------------------------------------------------------
-- Check more than two columns for a combination of values

DROP TABLE c8_employees;
CREATE TABLE c8_employees (
  employee_id INTEGER    NOT NULL,
  commission  DECIMAL(5) NOT NULL,
  bonus       DECIMAL(5) NOT NULL );

ALTER TABLE c8_employees
ADD CONSTRAINT comm_bonus_ck
CHECK ( (commission  > 0  AND bonus = 0)
   OR (  commission  = 0  AND bonus > 0) );

INSERT INTO c8_employees
  VALUES ( 101, 1500, 0 ),
         ( 102, 0, 3000 );
		 
SELECT * FROM c8_employees;

INSERT INTO c8_employees
  VALUES ( 103, 1500, 3000 ); -- Error - both columns have a value > 0
-- [SQL0545] INSERT, UPDATE, or MERGE not allowed by CHECK constraint.

SELECT * FROM c8_employees;

INSERT INTO c8_employees -- Error - both columns are 0
  VALUES ( 104, 0, 0 );
-- [SQL0545] INSERT, UPDATE, or MERGE not allowed by CHECK constraint.

SELECT * FROM c8_employees;

INSERT INTO c8_employees -- Error - negative number
  VALUES ( 105, -1000, 0 );
-- [SQL0545] INSERT, UPDATE, or MERGE not allowed by CHECK constraint.

SELECT * FROM c8_employees;

-- 2nd Example --------------------------------------------------------

DROP TABLE c8_employees;
CREATE TABLE c8_employees (
  employee_id       INTEGER     NOT NULL,
  emp_type          VARCHAR(1)  NOT NULL,
  salary            DECIMAL(5)  NOT NULL,
  bonus             DECIMAL(5)  NOT NULL,
  hourly_rate       DECIMAL(5)  NOT NULL,
  commission_earned DECIMAL(5)  NOT NULL );

ALTER TABLE c8_employees
ADD CONSTRAINT c8_emp_type_ck
CHECK ( emp_type IN ( 'S', 'H' ) );

ALTER TABLE c8_employees
ADD CONSTRAINT emp_salary_hourly_ck
CHECK ( ( emp_type = 'S'        AND
          salary > 0            AND
          bonus > 0             AND
          hourly_rate = 0       AND
          commission_earned = 0 )
          OR
        ( emp_type = 'H'        AND
          hourly_rate > 0       AND
          commission_earned > 0 AND
          salary = 0            AND
          bonus = 0 ) );

INSERT INTO c8_employees -- Valid inserts
  VALUES ( 101, 'S', 50000, 20000, 0, 0 ),
         ( 102, 'H', 0, 0, 125, 500 );

SELECT * FROM c8_employees;

INSERT INTO c8_employees
  VALUES ( 103, 'S', 50000, 0, 0, 0 ); -- salary > 0, but bonus = 0
-- [SQL0545] INSERT, UPDATE, or MERGE not allowed by CHECK constraint.

INSERT INTO c8_employees
  VALUES ( 106, 'S', 50000, 20000, 45.00, 0 ); -- salary and hourly_rate > 0
-- [SQL0545] INSERT, UPDATE, or MERGE not allowed by CHECK constraint.
-- and so on ...

  
-- Employee must provide either phone or email or both -----------------
DROP TABLE c8_employees;
CREATE TABLE c8_employees (
  employee_id   INTEGER       NOT NULL,
  contact_type  VARCHAR(1),
  mobile        VARCHAR(15),
  email         VARCHAR(50) );


ALTER TABLE c8_employees
ADD CONSTRAINT mobile_email_ck
CHECK (    contact_type = 'M'   AND mobile IS NOT NULL
        OR contact_type = 'E'   AND email IS NOT NULL
        OR contact_type IS NULL AND
           (mobile IS NOT NULL OR email IS NOT NULL) );

INSERT INTO c8_employees VALUES -- ALL Valid
  (101, 'M',  '+91 1234-567890', NULL),
  (102, 'M',  '1-111-111-1111', 'sally@mycompany.com'),
  (103, 'E',  NULL, 'joe@mycompany.com'),
  (104, 'E',  '1-222-222-2222', 'pete@mycompany.com'),
  (105, NULL, '1-333-333-3333', NULL),
  (106, NULL, NULL, 'alice@mycompany.com'),
  (107, NULL, '1-444-444-4444', 'bill@mycompany.com');

SELECT * FROM c8_employees;

INSERT INTO c8_employees VALUES (108, 'M', NULL, 'Al@mycompany.com');

INSERT INTO c8_employees VALUES (109, 'E', '1-555-5555', NULL);

INSERT INTO c8_employees VALUES (110, NULL, NULL, NULL);
 

SELECT * FROM c8_employees;


-- --------------------------------------------------------
-- BEWARE

DROP TABLE c8_employees;
CREATE TABLE c8_employees (
  employee_id INTEGER NOT NULL,
  salary      DECIMAL(7,0) );

ALTER TABLE c8_employees
  ADD CONSTRAINT c8_employees_salary_ck
  CHECK ( salary > 150000 AND salary < 100000 );

INSERT INTO c8_employees
  VALUES ( 101, 165000 ); -- salary > 150000
-- [SQL0545] INSERT, UPDATE, or MERGE not allowed by CHECK constraint.

INSERT INTO c8_employees
  VALUES ( 102, 95000 ); -- salary < 100000
-- [SQL0545] INSERT, UPDATE, or MERGE not allowed by CHECK constraint.

-- --------------------------------------------------------
-- DROP CHECK Constraint
ALTER TABLE c8_employees
  DROP CONSTRAINT emp_salary_hourly_ck;


