/* Citation and Sources...
Final Project Milestone 4
Module: Publication
Filename: Publication.cpp
Version 1.0
Author	Abdullah Al Mahfuz
Revision History
-----------------------------------------------------------
Date        Reason
2024/07/16  Added function implementation for the publication
2024/07/27  Modified the write function for adhering to MS4

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

#include <iostream>
#include <cstring>
#include "Utils.h"
#include "Publication.h"
#include "Lib.h"

using namespace std;
namespace seneca {

	// Function to set The Attributes to the default state
	void Publication::setEmpty() {
		
		m_title = nullptr;
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		m_date = Date();
	}

	// Setting the attributes to its default values
	Publication::Publication() {
	
		setEmpty();
	}

	// Sets m_membership to incoming argument
	void Publication::set(int member_id) {

		m_membership = member_id;
	}

	// Sets the **libRef** attribute value
	void Publication::setRef(int value) {

		m_libRef = value;
	}

	// Sets the date to the current date of the system.
	void Publication::resetDate() {

		m_date = Date();
	}

	//Returns the character 'P' to identify this object as a "Publication object"
	char Publication::type()const {

		return 'P';
	}

	//Returns true is the publication is checkout (membership is non-zero)
	bool Publication::onLoan()const {

		bool loan;

		if (m_membership != 0) {
			loan = true;
		}
		else {
			loan = false;
		}

		return loan;
	}
	
	//Returns the date attribute
	Date Publication::checkoutDate()const {

		return m_date;
	}

	//Returns true if the argument title appears anywhere in the title of the 
	//publication. Otherwise, it returns false; (use strstr() function in <cstring>)
	bool Publication::operator==(const char* title)const {

		bool temp;

		if (strstr(m_title, title) != nullptr) {
			temp = true;
		}
		else {
			temp = false;
		}
		return temp;
	}

	//Returns the title attribute
	Publication::operator const char* ()const {

		return m_title;
	}

	//Returns the libRef attirbute. 
	int Publication::getRef()const {

		return m_libRef;
	}

	// Returns true if the address of the io object is the same as the address of either the cin object or the cout object.
	bool Publication::conIO(ios& io)const {

		bool temp;

		if (&io == &cin || &io == &cout) {
			temp = true;
		}
		else {
			temp = false;
		}
		return temp;
	}

	ostream& Publication::write(ostream& os) const {
		// check if conIO returns true
		if (conIO(os) == true) {
			os << "| " << m_shelfId << " | ";

			// left justify padded with dots for title (MS4 modification)
			if (strlen(m_title) < SENECA_TITLE_WIDTH) {

				os.setf(ios::left);
				os.width(SENECA_TITLE_WIDTH);
				os.fill('.');
				os << m_title;
				os.unsetf(ios::left);
			}
			else {
				for (int i = 0; i < SENECA_TITLE_WIDTH; i++) {

					os << m_title[i];
				}
			}
			os << " | ";
			
			// check if membership is 0 and if so print N/A
			if (m_membership != 0) {
				os << m_membership;
			}
			else {
				os << " N/A ";
			}
			os << " | " << m_date << " |";
		}
		else {
			os << type() << "\t" << m_libRef << "\t" << m_shelfId << "\t";
			os << m_title << "\t" << m_membership << "\t" << m_date;
		}
		return os;
	}

	// Pure virtual function that reads from an input stream
	istream& Publication::read(std::istream& istr) {
		// clear all the attributes 
		setEmpty();
		// free the memory
		delete[] m_title;

		// create local variables
		char tempTitle[256] = { '\0' };
		char tempShelfId[SENECA_SHELF_ID_LEN + 1];
		int tempMembership = 0;
		int tempLibRef = 0;
		Date tempDate;

		// check if conIO returns true
		if (conIO(istr) == true) {
			cout << "Shelf No: ";
			// get line for shelfId up to length of Id + 1 for null terminator
			istr.getline(tempShelfId, SENECA_SHELF_ID_LEN + 1);

			// check if length of id is exactly 4 if not then set istr to fail state
			if (strlen(tempShelfId) != SENECA_SHELF_ID_LEN) {
				// use setstate function on input stream to set it to fail state
				istr.setstate(ios::failbit);
			}

			// get title using getline function to read up to 255 character or until it reaches new line 
			cout << "Title: ";
			istr.getline(tempTitle, 255);

			// get date
			cout << "Date: ";
			istr >> tempDate;
		}
		else {
			// get libRef and store in local variable and ignore new tab
			istr >> tempLibRef;
			istr.ignore();

			// get shelfId up to new tab and ignore the new tab 
			istr.get(tempShelfId, SENECA_SHELF_ID_LEN + 1, '\t');
			istr.ignore();

			// get title up to new tab or when 255 characters reached
			istr.getline(tempTitle, 255, '\t');

			// get membership and store in local variable and ignore new tab
			istr >> tempMembership;
			istr.ignore();

			// get date 
			istr >> tempDate;
		}

		// if date is invalid state then set istr to a fail state
		if (tempDate == false) {
			// use setstate function on input stream to set it to fail state
			istr.setstate(ios::failbit);
		}

		// if istr is in valid state using bool operator then assign the local variables to attributes
		if (istr) {
			m_title = new char[strlen(tempTitle) + 1];
			strcpy(m_title, tempTitle);
			m_title[strlen(tempTitle)] = '\0';
			m_libRef = tempLibRef;
			m_membership = tempMembership;
			strcpy(m_shelfId, tempShelfId);
			m_date = tempDate;
		}

		return istr;
	}

	// Returns true if neither of the title or shelfId attributes is null or empty
	Publication::operator bool() const {

		bool temp;

		if (m_title != nullptr && m_shelfId[0] != '\0') {
			temp = true;
		}
		else {
			temp = false;
		}
		return temp;
	}

	// The Rule of three implementation- Copy constructor
	Publication::Publication(const Publication& other) {

		// Perform a deep copy of the attributes
		m_libRef = other.m_libRef;
		m_membership = other.m_membership;
		m_date = other.m_date;
		m_shelfId[SENECA_SHELF_ID_LEN] = '\0';
		strncpy(m_shelfId, other.m_shelfId, SENECA_SHELF_ID_LEN);

		if (other.m_title != nullptr) {

			m_title = new char[strlen(other.m_title) + 1];
			strcpy(m_title, other.m_title);
		}
		else {
			m_title = nullptr;
		}
	}

	// Copy assignment
	Publication& Publication::operator = (const Publication& other) {

		if (this != &other) {

			m_libRef = other.m_libRef;
			m_membership = other.m_membership;
			m_date = other.m_date;
			m_shelfId[SENECA_SHELF_ID_LEN] = '\0';
			strncpy(m_shelfId, other.m_shelfId, SENECA_SHELF_ID_LEN);

			// delete the existing title and make a deep copy of the new one
			delete[] m_title;

			if (other.m_title != nullptr) {

				m_title = new char[strlen(other.m_title) + 1];
				strcpy(m_title, other.m_title);
			}
			else {
				m_title = nullptr;
			}
		}

		return *this;
	}

	// The Destructor
	Publication::~Publication() {

		delete[] m_title;
	}
}