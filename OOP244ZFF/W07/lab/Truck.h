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

#ifndef SENECA_TRUCK_H
#define SENECA_TRUCK_H

#include "MotorVehicle.h"

using namespace std;
namespace seneca {

	// a class named Truck that holds information about a motor vehicle that can carry cargo. This class should inherit from MotorVehicle class.
	class Truck : public MotorVehicle {

	private:
		double capacity; // a capacity in kilograms as a floating-point number in double precision; this is the maximum weight of the cargo the truck can carry.
		double currentCargo; // the current cargo load (in kilograms) is a floating-point number in double precision; the load cannot exceed the capacity.

	public:
		Truck(const char* plate, int yearBuilt, double capacity, const char* address); // a custom constructor that receives as parameters the license plate number, the year when the truck was built, the capacity of the truck and the current address
		bool addCargo(double cargo); // a mutator that adds to the attribute that stores the current cargo load the weight specified as a parameter
		bool unloadCargo(); // a mutator that unloads current cargo (sets the attribute to 0). If the current load has been changed, return true, otherwise, return false.
		ostream& write(ostream& os) const; // a query that inserts into os the content of the object in a specific format
		istream& read(istream& in); // a mutator that reads from the stream in the data for the current object
	};

	// overload the insertion and extraction operators to insert a Truck into a stream and extract a Truck from a stream.
	ostream& operator << (ostream& os, const Truck& truck);
	istream& operator >> (istream& in, Truck& truck);
}
#endif // !SENECA_TRUCK_H
