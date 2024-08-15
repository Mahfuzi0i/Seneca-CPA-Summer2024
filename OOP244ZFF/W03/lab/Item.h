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

#ifndef SENECA_ITEM_H_
#define SENECA_ITEM_H_

namespace seneca {

   class Item {

      char m_itemName[21]; 
      double m_price;
      bool m_taxed;
      void setName(const char* name); // Private member function to set the name for the item

   public:
      void setEmpty(); // Public member function to set the item to an empty state;
      void set(const char* name, double price, bool taxed); // public member function to set the items attributes
      void display()const; // Public function to display the items in a specific format
      bool isValid()const; // Public function to check if the item is valid
      double price()const; // Public member function to get the price
      double tax()const; // Public function to return tax
   };
}

#endif // !SENECA_SUBJECT_H
