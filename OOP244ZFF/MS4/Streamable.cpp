/* Citation and Sources...
Final Project Milestone 4
Module: Streamable
Filename: Streamable.cpp
Version 1.0
Author	Abdullah Al Mahfuz
Revision History
-----------------------------------------------------------
Date       Reason
2024/07/15 Added function implementations for the declarations in the header for the same file

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
#include "Streamable.h"

using namespace std;
namespace seneca {

	ostream& operator << (ostream& os, const Streamable& Streamable) {

		if (Streamable) { // Streamable can be written on an ostream object only if the Streamable object is in a valid state

			Streamable.write(os);
		}
		return os;
	}

	istream& operator >> (istream& is, Streamable& Streamable) {

		Streamable.read(is); // an object of type Streamable can be read from an istream object.
		return is;
	}
}