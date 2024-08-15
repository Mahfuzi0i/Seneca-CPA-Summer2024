/* Citation and Sources...
Final Project Milestone 5
Module: Book
Filename: Book.cpp
Version 1.0
Author	Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date        Reason
2024/07/27  Book module implementation  

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

#include <iostream>
#include <cstring>
#include "Book.h"
#include "Streamable.h"
#include "Lib.h"

using namespace std;
namespace seneca {

	// A book is created empty by default, in a safe empty state
	Book::Book() {

		authName = nullptr;
	}

	// The rule of three implementation
	// The copy constructor
	Book::Book(const Book& Book) {

		// Copy the incoming argument to attribute dynamically
		if (Book.authName != nullptr) {

			authName = new char[strlen(Book.authName) + 1]; 
			strcpy(authName, Book.authName);
		}
		else {
			authName = nullptr;
		}
	}

	// The copy assignment
	Book& Book::operator = (const Book& Book) {

		Publication::operator = (Book);
		
		if (this != &Book) {

			// Delete the existing author Name and make a deep copy of the new one
			delete[] authName;

			if (Book.authName != nullptr) {

				authName = new char[strlen(Book.authName) + 1];
				strcpy(authName, Book.authName);
			}
			else {

				authName = nullptr;
			}
		}

		return *this;
	}

	// The Destructor
	Book::~Book() {

		delete[] authName;
	}

	char Book::type() const {

		return 'B';
	}

	ostream& Book::write(ostream& os) const {

		Publication::write(os);

		// check for incoming argument if its a console IO object
		if (conIO(os) == true) {

			os << " ";
			if (strlen(authName) < SENECA_AUTHOR_WIDTH) {

				os.setf(ios::left);
				os.width(SENECA_AUTHOR_WIDTH);
				os << authName;
				os.unsetf(ios::left);
			}
			else {

				for (int i = 0; i < SENECA_AUTHOR_WIDTH && authName[i] != '\0'; i++) {

					os << authName[i];
				}
			}
			os << " |";
		}
		else {

			os << '\t';
			os << authName;
		}
		return os;
	}

	istream& Book::read(istream& istr) {

		// Read the author name in local variables before setting the attribute to any value. (to make it easier let us assume the author's name can not be more than 256 characters)
		char tempName[256] = { '\0' };
		// First, invoke the read of the Base class.
		Publication::read(istr);
		// Free the memory held for the author's name
		delete[] authName;
		
		if (conIO(istr) == true) {

			istr.ignore(); // ignore one character (skip the '\n')
			cout << "Author: ";
			istr.getline(tempName, 255);
		}
		else {

			istr.ignore(); // ignore the tab character
			istr.get(tempName, 256, '\n');
		}

		// if the incoming istream object is not in a fail state, dynamically hold the author's name in the char pointer attribute of the book class.
		if (istr) {

			authName = new char[strlen(tempName) + 1]; // Dynamically allocated memory to size tempName
			strcpy(authName, tempName); // copy the tempName to the attribute
			authName[strlen(tempName)] = '\0'; // Ensure null terminator
		}
		else {
			authName = nullptr;
		}
		return istr;
	}

	void Book::set(int member_id) {

		Publication::set(member_id); // invoke the set of the base class to set the member id
		Publication::resetDate(); // reset the date to the current date.
	}

	Book::operator bool() const {

		bool temp;
		// return true if the author's name exists and is not empty and the base class's operator bool() has returned true
		if (authName != nullptr && Publication::operator bool() == true) {

			temp = true;
		}
		else {

			temp = false;
		}
		return temp;
	}

}


