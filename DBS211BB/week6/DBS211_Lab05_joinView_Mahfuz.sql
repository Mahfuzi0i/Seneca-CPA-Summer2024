-- ***********************
-- Name: Abdullah Al Mahfuz
-- ID: 180377236
-- Date: 12 June 2024 (Wednesday)
-- Purpose: Lab 05 DBS211
-- ***********************
SET AUTOCOMMIT ON;

-- Q1 Solution
-- a. using an ANSI-89 Join.
SELECT 
    e.employeenumber,
    e.firstname,
    e.lastname,
    o.city,
    o.phone,
    o.postalcode
FROM
    dbs211_employees e,
    dbs211_offices o
WHERE
    e.officecode = o.officecode
    AND o.country = 'France';
    
-- b. using ANSI-92 join
SELECT 
    e.employeenumber,
    e.firstname,
    e.lastname,
    o.city,
    o.phone,
    o.postalcode
FROM 
    dbs211_employees e
JOIN 
    dbs211_offices o
USING
    (officecode)
WHERE o.country = 'France';

--Q2 Solution
SELECT
    c.customernumber,
    c.customername,
    TO_CHAR(p.paymentdate, 'DD-Mon-YY') AS paymentdate,
    p.amount
FROM
    dbs211_customers c,
    dbs211_payments p   
WHERE
    c.customernumber = p.customernumber
    AND c.country = 'Canada'
ORDER BY
    c.customernumber;
    
--Q3 Solution
SELECT
    c.customernumber,
    c.customername
FROM 
    dbs211_customers c
LEFT JOIN
    dbs211_payments p ON c.customernumber = p.customernumber
WHERE
    c.country = 'USA'
    AND p.customernumber IS NULL
ORDER BY
    c.customernumber;
    
--Q4 Solution 
-- a. Create a view (vwCustomerOrder) to view specific data
CREATE 
    VIEW vwCustomerOrder AS
SELECT
    o.customernumber,
    o.ordernumber,
    o.orderdate,
    p.productname,
    od.quantityordered,
    od.priceeach
FROM
    dbs211_orders o
JOIN
    dbs211_orderdetails od ON o.ordernumber = od.ordernumber
JOIN
    dbs211_products p ON od.productcode = p.productcode;
    
-- b. view the vwCustomerorder that was just created
SELECT *
FROM vwcustomerorder;

--Q5 Solution
SELECT
    v.customernumber,
    v.ordernumber,
    v.orderdate,
    v.productname,
    v.quantityordered,
    v.priceeach,
    od.orderlinenumber
FROM
    vwCustomerOrder v
JOIN
    dbs211_orderdetails od ON v.ordernumber = od.ordernumber 
    AND v.productname = (
    SELECT productname
    FROM dbs211_products p
    WHERE p.productcode = od.productcode
    )
WHERE
    v.customernumber = 124
ORDER BY 
    v.ordernumber,
    od.orderlinenumber;
    
--Q6 Solution
SELECT
    c.customernumber,
    c.contactfirstname AS firstname,
    c.contactlastname AS lastname,
    c.phone,
    c.creditlimit
FROM
    dbs211_customers c
LEFT JOIN
    dbs211_orders o ON c.customernumber = o.customernumber
WHERE
    o.ordernumber IS NULL;
    
--Q7 Solution
CREATE 
    VIEW vwEmployeeManager AS
SELECT
    e.employeenumber,
    e.firstname AS employeefirstname,
    e.lastname AS employeelastname,
    e.extension,
    e.email,
    e.officecode,
    e.reportsto,
    e.jobtitle,
    m.firstname AS managerfirstname,
    m.lastname AS managerlastname
FROM 
    dbs211_employees e
LEFT JOIN 
    dbs211_employees m ON e.Reportsto = m.employeenumber;
    
-- View the table
SELECT *
FROM vwEmployeeManager;

--Q8 Solution
CREATE OR REPLACE
VIEW
    vwEmployeeManager AS
SELECT
    e.employeenumber,
    e.firstname AS employeefirstname,
    e.lastname AS employeelastname,
    e.extension,
    e.email,
    e.officecode,
    e.reportsto,
    e.jobtitle,
    m.firstname AS managerfirstname,
    m.lastname AS managerlastname
FROM
    dbs211_employees e
LEFT JOIN
    dbs211_employees m ON e.reportsto = m.employeenumber
WHERE
    e.reportsto IS NOT NULL;
--View table 
SELECT*
FROM vwEmployeeManager;

--Q9 Solution
DROP VIEW vwCustomerOrder;
DROP VIEW vwEmployeeManager;
    

    
    
    