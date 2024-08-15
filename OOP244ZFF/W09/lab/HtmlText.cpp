/*
--------------------------------------------------------------------
Name           : Abdullah Al Mahfuz
Email          : aamahfuz@myseneca.ca
Student ID     : 180377236
Section        : ZFF
Date           : 23 July 2024 (Tuesday)

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
--------------------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include "HtmlText.h"
#include <cstring>

using namespace std;
namespace seneca {

	// Invoke the constructor for text
	HtmlText::HtmlText(const char* filename, const char* title) : Text(filename) {

		m_title = nullptr;

		if (title != nullptr) {

			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
		}
	}

	// The rule of three implementation
	HtmlText::HtmlText(const HtmlText& otherHtml) : Text(otherHtml) {

		m_title = nullptr;

		if (otherHtml.m_title) {

			m_title = new char[strlen(otherHtml.m_title) + 1];
			strcpy(m_title, otherHtml.m_title);
		}
	}

	HtmlText& HtmlText::operator = (const HtmlText& otherHtml) {

		Text::operator=(otherHtml);

		if (this != &otherHtml) {

			delete[] m_title;
			
			if (otherHtml.m_title) {

				m_title = new char[strlen(otherHtml.m_title) + 1];
				strcpy(m_title, otherHtml.m_title);
			}
			else {
				m_title = nullptr;
			}
		}

		return *this;
	}

	HtmlText::~HtmlText() {

		delete[] m_title;
	}

	void HtmlText::write(ostream& os) const {

		// Set Multiple Spaces (MS) to false
		bool MS = false;

		os << "<html><head><title>";

		// if m_title is not null, insert the title, otherwise insert "No Title"
		if (m_title != nullptr) {

			os << m_title;
		}
		else {
			os << "No Title";
		}

		os << "</title></head>\n<body>\n";

		// if "</title>\n\n" is not null insert "<h1>" << m_title << "</h1>\n"
		if (m_title != nullptr) {

			os << "<h1>" << m_title << "</h1>\n";
		}

		int i = 0;
		// Loop through each character until the null terminator has been hit
		while ((*this)[i] != '\0') {

			const char& chr = (*this)[i];

			// check if each character meets the sepecific requirements
			if (chr == ' ') {
				if (MS == true) {
					os << "&nbsp;";
				}
				else {
					MS = true;
					os << (' ');
				}
			}

			else if (chr == '<') {

				os << "&lt;";
				MS = false;
			}

			else if (chr == '>') {

				os << "&gt;";
				MS = false;
			}

			else if (chr == '\n') {

				os << "<br />\n";
				MS = false;
			}

			else {

				os << chr;
				MS = false;
			}

			++i; // Don't forget! #1 semantic error with while loop
		}

		os << "</body>\n</html>";
	}
}