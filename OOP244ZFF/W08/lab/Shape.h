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
#define CRT_SECURE_NO_WARNINGS

#ifndef SENECA_SHAPE_H
#define SENECA_SHAPE_H
#include <iostream>

using namespace std;
namespace seneca {

	class Shape {
	public:
		virtual void draw(ostream& os) const = 0;
		virtual void getSpecs(istream& is) = 0;
		virtual ~Shape() = default; // This tells the compiler to generate a default destructor. This guarantees that any dynamically allocated derived class from the Shape interface pointed by a Shape pointer will be removed properly from memory when deleted.
	};

	// The helper insertion (<<) and extraction (>>) operators
	ostream& operator << (ostream& os, const Shape& Shape);
	istream& operator >> (istream& is, Shape& Shape);
}

#endif // !SENECA_SHAPE_H
