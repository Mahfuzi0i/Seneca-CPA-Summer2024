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
#include "Line.h"

using namespace std;
namespace seneca {

	Line::Line() : m_length(0) {};

	Line::Line(const char* string, int lengthOfLine) : LblShape(string), m_length(lengthOfLine) {};

	void Line::getSpecs(istream& is) {

		LblShape::getSpecs(is); // call the getSpecs function of base class
		is >> m_length; // read m_length from istream
		is.ignore(1000, '\n'); // ignore rest of characters up to and including newline character 
	}

	void Line::draw(ostream& os) const {

		int i;

		if (m_length > 0 && label()) {

			os << label() << endl;	
		}

		for (i = 0; i < m_length; i++) {

			os << "=";
		}
	}
}
