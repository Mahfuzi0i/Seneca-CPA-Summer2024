/*
--------------------------------------------------------------------
Name           : Abdullah Al Mahfuz
Email          : aamahfuz@myseneca.ca
Student ID     : 180377236
Section        : ZFF
Date           : 21 May 2024 (Tuesday)

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
--------------------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Employee.h"
#include "File.h"
using namespace std;
namespace seneca {

   int noOfEmployees;
   Employee* employees;


   void sort() {
      int i, j;
      Employee temp;
      for (i = noOfEmployees - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (employees[j].m_empNo > employees[j + 1].m_empNo) {
               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }

   // TODO: Finish the implementation of the 1 arg load function which
   // reads one employee record from the file and loads it into the employee reference
   // argument
   bool load(Employee& emp) {
      bool ok = false;
      char name[128];
      /* if reading of employee number, salay and name are successful
              allocate memory to the size of the name + 1
              and keep its address in the name of the Employee Reference

              copy the name into the newly allocated memroy

              make sure the "ok" flag is set to true
         end if
      */
      if (read(emp.m_empNo) && read(emp.m_salary) && read(name)) {
          
          emp.m_name = new char[strlen(name) + 1];
          strcpy(emp.m_name, name);
          ok = true;
      }
      return ok;
   }
   // TODO: Finish the implementation of the 0 arg load function 
   bool load() {
      bool ok = false;
      int i = 0;
      if (openFile(DATAFILE)) {
         /* 
          Set the noOfEmployees to the number of recoreds in the file.
          dyanamically allocated an array of employees into the global
          Employee pointer; "employees" to the size of the noOfEmployees.

          In a loop load the employee records from the file into 
          the dynamic array.

          If the number of the records does not match the number of reads
             print the message
            "Error: incorrect number of records read; the data is possibly corrupted"
          Otherwise
             set the ok flag to true
          End if

          close the file
          */

          noOfEmployees = noOfRecords();

          employees = new Employee[noOfEmployees];

          for (i = 0; i < noOfEmployees; ++i) {
              if (!load(employees[i])) {
                  cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
                  break;
              }
          }

          if (i == noOfEmployees) {
              ok = true;
          }

          closeFile();
         
      }
      else {
         cout << "Could not open data file: " << DATAFILE<< endl;
      }
      return ok;
   }

   // TODO: Implementation for the display functions go here
   void display(const Employee& emp) {

       cout << emp.m_empNo << ": " << emp.m_name << ", " << emp.m_salary << endl;
   }

   void display() {

       int i;

       cout << "Employee Salary report, sorted by employee number" << endl;
       cout << "no- Empno, Name, Salary" << endl;
       cout << "------------------------------------------------" << endl;

       sort();

       for (i = 0; i < noOfEmployees; ++i) {

           cout << i + 1 << "- ";
           display(employees[i]);
       }
   }

   // TODO: Implementation for the deallocateMemory function goes here
   void deallocateMemory() {

       int i;

       for (i = 0; i < noOfEmployees; ++i) {
           delete[] employees[i].m_name;
       }
       delete[] employees;
   }


}