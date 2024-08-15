/* Citation and Sources...
Final Project Milestone 4
Module: Streamable
Filename: Streamable.h
Version 1.0
Author	Abdullah Al Mahfuz
Revision History
-----------------------------------------------------------
Date        Reason
2024/07/15  Create declarations for the streamable Interface Module

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

#ifndef SENECA_STREAMABLE_H
#define SENECA_STREAMABLE_H
#include <iostream>

using namespace std;
namespace seneca {

	class Streamable {
	public:
		virtual ostream& write(ostream& os) const = 0; // Pure virtual function that writes into an ostream object, can not modify the streamable object
		virtual istream& read(istream& is) = 0; // Pure virtual function that reads from an istream object
		virtual bool conIO(ios& ios) const = 0; // receives a reference of an ios object and is not capable of modifying the streamable object.
		virtual operator bool() const = 0; // will return if the Streamable object is in a valid state or not.

		virtual ~Streamable() {}; // The DE-structor
	};

	// Helper functions overload (insertion and extraction operator)
	ostream& operator << (ostream& os, const Streamable& Streamable);
	istream& operator >> (istream& is, Streamable& Streamable);
}
#endif // !SENECA_STREAMABLE_H
