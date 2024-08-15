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
#include "MotorVehicle.h"

namespace seneca {
	MotorVehicle::MotorVehicle(const char* plate, int yearBuilt) : year(yearBuilt) {

		strncpy(licensePlate, plate, 8);
		licensePlate[8] = '\0'; // Ensuring null-termination
		strncpy(address, "Factory", 63);
		address[63] = '\0'; // Ensring null-termination
	}

	void MotorVehicle::moveTo(const char* newAddress) {

		if (strcmp(address, newAddress) != 0) {

			cout << "|" << setw(8) << right << licensePlate;
			cout << "| |" << setw(20) << right << address;
			cout << " ---> " << setw(20) << left << newAddress << "|" << endl;

			strncpy(address, newAddress, 63);
			address[63] = '\0'; // Ensuring null-termination

		}
	}

	ostream& MotorVehicle::write(ostream& os) const {

		os << "| " << year << " | " << licensePlate << " | " << address;
		return os;
	}

	istream& MotorVehicle::read(istream& in) {

		cout << "Built year: ";
		in >> year;
		cout << "License plate: ";
		in >> licensePlate;
		cout << "Current location: ";
		in.ignore();
		in.getline(address, 64);

		return in;
	}

	ostream& operator << (ostream& os, const MotorVehicle& vehicle) {
		return vehicle.write(os);
	}

	istream& operator >> (istream& in, MotorVehicle& vehicle) {
		return vehicle.read(in);
	}
}