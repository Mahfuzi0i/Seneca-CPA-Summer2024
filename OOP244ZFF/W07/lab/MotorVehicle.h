/*
--------------------------------------------------------------------
Name           : Abdullah Al Mahfuz
Email          : aamahfuz@myseneca.ca
Student ID     : 180377236
Section        : ZFF
Date           : 08 July 2024 (Monday)

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
--------------------------------------------------------------------
*/

#ifndef SENECA_MOTORVEHICLE_H
#define SENECA_MOTORVEHICLE_H

#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;
namespace seneca {

	class MotorVehicle {

	private:
		char licensePlate[9]; // a license plate number as a statically allocated array of characters of size 9.
		char address[64]; // the address where the vehicle is at a given moment as a statically allocated array of characters of size 64.
		int year; // the year when the vehicle was built.

	public:
		MotorVehicle(const char* plate, int yearBuilt); // a custom constructor that receives as parameters the license plate number and the year when the vehicle was built
		void moveTo(const char* address); // moves the vehicle to the new address if the new address is different from the current address
		ostream& write(ostream& os) const; // a query that inserts into os the content of the object in a specific format
		istream& read(istream& in); // a mutator that reads from the stream in the data for the current object
	};

	// Overloaded insertion and extraction operators
	ostream& operator << (ostream& os, const MotorVehicle& vehicle);
	istream& operator >> (istream& in, MotorVehicle& vehicle);
}
#endif // !SENECA_MOTORVEHICLE_H
