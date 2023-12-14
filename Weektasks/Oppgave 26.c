
/**     Date and time
 *      Task 26 in grprog.pdf
 *
 *      Program description:
 *          - This is in in the program
 *          - This is in in the program
 *          - This is in in the program
 *
 *      @file Oppgave 26.c
 *      @date 14-Dec-23
 *
 *      @author Luna S.
 *      @alias LunaMellow
 */

// Includes
#include <stdio.h>

// Structs
struct Dato {
    int dag;
    int maaned;
    int aar;
};

// Struct declarations
struct Dato gDato;
struct Dato gDato2;

// Function declarations
int datocmp (const struct Dato dato, const struct Dato dato2);

/**
 *      Main Program starts here
 */
int main() {

    // Variable declarations
    int dag;
    int maaned;
    int aar;

    // First date
    printf("\n\nFørste dato\n"
                 "--------------\n");
    printf("\tDag: ");
    scanf("%d", &gDato.dag);
    printf("\tMåned: ");
    scanf("%d", &gDato.maaned);
    printf("\tÅr: ");
    scanf("%d", &gDato.aar);

    // Second date
    printf("\n\nAndre dato\n"
           "--------------\n");
    printf("\tDag: ");
    scanf("%d", &gDato2.dag);
    printf("\tMåned: ");
    scanf("%d", &gDato2.maaned);
    printf("\tÅr: ");
    scanf("%d", &gDato2.aar);

    // Call function to compare dates
    int tidligst = datocmp(gDato, gDato2);
    switch (tidligst) {

        // Dates are the same
        case 0: printf("\nDatoene er like\n"); break;

        // First date is earliest
        case 1: printf("\nFørste datoen er tidligst\n"); break;

        // Second date is earliest
        case -1: printf("\nAndre datoen er tidligst\n"); break;

    }

    return 0;
}

int datocmp (const struct Dato dato, const struct Dato dato2) {
    if (dato.aar != dato2.aar)
        return (dato.aar > dato2.aar) ? -1 : 1;
    if (dato.maaned != dato2.maaned )
        return (dato.maaned  > dato2.maaned ) ? -1 : 1;
    if (dato.dag != dato2.dag)
        return (dato.dag > dato2.dag) ? -1 : 1;
    return 0;
}