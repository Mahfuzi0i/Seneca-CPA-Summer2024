/*
--------------------------------------------------------------------
Name           : Abdullah Al Mahfuz
Email          : aamahfuz@myseneca.ca
Student ID     : 180377236
Section        : ZFF
Date           : 28 May 2024 (Tuesday)

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
--------------------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Item.h"

const double TAX_RATE = 0.13; // The constant tax rate

using namespace std;
namespace seneca {

	// Private member function to set the name for the item
	void Item::setName(const char* name) {

		if (name) {

			strncpy(m_itemName, name, 20);
			m_itemName[20] = '\0'; // Ensure null termination
		}
		else {

			m_itemName[0] = '\0';
		}
	}

	// Public member function to set the item to an empty state;
	void Item::setEmpty() {

		m_itemName[0] = '\0'; // Blank string
		m_price = 0.0; // setting the price to an impossible value like 0.0 to set the item to a safe recognizable empty state
		m_taxed = false; // If there is no item, then what will the tax be upon?
	}

	// public member function to set the items attributes
	void Item::set(const char* name, double price, bool taxed) {

		if (name && price >= 0) {

			setName(name);
			m_price = price;
			m_taxed = taxed;
		}
		else {

			setEmpty();
		}
	}

	// Public member function to get the price
	double Item::price() const {

		return m_price;
	}

	// Public function to return tax
	double Item::tax() const {

		if (m_taxed) {

			return m_price * TAX_RATE; 
		}
		else {  // Returns the taxed amount otherwise 0.0 if the boolean m_taxed is false

			return 0.0;
		}
	}

	// Public function to check if the item is valid
	bool Item::isValid() const {

		return m_price > 0.0 && m_itemName[0] != '\0';
	}

	// Public function to display the items in a specific format
	void Item::display() const {

		if (isValid()) {

			cout << "| " << left << setw(20) << setfill('.') << m_itemName
				<< " | " << right << setfill(' ') << setw(7) << fixed << setprecision(2) << m_price
				<< " | " << (m_taxed ? "Yes" : "No ") << " |" << endl;
		}
		else {

			cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
		}
	}
}