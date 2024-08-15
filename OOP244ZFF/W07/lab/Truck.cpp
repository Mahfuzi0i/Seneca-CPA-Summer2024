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

#define _CRT_SECURE_NO_WARNINGS
#include "Truck.h"

using namespace std;
namespace seneca {

	Truck::Truck(const char* plate, int yearBuilt, double capacity, const char* address)
		: MotorVehicle(plate, yearBuilt), capacity(capacity), currentCargo(0) {

		moveTo(address);
	}

	bool Truck::addCargo(double cargo) {
		
		if (currentCargo + cargo <= capacity) {
			currentCargo += cargo;
			return true;
		}
		else if (currentCargo != capacity) {
			currentCargo = capacity;
			return true;
		}

		return false;
	}

	bool Truck::unloadCargo() {

		if (currentCargo > 0) {
			currentCargo = 0;
			return true;
		}

		return false;
	}

	ostream& Truck::write(ostream& os) const {

		MotorVehicle::write(os);
		os << " | " << currentCargo << "/" << capacity;
		return os;
	}

	istream& Truck::read(istream& in) {
		MotorVehicle::read(in);
		cout << "Capacity: ";
		in >> capacity;
		cout << "Cargo: ";
		in >> currentCargo;

		return in;
	}

	ostream& operator << (ostream& os, const Truck& truck) {
		return truck.write(os);
	}

	istream& operator >> (istream& in, Truck& truck) {
		return truck.read(in);
	}
}