-- ***********************
-- Group 8 Assignment--
-- Member 1: Abdulla Al Mamun
-- Member 2: Abdullah Al Mahfuz
-- Member 3: Abrar Jawad Fardin
-- Date: 14th June 2024
-- Purpose: Assignment 01 DBS211
-- ***********************

-- Q1 SOLUTION --
SELECT 
    e.employeenumber AS "Employee Number",
    e.lastname || ', ' || e.firstname AS "Employee Name",
    o.phone AS "Phone",
    e.extension AS "Extension",
    o.city AS "City",
    CASE
        WHEN e.reportsto IS NULL THEN 'Unknown' 
        ELSE TO_CHAR(m.employeenumber) 
        END AS "Manager ID",
    CASE
        WHEN e.reportsto IS NULL THEN 'Unknown' 
        ELSE m.firstname || ' ' || m.lastname
        END AS "Manager Name"
FROM 
    dbs211_employees e
LEFT JOIN 
    dbs211_offices o USING (officecode) --I used USING because in both tables the column name is the same
LEFT JOIN 
    --the table e is left joined with table m even though both are the same table i.e, employees
    dbs211_employees m ON e.reportsto = m.employeenumber 
WHERE 
    e.reportsto IS NULL
ORDER BY 
    o.city, e.employeenumber;

-- Q2 Solution 
SELECT
    e.employeenumber AS "Employee Number",
    e.firstname || ' ' || e.lastname AS "Employee Name",
    o.phone AS "Phone",
    e.extension AS "Extension",
    o.city AS "City"
FROM 
    dbs211_employees e
LEFT JOIN
    dbs211_offices o USING (officecode)
WHERE
    o.city IN ('NYC','Paris','Tokyo')
ORDER BY
    o.city, e.employeenumber;

-- Q3 Solution --
SELECT
    e.employeenumber AS "Employee Number",
    e.lastname || ', ' || e.firstname AS "Employee Name",
    o.phone AS "Phone",
    e.extension AS "Extension",
    o.city AS "City",
    e.reportsto as "Manager ID",
    m.firstname || ' ' || m.lastname AS "Manager Name"
FROM 
    dbs211_employees e
LEFT JOIN
    dbs211_offices o USING (officecode)
LEFT JOIN
    dbs211_employees m ON e.reportsto = m.employeenumber
WHERE
    o.city IN ('NYC','Paris','Tokyo')
ORDER BY
    o.city, e.employeenumber;
    
    
-- Q4 Solution --
SELECT
    e.employeenumber AS "Manager ID",
    e.firstname || ' ' || e.lastname AS "Manager Name",
    o.country AS "COUNTRY",
    CASE 
        WHEN e.reportsto IS NOT NULL THEN 'Reports to ' || m.firstname || ' ' || m.lastname || '(' || m.jobtitle || ')'
        ELSE 'Does not report to anyone'
    END AS "Reports To"
FROM 
    dbs211_employees e
LEFT JOIN
    dbs211_offices o ON e.officecode = o.officecode
LEFT JOIN
    dbs211_employees m ON e.reportsto = m.employeenumber
WHERE 
    e.jobtitle LIKE '%Manager%' OR
    e.jobtitle LIKE 'President' OR
    e.employeenumber = 1056 OR
    e.employeenumber = 1621
ORDER BY
    e.employeenumber;

    
-- Q5 Solution --
SELECT
    c.customernumber,
    c.customername,
    od.productcode,
    p.msrp as "OLD Price",
    ROUND((p.msrp - (p.msrp * 0.10)), 2) as "New Price"
FROM
    dbs211_customers c
JOIN
    dbs211_orders o ON c.customernumber = o.customernumber
JOIN
    dbs211_orderdetails od ON o.ordernumber = od.ordernumber
JOIN
    dbs211_products p ON od.productcode = p.productcode
WHERE
    p.productvendor = 'Exoto Designs'
    AND od.quantityordered > 55
ORDER BY
    c.customernumber;
       
-- Q6 Solution --
SELECT
    --I used distinct because there are two prices that is 95.7 but we need only one maximum value
    DISTINCT od.priceeach AS "Maximum Price"
FROM 
    dbs211_orderdetails od
LEFT JOIN
    dbs211_orderdetails od2 ON od.productcode = od2.productcode
    -- Compares price from od and od2 priceeach
    -- For each row in od1, find rows in od2 where priceeach for od1 is less than priceeach for od2 with the same productcode
    AND od.priceeach < od2.priceeach
WHERE 
    -- If there priceeach in od2 does not exist, then the priceeach in od is the maximum value
    od.productcode = 'S10_1678' AND od2.priceeach IS NULL;



