/*
--------------------------------------------------------------------
Name           : Abdullah Al Mahfuz
Email          : aamahfuz@myseneca.ca
Student ID     : 180377236
Section        : ZFF
Date           : 11 June 2024 (Tuesday)

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
--------------------------------------------------------------------
*/

#ifndef SENECA_ACCOUNT_H_
#define SENECA_ACCOUNT_H_
#include <iostream>

namespace seneca {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;

      // Type conversion operators
      operator bool() const;
      operator int() const;
      operator double() const;

      // The Unary member operator
      bool operator ~() const;

      // Assignment operators
      Account& operator = (int number);
      Account& operator = (Account& other);

      // Binary member operators
      Account& operator += (double amount);
      Account& operator -= (double amount);

      Account& operator << (Account& other);
      Account& operator >> (Account& other);

      // Getter function to to allow the helper functions access to the class
      double getBalance() const;

   };
   
   // Binary helper operators
   double operator + (const Account& left, const Account& right);
   double& operator += (double& left, const Account& right);
   
}
#endif // SENECA_ACCOUNT_H_