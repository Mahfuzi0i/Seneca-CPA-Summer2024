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

#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include "Account.h"

using namespace std;
namespace seneca {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }

   // Type conversion operators
   Account::operator bool() const {
       return m_number >= 10000 && m_number <= 99999 && m_balance >= 0;
   }

   Account::operator int() const {
       return m_number;
   }

   Account::operator double() const {
       return m_balance;
   }

   // The Unary member operator
   bool Account::operator ~() const {
       return m_number == 0;
   }

   // Assignment operator to set account number
   Account& Account::operator = (int number) {

       if (m_number == 0) { // Only if the account is new!

           if (number >= 10000 && number <= 99999) {
               m_number = number;
           }
           else {
               setEmpty();
           }
       }
       return *this;
   }

   // Assignment operator to update the account balance and account number
   Account& Account::operator = (Account& other) {

       if (m_number == 0 && other) {  // Only if the current account is new and the other account is valid

           m_number = other.m_number;
           m_balance = other.m_balance;
           other.m_number = 0;
           other.m_balance = 0.0;
       }
       return *this;
   }

   // += operator to add a double value to the account balance
   Account& Account::operator += (double amount) {

       if (*this && amount > 0) {

           m_balance += amount;
       }
       return *this;
   }

   // -= operator to subtract a double value from the account balance
   Account& Account::operator -= (double amount) {

       if (*this && amount > 0 && m_balance >= amount) { // The account must have a balance equal to or more than the subtraction amount

           m_balance -= amount;
       }
       return *this;
   }

   // << operator to move funds from right account to left
   Account& Account::operator << (Account& other) {

       if (this != &other && *this && other) {

           m_balance += other.m_balance;
           other.m_balance = 0.0;
       }
       return *this;
   }

   // >> operator to move funds from left account to right
   Account& Account::operator >> (Account& other) {

       if (this != &other && *this && other) {

           other.m_balance += m_balance;
           m_balance = 0.0;
       }
       return *this;
   }

   // Getter functions 
   double Account::getBalance() const {
       return m_balance;
   }

   // Binary helper operator +
   double operator+(const Account& left, const Account& right) {

       if (left && right) {

           return left.getBalance() + right.getBalance();
       }
       return 0.0;
   }

   // Binary helper operator +=
   double& operator+=(double& left, const Account& right) {

       if (right) {

           left += right.getBalance();
       }
       return left;
   }
}