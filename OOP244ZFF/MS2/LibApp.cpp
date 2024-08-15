/* Citation and Sources...
Final Project Milestone 2
Module: LibApp.cpp
Filename: LibApp.cpp
Version 1.0
Author	Abdullah Al Mahfuz
Description build a mockup application for the Seneca Library Application in a module called LibApp.
Revision History
-----------------------------------------------------------
Date      Reason
2024/07/01  Preliminary release
2024/07/01  Debugged DMA

Name           : Abdullah Al Mahfuz
Email          : aamahfuz@myseneca.ca
Student ID     : 180377236
Section        : ZFF
Date           : 11 July 2024 (Thursday)
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "LibApp.h"
using namespace std;

namespace seneca {
   
	bool LibApp::confirm(const char* message) {
		bool temp;

		Menu menu(message);
		menu << "Yes";

		// Finally, run the menu and return true if the run method of Menu returns 1 otherwise this function returns false.
		if (menu.run() == 1) {
			temp = true;
		}
		else {
			temp = false;
		}
		return temp;
	}

	void LibApp::load() {
		cout << "Loading Data" << endl;
	}

	void LibApp::save() {
		cout << "Saving Data" << endl;
	}

	void LibApp::search() {
		cout << "Searching for publication" << endl;
	}

	void LibApp::returnPub() {
		search();
		cout << "Returning publication" << endl;
		cout << "Publication returned" << endl << endl;
		m_changed = true;
	}

	void LibApp::newPublication() {
		cout << "Adding new publication to library" << endl;

		if (confirm("Add this publication to library?\n") == true) {
			m_changed = true;
			cout << "Publication added";
		}
		cout << endl;
	}

	void LibApp::removePublication() {
		cout << "Removing publication from library" << endl;
		search();

		if (confirm("Remove this publication from the library?\n") == true) {
			m_changed = true;
			cout << "Publication removed" << endl << endl;
		}
	}

	void LibApp::checkOutPub() {
		search();

		if (confirm("Check out publication?\n") == true) {
			m_changed = true;
			cout << "Publication checked out" << endl << endl;
		}
	}

	// The constructor (with default initialization values)
	LibApp::LibApp() : m_changed(false), m_mainMenu("Seneca Library Application\n"), m_exitMenu("Changes have been made to the data, what would you like to do?\n") {

		// Populate the m_mainMenu with the following menu items
		m_mainMenu << "Add New Publication";
		m_mainMenu << "Remove Publication";
		m_mainMenu << "Checkout publication from library";
		m_mainMenu << "Return publication to library";

		// Populate the m_exit Menu with the following menu items
		m_exitMenu << "Save changes and exit";
		m_exitMenu << "Cancel and go back to the main menu";

		// Calls the load method
		load();
	}

	// The main application driver method run
	void LibApp::run() {

		int selection;
		int selectionExit;
		bool terminatorMsg = false;

		do {
			// Display the main menu
			selection = m_mainMenu.run();

			if (selection == 1) {
				newPublication();
			}
			if (selection == 2) {
				removePublication();
			}
			if (selection == 3) {
				checkOutPub();
			}
			if (selection == 4) {
				returnPub();
			}
		} while (selection != 0);

		if (m_changed == true) {
			selectionExit = m_exitMenu.run();

			// if the user enters 1 in the exit screen, must call save
			if (selectionExit == 1) {
				save();
				terminatorMsg = true;
			}

			// if the user selects 2 in the exit screen, call run function
			else if (selectionExit == 2) {
				cout << endl;
				run();
			}

			else {
				if (confirm("This will discard all the changes are you sure?\n") == true) {
					terminatorMsg = true;
				}
				else {
					run(); // Other wise- the program goes back to mainmenu and execution resumes
				}
			}
		}
		else {
			terminatorMsg = true;
		}

		if (terminatorMsg == true) {
			cout << endl;
			cout << "-------------------------------------------" << endl;
			cout << "Thanks for using Seneca Library Application" << endl;
		}
	}
}
