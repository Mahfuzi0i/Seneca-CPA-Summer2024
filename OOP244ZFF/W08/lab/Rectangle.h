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

#ifndef SENECA_RECTANGLE_H
#define SENECA_RECTANGLE_H
#include "LblShape.h"

using namespace std;
namespace seneca {

	class Rectangle : public LblShape {
		int m_width;
		int m_height;
	
	public:
		Rectangle(); // The no argument constructor
		Rectangle(const char* string, int width, int height); // The 3 argument constructor

		void getSpecs(istream& is) override; // reads comma separated specs of the rectangle from istream
		void draw(ostream& os) const override; // Draws Triangle
	};
}

#endif // !SENECA_RECTANGLE_H
