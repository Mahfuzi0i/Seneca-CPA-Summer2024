#include <stdio.h>
#include <string.h>

#define MAX_STRING_LEN 30
#define MAX_PRODUCTS 10
#define MAX_CART 10

struct Cart {
    int items[MAX_CART];
    int nItems;
};

int findString(const char str[], const char list[][MAX_STRING_LEN + 1], const int nstrings);
void init(int ar[], const int value, const int size);
int add2Cart(struct Cart* cart, const int item);
void clear();

// Helper function to compare arrays
int compareArrays(int arr1[], int arr2[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr1[i] != arr2[i]) {
            return 0;  // Arrays are not equal
        }
    }
    return 1;  // Arrays are equal
}

// Integration test combining add2Cart and findString
void testAdd2CartFindStringIntegration() {
    // Setup
    struct Cart cart;
    char descriptions[][MAX_STRING_LEN + 1] = {
        "flour", "sugar", "bananas", "potatoes", "milk", "tea"
    };
    int numProducts = 6;
    init(cart.items, -1, MAX_CART);
    cart.nItems = 0;

    // Execute
    // Find the position of "milk" in the descriptions
    int pos = findString("milk", descriptions, numProducts);
    // Add the found item to the cart
    int rc = add2Cart(&cart, pos);

    // Comparison
    int expectedItems[MAX_CART] = { 4, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
    if (rc == 0 && cart.nItems == 1 && compareArrays(cart.items, expectedItems, MAX_CART)) {
        printf("Integration test (add2Cart + findString): PASSED\n");
    }
    else {
        printf("Integration test (add2Cart + findString): FAILED\n");
    }
}

int main(void) {
    testAdd2CartFindStringIntegration();
    return 0;
}

// Function implementations
int findString(const char str[], const char list[][MAX_STRING_LEN + 1], const int nstrings) {
    int i, result = -1, found = 0;
    for (i = 0; i < nstrings && !found; i++) {
        if (0 == strcmp(str, list[i])) {
            result = i;
            found = 1;
        }
    }
    return result;
}

void init(int ar[], const int value, const int size) {
    int i;
    for (i = 0; i < size; i++) {
        ar[i] = value;
    }
}

int add2Cart(struct Cart* cart, const int item) {
    int result = 0;
    if (cart->nItems >= MAX_CART) {
        result = -1;
    }
    else {
        if (item >= 0 && item < MAX_PRODUCTS) {
            cart->items[cart->nItems] = item;
            cart->nItems++;
        }
        else {
            result = -2;
        }
    }
    return result;
}

void clear() {
    char ch;
    while ((ch = getchar()) != '\n');
}
