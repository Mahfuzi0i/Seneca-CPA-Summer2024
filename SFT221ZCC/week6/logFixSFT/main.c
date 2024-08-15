#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "assert.h"
#include "stringhelp.h"
#include "log4c.h"
#include <string.h>
#include <ctype.h>

struct Log4cStruct generalLog;
struct Log4cStruct errorLog;

int main(void)
{	
	// Create and open log files for 
	generalLog = l4cOpen("GeneralLog.txt", 1);
	errorLog = l4cOpen("Error.txt", 1);

	// Log for entering the main function
	l4cPrintf(&generalLog, L4C_INFO, "Entered the main function.");
	
	char testStr[]={ "the \nlast 66655 normal case for \n 888 the code *** 12345 \nand "};
	l4cPrintf(&generalLog, L4C_INFO, "The Input test String-- \n%s\n",testStr); // printing the line in the log file
	// Assert the test string for proper initialization
	// The code will constinue as long as there is a string in the testStr array
	// If it is not (i.e. NULL) the program will stop execution
	assert(testStr != NULL);
	if (testStr == NULL) {  // Log the report into the error.txt
		l4cError(&errorLog, "assertion failed, testStr != NULL");
	}
	
	struct StringIndex index = indexString(testStr);
	// Assert the index function for proper execution
	assert(index.numLines >= 0);
	if (index.numLines < 0) {
		l4cError(&errorLog, "Assertion failed : index.numLines >= 0");
	}
	assert(index.numWords >= 0);
	if (index.numWords < 0) {
		l4cError(&errorLog, "Assertion failed : index.numWords >= 0");
	}
	assert(index.numNumbers >= 0);
	if (index.numNumbers < 0) {
		l4cError(&errorLog, "Assertion failed : index.numNumbers >= 0");
	}

	// Log the number of lines, words, and numbers found
	l4cPrintf(&generalLog, L4C_INFO, "Number of Lines found: %d", index.numLines);
	l4cPrintf(&generalLog, L4C_INFO, "Number of words found: %d", index.numWords);
	l4cPrintf(&generalLog, L4C_INFO, "Number of numbers found: %d", index.numNumbers);
	
	int i;

	printf("LINES\n");
	for (i = 0; i < index.numLines; i++)
	{
		printUntil(index.str, index.lineStarts[i], '\n');
		printf("\n");
	}

	// Printing as stdout on the screen
	printf("\nWORDS\n");
	for (i = 0; i < index.numWords; i++)
	{
		printUntilSpace(index.str, index.wordStarts[i]);
		printf("\n");
	}

	// Printing the words in the log file
	l4cPrintf(&generalLog, L4C_INFO, "\nWORDS by index\n");
	for (i = 0; i < index.numWords; i++)
	{
		char word[MAX_WORD_SIZE + 1];
		getWord(word, &index, i);
		l4cPrintf(&generalLog, L4C_INFO, "Printing word %d - %s", i, word);
	}

	// Printing numbers in std screen
	printf("\nNUMBERS\n");
	for (i = 0; i < index.numNumbers; i++)
	{
		printUntilSpace(index.str, index.numberStarts[i]);
		printf("\n");
	}

	// Printing the numbers in the log file
	l4cPrintf(&generalLog, L4C_INFO, "\nNUMBERS by index\n");
	for (int i = 0; i < index.numNumbers; i++)
	{
		char number[MAX_WORD_SIZE + 1];
		getNumber(number, &index, i);
		l4cPrintf(&generalLog, L4C_INFO, "Printing number %d - %s", i, number);
	}

	l4cPrintf(&generalLog, L4C_INFO, "Exited the Main function\n\n");

	l4cClose(&generalLog); // close the file after we are done writing to it.
	l4cClose(&errorLog);
	
	return 0;
	
}