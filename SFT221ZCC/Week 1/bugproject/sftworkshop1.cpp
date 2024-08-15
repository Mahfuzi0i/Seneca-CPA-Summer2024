#include <stdio.h>
#include <string.h>

/**
* Determine if the string s starts with the string prefix.
* @param s - the string to see if it starts with prefix
* @param prefix - the prefix to test
* @returns 1 if the string begins with the prefix, 0 otherwise.
*/
int startsWith(const char s[], const char prefix[])
{
    size_t s_len = strlen(s);
    size_t prefix_len = strlen(prefix);

    // Check if prefix is longer than s
    if (prefix_len > s_len) {
        printf("Error: Prefix length exceeds the length of the string.\n");
        return 0;  // Return 0 indicating error
    }

    // Compare the first prefix_len characters of s with prefix
    return strncmp(s, prefix, prefix_len) == 0;
}

/**
* Determine if the string s ends with the string suffix.
* @param s - the string to see if it ends with suffix
* @param suffix - the suffix to test
* @returns 1 if the string ends with the suffix, 0 otherwise.
*/
int endsWith(const char s[], const char suffix[])
{
    size_t sz = strlen(suffix);
    size_t slen = strlen(s);

    // Check if suffix is longer than s
    if (sz > slen) {
        printf("Error: Suffix length exceeds the length of the string.\n");
        return 0;  // Suffix cannot be longer than s
    }

    // Compare the last sz characters of s with suffix
    return strncmp(s + (slen - sz), suffix, sz) == 0;
}

int main(void)
{
    char s1[] = "I don't suppose 10 in -eq to 1000000";
    char prefix[] = "10";
    char suffix[] = "I don't suppose 10 in -eq to 1000000000";

    // Check if s1 starts with prefix
    if (startsWith(s1, prefix)) {
        printf("%s starts with %s\n", s1, prefix);
    } else {
        printf("%s does not start with %s\n", s1, prefix);
    }

    // Check if s1 ends with suffix
    if (endsWith(s1, suffix)) {
        printf("%s ends with %s\n", s1, suffix);
    } else {
        printf("%s does not end with %s\n", s1, suffix);
    }

    return 0;
}
