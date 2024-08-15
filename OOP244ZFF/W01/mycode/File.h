/*
--------------------------------------------------------------------
Name           : Abdullah Al Mahfuz
Email          : aamahfuz@myseneca.ca
Student ID     : 180377236
Section        : ZFF
Date           : 11 May 2024 (Saturday)

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
--------------------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS

#ifndef NAMESPACE_FILE_H
#define NAMESPACE_FILE_H

#include "ShoppingRec.h"

namespace seneca {

	//The File function prototypes
	bool openFileForRead();
	bool openFileForOverwrite();
	void closeFile();
	bool freadShoppingRec(ShoppingRec* rec);
	void fwriteShoppintRec(const ShoppingRec* rec);
}
#endif
