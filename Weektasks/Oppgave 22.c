
/**     Squares
 *      Task 22 in grprog.pdf
 *
 *      Program description:
 *          - Promt user for height and width of square
 *          - Use dots and spacing to create a representation of the square
 *
 *      @file Oppgave 22.c
 *      @date 23/11/2023
 *
 *      @author Luna S.
 *      @alias LunaMellow
 */

// Includes
#include <stdio.h>

// Function declarations
void lagFirkant(int bredde, int hoyde);

int main() {

    // Declare variables
    int firkantHoyde;
    int firkantBredde;

    // Promt user to input height and width
    printf("Vennligst skriv høyde og bredde for firkanten\n");

    // Width
    printf("\nBredde: ");
    scanf("%d", &firkantBredde);

    // Height
    printf("\nHøyde: ");
    scanf("%d", &firkantHoyde);

    // Call the function and make the square
    lagFirkant(firkantBredde, firkantHoyde);

    return 0;
}

void lagFirkant(int bredde, int hoyde) {

    // New line
    printf("\n");

    // Print top bar
    for (int i = 0; i < bredde; i++) {
        printf("*");
    }

    // New line
    printf("\n");

    for (int i = 0; i < hoyde-2; i++) {

        // Add left dot
        printf("*");

        // Add middle spacing
        for (int i = 1; i < bredde-1; i++) {
            printf(" ");
        }

        // Add right dot
        printf("*");

        // New line
        printf("\n");

    }

    // Print bottom bar
    for (int i = 0; i < bredde; i++) {
        printf("*");
    }

}

