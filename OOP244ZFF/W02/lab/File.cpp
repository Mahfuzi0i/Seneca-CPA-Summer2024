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
#include <cstdio>
#include "File.h"

using namespace std;
namespace seneca {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }

    //TODO: read functions go here    
   // Function to read employee name
   bool read(char* name) {

       if (fscanf(fptr, "%[^\n]\n", name) == 1) {
           return true;
       }
       else {
           return false;
       }
   }

   // Function to read employee number
   bool read(int& empNo) {

       if (fscanf(fptr, "%d,", &empNo) == 1) {
           return true;
       } 
       else {
           return false;
       }
   }

   // Function to read employee salary
   bool read(double& salary) {

       if (fscanf(fptr, "%lf,", &salary) == 1) {
           return true;
       }
       else {
           return false;
       }
   }
   
}