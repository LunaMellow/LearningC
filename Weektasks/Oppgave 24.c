
/**     Smallest and largest values
 *      Task 24 in grprog.pdf
 *
 *      Program description:
 *          - Promts user for n amount of integers
 *          - Finds smallest or largest integer
 *          - Returns according value
 *
 *      @file Oppgave 24.c
 *      @date 09-Dec-23
 *
 *      @author Luna S.
 *      @alias LunaMellow
 */

// Includes
#include <stdio.h>

// Enums
enum Handling {
    MINSTE,
    STORSTE
};

// Declare functions
int hentMinsteVerdi(const int n);
int hentStorsteVerdi(const int n);
int hentVerdi(const int n, enum Handling handling);

/**
 *      Main Program starts here
 */
int main() {
    int antall;
    int minsteVerdi;
    int storsteVerdi;

    // Promt user for n amount of integers
    printf("\nAntall verdier for minste: ");
    scanf("%d", &antall);

    minsteVerdi = hentVerdi(antall, MINSTE);
    printf("\nMinste Verdi: %d\n", minsteVerdi);

    // Promt user for n amount of integers
    printf("\nAntall verdier for storste: ");
    scanf("%d", &antall);

    storsteVerdi = hentVerdi(antall, STORSTE);
    printf("\nStørste Verdi: %d\n", storsteVerdi);

/*      First part of task:
 *
 *      // Promt user for n amount of integers
 *      printf("\nAntall verdier for minste:\n");
 *      scanf("%d", &antall);
 *
 *      int minsteVerdi = hentMinsteVerdi(antall);
 *      printf("%d", minsteVerdi);
 *
 *      // Promt user for n amount of integers
 *      printf("\nAntall verdier for storste:\n");
 *      scanf("%d", &antall);
 *
 *      int storsteVerdi = hentStorsteVerdi(antall);
 *      printf("%d", storsteVerdi);
*/

    return 0;
}

/**
 *  Takes n amount of integers and returns the smallest one
 *
 *  @param   n        -  Amount of numbers promted from user
 *  @param   handling - Enum for MINST or STORST, smallest or largest
 *
 *  @return handling - Smallest or largest integer of n integers
 */
int hentVerdi(const int n, enum Handling handling) {
    int minste;
    int storste;
    int nummer;

    switch (handling) {
        case MINSTE:

            // Initial number is smallest
            printf("\tNummer 1: ");
            scanf("%d", &nummer);
            minste = nummer;

            // Iterate and check if new number is smaller than previous
            for (int i = 0; i < n-1; i++) {
                printf("\tNummer %d: ", i+2);
                scanf("%d", &nummer);

                if (nummer < minste) {
                    minste = nummer;
                }
            }

            return minste;

        case STORSTE:

            // Initial number is biggest
            printf("\tNummer 1: ");
            scanf("%d", &nummer);
            storste = nummer;

            // Iterate and check if new number is larger than previous
            for (int i = 0; i < n-1; i++) {
                printf("\tNummer %d: ", i+2);
                scanf("%d", &nummer);

                if (nummer > storste) {
                    storste = nummer;
                }
            }

            return storste;

    }

}

/**
 *  Takes n amount of integers and returns the smallest one
 *
 *  @param   n   -  Amount of numbers promted from user
 *
 *  @return minste - Smallest integer of n integers
 */
int hentMinsteVerdi(const int n) {
    int minste;
    int nummer;

    // Initial number is smallest
    printf("\tNummer 1: ");
    scanf("%d", &nummer);
    minste = nummer;

    // Iterate and check if new number is smaller than previous
    for (int i = 0; i < n-1; i++) {
        printf("\tNummer %d: ", i+2);
        scanf("%d", &nummer);

        if (nummer < minste) {
            minste = nummer;
        }
    }

    return minste;
}

/**
 *  Takes n amount of integers and returns the largest one
 *
 *  @param   n   -  Amount of numbers promted from user
 *
 *  @return storste - Largest integer of n integers
 */
int hentStorsteVerdi(const int n) {
    int storste;
    int nummer;

    // Initial number is biggest
    printf("\tNummer %1: ");
    scanf("%d", &nummer);
    storste = nummer;

    // Iterate and check if new number is larger than previous
    for (int i = 0; i < n-1; i++) {
        printf("\tNummer %d: ", i+2);
        scanf("%d", &nummer);

        if (nummer > storste) {
            storste = nummer;
        }
    }

    return storste;
}