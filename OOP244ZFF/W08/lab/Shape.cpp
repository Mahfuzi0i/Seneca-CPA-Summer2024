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
#define CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Shape.h"

using namespace std;
namespace seneca {

	// The helper operators
	ostream& operator << (ostream& os, const Shape& Shape) {

		Shape.draw(os);
		return os;
	}

	istream& operator >> (istream& is, Shape& Shape) {

		Shape.getSpecs(is);
		return is;
	}
}
