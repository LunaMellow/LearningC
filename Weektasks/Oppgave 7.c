
/**     Quick math
 *      Task 7 in grprog.pdf
 *
 *      Program description:
 *          - Takes 3 floats, calculates sum and squared sum
 *          - Takes 2 floats, calculates average and squared average
 *          - Prints out all the values and sums/results
 *
 *      @file Oppgave 7.c
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

    // Declare ints
    int num1 = 8;
    int num2 = 7;
    int num3 = 6;
    int sum = num1 + num2 + num3;
    int squaredSum = num1 * num2 * num3;

    // Declare floats
    float float1 = 6.25;
    float float2 = 8.75;
    float averageSum = (float1 + float2) / 2;
    float averageSquared = (float1 * float2) / 2;

    // Print out the results
    printf("Number 1: %i\nNumber 2: %i\nNumber 3: %i\n\nSum: %i\nSquared: %i\n\nFloat1: %f\nFloat 2: %f\n\nAverage: %f\nSquared Average: %f",
           num1, num2, num3, sum, squaredSum, float1, float2, averageSum, averageSquared);

    return 0;

}