// **********************
//Name: Abdullah Al Mahfuz
//ID : 180377236
//Date : 05 July 2024 (Friday)
//Purpose : Lab 07 DBS211 (Connecting to an Oracle database from a C++ Program)
// **********************
// Even though this is lab7, but the word instructions say L06_ID_LASTNAME.cpp, so thats why i named it L06_180377236_MAHFUZ.cpp

#include <iostream>
#include <occi.h>
#include <iomanip>

using oracle::occi::Environment;
using oracle::occi::Connection;
using namespace oracle::occi;
using namespace std;

/*
1.	Display Employee Number, First Name, Last Name, Phone Number, and Extension of 
all Employees who work in San Francisco. See the following Sample output. 
(Sort the report according to the employee number)
*/
void displayEmployeesInSanFrancisco(Connection* conn) {
    Statement* stmt = conn->createStatement(
        "SELECT employeenumber, firstname, lastname, o.phone, extension "
        "FROM dbs211_employees e "
        "JOIN dbs211_offices o ON e.officecode = o.officecode "
        "WHERE o.CITY = 'San Francisco' "
        "ORDER BY employeenumber");
    ResultSet* rs = stmt->executeQuery();
  //cout << "Employee ID    First Name          Last Name           Phone                    Extension
    cout << "--------------------------- Report 1 (Employee Report) -------------------------------------------" << endl;
    cout << left << setw(15) << "Employee ID"
        << left << setw(20) << "First Name"
        << left << setw(20) << "Last Name"
        << left << setw(25) << "Phone"
        << left << setw(10) << "Extension" << endl;
  //cout << "Employee ID    First Name          Last Name           Phone                    Extension
    cout << "------------   -----------------   -----------------   ----------------------   ---------" << endl;

    while (rs->next()) {
        cout << left << setw(15) << rs->getInt(1)
            << left << setw(20) << rs->getString(2)
            << left << setw(20) << rs->getString(3)
            << left << setw(25) << rs->getString(4)
            << left << setw(10) << rs->getString(5) << endl;
    }

    stmt->closeResultSet(rs);
    conn->terminateStatement(stmt);
}

/*
2.	Display Employee Number, Last Name, Phone Number, and Extension for all managers. 
(You can use column reportsto to find the managers’ employee number)
*/
void displayManagers(Connection* conn) {
    Statement* stmt = conn->createStatement(
        "SELECT employeenumber, firstname, lastname, o.phone, extension "
        "FROM dbs211_employees e "
        "JOIN dbs211_offices o ON e.officecode = o.officecode "
        "WHERE employeenumber IN (SELECT DISTINCT reportsto FROM dbs211_employees)");
    ResultSet* rs = stmt->executeQuery();

    cout << "--------------------------- Report 2 (Manager Report) -------------------------------------------" << endl;
    cout << left << setw(15) << "Employee ID"
        << left << setw(20) << "First Name"
        << left << setw(20) << "Last Name"
        << left << setw(25) << "Phone"
        << left << setw(10) << "Extension" << endl;
    cout << "------------   -----------------   -----------------   ----------------------   ---------" << endl;

    while (rs->next()) {
        cout << left << setw(15) << rs->getInt(1)
            << left << setw(20) << rs->getString(2)
            << left << setw(20) << rs->getString(3)
            << left << setw(25) << rs->getString(4)
            << left << setw(10) << rs->getString(5) << endl;
    }

    stmt->closeResultSet(rs);
    conn->terminateStatement(stmt);
}

int main(void) {
    /* OCCI Variables */
    Environment* env = nullptr;
    Connection* conn = nullptr;
    /* Used Variables */
    string user = "dbs211_242zbb17"; // The provided seneca oracle id
    string pass = "28195285"; // The provided seneca oracle password
    string constr = "myoracle12c.senecacollege.ca:1521/oracle12c";

    try {
        env = Environment::createEnvironment(Environment::DEFAULT);
        conn = env->createConnection(user, pass, constr);

        // Display reports
        displayEmployeesInSanFrancisco(conn);
        cout << endl;
        displayManagers(conn);

        env->terminateConnection(conn);
        Environment::terminateEnvironment(env);
    }
    catch (SQLException& sqlExcp) {
        cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage() << endl;
    }

    return 0;
}

