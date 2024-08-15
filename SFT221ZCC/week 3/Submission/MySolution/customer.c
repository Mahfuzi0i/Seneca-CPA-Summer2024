#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "customer.h"

// The user input function
void enterData(struct customer* data)
{
	int check = 0;
	int i;

	// Prompt for first name until proper input is given
	do
	{
		printf("Enter your first Name: ");
		fgets(data->firstName, MAX_CHAR - 1, stdin);

		if (data->firstName[0] == "\n" || data->firstName == '\n' || !checkalpha(data->firstName)) // Deal with no inputs
		{
			printf("Invalid Entry: ");
		}
		else
		{
			for (i = 0; data->firstName[i] != '\0'; i++) // until the null terminal has been reached
			{
				check++;
			}
			data->firstName[check - 1] = '\0'; // added null terminal to make it a string again
		}
	} while (!check);

	// Prompt for last name until proper input is given
	check = 0;
	do
	{
		printf("Enter Your Last Name: ");
		fgets(data->lastName, MAX_CHAR - 1, stdin);

		if (data->lastName == "\n" || data->lastName == '\n' || !checkalpha(data->lastName))
		{
			printf("Invalid Entry: ");
		}
		else
		{
			for (i = 0; data->lastName[i] != '0'; i++)
			{
				check++;
			}
			data->lastName[check - 1] = '\0';
		}
	} while (!check);

	// Prompt for street address until proper input is given
	check = 0;
	do
	{
		printf("Enter Your Street Address: ");
		fgets(data->address, MAX_CHAR - 1, stdin);

		if (data->address[0] == '\n' || data->address[0] == ' ')
		{
			printf("Invalid Entry: ");
		}
		else
		{
			for (i = 0; data->address[i] != '\0'; i++)
			{
				check++;
			}
			data->address[check - 1] = '\0';
		}
	} while (!check);

	// Prompt to enter city until valid input is given
	check = 0;
	do
	{
		printf("Enter Your City: ");
		fgets(data->city, MAX_CHAR - 1, stdin);

		if (data->city[0] == '\n' || data->city[0] == ' ' || !checkalpha(data->city))
		{
			printf("Invalid Entry: ");
		}
		else
		{
			for (i = 0; data->city[i] != '\0'; i++)
			{
				check++;
			}
			data->city[check - 1] = '\0';
		}
	} while (!check);

	// Prompt to enter province until valid input is given
	check = 0;
	do
	{
		printf("Enter Your Province: ");
		fgets(data->province, MAX_CHAR - 1, stdin);
 
		if (data->province[0] == '\n' || data->province[0] == ' ' || !checkalpha(data->city))
		{
			printf("Invalid Entry: ");
		}
		else
		{
			for (i = 0; data->province[i] != '\0'; i++)
			{
				check++;
			}
			data->province[check - 1] = '\0';
		}
	} while (!check);

	// Prompt for proper Postal Code entry
	check = 0;
	do
	{
		printf("Enter Your postal code: ");
		fgets(data->postalCode, MAX_CHAR - 1, stdin);

		for (int i = 0; data->postalCode[i] != '\0'; i++)
		{
			data->postalCode[i] = toupper(data->postalCode[i]);
		}

		if (data->postalCode[0] == '\n' || data->postalCode[0] == ' ' || !checkCode(data->postalCode))
		{
			printf("Invalid Entry: ");
		}
		else
		{
			check = 1;
		}
	} while (!check);
}

// The check alpha function
int checkalpha(char string[])
{
	int check = 0;
	int i;

	for (i = 0; string[i] != '\0'; i++)
	{
		if (isalpha(string[i]))
		{
			check = 1;
		}
	}
	return check;
}

// The postal code checker function
int checkCode(char* PostalCode)
{
	int length = 0;
	int i;

	for (i = 0; PostalCode[i] != '\n'; i++)
	{
		length++;
	}

	if (length == 7)
	{
		// Validate the format of the postal code "i.e. {string}{digit}{string}{space}{digit}{string}{digit}"
		if (isalpha(PostalCode[0]) && isdigit(PostalCode[1]) && isalpha(PostalCode[2]) && PostalCode[3] == ' ' && isdigit(PostalCode[4]) && isalpha(PostalCode[5]) && isdigit(PostalCode[6]))
		{

			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if (length == 6) 
	{
		if (isalpha(PostalCode[0]) && isdigit(PostalCode[1]) && isalpha(PostalCode[2]) && isdigit(PostalCode[3]) && isalpha(PostalCode[4]) && isdigit(PostalCode[5]))
		{
			// Manually fixing the postal code with 6 inputs, for the user put the cose without spaces

			PostalCode[8] = '\0';
			PostalCode[7] = PostalCode[6];
			PostalCode[6] = PostalCode[5];
			PostalCode[5] = PostalCode[4];
			PostalCode[4] = PostalCode[3];
			PostalCode[3] = ' ';

			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if (length > 7)
	{
		// postal code with multiple whitespaces
		if (isalpha(PostalCode[0]) && isdigit(PostalCode[1]) && isalpha(PostalCode[2]) && PostalCode[3] == ' ' && PostalCode[4] == ' ')
		{
			while (!(isalpha(PostalCode[0]) && isdigit(PostalCode[1]) && isalpha(PostalCode[2]) && PostalCode[3] == ' ' && isdigit(PostalCode[4]) && isalpha(PostalCode[5]) && isdigit(PostalCode[6])))
			{
				for (i = 0; PostalCode[i] != '\n'; i++)
				{

					if (PostalCode[i] != ' ' && i > 3)
					{
						PostalCode[i - 1] = PostalCode[i];
						PostalCode[i] = PostalCode[i + 1];

					}
				}
			}

			PostalCode[8] = '\0';

			return 1;

		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}

}

// The main function!
int main(void)
{
	struct customer Customer;

	enterData(&Customer);

	printf("\n");
	printf("You information\n");
	printf("---------------\n");
	printf("Full Name   : %s %s", Customer.firstName, Customer.lastName);
	printf("Full Address: %s,\n", Customer.address);
	printf("              %s, %s,\n", Customer.city, Customer.province);
	printf("              %s\n", Customer.postalCode);

	return 0;
}