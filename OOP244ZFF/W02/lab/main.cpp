/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 2
// Version 1.0
// Description
// professor's tester program
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
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
#include "Employee.h"
using namespace seneca;
int main() {
   if (load()) {
      display();
   }
   deallocateMemory();
   return 0;
}