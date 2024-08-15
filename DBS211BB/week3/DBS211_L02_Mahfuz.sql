-- ***********************
-- Name: Abdullah Al Mahfuz
-- ID: 180377236
-- Date: 23 May 2024
-- Purpose: Lab 02 DBS211
-- ***********************

-- Q1 SOLUTION 
/*
1.	Display the data for all offices. Display office code, city, state, country, and phone for all offices.
*/
SELECT 
    OFFICECODE,
    CITY,
    STATE,
    COUNTRY,
    PHONE 
FROM 
    DBS211_OFFICES;

-- Q2 Solution 
/*
2.	Display employee number, first name, last name, and extension for all employees whose office code is 1. Sort the result based on the employee number.
*/
SELECT 
    EMPLOYEENUMBER,
    FIRSTNAME,
    LASTNAME,
    EXTENSION 
FROM 
    DBS211_EMPLOYEES
WHERE 
    OFFICECODE = 1
ORDER BY
    EMPLOYEENUMBER;
    
-- Q3 Solution 
/*
3.	Display customer number, customer name, contact first name and contact last name, and phone for all customers in Paris. (hint: be wary of case sensitivity) Sort the result based on the customer number.
*/
SELECT 
    CUSTOMERNUMBER,
    CUSTOMERNAME,
    CONTACTFIRSTNAME,
    CONTACTLASTNAME,
    PHONE
FROM
    DBS211_CUSTOMERS
WHERE
    upper(city) = 'PARIS'
ORDER BY
    CUSTOMERNUMBER;
    
-- Q4 Solution --
/*
4.	Repeat the previous Query with a couple small changes:
    a.	The contact�s first and last name should be in a single column in the format �lastname, firstname�.
    b.	Show customers who are in Canada
    c.	Sort the result based on the customer name.
*/
SELECT 
    CUSTOMERNUMBER AS "Customer Number",
    CUSTOMERNAME AS "Customer Name", 
    (CONTACTLASTNAME || ', ' || CONTACTFIRSTNAME) AS "Contact Name",
    PHONE AS "Phone"
FROM 
    DBS211_CUSTOMERS
WHERE 
    upper(country) = 'CANADA'
ORDER BY 
    CUSTOMERNAME;
    
-- Q5 Solution --
/*
5.	Display customer number for customers who have payments.  Do not included any repeated 
values. Sort the result based on the customer number. (Hints: How do you know a customer has made a payment? You will need to access only one table for this query)
The first 10 rows of the output result. The query returns 98 rows.
*/
SELECT DISTINCT 
    CUSTOMERNUMBER
FROM 
    DBS211_PAYMENTS
ORDER BY
    CUSTOMERNUMBER;
    
-- Q6 Solution --
/*
6.	List customer numbers, check number, and amount for customers whose payment amount is not in the range of $1,500 to $120,000. Sort the output by top payments amount first.
*/
SELECT
    CUSTOMERNUMBER,
    CHECKNUMBER,
    AMOUNT
FROM 
    DBS211_PAYMENTS
WHERE
    AMOUNT NOT BETWEEN 1500 AND 120000
ORDER BY
    AMOUNT DESC;
    
-- Q7 Solution --
/*
7.	Display order number, order date, status, and customer number for all orders that are cancelled. Sort the result according to order date.
*/
SELECT 
    ORDERNUMBER,
    ORDERDATE,
    STATUS,
    CUSTOMERNUMBER
FROM 
    DBS211_ORDERS
WHERE
    upper(status) = 'CANCELLED'
ORDER BY
    ORDERDATE;
    
-- Q8 Solution --
/*
8.	The company needs to know the percentage markup for each product sold.  Produce a query that outputs the ProductCode, ProductName, BuyPrice, MSRP in addition to
    a.	The difference between MSRP and BuyPrice (i.e. MSRP-BuyPrice) called markup
    b.	The percentage markup (100 * calculated by difference / BuyPrice) called percmarkup
        rounded to 1 decimal place.
    c.	Sort the result according to percmarkup.
    d.	Show products with percmarkup greater than 140.
*/
SELECT
    PRODUCTCODE,
    PRODUCTNAME,
    BUYPRICE,
    MSRP,
    (MSRP - BUYPRICE) AS MARKUP,
    ROUND(100 * ((MSRP - BUYPRICE)/BUYPRICE), 1) AS PERCMARKUP
FROM
    DBS211_PRODUCTS
WHERE 
    ROUND(100 * ((MSRP - BUYPRICE)/BUYPRICE), 1) > 140
ORDER BY
    PERCMARKUP;
    
-- Q9 Solution --
/*
9.	Display product code, product name, and quantity in stock the information of all products with string �co� in their product name. (c and o can be lower or upper case). Sort the result according to quantity in stock.
*/
SELECT 
    PRODUCTCODE,
    PRODUCTNAME,
    QUANTITYINSTOCK
FROM
    DBS211_PRODUCTS
WHERE
    lower(productname) LIKE '%co%'
ORDER BY
    QUANTITYINSTOCK;
    
-- Q10 Solution --
/*
10.	Display customer number, contact first name, contact last name for all customers whose contact first name starts with letter s (both lowercase and uppercase) and includes letter e (both lowercase and uppercase). Sort the result according to customer number.
*/
SELECT 
    CUSTOMERNUMBER,
    CONTACTFIRSTNAME,
    CONTACTLASTNAME
FROM
    DBS211_CUSTOMERS
WHERE
    lower(contactfirstname) LIKE 's%'
    AND lower(contactfirstname) LIKE '%e%'
ORDER BY
    CUSTOMERNUMBER;
    
