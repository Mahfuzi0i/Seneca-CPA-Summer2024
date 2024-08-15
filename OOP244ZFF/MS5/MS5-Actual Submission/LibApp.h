/* Citation and Sources...
Final Project Milestone 5
Module: LibApp.h
Filename: LibApp.h
Version 1.0
Author	Fardad Soleimanloo
Description build a mockup application for the Seneca Library Application in a module called LibApp.
Revision History
-----------------------------------------------------------
Date      Reason
2024/07/01  Preliminary release
2024/07/01  Debugged DMA
2024/07/30  Add more attributes and modifications to the module


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

#define _CRT_SECURE_NO_WARNINGS
#ifndef SENECA_LIBAPP_H
#define SENECA_LIBAPP_H
#include "Menu.h"
#include "Lib.h"
#include "Publication.h"

namespace sdds {
   class LibApp {
       bool m_changed;
       Menu m_mainMenu; // The 3 LibApp publications
       Menu m_exitMenu;

       // Milestone 5 additions 
       char m_filename[256]; // Add an array of 256 characters to hold the publication data file name
       Publication* m_PPA[SENECA_LIBRARY_CAPACITY]; // PPA(Publication Pointers Array)- containing all the records of Publication file
       int m_NOLP; // NOLP(Number Of Loaded Publications)- an integer to hold the number of publications loaded into the PPA
       int m_LLRN; // LLRN(Last Library Reference Number)- an integer to hold the last library reference number read the data file
       Menu m_publicationMenu; // Add a Menu to the LibApp for selection of publication type.

       bool confirm(const char* message); // Instantiate a Menu in this function and initialize it with the message argument "yes"
       
       // Milestone 5 updates
       void load();  // prints: "Loading Data"<NEWLINE>, open the data file for reading and read all the publications in dynamic instances pointed by the PPA Array.
       void save();  // prints: "Saving Data"<NEWLINE>, then open the data file stream for overwriting. (ofstream)
       int search(int searchType);  // prints: "Searching for publication"<NEWLINE>, search for publication in 3 different ways

       void returnPub();  /*  Calls the search() method.
                              prints "Returning publication"<NEWLINE>
                              prints "Publication returned"<NEWLINE>
                              sets m_changed to true;
                          */
       void newPublication(); // prints "Adding new publication to library"+newline calls the confirm method with "Add this publication to library?"
       void removePublication(); // prints "Removing publication from library"+newline calls the search method
       void checkOutPub();  // calls the search method

   public:
       // The one argument constructor
       LibApp(const char* filename);
       void run();

       // Milestone 5 additions
       // to return the address of a Publication object in the PPA that has the library reference number matching the "libRef" argument.
       Publication* getPub(int libRef);
       virtual ~LibApp(); // The destructor for dynamically allocated memory for m_PPA
   };
}
#endif // !SENECA_LIBAPP_H



