/* Citation and Sources...
Final Project Milestone 5
Module: LibApp.cpp
Filename: LibApp.cpp
Version 1.0
Author	Fardad Soleimanloo
Description build a mockup application for the Seneca Library Application in a module called LibApp.
Revision History
-----------------------------------------------------------
Date      Reason
2024/07/01  Preliminary release
2024/07/01  Debugged DMA
2024/07/30  Add more attributes and modifications to the module

Name           : Abdullah Al Mahfuz
Email          : aamahfuz@myseneca.ca
Student ID     : 180377236
Section        : ZFF
Date           : 30 July 2024 (Tuesday)
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "LibApp.h"
#include "Book.h"
#include "PublicationSelector.h"
using namespace std;

namespace sdds {
   
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

	// Additional modification to the function
	void LibApp::load() { 
		cout << "Loading Data" << endl;

		// MS5 addition
		// Open file for reading
		ifstream infile(m_filename);
		char type{};

		// Loop through each publication until it hits the maximum cpacity or ifstream reading fails
		for (int i = 0; infile && i < SENECA_LIBRARY_CAPACITY; i++) {

			infile >> type; // get the first character
			infile.ignore();
			if (infile) {

				if (type == 'P') {
					m_PPA[i] = new Publication;
				}
				else if (type == 'B') {
					m_PPA[i] = new Book;
				}
				if (m_PPA[i]) {
					infile >> *m_PPA[i];
					m_NOLP++;
				}
			}
		}
		// If the number of publication is greater than 0
		if (m_NOLP > 0) {
			// set the LLRN to the reference number of the last publication read.
			m_LLRN = m_PPA[m_NOLP - 1]->getRef();
		}
	}

	// MS5 updates
	void LibApp::save() {
		cout << "Saving Data" << endl;

		// MS5 updates
		//open the data file stream for overwriting. (ofstream)
		ofstream outfile(m_filename);

		// Go through the elements of PPA up to the N0LP. 
		for (int i=0; i < m_NOLP; i++) {
			// Insert all elements into the ofstream object except those with 0 (zero) as Library Reference Number.
			if (m_PPA[i]->getRef() != 0) {

				outfile << *m_PPA[i] << endl;
			}
		}
	}

	// MS5 updates
	int LibApp::search(int searchType) {
		//cout << "Searching for publication" << endl;
		// Get library reference number, set to -1 for abort status
		int libRefNum;
		int selection = m_publicationMenu.run();
		cin.ignore(1000, '\n');

		// The abort selection from the menu- user can abort at any stage
		if (selection == 0) {

			cout << "Aborted!" << endl;
			libRefNum = -1;
		}
		else {

			// get the title to search the PPA for. (up to 256 characters)
			char publicationTitle[256];
			cout << "Publication Title: ";
			cin.getline(publicationTitle, 256);

			// The page size for the selector menu should be 15 (the default value)
			PublicationSelector userSelection("Select one of the following found matches:");

			// Go through all publications in PPA
			for (int i = 0; i < m_NOLP; i++) {

				if (m_PPA[i]->getRef() != 0) {
					/* if type is equal to B or P based on user input of 1 or 2 using ternary operator
					&& if title contains the title user entered using overloaded == operator */
					if (m_PPA[i]->type() == (selection == 1 ? 'B' : 'P') && *m_PPA[i] == publicationTitle) {

						// If search input is 1- Search all
						if (searchType == 1) {
							userSelection << m_PPA[i];
						}
						// If search input is 2- Search Checkout Items Search only those publications which are on loan by library members
						else if (searchType == 2) {

							if (m_PPA[i]->onLoan()) {

								userSelection << m_PPA[i];
							}
						}
						// If search input is 3- Search Available Items Search only those publications which are not on loan
						else if (searchType == 3) {

							if (!m_PPA[i]->onLoan()) {

								userSelection << m_PPA[i];
							}
						}
					}
				}
			}
			// If matches are found sort the result, get the user's selection and return the library reference number
			if (userSelection == true) {

				userSelection.sort();
				int removalSelection = userSelection.run();

				// If user selected a row number
				if (removalSelection != 0) {

					// get address of publication object selected by user using library reference
					Publication* selectedPublication = getPub(removalSelection);
					// return library reference
					libRefNum = selectedPublication->getRef();
					selectedPublication->write(cout) << endl;
				}
				else {
					// Abort and set the library reference number to -1
					cout << "Aborted!" << endl << endl;
					libRefNum = -1;
				}
			}
			else {

				// Display the appropriate message and set the library reference number to -1
				cout << "No matches found!" << endl << endl;
				libRefNum = -1;
			}	
		}
		return libRefNum;
	}

	// MS5 addition
	void LibApp::returnPub() {
		
		cout << "Return publication to the library" << endl;
		int libRef = search(2); // Search for on loan publications only
		
		// Check if the search is not in a fail state
		if (libRef != -1) {

			// Call confirm function to confirm the returning publication
			if (confirm("Return Publication?") == true) {

				// Get the address of the object
				Publication* returnedPublication = getPub(libRef);
				// Use date constructor to get current date and subtract checkout from it
				int lateDays = Date() - returnedPublication->checkoutDate();
				double penalty = 0.00;
				// If the publication is more than 15 days on loan, a 50 cents per day penalty will be calculated for the number of days exceeding the 15 days.
				if (lateDays > 15) {

					int daysLate = lateDays - 15;
					penalty = (daysLate) * 0.50;
					// Display the fine in two decimal precisions
					cout << "Please pay $";
					cout.setf(ios::fixed);
					cout.precision(2);
					cout << penalty;
					cout.unsetf(ios::fixed);
					cout << " penalty for being " << daysLate << " days late!" << endl;
				}
				// set m_changed to true and set membership number to 0
				
				m_changed = true;
				returnedPublication->set(0);
				cout << "Publication returned" << endl << endl;
			}
		}	
	}

	// MS5 updates
	void LibApp::newPublication() {

		// If the NOLP is equal to the SENECA_LIBRARY_CAPACITY, print: "Library is at its maximum capacity!" and exit.
		if (m_NOLP == SENECA_LIBRARY_CAPACITY) {

			cout << "Library is at its maximum capacity!" << endl << endl;
		}
		else {

			cout << "Adding new publication to the library" << endl;
			// Run publication menu and get user input
			int selectionType = m_publicationMenu.run();

			// set the publication object to null ptr
			if (selectionType == 1 || selectionType == 2) {

				Publication* pub = nullptr;

				// If the selection is 1 then create new Book object
				if (selectionType == 1) {

					pub = new Book;
				}
				// Is the selection is 2, then create a new Publication object
				else if (selectionType == 2) {

					pub = new Publication;
				}
				cin.ignore(1000, '\n');

				// Read the instantiated object from cin object
				cin >> *pub;

				// If cin fails- flush the keyboard
				if (cin.fail()) {

					cin.clear();
					cin.ignore(1000, '\n');
					cout << "Aborted!" << endl << endl;
					// Delete the type
					delete pub;
				}
				else if (confirm("Add this publication to the library?")) {

					// increment the LLRN (Last Library Reference Number)
					m_LLRN++;
					// set Library reference number t0 value
					pub->setRef(m_LLRN);
					// Add the publication object's address to the end of the PPA and add one to the NOLP
					m_PPA[m_NOLP++] = pub;
					m_changed = true;
					cout << "Publication added" << endl << endl;
				}
				else {

					cout << "Failed to add publication!" << endl;
					delete pub;
				}
			}
			else {
				cout << "Aborted!" << endl << endl;
			}
		}
	}

	// MS5 additions
	void LibApp::removePublication() {
		cout << "Removing publication from the library" << endl;
		
		// Search all publication using the select all (1) from the selection menu
		int libRef = search(1);

		if (libRef != -1) {

			if (confirm("Remove this publication from the library?") == true) {

				Publication* selectedPublication = getPub(libRef);
				selectedPublication->setRef(0); // Set the library reference of the selected publication to 0 (zero)
				m_changed = true;
				cout << "Publication removed" << endl << endl;
			}
		}	
	}

	// MS5 Updates
	void LibApp::checkOutPub() {

		cout << "Checkout publication from the library" << endl;

		// Search in available publications only
		int libRef = search(3);
		
		if (libRef != -1) {

			if (confirm("Check out publication?") == true) {

				m_changed = true;
				int memberID;
				cout << "Enter Membership number: ";
				do {

					cin >> memberID;

					// read a 5 - digit number from the console, if invalid print message and ask for input again
					if (cin.fail() || memberID < 10000 || memberID > 99999) {

						cout << "Invalid membership number, try again: ";
						cin.clear();
						cin.ignore(1000, '\n');
					}
				} while (cin.fail() || memberID < 10000 || memberID > 99999);

				// Get the address of the publication
				Publication* selectedPublication = getPub(libRef);
				// Set member ship ID of that object to the membership id entered
				selectedPublication->set(memberID);

				cout << "Publication checked out" << endl << endl;
			}
		}	
	}

	// MS5 update add new attributes to constructor and change from no argument constructor to one argument constructor
	// initalize mainMenu and exitMenu  and publicationMenu during construction using constructor initialization
	LibApp::LibApp(const char* filename) : m_changed(false), m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?"), m_NOLP(0), m_LLRN(0), m_publicationMenu("Choose the type of publication:") {

		strncpy(m_filename, filename, 255);
		m_filename[strlen(filename)] = '\0'; // Ensuring null termination
		
		// Populate the m_mainMenu with the following menu items
		m_mainMenu << "Add New Publication";
		m_mainMenu << "Remove Publication";
		m_mainMenu << "Checkout publication from library";
		m_mainMenu << "Return publication to library";

		// Populate the m_exit Menu with the following menu items
		m_exitMenu << "Save changes and exit";
		m_exitMenu << "Cancel and go back to the main menu";

		// Add the publication menu using the overloaded operator <<
		m_publicationMenu << "Book";
		m_publicationMenu << "Publication";
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
				if (confirm("This will discard all the changes are you sure?") == true) {
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

	// Milestone 5 additions
	// to return the address of a Publication object in the PPA that has the library reference number matching the "libRef" argument.
	Publication* LibApp::getPub(int libRef) {

		Publication* foundPublication = nullptr;
		for (int i = 0; i < m_NOLP; i++) {

			if (m_PPA[i]->getRef() == libRef) {

				foundPublication = m_PPA[i];
			}
		}
		return foundPublication;
	}

	// MS5 addition- the destructor
	LibApp::~LibApp() {

		// Delete the dynamically allocated memory for the publications objects
		for (int i = 0; i < m_NOLP; i++) {

			delete m_PPA[i];
		}
	}
}
