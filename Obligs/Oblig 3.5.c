
/**     Task 30 in grprog.pdf - Oblig 3.5
 *
 *      Program description:
 *          - Present user with menu command options
 *          - Let the user manage their trolleys
 *          - Quit if 'Q' is read
 *
 *      @file Oblig 3.5.c
 *      @date 06-Nov-23
 *
 *      @author Luna S.
 *      @alias LunaMellow
 */

// Includes
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

// Tralle Struct
struct Tralle {
    bool utlaant;
    char navn[80];
    int tlfNr;
};

// Declare Global Variables
struct Tralle gTraller[30]; // Array of Trolley-structs
int gAntallUtlaant = 0; // Number of trolleys currently rented
const int MAXTRALLER = 30; ///< Maximum number of trolleys available to rent

// Function Declarations
void finnLaaner();
void innlevering();
void ledige();
char lesKommando();
void oversikt();
void skrivMeny();
void utlaan();

/**
 *      Main Program Starts Here
 */
int main ()  {
    char kommando;

    skrivMeny();
    kommando = lesKommando();

    while (kommando != 'Q')  {
        switch (kommando)  {
            case 'O':  oversikt();      break;    //  Overview over rented trolleys
            case 'L':  ledige();        break;    //  Overview over rentable trolleys
            case 'U':  utlaan();        break;    //  Rent a trolley
            case 'I':  innlevering();   break;    //  Return a trolley
            case 'F':  finnLaaner();    break;    //  Find a trolley
            default:   skrivMeny();     break;    //  Non-existent menu choice
        }
        kommando = lesKommando();
    }

    printf("\n\n");
    return 0;
}

/**
 *  Find trolley owner
 */
void finnLaaner() {
    printf("Finn Traller");
}

/**
 *  Return trolley
 */
void innlevering() {
    printf("Innlever Traller");
}

/**
 *  Available trolleys
 */
void ledige(){
    printf("Ledige Traller");
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
 *  Overview over rented trolleys
 */
void oversikt() {
    printf("Oversikt Traller");
}

/**
 *  Prints out the menu with a list of commands
 */
void skrivMeny() {
    printf("\n--------------- Velkommen ---------------\n"
           "\n"
           "O = Oversikt\n"
           "L = Ledige Traller\n"
           "U = Utlån\n"
           "I = Innlevering\n"
           "F = Finn Traller\n"
           "\n"
           "-----------------------------------------\n");
}

/**
 *  Rent a trolley
 */
void utlaan() {
    printf("Utlån Traller");
}
