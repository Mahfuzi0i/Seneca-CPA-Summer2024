/* Citation and Sources...
Final Project Milestone 2
Module: LibApp.h
Filename: LibApp.h
Version 1.0
Author	Abdullah Al Mahfuz
Description build a mockup application for the Seneca Library Application in a module called LibApp.
Revision History
-----------------------------------------------------------
Date      Reason
2024/07/01  Preliminary release
2024/07/01  Debugged DMA

Name           : Abdullah Al Mahfuz
Email          : aamahfuz@myseneca.ca
Student ID     : 180377236
Section        : ZFF
Date           : 11 July 2024 (Thursday)
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#ifndef SENECA_LIBAPP_H
#define SENECA_LIBAPP_H
#include "Menu.h"

namespace seneca {
   class LibApp {
       bool m_changed;
       Menu m_mainMenu; // The 3 LibApp publications
       Menu m_exitMenu;

       bool confirm(const char* message); // Instantiate a Menu in this function and initialize it with the message argument "yes"
       void load();  // prints: "Loading Data"<NEWLINE>
       void save();  // prints: "Saving Data"<NEWLINE>
       void search();  // prints: "Searching for publication"<NEWLINE>

       void returnPub();  /*  Calls the search() method.
                              prints "Returning publication"<NEWLINE>
                              prints "Publication returned"<NEWLINE>
                              sets m_changed to true;
                          */
       void newPublication(); // prints "Adding new publication to library"+newline calls the confirm method with "Add this publication to library?"
       void removePublication(); // prints "Removing publication from library"+newline calls the search method
       void checkOutPub();  // calls the search method

   public:
       LibApp();
       void run();
   };
}
#endif // !SENECA_LIBAPP_H



