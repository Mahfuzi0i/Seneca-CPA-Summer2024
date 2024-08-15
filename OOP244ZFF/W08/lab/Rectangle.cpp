/*
--------------------------------------------------------------------
Name           : Abdullah Al Mahfuz
Email          : aamahfuz@myseneca.ca
Student ID     : 180377236
Section        : ZFF
Date           : 14 July 2024 (Sunday)

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
--------------------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include "Rectangle.h"

using namespace std;
namespace seneca {

	Rectangle::Rectangle() : m_width(0), m_height(0) {};

	Rectangle::Rectangle(const char* string, int width, int height)
		: LblShape(string), m_width(width), m_height(height) {

		if (m_height < 3 || m_width < static_cast<int>(strlen(label()) + 2)) {

			m_width = 0;
			m_height = 0;
		}
	}

	void Rectangle::getSpecs(istream& is) {

		LblShape::getSpecs(is);
		
		char comma; // read two comma separated values from the input stream
		is >> m_width >> comma >> m_height;
		is.ignore(1000, '\n'); // Ignore the rest of the characters up to and including the newline character
	}

	void Rectangle::draw(std::ostream& os) const {
		
		// is rectangle not in empty state 
		if (m_width != 0 && m_height != 0) {
			// print first line
			os << "+";
			for (int i = 0; i < m_width - 2; i++) {
				os << "-";
			}
			os << "+" << endl;
			// print second line
			os << "|";
			os.width(m_width - 2);
			os.setf(ios::left);
			os << label();
			os.unsetf(ios::left);
			os << "|" << endl;
			// print m_height -3 lines 
			for (int i = 0; i < m_height - 3; i++) {
				os << "|";
				for (int i = 0; i < m_width - 2; i++) {
					os << " ";
				}
				os << "|" << endl;
			}
			// print last line
			os << "+";
			for (int i = 0; i < m_width - 2; i++) {
				os << "-";
			}
			os << "+";

		}
	}


}
