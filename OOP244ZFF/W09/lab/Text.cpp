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
#include <fstream>
#include "Text.h"
#include <cstring>

using namespace std;
namespace seneca {
   int Text::getFileLength() const {
      int len = 0;
      ifstream fin(m_filename);
      while (fin) {
         fin.get();
         len += !!fin;
      }
      return len;
   }

   // The one argument constructor
   Text::Text(const char* filename) {

       m_filename = nullptr; // Set filename to nullptr
       m_content = nullptr; // Set content to nullptr

       // Set filename to incoming argument if incoming argument != nullptr
       if (filename != nullptr) {

           m_filename = new char[strlen(filename) + 1];
           strcpy(m_filename, filename);
           read();
       }
   }

   // The Rule of three implementation
   // Copy constructor
   Text::Text(const Text& other) {

       m_filename = nullptr;
       m_content = nullptr;

       // Copy object in argument to class attributes if object != nullptr
       if (other.m_filename != nullptr) {

           m_filename = new char[strlen(other.m_filename) + 1];
           strcpy(m_filename, other.m_filename);

           m_content = new char[strlen(other.m_content) + 1];
           strcpy(m_content, other.m_content);
       }
   }

   // Copy assignment
   Text& Text::operator=(const Text& other) {

       if (this != &other) {

           delete[] m_filename;
           delete[] m_content;

           // Copy filename
           if (other.m_filename != nullptr) {

               m_filename = new char[strlen(other.m_filename) + 1];
               strcpy(m_filename, other.m_filename);
           }
           else {
               m_filename = nullptr;
           }

           // Copy content
           if (other.m_content != nullptr) {

               m_content = new char[strlen(other.m_content) + 1];
               strcpy(m_content, other.m_content);
           }
           else {
               m_content = nullptr;
           }
       }

       return *this;
   }

   // The Destructor
   Text::~Text() {

       delete[] m_filename;
       m_filename = nullptr;

       delete[] m_content;
       m_content = nullptr;
   }

   // index operator to provide read-only access to the content
   const char& Text::operator[](int index)const {

       return m_content[index];
   }

   // Read from the file
   void Text::read() {

       ifstream f(m_filename);

       if (f) {
           // dynamically set the memory of m_content equal to the file length
           m_content = new char[getFileLength() + 1];

           // Declare and initialize variables for internal operations
           int i = 0;
           char chr;

           // Loop through each character of content
           while (f.get(chr)) {

               m_content[i] = chr;
               i++;
           }

           // Manually add the null terminator at the end of file
           m_content[getFileLength()] = '\0';
       }
   }

   // Display the content into the std outstream (Display)
   void Text::write(ostream& os)const {

       if (m_content != nullptr) { // if the content is not nullptr

           os << m_content;
       }
   }

   // instertion overload into ostream
   ostream& operator<<(ostream& os, const Text& text) {

       text.write(os);
       return os;
   }

}