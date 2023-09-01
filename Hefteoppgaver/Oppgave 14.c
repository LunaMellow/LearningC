
/**     Project name
 *      Task x in grprog.pdf
 *
 *      Program description:
 *          - This happens in the code
 *          - This happens in the code
 *          - This happens in the code
 * 
 *      @file Oppgave 14.c
 *      @date 01/09/2023
 *
 *      @author Luna S.
 *      @alias LunaMellow
 */

// Includes

#include <stdio.h>

/**
 *      Main Program starts here
 */

int main() {

    // Define the max of inputs the user is allowed to give
    int maxInput = 1000;
    float inputAmount = 0;
    float input;
    float total;
    float average;

    for (int i = 0; i < maxInput; i++) {
        printf("\n\nPlease enter one of the following\n\n1. Input a positive number to add a number to the list\n"
               "2. Input a negative number to see the total value of all the numbers\n\nInput: ");
        scanf("%f", &input);

        if (input > 0) {
            total = total + input;
            inputAmount++;
        }
        else {
            average = total/inputAmount;

            printf("Input: %d\nTotal: %.0d\nAverage: %.2f\n\n", input, total, average);
            break;
        }
    }

    return 0;
}