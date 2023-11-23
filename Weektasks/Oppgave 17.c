
/**     Ice-skating
 *      Task 17 in grprog.pdf
 *
 *      Program description:
 *          - Take user input distance, and time for participant
 *          - Calculate score for participant
 *          - Ask if user wants to continue
 * 
 *      @file Oppgave 17.c
 *      @date 23/11/2023
 *
 *      @author Luna S.
 *      @alias LunaMellow
 */

// Includes
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

// Declare const variables
#define MAXLOPERE 10         ///< Maximum allowed participants

/**
 *      Main Program starts here
 */

int main() {

    // Declare variables
    int distanse;
    int lopere;

    int minutt;
    int sekund;
    int hundredel;

    int antallHalvkilometere;
    float poengsum;

    char svar;

    // While answer is not 'N', continue
    while (toupper(svar) != 'N'){

        // Ask user for distance
        while (1) {
            printf("\nSkriv en distanse (500, 1500, 3000, 5000): ");
            scanf("%d", &distanse);

            if (distanse == 500 || distanse == 1500 || distanse == 3000 || distanse == 5000) {
                break;
            }
            else {
                printf("\nIkke en lovlig distanse, prøv igjen\n");
            }
        }

        // Ask user for the amount of participants
        while (1) {
            printf("\nSkriv antall løpere (Max 10): ");
            scanf("%d", &lopere);

            if (lopere <= MAXLOPERE-1) {
                break;
            }
            else {
                printf("\nIkke en lovlig mengde løpere, prøv igjen\n");
            }

        }

        // Ask user for time (minutes) of participant
        for (int i = 1; i <= lopere; i++) {
            printf("\nTid for løper nr. %d\n", i);

            while (1) {
                printf("Minutt: ");
                scanf("%d", &minutt);

                if (minutt >= 0) {
                    break;
                }
                else {
                    printf("\nTiden kan ikke være mindre enn 0, prøv igjen\n");
                }
            }

            // Ask user for time (Seconds) of participant
            while (1) {
                printf("Sekund: ");
                scanf("%d", &sekund);

                if (sekund >= 0) {
                    break;
                }
                else {
                    printf("\nTiden kan ikke være mindre enn 0, prøv igjen\n");
                }
            }

            // Ask user for time (hundreth) of participant
            while (1) {
                printf("Hundredel: ");
                scanf("%d", &hundredel);

                if (hundredel >= 0) {
                    break;
                }
                else {
                    printf("\nTiden kan ikke være mindre enn 0, prøv igjen\n");
                }
            }

            // Calculate score
            antallHalvkilometere = distanse/500;
            poengsum = (((minutt * 60) + sekund + (hundredel / 100.0)) / antallHalvkilometere);

            // Print score and ask if user wants to continue
            printf("\nPoengscore for løper nr. %d \t=\t %.3f\n\nØnsker du å regne ut flere? (J/N): ", i, poengsum);
            scanf(" %c", &svar);
        }
    }
}