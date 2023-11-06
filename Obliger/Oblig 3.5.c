
/**     Task 30 in grprog.pdf - Oblig 3.5
 *
 *      Program description:
 *          - This is in in the program
 *          - This is in in the program
 *          - This is in in the program
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

// Declare global Variables
struct Tralle gTraller[30]; // Array av Tralle-struct'er.
int gAntallUtlaant = 0; // Antall traller som pt. er utlånt.
const int MAXTRALLER = 30; ///< Max. antall traller til utlån

// Function declarations
void finnLaaner();
void innlevering();
void ledige();
char lesKommando();
void oversikt();
void skrivMeny();
void utlaan();

/**
 *      Main Program starts here
 */
int main ()  {
    char kommando;

    skrivMeny();
    kommando = lesKommando();

    while (kommando != 'Q')  {
        switch (kommando)  {
            case 'O':  oversikt();      break;    //  Oversikt over varelager.
            case 'L':  ledige();        break;    //  Registrer ny vare.
            case 'U':  utlaan();        break;    // Motta 'x' stk. av vare.
            case 'I':  innlevering();   break;    // Selg 'x' stk. av vare.
            case 'F':  finnLaaner();    break;    //  Fjern en vare fra lager.
            default:   skrivMeny();     break;    //  Ikke-eksisterende menyvalg.
        }
        kommando = lesKommando();
    }

    printf("\n\n");
    return 0;
}

/**
 *  Finn låner
 */
void finnLaaner() {
    printf("Finn Traller");
}

/**
 *  Innlevering
 */
void innlevering() {
    printf("Innlever Traller");
}

/**
 *  Ledige
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
 *  Oversikt
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
 *  Utlån
 */
void utlaan() {
    printf("Utlån Traller");
}
