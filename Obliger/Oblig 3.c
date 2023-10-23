
/**     Oblig 3
 *
 *      Program description:
 *          - Give the user menu commmand options
 *          - Call the functions from the command chosen
 *          - Quit if 'Q' is read
 * 
 *      @file Oblig 3.c
 *      @date 19/10/2023
 *
 *      @author Luna S.
 *      @alias LunaMellow
 */

// Includes
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Const variables
const int STRLEN = 80; ///< Max.textlength.
const int ANTINT = 20; ///< the length of the int-array

// Declare functions
int antallIArray(int tall[], const int n, const int min, const int max);
void fyllArray(int tall[], const int n);
char lesKommando();
int lesTall(const char tekst[], const int min, const int max);
void lesTekst(const char ledetekst[], char tekst[]);
bool sjekkTekst(const char tekst[]);
void skrivMeny();

/*
 *      PS!
 *      I commented Frode's code just in case.
 *      didnt know if we were supposed to or not :)
 *
 */

/**
 *      Main Program starts here
 */

int main() {
    // Declare variables
    char kommando;

    // Declare array variables
    int tallene[ANTINT];
    char teksten[STRLEN];

    // Calls to print out the menu interface
    skrivMeny();

    // Takes user command input
    kommando = lesKommando();

    // While the user input command is not 'Q', keep the program running
    while (kommando != 'Q') {
        switch (kommando) {
            // Command 'F' - Reads and writes user input integer (0-2000) to an array
            case 'F': fyllArray(tallene, ANTINT); break;

            // Command 'A' - Reads and returns the number of integers (0-2000) in an array
            case 'A': printf("\n\tAntall i arrayen i intervallet 0-2000: %i\n",
                             antallIArray(tallene, ANTINT, 0, 2000)); break;

            // Command 'L' - Reads a postal code and postal place from the user
            case 'L': lesTekst("Postnummer og -sted", teksten); break;

            // Command 'S' - Checks if the postal code and postal place is valid
            case 'S': printf("\n\tTeksten er%s et gyldig postnr og -sted.\n",
                             ((!sjekkTekst(teksten)) ? " ikke" : "")); break;

            // Print the menu interface if command not recognized
            default: skrivMeny(); break;
        }

        // Takes user command input
        kommando = lesKommando();

    }

    // Exit the program
    return 0;
}

/**
 *  Reads and returns the number of integers (0-2000) in an array
 *
 *  @param   tall   - Array where integers are stored
 *  @param   n      - Maximum loop iteration
 *  @param   min    - Minimum for the input and accepted numerical value
 *  @param   max    - Maximum for the input and accepted numerical value
 *
 *  @return  The number of integers (0-2000) in the 'tall' array
 */
int antallIArray(int tall[], const int n, const int min, const int max) {
    int teller = 0;
    for (int i = 0; i < n; i++) {
        if (tall[i] < 2000 && tall[i] > 0) {
            teller++;
        }
    }
    return teller;
}

/**
 *  Reads and writes user input integer (0-2000) to an array
 *
 *  @param   tall   - Array where valid user input integers will be stored
 *  @param   n      - Maximum loop iteration
 *
 */
void fyllArray(int tall[], const int n) {
    for (int i = 0; i <= n; i++) {
        tall[i]=lesTall("Skriv et tall",0,2000);
    }
}

/**
 *  Read and returns a character (toupper)
 *
 *  @return  A (toupper) character from the command input
 */
char lesKommando() {
    char tegn;
    printf("\nSkriv kommando:  ");
    scanf(" %c", &tegn);   getchar();
    return (toupper(tegn));
}

/**
 *  Reads and returns a number between two given bounds
 *
 *  @param   tekst  - Text for the user to input a number
 *  @param   min    - Minimum for the input and accepted numerical value
 *  @param   max    - Minimum for the input and accepted numerical value
 *
 *  @return  Accepted value in the range 'min' - 'max'
 */
int lesTall(const char tekst[], const int min, const int max) {
    int tall;
    do  {
        printf("\t%s (%i-%i):  ", tekst, min, max);
        scanf("%i", &tall);     getchar();
    } while (tall < min  ||  tall > max);
    return tall;
}

/**
 *  Reads text into the provided char array/string.
 *
 *  @param   ledetekst  - The prompt or message displayed to the user, indicating what text to enter
 *  @param   tekst      - Char array filled with the user inputted text
 *
 */
void lesTekst(const char ledetekst[], char tekst[]) {
    printf("\t%s:  ", ledetekst);
    gets(tekst);                    //  Updates ORIGINAL/actual parameter.
}

/**
 *  Checks that the text is a valid postcode and place name
 *
 * @param tekst - Char array filled with the user inputted text
 *
 * @return If the postcode and placename is valid or not (true or false)
 */
bool sjekkTekst(const char tekst[]) {

    for (int j = 0; j < 4; j++) {
        if (!isdigit(tekst[j]) && tekst[j] != ' ') {
            return false;
        }
    }

    for (int j = 4; j < strlen(tekst); j++) {
        if (!isalpha(tekst[j]) && tekst[j] != ' ' && tekst[j] != '-' && tekst[j] != '.') {
            return false;
        }
    }

    return true;
}

/**
 *  Prints out the menu with a list of commands
 */
void skrivMeny() {
    printf("\n--------------- Velkommen ---------------\n"
                  "\n"
                  "F = Fyll listen din med tall\n"
                  "A = Antall tall i listen din\n"
                  "L = Legg til postnummer og addresse\n"
                  "S = Sjekk om det du skrev var gyldig\n"
                  "\n"
                  "-----------------------------------------\n");
}