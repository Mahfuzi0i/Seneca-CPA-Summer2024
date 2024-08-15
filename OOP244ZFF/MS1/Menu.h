/* Citation and Sources...
Final Project Milestone 1
Module: Menu.cpp
Filename: Menu.cpp
Version 1.0
Author	Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date      Reason
2024/06/30  Preliminary release
2024/06/30  Debugged DMA

Name           : Abdullah Al Mahfuz
Email          : aamahfuz@myseneca.ca
Student ID     : 180377236
Section        : ZFF
Date           : 11 July 2024 (Friday)
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#ifndef SENECA_MENU_H
#define SENECA_MENU_H
#include <iostream>
using namespace std;

namespace seneca {

	const unsigned int MAX_MENU_ITEMS = 20;
	class Menu; // forward declaration of the Menu class 
	// The MenuItem class
	class MenuItem {

		char* m_content;
		
		MenuItem(const char* content = nullptr); // The private constructor

		// The rule of three
		MenuItem(const MenuItem& other) = delete; // No Copy constructor
		MenuItem& operator = (const MenuItem& other) = delete; // No copy assignment
		~MenuItem(); // the Destructor;

		explicit operator bool() const; // Bool conversion
		operator const char* () const; // Conversion to const char*

		void display(ostream& os) const; // Display content

		friend class Menu; // Friend declaration for Menu class
	};

	// The Menu class
	class Menu {

		MenuItem* m_title;
		MenuItem* m_menuItems[MAX_MENU_ITEMS];
		unsigned int m_numItems;

		// Rule of three
		Menu(const Menu& other) = delete;
		Menu& operator = (const Menu& other) = delete;

		// Display title
		void displayTitle(ostream& os, bool showColon = true) const;
		// Display Menu Items
		void displayMenuItems(ostream& os) const;

	public:
		Menu();
		Menu(const char* title);
		~Menu(); // The Destructor

		Menu& operator<<(const char* menuItemContent); // Insertion operator overload
		void display(ostream& os) const; // Display the entire menu
		unsigned int run() const; // Run menu and get user selection
		unsigned int operator~() const; // overload operator ~ to act like run

		explicit operator bool() const; // bool convertion
		operator unsigned int() const;
		const char* operator[](unsigned int index) const; // Indexing operator overload

		ostream& write(ostream& os) const;
		friend ostream& operator<<(ostream& os, const Menu& menu);
		
	};
	
}
#endif


