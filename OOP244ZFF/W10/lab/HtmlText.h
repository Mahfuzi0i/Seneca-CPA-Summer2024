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
#ifndef SENECA_HTMLTEXT_H__
#define SENECA_HTMLTEXT_H__
#include <iostream>
#include "Text.h"

using namespace std;
namespace seneca {
   class HtmlText :  public Text {
      char* m_title;
   public:
      HtmlText(const char* filename=nullptr, const char* title = nullptr);

      // Rule of three goes here (the copy constructor, copy assignment, Destructor)
      HtmlText(const HtmlText& otherHtml);
      HtmlText& operator = (const HtmlText& otherHtml); 
      virtual ~HtmlText();

      // Override the write function
      virtual void write(ostream& os) const;
   };
}
#endif // !SENECA_HTMLTEXT_H__
