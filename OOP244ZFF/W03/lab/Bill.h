/*
--------------------------------------------------------------------
Name           : Abdullah Al Mahfuz
Email          : aamahfuz@myseneca.ca
Student ID     : 180377236
Section        : ZFF
Date           : 28 May 2024 (Tuesday)

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
--------------------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS

#ifndef SENECA_BILL_H_
#define SENECA_BILL_H_
#include "Item.h"

namespace seneca {

   class Bill {

      char m_title[37];         // title of the shopping list
      Item* m_items;            // pointer to the dynamically allocated array of Items
      int m_noOfItems;          // size of the dynamically allocated array of Items
      int m_itemsAdded;         // number of the Items added by the add method

      double totalTax()const;   // returns the total tax applied to the Items
      double totalPrice()const; // returns the sum of prices of Items
      void Title()const;        // Prints the title of the shopping list
      void footer()const;       // prints the footer contaning total tax, price and total price after tax
      void setEmpty();          // sets the Bill to an emtpy state
      bool isValid()const;      // returns true is the Bill and all of its Items are valid

   public:
      void init(const char* title, int noOfItems);
      bool add(const char* item_name, double price, bool taxed);
      void display()const;
      void deallocate();
   };
}
#endif // !SENECA_TRANSCRIPT_H
