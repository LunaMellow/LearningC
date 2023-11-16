
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

// Function Declarations
void finnLaaner();
void innlevering();
void ledige();
char lesKommando();
void oversikt();
void skrivMeny();
void utlaan();

// Declare Global Variables
struct Tralle gTraller[30]; // Array of Trolley-structs
int gAntallUtlaant = 0; // Number of trolleys currently rented
const int MAXTRALLER = 30; ///< Maximum number of trolleys available to rent

/**
 *      Main Program Starts Here
 */
int main ()  {
    char kommando;

    skrivMeny();
    kommando = lesKommando();

    for (int i = 0; i < MAXTRALLER; i++) {
        gTraller[i].utlaant = false;
    }

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
    char navn[80];  // Assuming navn is a string
    bool eierTralle = false;

    lesTekst("Skriv navnet på en tralleeier", navn, sizeof(navn));

    printf("\n\t%s eier tralle:\n\t", navn);

    for (int i = 0; i < MAXTRALLER; i++) {
        if (strcmp(gTraller[i].navn, navn) == 0 && gTraller[i].utlaant == true) {
            printf("%d, ", i+1);  // Adjusted to print tralle number
            eierTralle = true;
        }
    }

    printf("\n");

    if (!eierTralle) {
        printf("\n\tBeklager, %s eier ingen traller for øyeblikket\n", navn);
    }
}


/**
 *  Return trolley
 */
void innlevering() {
    int tralleNr;

    if (gAntallUtlaant <= 0) {
        printf("\n\tBeklager, det er ingen utlånte traller\n");
        return;
    }

    while (1) {
        tralleNr = lesTall("Skriv trallenummeret du ønsker å levere inn", 1, MAXTRALLER);

        // Check if the selected trolley is rented or not
        if (gTraller[tralleNr-1].utlaant = false) {
            printf("\tTralle er ikke utlånt. Velg en annen tralle.\n");
        } else {
            break;  // Exit the loop if the selected trolley is available
        }
    }

    gTraller[tralleNr-1].utlaant = false;
    gAntallUtlaant--;

    printf("\n\t%s sin tralle er nå innlevert\n",gTraller[tralleNr-1].navn);

}

/**
 *  Prints out the available trolleys
 */
void ledige(){
    if (gAntallUtlaant >= MAXTRALLER) {
        printf("\n\tBeklager, alle traller er utlånt\n");
        return;
    }
    else {
        printf("\n\tLedige Traller:\n\t");
        for (int i = 0; i < MAXTRALLER; i++) {
            if (gTraller[i].utlaant != true) {
                printf("%i, ", i+1);
            }
        }
        printf("\n");
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
void lesTekst(const char ledetekst[], char tekst[], size_t maxLen) {
    printf("\t%s:  ", ledetekst);
    fgets(tekst, maxLen, stdin);

    // Remove the newline character if present
    size_t len = strlen(tekst);
    if (len > 0 && tekst[len - 1] == '\n') {
        tekst[len - 1] = '\0';
    }
}

/**
 *  Overview over rented trolleys
 */
void oversikt() {
    if (gAntallUtlaant <= 0) {
        printf("\n\tBeklager, det er ingen utlånte traller\n");
        return;
    }

    for (int i = 0; i < MAXTRALLER; i++) {
        if (gTraller[i].utlaant == true) {
            printf("\n\tTrallenr: %d\n\tNavn: %s\n\tTelefonnr: %d\n", i+1, gTraller[i].navn, gTraller[i].tlfNr);  // Adjusted to print tralle number
        }
    }
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
    int tralleNr;

    // Keep asking for a trolley number until a valid, available trolley is selected
    while (1) {
        tralleNr = lesTall("Skriv trallenummeret du ønsker å låne", 1, MAXTRALLER);

        // Check if the selected trolley is already rented
        if (gTraller[tralleNr-1].utlaant) {
            printf("\nTralle er allerede utlånt. Velg en annen tralle.\n");
        } else {
            break;  // Exit the loop if the selected trolley is available
        }
    }

    lesTekst("Navn", gTraller[tralleNr-1].navn, sizeof(gTraller[tralleNr-1].navn));
    printf("\tTelefonnr: ");
    scanf(" %d", &gTraller[tralleNr-1].tlfNr);

    gTraller[tralleNr-1].utlaant = true;
    gAntallUtlaant++;

    printf("\n\tTrallen din, nr. %d\n"
           "\t--------------------\n"
           "\tNavn: %s\n"
           "\tTelefonnr: %d\n", tralleNr,
           gTraller[tralleNr-1].navn,
           gTraller[tralleNr-1].tlfNr);
}
