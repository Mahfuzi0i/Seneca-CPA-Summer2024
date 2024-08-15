/*
--------------------------------------------------------------------
Name           : Abdullah Al Mahfuz
Email          : aamahfuz@myseneca.ca
Student ID     : 180377236
Section        : ZFF
Date           : 21 May 2024 (Tuesday)

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
--------------------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#ifndef SENECA_FILE_H_
#define SENECA_FILE_H_
namespace seneca {

   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   // TODO: Declare read prototypes
   bool read(char* name);
   bool read(int& empNo);
   bool read(double& salary);
	
}
#endif // !SENECA_FILE_H_
