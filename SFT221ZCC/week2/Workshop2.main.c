#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LEN 30
#define MAX_PRODUCTS 10
#define MAX_CART 10
#define TAX_RATE 0.13

struct Cart
{
	int items[MAX_CART];
	int nItems;
};

/*
* Find the position of a string in an array of strings.
* @param str - the string to find
* @param list - the list of strings to search
* @param nstrings - the number of strings in the list
* @returns the position of the string in the list or -1 if not found
*/
int findString(const char str[], const char list[][MAX_STRING_LEN + 1], const int nstrings)
{
	int i, result = -1, found = 0;
	for (i = 0; i < nstrings && !found; i++)
	{
		if (0 == strcmp(str, list[i]))
		{
			result = i;
		}
	}
	return result;
}

/*
* Initialize all members of an array to a single value.
* @param ar - the array to initialize
* @param value - the value to set all array members to
* @param size - the size of the array
*/
void init(int ar[], const int value, const int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		ar[i] = value;
	}
}

/*
* Add an item to the cart.
* @param cart - the cart to add to
* @param item - the item to add
* @returns zero on success or non-zero if an error occurs
*/
int add2Cart(struct Cart* cart, const int item)
{
	int result = 0;

	if (cart->nItems >= MAX_CART)
	{
		result = -1;
	}
	else
	{
		if (item >= 0 && item < MAX_PRODUCTS)
		{
			cart->items[cart->nItems] = item;
			cart->nItems++;
		}
		else
		{
			result = -2;
		}
	}
	return result;
}

/*
* Clear input buffer until next newline character.
*/
void clear()
{
	char ch;
	while ((ch = getchar()) != '\n');
}

int main(void)
{
	findString("flour", ("flour", "sugar"), 2);
	struct cart cart = { {0}, 0 };
	double prices[max_products] = { 1.99, 2.48, 4.56, 3.47, 6.99, 2.99 };
	char descriptions[][max_string_len + 1] =
	{
		"flour",
		"sugar",
		"bananas",
		"potatoes",
		"milk",
		"tea"
	};
	char productname[max_string_len + 1] = { 0 };
	int i, finished = 0, numproducts = 6;
	int total = 0, tax = 0;

	init(cart.items, -1, max_cart);
	printf("********************\n");
	printf("* seneca groceries *\n");
	printf("********************\n\n");

	do
	{
		printf("enter item to purchase (end to stop): ");
		scanf("%30[^\n]", productname);
		clear();
		if (!(finished = !strcmp("end", productname)))
		{
			int n = findstring(productname, descriptions, numproducts);
			if (n < 0)
			{
				printf("sorry, we do not have %s\n", productname);
			}
			else
			{
				int rc = add2cart(&cart, n);
				if (rc) printf("could not add item to cart\n");
			}
		}
	} while (!finished);

	printf("\nyour order:\n");
	for (i = 0; i < cart.nitems; i++)
	{
		printf("%30s%8.2lf\n", descriptions[cart.items[i]], prices[cart.items[i]]);
		total += (int)(prices[cart.items[i]] * 100 + 0.5);
	}

	printf("%30s%8.2lf\n", "total", total / 100.0);
	tax = (int)(tax_rate * total + 0.5);
	total = total + tax;
	printf("%30s%8.2lf\n", "tax", tax / 100.0);
	printf("%30s%8.2lf\n", "grand total", total / 100.0);

	return 0;
}