/*
--------------------------------------------------------------------
Name           : Abdullah Al Mahfuz
Email          : aamahfuz@myseneca.ca
Student ID     : 180377236
Section        : ZFF
Date           : 05 june 2024 (Wednesday)

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
--------------------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include <cstring>
#include "Canister.h"

using namespace std;

namespace seneca {

	const double PI = 3.14159265;

	void Canister::setToDefault() { // The default characteristics of a canister

		m_contentName = nullptr;
		m_diameter = 10.0;
		m_height = 13.0;
		m_contentVolume = 0.0;
		m_usable = true;  
	}

	bool Canister::isEmpty()const {  // Private method to check if the Canister is empty (achive it by comparing the content volume to 0.00001)

		return m_contentVolume < 0.00001;
	}

	bool Canister::hasSameContent(const Canister& C)const {  // Private method to check if the content name matches another Canister's content

		if (m_contentName && C.m_contentName) {

			return strcmp(m_contentName, C.m_contentName) == 0;
		}

		return false;
	}

	void Canister::setName(const char* Cstr) {  // Private method to set the content name of the Canister

		if (Cstr && m_usable) {

			delete[] m_contentName;
			m_contentName = new char[strlen(Cstr) + 1]; // +1 for the null 
			strcpy(m_contentName, Cstr);
		}
	}

	Canister::Canister() {  // The no argument constructor, set attributes to their default values

		setToDefault();
	}

	Canister::Canister(const char* contentName) {  // One argument constructor. set the upcoming contentname to the name of the canister, as well as setting the values to default

		setToDefault();
		setName(contentName);
	}

	Canister::Canister(double height, double diameter, const char* contentName) {  // Constructor with height, diameter, and content name (the custom canister within the provided valid range)

		setToDefault();
		if (height >= 10.0 && height <= 40.0 && diameter >= 10.0 && diameter <= 30.0) {

			m_height = height;
			m_diameter = diameter;
			m_contentVolume = 0.0;
			setName(contentName);
		}
		else {
			m_usable = false;
		}
	}

	Canister::~Canister() {  // Destructor
		delete[] m_contentName;
	}

	Canister& Canister::setContent(const char* contentName) {  // Public method to set content name

		if (contentName == nullptr) {

			m_usable = false;
		}
		else if (isEmpty()) {

			setName(contentName);
		}
		else if (!hasSameContent(*this)) {

			m_usable = false;
		}

		return *this;
	}

	Canister& Canister::pour(double quantity) {  // Public method to pour a quantity of liquid into the Canister

		if (m_usable && quantity > 0 && (m_contentVolume + quantity <= capacity())) {

			m_contentVolume += quantity;
		}
		else {

			m_usable = false;
		}

		return *this;
	}

	Canister& Canister::pour(Canister& C) {  // Public method to pour contents from another Canister

		setContent(C.m_contentName);

		if (m_usable) {

			if (C.volume() > (capacity() - volume())) {

				C.m_contentVolume -= (capacity() - volume());
				m_contentVolume = capacity();

				if (!hasSameContent(C)) {

					m_usable = false;
				}
			}
			else {

				pour(C.m_contentVolume);
				C.m_contentVolume = 0.0;
			}
		}

		return *this;
	}

	double Canister::volume()const {  // Public method to get the current volume

		return m_contentVolume;
	}

	std::ostream& Canister::display()const {  // Public method to display Canister details in a very specific format

		cout << fixed << setprecision(1) << setw(7) << capacity() << "cc (" << m_height << "x" << m_diameter << ") Canister";

		if (!m_usable) {

			cout << " of Unusable content, discard!";
		}
		else if (m_contentName) {

			cout << " of " << setw(7) << m_contentVolume << "cc   " << m_contentName;
		}

		return cout;
	}


	double Canister::capacity()const {  // Public method to calculate the capacity

		return PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
	}

	void Canister::clear() {  // Public method to clear an unusable Canister (as well as making sure the let go of the dynamically allocated memory)

		delete[] m_contentName;
		m_contentName = nullptr;
		m_contentVolume = 0.0;
		m_usable = true;
	}

}