/*
--------------------------------------------------------------------
Name           : Abdullah Al Mahfuz
Email          : aamahfuz@myseneca.ca
Student ID     : 180377236
Section        : ZFF
Date           : 30 June 2024 (Sunday)

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
--------------------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "TextFile.h"

using namespace std;

namespace seneca {
	Line::operator const char* () const {
		return (const char*)m_value;
	}
	Line& Line::operator=(const char* lineValue) {
		delete[] m_value;
		m_value = new char[strlen(lineValue) + 1];
		strcpy(m_value, lineValue);
		return *this;
	}
	Line::~Line() {
		delete[] m_value;
	}

	void TextFile::setEmpty() {
		// delete dynamic array of textLines and set to null ptr
		delete[] m_textLines;
		m_textLines = nullptr;

		// delete dynamic array of textLines and set to null ptr
		delete[] m_filename;
		m_filename = nullptr;

		// set number of lines to 0
		m_noOfLines = 0;
	}

	void TextFile::setFilename(const char* fname, bool isCopy) {
		char prefix[3] = "C_";

		if (isCopy == false) {

			delete[] m_filename;
			m_filename = new char[strlen(fname) + 1];
			strcpy(m_filename, fname);
		}

		if (isCopy == true) {

			delete[] m_filename;
			m_filename = new char[strlen(fname) + 3]; //Add space for string and null terminator
			strcpy(m_filename, prefix);
			strcat(m_filename, fname);
		}
	}

	void TextFile::setNoOfLines() {

		ifstream file(m_filename);

		char ch;
		m_noOfLines = 0;

		// read file character by character and increase noOfLines when new line characte reached
		while (file.get(ch)) {

			if (ch == '\n') {

				m_noOfLines++;
			}
		}
	
		if (m_noOfLines == 0) {

			delete[] m_filename;
			m_filename = nullptr;
		}
		else {
			// add one to new line just in case the lalst line does not have a new line character
			m_noOfLines++;
		}

	}


	void TextFile::loadText() { 

		// if m_file name is null do nothing
		if (m_filename == nullptr) {

		}

		// if m_filename is not null 
		if (m_filename != nullptr) {

			// prevent memory leak delete textLine
			delete[] m_textLines;
			m_textLines = new Line[m_noOfLines];

			ifstream file(m_filename);  // create local instande of ifstream

			// define the string object to accept the input
			string line;
			unsigned i = 0;
			// extrct the input using getline helper function
			while (getline(file, line)) {
				// use line.c_str() to assign a c-style string
				m_textLines[i] = line.c_str();
				i++;
			}
			m_noOfLines = i;	    
		}
	}

	void TextFile::saveAs(const char* fileName)const {

		ofstream file(fileName);
		unsigned i;

		if (file) {
			for (i = 0; i < m_noOfLines; i++) {
				file << m_textLines[i] << endl;
			}
		}
	}

	TextFile::TextFile(unsigned pageSize) {
		// create empty TextFile and initialize m_pageSize to incoming argument
		m_filename = nullptr;
		m_textLines = nullptr;
		m_noOfLines = 0;
		m_pageSize = pageSize;
	}

	TextFile::TextFile(const char* filename, unsigned pageSize) {
		// create empty TextFile and initialize m_pageSize to incoming argument
		m_filename = nullptr;
		m_textLines = nullptr;
		m_noOfLines = 0;
		m_pageSize = pageSize;

		// if filename not null ptr set the filename, number of lines, and load text
		if (filename != nullptr) {
			setFilename(filename);
			setNoOfLines();
			loadText();
		}
	}

	// copy constructor
	TextFile::TextFile(const TextFile& text) {
		m_filename = nullptr;
		m_textLines = nullptr;
		m_noOfLines = 0;
		m_pageSize = text.m_pageSize;
	
		if (text.m_filename != nullptr) {
			setFilename(text.m_filename, true);
			text.saveAs(m_filename);
			setNoOfLines();
			loadText();
		}
	}

	TextFile& TextFile:: operator=(const TextFile& text) {
		// check for self assignment
		if (this != &text) {

			// deallocate previously allocated memory
			delete[] m_textLines;
			m_textLines = nullptr;

			// check of the current and incoming TextFiles are valid
			if (text.m_filename != nullptr && m_filename != nullptr) {
				//setFilename(text.m_filename, true);
				text.saveAs(m_filename);
				setNoOfLines();
				loadText();
			}
		}

		return *this;
	}

	TextFile:: ~TextFile() {  // The Destructor
		delete[] m_filename;
		delete[] m_textLines;
	}

	unsigned TextFile::lines()const {
		return m_noOfLines;
	}

	ostream& TextFile::view(ostream& ostr)const {
		char symbol = '=';
		unsigned checkLines = 0;
		unsigned i;

		if (m_filename != nullptr && m_textLines != nullptr) {
			ostr << m_filename << endl;
	
			unsigned filenameLength = strlen(m_filename);
			for ( i = 0; i < filenameLength; i++) {
				ostr << symbol;
			}

			ostr << endl;

			for ( i = 0; i < m_noOfLines; i++) {
				ostr << m_textLines[i] << endl;
				checkLines++;

				if (checkLines == m_pageSize) {
					ostr << "Hit ENTER to continue...";
					cin.ignore(1000, '\n');
					checkLines = 0;
				}
			}
		}
		return ostr;
	}

	istream& TextFile::getFile(istream& istr) {
		// read file name 
		string file;
		istr >> file;
		istr.ignore(10000, '\n');

		setFilename(file.c_str());
		setNoOfLines();
		loadText();
		return istr;
	}

	const char* TextFile::operator[](unsigned index)const {

		if (m_textLines != nullptr && m_noOfLines != 0) {
			index %= m_noOfLines;
			return m_textLines[index];
		}
		else {
			return nullptr;
		}
	}

	TextFile::operator bool()const {
		bool temp;

		if (m_filename != nullptr && m_textLines != nullptr) {
			temp = true;
		}
		else {
			temp = false;
		}

		return temp;
	}

	const char* TextFile::name()const {
		return m_filename;
	}

	ostream& operator<<(ostream& ostr, const TextFile& text) {
		return text.view(ostr);
	}

	istream& operator>>(istream& istr, TextFile& text) {
		return text.getFile(istr);
	}
}