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
#pragma once
#define _CRT_SECURE_NO_WARNINGS

#ifndef SENECA_LINE_H
#define SENECA_LINE_H
#include "LblShape.h"

using namespace std;
namespace seneca {

	class Line : public LblShape { // Line inherits the LblShape class to create a horizontal line with a label.

		int m_length; // m_length to hold the length of the Line in characters.

	public:
		Line(); // The no-argument constructor
		Line(const char* string, int lengthOfLine); // The two argument constructor

		void getSpecs(istream& is) override; // reads comma separated specs of the line from the input stream
		void draw(ostream& os) const override; // overrides draw  of baseclass and prints on the screen
	};
}

#endif // !SENECA_LINE_H
