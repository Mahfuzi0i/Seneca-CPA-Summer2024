/* Citation and Sources...
Final Project Milestone 4
Module: Book
Filename: Book.h
Version 1.0
Author	Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date          Reason
2024/07/27    Create Book class

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

#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H
#include <iostream>
#include "Publication.h"

using namespace std;
namespace seneca {

	class Book : public Publication {

		char* authName;

	public:

		Book(); // The Book constructor
		// The rule of three declaration (copy constructor, copy assignment, Destructor)
		Book(const Book& Book); // Copy constructor
		Book& operator = (const Book& Book); // Copy assignment
		virtual ~Book(); // The Destructor
		// Declaring the provided virtual methods and type conversion operators
		virtual char type() const; // Will return the letter "B"
		virtual ostream& write(ostream& os) const; // Display publication with the author's name
		virtual istream& read(istream& istr); // read author's name
		virtual void set(int member_id); // invoke the set of the base class to set the member id
		virtual operator bool() const; // return true if the author's name exists and is not empty and the base class's operator bool() has returned true.
	};
}

#endif // !SENECA_BOOK_H