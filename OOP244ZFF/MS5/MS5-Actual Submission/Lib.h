/* Citation and Sources...
Final Project Milestone 5
Module: Seneca Library
Filename: Lib.h
Version 1.0
Author	Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date         Reason
2024/07/15   Add general values of the system
2024/07/30   Modified one macro to adhere with the requirement

Name           : Abdullah Al Mahfuz
Email          : aamahfuz@myseneca.ca
Student ID     : 180377236
Section        : ZFF
Date           : 27 July 2024 (Saturday)
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS

#ifndef SENECA_LIB_H
#define SENECA_LIB_H

namespace sdds {

    const int SENECA_MAX_LOAN_DAYS = 15;
    // maximum number of day a publication can be borrowed with no penalty
    const int SENECA_TITLE_WIDTH = 30;
    // The width in which the title of a publication should be printed on the console
    const int SENECA_AUTHOR_WIDTH = 15;
    // The width in which the author name of a book should be printed on the console
    const int SENECA_SHELF_ID_LEN = 4;
    // The width in which the shelf id of a publication should be printed on the console
    const int SENECA_LIBRARY_CAPACITY = 333;
    // Before starting this test make sure that in "Lib.h"
    //The maximum capacity of the library is set to 333.
    // Maximum number of publications the library can hold.
}

#endif // !SENECA_LIB_H