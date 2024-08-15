#define _CRT_SECURE_NO_WARNINGS
#include "stringhelp.h"
#include "assert.h"
#include "log4c.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>

struct Log4cStruct generalLog;
struct Log4cStruct errorLog;

int nextWhite(const char* str)
{
    assert(str != NULL); // assert that str is not null 

    int i, result = -1;
    for (i = 0; result < 0 && str[i] != '\0'; i++)
    {
        if (isspace((unsigned char)str[i]))
        {
            result = i;
        }
    }
    return (result < 0) ? i : result;
}

int isNumber(const char* str, const int len)
{
    assert(str != NULL); 
    assert(len >= 0); // Asserting that len is a non-negative integer

    int i, result = 1;
    for (i = 0; i < len && result; i++)
    {
        result = result && isdigit((unsigned char)str[i]);
    }
    return result;
}

struct StringIndex indexString(const char* str)
{

    assert(str != NULL); 
    // Show what the execution started with
    l4cPrintf(&generalLog, L4C_INFO, "Entered indexString function with input: \n%s\n", str);

    struct StringIndex result = { {0}, {0}, {0}, 0, 0, 0 };
    int i = 0, sp;

    assert(strlen(str) < MAX_INDEX_SIZE); // Ensure the string length doesn't exceed the maximum allowed size
    strcpy(result.str, str);

    if (str[0] != '\0') {
        result.lineStarts[0] = 0;
        result.numLines = 1;
    }

    while (str[i] != '\0') {
        // Skip leading whitespace
        while (str[i] != '\0' && isspace((unsigned char)str[i])) {
            if (str[i] == '\n') {
                assert(result.numLines < MAX_INDEX_SIZE);
                if (result.numLines < MAX_INDEX_SIZE) {
                    result.lineStarts[result.numLines++] = i + 1;
                }
            }
            i++;
        }

        if (str[i] == '\0') break;

        sp = nextWhite(str + i);

        if (isNumber(str + i, sp)) {
            assert(result.numLines < MAX_INDEX_SIZE);
            if (result.numNumbers < MAX_INDEX_SIZE) {
                result.numberStarts[result.numNumbers++] = i;
            }
        }
        else {
            assert(result.numLines < MAX_INDEX_SIZE); // make sure no overflow is caused
            if (result.numWords < MAX_INDEX_SIZE) {
                result.wordStarts[result.numWords++] = i;
            }
        }

        i += sp;
    }

    return result;
}

int getNumberLines(const struct StringIndex* idx)
{
    assert(idx != NULL); 
    // the number line that got called
    l4cPrintf(&generalLog, L4C_INFO, "Called getNumberLines function");
    return idx->numLines;
}

int getNumberWords(const struct StringIndex* idx)
{
    assert(idx != NULL);
    // the number words got called
    l4cPrintf(&generalLog, L4C_INFO, "Called getNumberWords function");
    return idx->numWords;
}

int getNumberNumbers(const struct StringIndex* idx)
{
    assert(idx != NULL);
    l4cPrintf(&generalLog, L4C_INFO, "Called getNumberNumbers function");
    return idx->numNumbers;
}

void getWord(char word[], const struct StringIndex* idx, int wordNum)
{
    int i, sp, start;
    word[0] = '\0';

    assert(idx != NULL);
    assert(word != NULL);
    assert(wordNum >= 0 && wordNum < idx->numWords); // Validation for numWord 

    l4cPrintf(&generalLog, L4C_INFO, "Called getWord function for wordnum - %d", wordNum); // show in the log file that this function has been called

    if (wordNum < idx->numWords && wordNum >= 0)
    {
        start = idx->wordStarts[wordNum];
        sp = nextWhite(idx->str + start);
        for (i = 0; i < sp; i++)
        {
            word[i] = idx->str[start + i];
        }
        word[i] = '\0'; // Ensure null-termination
    }
}

void getNumber(char word[], const struct StringIndex* idx, int numberNum)
{
    int i, sp, start;
    word[0] = '\0';

    assert(idx != NULL);
    assert(word != NULL);
    assert(numberNum < idx->numNumbers && numberNum >= 0); // Validation for getNumber 

    l4cPrintf(&generalLog, L4C_INFO, "Called getNumber function for numbers - %d", numberNum);

    if (numberNum < idx->numNumbers && numberNum >= 0)
    {
        start = idx->numberStarts[numberNum];
        sp = nextWhite(idx->str + start);
        for (i = 0; i < sp; i++)
        {
            word[i] = idx->str[start + i];
        }
        word[i] = '\0'; // Ensure null-termination
    }
}

char* getLine(struct StringIndex* idx, int lineNum)
{
    assert(idx != NULL);
    assert(lineNum != NULL);
    assert(lineNum >= 0 && lineNum < idx->numLines);

    l4cPrintf(&generalLog, L4C_INFO, "Called getLine function for lineNum %d", lineNum);

    char* result = NULL;
    if (lineNum < idx->numLines && lineNum >= 0)
    {
        result = idx->str + idx->lineStarts[lineNum];
    }
    return result;
}

void printUntil(const char* s, const int start, const char terminator)
{
    assert(s != NULL);
    l4cPrintf(&generalLog, L4C_INFO, "Called printUntil function");
    
    int i;
    for (i = start; s[i] != '\0' && s[i] != terminator; i++)
        printf("%c", s[i]);
}

void printUntilSpace(const char* s, const int start)
{
    assert(s != NULL);
    l4cPrintf(&generalLog, L4C_INFO, "Called printfUntilSpace function");

    int i;
    for (i = start; s[i] != '\0' && !isspace((unsigned char)s[i]); i++)
        printf("%c", s[i]);
}
