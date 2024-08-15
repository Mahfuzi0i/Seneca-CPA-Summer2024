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
#include "Bill.h"

using namespace std;
namespace seneca {

	// Private member function to set the Bill object to an empty state
	void Bill::setEmpty() {

		m_title[0] = '\0';
		m_items = nullptr;
		m_noOfItems = 0;
		m_itemsAdded = 0;
	}

	// Private member function to check validity of items
	bool Bill::isValid() const {

		int i;
		// Check if the title is empty or if the items pointer is null
		if (m_title[0] == '\0' && m_items == nullptr) {

			return false; // If either is true, the Bill is invalid
		}

		for (i = 0; i < m_noOfItems; ++i) {
			// Check if the current item is invalid
			if (!m_items[i].isValid()) {
				return false;  // If any item is invalid, the Bill is invalid
			}
		}
		// If the title is not empty, the items pointer is not null, and all items are valid
		return true;
	}

	// Private member function to calculate the total tax on the items
	double Bill::totalTax() const {

		double sum = 0.0;
		int i;

		for (i = 0; i < m_noOfItems; ++i) {

			sum += m_items[i].tax();
		}
		return sum;
	}

	// Private member function to calculate the sum all the items
	double Bill::totalPrice() const {

		double sum = 0.0;
		int i;

		for (i = 0; i < m_noOfItems; ++i) {

			sum += m_items[i].price();
		}
		return sum;
	}

	// Private member function to print the title of the shopping list in a specific format
	void Bill::Title() const {

		cout << "+--------------------------------------+" << endl;
		if (isValid()) {

			cout << "| " << left << setw(36) << m_title << " |" << endl;
		}
		else {

			cout << "| Invalid Bill                         |" << endl;
		}
		// Then in both cases (valid or invalid), it will print:
		cout << "+----------------------+---------+-----+" << endl;
		cout << "| Item Name            | Price   + Tax |" << endl;
		cout << "+----------------------+---------+-----+" << endl;
	}

	// Private member function to print the footer of the Bill
	void Bill::footer() const {

		cout << "+----------------------+---------+-----+" << endl;
		if (isValid()) {

			cout << "|                Total Tax: " << right << setw(10) << fixed << setprecision(2) << totalTax() << " |" << endl;
			cout << "|              Total Price: " << right << setw(10) << fixed << setprecision(2) << totalPrice() << " |" << endl;
			cout << "|          Total After Tax: " << right << setw(10) << fixed << setprecision(2) << (totalTax() + totalPrice()) << " |" << endl;
		}
		else {

			cout << "| Invalid Bill                         |" << endl;
		}
		// Then in both cases (valid or invalid), it will print:
		cout << "+--------------------------------------+" << endl;
	}

	//--------------Public Member functions to----------------------
	// set the Bill to an empty state if any of the arguments are invalid
	void Bill::init(const char* title, int noOfItems) {

		int i;

		if (title == nullptr || noOfItems <= 0) {

			setEmpty();
			return;
		}

		// If arguments are valid, initialize the Bill object
		m_noOfItems = noOfItems;
		m_itemsAdded = 0;

		// Copy the title into m_title up to 36 characters
		strncpy(m_title, title, 36);
		m_title[36] = '\0';

		// Dynamically allocate an array of Items
		m_items = new Item[m_noOfItems];

		// Making sure all dynamically allocated Items are set to empty
		for (i = 0; i < m_noOfItems; ++i) { 

			m_items[i].setEmpty();
		}

	}

	// Add an item to the Bill
	bool Bill::add(const char* item_name, double price, bool taxed) {

		if (m_itemsAdded < m_noOfItems) {

			m_items[m_itemsAdded].set(item_name, price, taxed);
			++m_itemsAdded;

			return true;
		}
		else {

			return false; // return false if there is no space for a new item to ADD
		}
	}

	// Display the Bill
	void Bill::display() const {

		int i;

		// A very specific format of printing the values
		Title();
		for (i = 0; i < m_noOfItems; ++i) {

			m_items[i].display();
		}
		footer();
	}

	// Deallocate the m_items array
	void Bill::deallocate() {

		delete[] m_items;
		m_items = nullptr;
	}
}