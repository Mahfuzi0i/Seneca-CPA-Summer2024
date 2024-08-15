/*
--------------------------------------------------------------------
Name           : Abdullah Al Mahfuz
Email          : aamahfuz@myseneca.ca
Student ID     : 180377236
Section        : ZFF
Date           : 30 June 2024 (Sunday)

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
--------------------------------------------------------------------
*/

#ifndef SENECA_TEXTFILE_H__
#define SENECA_TEXTFILE_H__
#include <iostream>

using namespace std;

namespace seneca {

   class TextFile; // forward declaration

   class Line {
      char* m_value{ nullptr };
      operator const char* ()const;
      Line() {}
      Line& operator=(const char*);
      ~Line();
      friend class TextFile;
      // copy and copy assignment prevention goes here
      Line(const Line& source) = delete;
      Line& operator=(const Line& source) = delete;

   };

   class TextFile {
      Line* m_textLines;
      char* m_filename;
      unsigned m_noOfLines;
      unsigned m_pageSize;
      void setFilename(const char* fname, bool isCopy = false);
      void setNoOfLines();
      void loadText();
      void saveAs(const char *fileName)const;
      void setEmpty(); // set the object to empty state
   public:
      TextFile(unsigned pageSize = 15);
      TextFile(const char* filename, unsigned pageSize = 15);
      TextFile(const TextFile& text);
      TextFile& operator=(const TextFile& text);
      ~TextFile();
      ostream& view(ostream& ostr)const;
      istream& getFile(istream& istr);
      operator bool()const;
      unsigned lines()const;
      const char* name()const;
      const char* operator[](unsigned index)const;
   };
   ostream& operator<<(ostream& ostr, const TextFile& text);
   istream& operator>>(istream& istr, TextFile& text);

}
#endif // !SENECA_TEXTFILE_H__
