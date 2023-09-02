
/**     Are they valid?
 *      Task 16 in grprog.pdf
 *
 *      Program description:
 *          - Get 5 number inputs from the user
 *          - Check if they are within range and print out
 *          - Get 10 character inputs from the user
 *          - Check if they are valid characters and print out
 * 
 *      @file Oppgave 16.c
 *      @date 02/09/2023
 *
 *      @author Luna S.
 *      @alias LunaMellow
 */

// Includes

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

/**
 *      Main Program starts here
 */

int main() {

    // Declare constant values min and max
    const int minValue = 1;
    const int maxValue = 10000;

    // Declare the arrays
    int numbers[10];
    char characters[100] = "";

    // Promt the user to give inputs
    printf("Please input 5 different values between 1 and 10000\n");

    // Loop to get users to give numbers and assign them to different array elements
    for (int i = 1; i <= 5; i++) {
        printf("%i. ", i);
        scanf("%d", &numbers[i]);

        // Check if input value is between min and max values
        if (minValue > numbers[i] || numbers[i] > maxValue) {
            printf("\nThe number is not between 1 and 10000. Try again.");
            break;
        }
    }

    printf("\nNumber array elements:");

    // Print out all the number elements
    for (int i = 1; i <= 5; i++) {
        printf("\nElement %d = %8d", i, numbers[i]);
    }

    // Promt user to give 10 inputs
    printf("\n\nPlease input 10 different letters\n");

    // Take 10 inputs as letters
    for (int i = 1; i <= 10; i++) {
        printf("%i. ", i);
        scanf("\n%c", &characters[i]);

        // Check if the letter is a valid character
        if (isalpha(characters[i]) != 0) {                            // isalpha() gives int 0 for invalid character
        }
        // Else error, character is not valid
        else {
            printf("\n%c is not a valid character. Try again.", characters[i]);
            exit(0);
        }
    }

    printf("\nChar array elements:");

    // Print out all the characters elements in uppercase
    for (int i = 1; i <= 10; i++) {
        printf("\nElement %d = %8c", i, toupper(characters[i]));      // Converts the letters to uppercase
    }

    return 0;
}