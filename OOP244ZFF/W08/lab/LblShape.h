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

#ifndef SENECA_LBLSHAPE_H
#define SENECA_LBLSHAPE_H
#include "Shape.h"

using namespace std;
namespace seneca {

	class LblShape : public Shape { // Inherit an abstract class from the interface Shape called LblShape. This class adds a label to a Shape
		char* m_label{ nullptr };

	protected:
		const char* label() const;

	public:
		LblShape(); // Default (no argument) constructor
		LblShape(const char* label); // One argument constructor-- Allocates memory large enough to hold the incoming Cstring argument pointed by the m_label member variable.Then copies the Cstring argument to the newly allocated memory.
		
		virtual ~LblShape(); // The Destructor
		
		LblShape(const LblShape& otherShape) = delete; // Prohibit copy constructor
		LblShape& operator = (const LblShape& otherShape) = delete; // Prohibit copy assignment

		void getSpecs(istream& is) override; // Override the pure virtual functions

	};
}

#endif // !SENECA_LBLSHAPE_H