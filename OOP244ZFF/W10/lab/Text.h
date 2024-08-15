/*
--------------------------------------------------------------------
Name           : Abdullah Al Mahfuz
Email          : aamahfuz@myseneca.ca
Student ID     : 180377236
Section        : ZFF
Date           : 23 July 2024 (Tuesday)

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
--------------------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#ifndef SENECA_TEXT_H__
#define SENECA_TEXT_H__
#include <iostream>

using namespace std;
namespace seneca {
   class Text {
      char* m_filename ;
      char* m_content ;
      int getFileLength()const;
   protected:
      const char& operator[](int index)const;
   public:
      Text(const char* filename=nullptr);
      // Implement the rule of three (copy constructor, copy assignment, destructor)
      Text(const Text& other); // Copy constructor
      Text& operator = (const Text& other); // copy assignent
      ~Text(); // The Destructor

      void read();
      virtual void write(std::ostream& os)const;
   };
   // prototype of insertion overload into ostream goes here
   ostream& operator<<(ostream& os, const Text& text);
}
#endif // !SENECA_PERSON_H__

