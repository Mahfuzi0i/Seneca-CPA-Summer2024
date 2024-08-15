#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "assert.h""
#include "stringhelp.h"
#include "log4c.h"
#include <string.h>
#include <ctype.h>


//int main(void) {
//
//	struct Log4cStruct apiLog = l4cOpen("APIlog.txt", 1);
//	struct Log4cStruct inputLog = l4cOpen("inputtext.txt", 1);
//	struct Log4cStruct errorLog = l4cOpen("errortext.txt", 1);
//
//	int a = 2;  // assert will make sure a matches to the value, if someone alters it the code will break
//	assert(a == 1); 
//
//	l4cError(&errorLog, "Error in line 50");
//	l4cPrintf(&inputLog, L4C_INFO, "Input value 2");
//	return 0;
//}


int main(void)
{
    struct Log4cStruct generalLog = l4cOpen("inputtext.txt", 1);
    char testStr[] = { "This is the 3453 final test \n with    multiple @@@ 3454 values with MIxxed types 12444 an\n multiple line     s and hoard of 12343 ((&*( special chracters. FINALLY !! \n It works 45433 just 5545 fine."};
    struct StringIndex index = indexString(testStr);
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
    printf("\nWORDS\n");
    for (i = 0; i < index.numWords; i++)
    {
        printUntilSpace(index.str, index.wordStarts[i]);
        printf("\n");
    }
    printf("\nNUMBERS\n");
    for (i = 0; i < index.numNumbers; i++)
    {
        printUntilSpace(index.str, index.numberStarts[i]);
        printf("\n");
    }
    return 0;
}
