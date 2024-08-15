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
#include "LblShape.h"
#include <cstring>
#include <string>

using namespace std;
namespace seneca {

	const char* LblShape::label() const {

		return m_label;
	}

	LblShape::LblShape() : m_label(nullptr) {};

	LblShape::LblShape(const char* label) : m_label(nullptr) {

		if (label != nullptr) {

			m_label = new char[strlen(label) + 1];
			strcpy(m_label, label);
		}
	}

	LblShape::~LblShape() {

		delete[] m_label;
		m_label = nullptr;
	}

	void LblShape::getSpecs(istream& is) {

		string tempString;
		getline(is, tempString, ',');

		delete[] m_label;

		m_label = new char[tempString.length() + 1];
		strcpy(m_label, tempString.c_str());
	}
}
