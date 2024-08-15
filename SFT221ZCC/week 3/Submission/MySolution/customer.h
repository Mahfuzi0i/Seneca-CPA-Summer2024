#pragma once
#define _CRT_SECURE_NO_WARNINGS

#define MAX_CHAR 50

struct customer
{
	char firstName[MAX_CHAR];
	char lastName[MAX_CHAR];
	char address[MAX_CHAR];
	char city[MAX_CHAR];
	char province[MAX_CHAR];
	char postalCode[MAX_CHAR];
};


void enterData(struct customer* data);

int checkalpha(char string[]);

int checkCode(char* PostalCode);
