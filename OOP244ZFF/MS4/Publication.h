/* Citation and Sources...
Final Project Milestone 4
Module: Publication
Filename: Publication.h
Version 1.0
Author	Abdullah Al Mahfuz
Revision History
-----------------------------------------------------------
Date        Reason
2024/07/15  Create the Publication class

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

#ifndef SENECA_PUBLICATION_H
#define SENECA_PUBLICATION_H
#include <iostream>
#include "Date.h"
#include "Streamable.h"
#include "Lib.h"

using namespace std;
namespace seneca {

	class Publication : public Streamable {
		char* m_title; // a c-string to hold a dynamic title for the publication (NULL by default)
		char m_shelfId[SENECA_SHELF_ID_LEN + 1]; // a c-string that is exactly 4 characters long 4 is also defined as a macro in Lib.h, +1 to ensure null termination
		int m_membership; // an integer to hold a 5-digit membership number of members of the library.
		int m_libRef; // This serial number is used internally to uniquely identify each publication in the system. -1 by default. 

		Date m_date;
		void setEmpty(); // The function to set the attributes at its defaults

	public:
		Publication(); // The constructor to set the attributes to their default values

		// The Modifiers
		virtual void set(int member_id);
		// Sets the membership attribute to either zero or a five-digit integer.
		void setRef(int value);
		// Sets the **libRef** attribute value
		void resetDate();
		// Sets the date to the current date of the system.

		// The Queries
		virtual char type()const;
		//Returns the character 'P' to identify this object as a "Publication object"
		bool onLoan()const;
		//Returns true is the publication is checkout (membership is non-zero)
		Date checkoutDate()const;
		//Returns the date attribute
		bool operator==(const char* title)const;
		//Returns true if the argument title appears anywhere in the title of the 
		//publication. Otherwise, it returns false; (use strstr() function in <cstring>)
		operator const char* ()const;
		//Returns the title attribute
		int getRef()const;
		//Returns the libRef attirbute. 

		virtual bool conIO(ios& io)const; // Returns true if the address of the io object is the same as the address of either the cin object or the cout object.
		virtual ostream& write(ostream& os) const; // If the os argument is a console IO object (use conIO())
		virtual istream& read(istream& istr); // Pure virtual function that reads from an input stream
		virtual operator bool() const; // Returns true if neither of the title or shelfId attributes is null or empty

		// The rule of Three (copy construction, copy assignment and destructor)
		Publication(const Publication& other);
		Publication& operator = (const Publication& other);
		~Publication(); 
	};
}

#endif // !SENECA_PUBLICATION_H