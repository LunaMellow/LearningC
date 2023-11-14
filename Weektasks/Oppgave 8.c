
/**     Quick math 2
 *      Task 8 in grprog.pdf
 *
 *      Program description:
 *          - Declaring 3 random int variables
 *          - Making 3 equations with different operators
 *          - Making another equation using loops
 *
 *      @file Oppgave 8.c
 *      @date 8/31/2023
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
    const int amount = 17;      // A constant int variable set by the task description

    int num1 = 37;               // Random number
    int num2 = 12;              // Random number
    int num3 = 25;              // Random number
    int sum;

    // Different equations with different operators using the numbers declared above

    /*
     *      Equation 1:
     *      Using + - and * operators
    */

    // Calculate the result
    sum = ((num1 + num2) - num3) * amount;

    // Print out the result
    printf("Equation 1:\n((%i + %i) - %i) * %i = %i\n\n", num1, num2, num3, amount, sum);

    /*
    *      Equation 2:
    *      Using + / and * operators
    */

    // Calculate the result
    sum = (num1 / num2) + (num3 * amount);

    // Print out the result
    printf("Equation 2:\n(%i / %i) + (%i * %i) = %i\n\n", num1, num2, num3, amount, sum);

    /*
    *      Equation 3:
    *      Using += and *= operators
    */

    // Calculate the result
    num1 += num2;
    num2 *= amount;
    sum = num1 + num2;

    // Print out the result
    printf("Equation 3:\n%i += %i\n%i *= %i = %i\n\n", num1, num2, num1, amount, sum);

    /*
    *      Equation 4:
    *      Using for loops incrementing the variables
    */

    // Calculate the result
    for (int i = 0; i < 3; i++) {
        num1++;                     // Increase num1 for each loop
    }
    for (int i = 0; i < 4; i++) {
        num2--;                     // Decrease num2 for each loop
    }

    // Print out the result
    printf("Number 1: %i\nNumber 2: %i\n", num1, num2);

    return 0;
}