
/**     Recreating String.h lol :p
 *      Task 25 in grprog.pdf
 *
 *      Program description:
 *          - Create different string manipulation functions
 *          - Make a main function that calls the others
 *          - Let user play around with it
 *
 *      @file Oppgave 25.c
 *      @date 09-Dec-23
 *
 *      @author Luna S.
 *      @alias LunaMellow
 */

// Includes
#include <stdio.h>
#include <ctype.h>      // toupper()

/// Const variables
#define STRLEN 25       ///< Max string length

// Declare functions
int mstrlen(const char s[]);
void mstrcpy(char s[], const char t[]);
void mstrcat(char s[], const char t[]);
int mstrcmp(const char s[], const char t[]);

/**
 *      Main Program starts here
 */
int main() {
    char ans[STRLEN];
    char ans2[STRLEN];
    char string[50];

    // Promt user to find length of string
    printf("\n~ Finn lengden av en streng ~");
    printf("\nSkriv en streng: ");
    scanf("%24s", &ans);
    printf("\nLengde på strengen: %d", mstrlen(ans));

    // Promt user to copy string into another
    printf("\n\n~ Kopier en streng inn i en annen ~");
    printf("\nByttbar streng: ");
    scanf("%24s", &ans);
    printf("\nSkriv enda en streng: ");
    scanf("%24s", &ans2);
    mstrcpy(ans, ans2);

    // Promt user to copy a string at the end of another
    printf("\n\n~ Kopier en streng på enden av en annen ~");
    char tihi[] = "Hello ";
    printf("\nFullfør setningen 'Hello .....': ");
    scanf("%24s", &ans);
    printf("\nDen sammensatte strengen: ");
    mstrcat(tihi, ans);

    // Promt user to compare strings
    printf("\n\nSammelign to strenger");
    printf("\nSkriv en streng: ");
    scanf("%24s", &ans);
    printf("\nSkriv enda en streng: ");
    scanf("%24s", &ans2);

    // Print the string comparison result accordingly
    int alike = mstrcmp(ans, ans2);
    if (alike > 0) {
        printf("> 0");
    }
    else if (alike < 0) {
        printf("< 0");
    }
    else {
        printf("0");
    }

    return 0;
}
/**
 *      Finds length of given char array
 *
 *      @param s - Char array, string
 *      @return String length
 */
int mstrlen(const char s[]) {
    int len = 0;

    // Find length by going through each char
    for (int i = 0; s[i] != '\0'; i++) {
        len++;
    }
    return len;
}

/**
 *      Copies a string into another
 *
 *      @param s - String to be copied into
 *      @param t - String to be copied
 *
 *      @see mstrlen(...)
 */
void mstrcpy(char s[], const char t[]) {

    // Replace each char with the other
    for (int i = 0; t[i] != '\0'; i++) {
        s[i] = t[i];
    }
    s[mstrlen(t)] = '\0';
    printf("\nFullført streng: %s", s);

}

/**
 *      Copies one string at the end of the other
 *
 *      @param s - String to be copied onto
 *      @param t - String to be copied
 *
 *      @see mstrlen(...)
 */
void mstrcat(char s[], const char t[]) {

    // Copy string to the end
    for (int i = 0; t[i] != '\0'; i++) {
        s[mstrlen(s)] = t[i];
    }
    s[mstrlen(s)] = '\0';
    printf("\nFullført streng: %s", s);

}

/**
 *      Compares strings and chars
 *
 *      @param s - First string
 *      @param t - Second string
 *
 *      @see mstrlen(...)
 *
 *      @return If strings are alike, before or after alphabetically
 */
int mstrcmp(const char s[], const char t[]) {

    // Checks if strings are different length
    int lencmp = mstrlen(s) - mstrlen(t);
    if (lencmp != 0) {
        return lencmp;
    }

    // Char comparison for each i value
    for (int i = 0; t[i] != '\0' && s[i] != '\0'; i++) {
        char cmp = tolower(s[i]) - tolower(t[i]);
        if (cmp != 0) {
            return cmp;
        }
    }

    return 0;
}