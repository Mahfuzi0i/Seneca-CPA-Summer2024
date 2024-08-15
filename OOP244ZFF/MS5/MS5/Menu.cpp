/* Citation and Sources...
Final Project Milestone 5
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
Date           : 11 July 2024 (Thursday)
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Menu.h"

using namespace std;
namespace seneca {

    // MenuItem Implementation

    MenuItem::MenuItem(const char* content) {
        if (content) {
            m_content = new char[strlen(content) + 1];
            strcpy(m_content, content);
        }
        else {
            m_content = nullptr;
        }
    }

    MenuItem::~MenuItem() { // The Destructor
        delete[] m_content;
    }

    MenuItem::operator bool() const {
        return m_content != nullptr;
    }

    MenuItem::operator const char* () const {
        return m_content;
    }

    void MenuItem::display(ostream& os) const {
        if (m_content) {
            os << m_content;
        }
    }

    // Menu Implementation

    Menu::Menu() : m_title(nullptr), m_numItems(0) {
        for (unsigned int i = 0; i < MAX_MENU_ITEMS; ++i) {
            m_menuItems[i] = nullptr;
        }
    }

    Menu::Menu(const char* title) : m_title(nullptr), m_numItems(0) {
        if (title) {
            m_title = new MenuItem(title);
        }
        else {
            m_title = nullptr;
        }
        for (unsigned int i = 0; i < MAX_MENU_ITEMS; ++i) {
            m_menuItems[i] = nullptr;
        }
    }

    Menu::~Menu() {
        delete m_title;
        unsigned int i;

        for (i = 0; i < m_numItems; ++i) {
            delete m_menuItems[i];
        }
    }

    Menu& Menu::operator<<(const char* menuItemContent) {
        if (m_numItems < MAX_MENU_ITEMS) {
            m_menuItems[m_numItems] = new MenuItem(menuItemContent);
            m_numItems++;
        }
        return *this;
    }

    void Menu::displayTitle(ostream& os) const {
        if (m_title && *m_title) {
            os << static_cast<const char*>(*m_title);
            
        }
    }

    void Menu::displayMenuItems(ostream& os) const {
        cout << endl;
        if (m_numItems > 0) {
            unsigned int i;

            for (i = 0; i < m_numItems; ++i) {
                os << setw(2) << (i + 1) << "- ";
                m_menuItems[i]->display(os);
                os << endl;
            }
        }
        os << " 0- Exit" << endl << "> ";
    }

    void Menu::display(ostream& os) const {
        displayTitle(os); // Display title with colon
        displayMenuItems(os);
    }

    unsigned int Menu::run() const {
        unsigned int choice;
        display(cout);
        while (true) {
            cin >> choice;
            if (cin.fail() || choice > m_numItems) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid Selection, try again: ";
            }
            else {
                break;
            }
        }
        return choice;
    }

    unsigned int Menu::operator~() const {
        return run();
    }

    Menu::operator bool() const {
        return m_numItems > 0;
    }

    Menu::operator unsigned int() const {
        return m_numItems;
    }

    const char* Menu::operator[](unsigned int index) const {
        if (m_numItems == 0) {
            return nullptr;
        }
        return static_cast<const char*>(*m_menuItems[index % m_numItems]);
    }

    ostream& operator<<(ostream& os, const Menu& menu) {
        menu.displayTitle(os); // Display title without colon
        return os;
    }
}
