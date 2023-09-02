
/**     Whole and negative numbers
 *      Task 14 in grprog.pdf
 *
 *      Program description:
 *          - Take a user input, positive or negative
 *          - If user gives positive; increment and add the number
 *          - If user gives negative; stop script and give results
 *          - Print out the results throughout the for loop
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

    // Declare variables
    int maxInput = 1000;
    float inputAmount = 0;
    float input;
    float total;
    float average;

    // Make a for loop that takes user input until the input is a negative number
    for (int i = 0; i < maxInput; i++) {
        printf("\n\nPlease enter one of the following\n\n1. Input a positive number to add a number to the list\n"
               "2. Input a negative number to see the total value of all the numbers\n\nInput: ");

        scanf("%f", &input);    // Take user input and store it in input

        // Increment the amount and continue if the user gives a whole number
        if (input > 0) {
            total = total + input;
            inputAmount++;
        }

        // Stop the statement if the user gives a negative number and print out the results
        else {
            average = total/inputAmount;    // Calculate the average
            printf("\n\nResults\n> Input: %.0f\n> Total: %.2f\n> Average: %.2f\n\n", input, total, average);
            break;
        }
    }
    return 0;
}