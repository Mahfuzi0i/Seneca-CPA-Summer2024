// Final Project 
// PublicationSelector
// File PublicationSelector.h
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
//                    
/////////////////////////////////////////////////////////////////
/* Citation and Sources...
Final Project Milestone 5

Name           : Abdullah Al Mahfuz
Email          : aamahfuz@myseneca.ca
Student ID     : 180377236
Section        : ZFF
Date           : 30 July 2024 (Tuesday)
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef SDDS_PUBLICATIONSELECTOR_H
#define SDDS_PUBLICATIONSELECTOR_H
#include "Publication.h"
namespace sdds {
   class PublicationSelector {
      const int allocationUnit{ 10 };
      const int m_pageSize{ };
      const Publication** m_pub{};
      char m_title[81]{};
      int m_currentPage{ 1 };
      int m_arraySize{};
      int m_noOfPubs{};
      void display(int page)const;
      int getSelectedLibRef()const;
   public:
      PublicationSelector(const char* title = "Select a publication: ", int pageSize = 15);
      ~PublicationSelector();
      PublicationSelector(const PublicationSelector&) = delete;
      PublicationSelector& operator=(const PublicationSelector&) = delete;
      // adds publication to the menu by address
      PublicationSelector& operator<<(const Publication* pub);
      // add publication tot he menu by reference
      PublicationSelector& operator<<(const Publication& pub);
      // return true menu is not empty 
      operator bool()const;
      // clears all the publications and sets the selector empty and ready to be refilled
      void reset(); 
      // sorts the selections based on date and title
      void sort();
      // runs the selection return the library reference fo the selection publication.
      int run();
   };
}
#endif // !SDDS_PUBLICATIONSELECTOR_H
