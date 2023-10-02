
/**     Oblig 1
 *
 *      Program description:
 *          - Define variables with pre-set values from the task description
 *          - Take user input for the teams, with possibility of spaces inbetween the words
 *          - Print out table with pre-set values
 *          - Promt user for team goals and points
 *          - Print out final result with updated values
 *
 *      @file Oblig 1.c
 *      @date 15/9/2023
 *
 *      @author Luna S.
 *      @alias LunaMellow
 */

// Includes
#include <stdio.h>

/**
 *      Main Program starts here
 */

// Declare const int variables
const int STRLEN = 20;                          // Constant string length 20

int main() {

    // Declare variables
    int kamper = 10;                            // Matches played
    int maalA = 0;
    int maalB = 0;
    int poengA = 23;                            // Points A
    int poengB = 19;                            // Points B
    int inputPoengA;                            // Temporary variables for user input
    int inputPoengB;                            // Temporary variables for user input

    // Declare int arrays
    int tallA[] = {22,10};             // Goals scored, goals lost
    int tallB[] = {18,12};             // Goals scored, goals lost

    // Declare char arrays
    char navnA[STRLEN];                         // Size of char array 20 from const STRLEN = 20
    char navnB[STRLEN];                         // Size of char array 20 from const STRLEN = 20

    // Get user input for both teams and assign them to navnA and navnB
    printf("First team: ");
    scanf("%[^\n]%*c", navnA);            // User input A
    printf("Second team: ");
    scanf("%[^\n]%*c", navnB);            // User input B

    // Print out first table
    printf("\n\t%-12s %4d %4d-%d %4d\n", navnA, kamper, tallA[0], tallA[1], poengA);
    printf("\t%-12s %4d %4d-%d %4d\n", navnB, kamper, tallB[0], tallB[1], poengB);

    // Get user input for both teams and assign them to navnA and navnB
    printf("\n%s goal: ", navnA);
    scanf("%d", &maalA);                 // User input A
    printf("%s goal: ", navnB);
    scanf("%d", &maalB);                 // User input B

    // Increment total matches
    ++kamper;

    // Add the user input goals to the int arrays
    tallA[0] += maalA;                          // First element of tallA incremented with maalA
    tallA[1] += maalB;                          // Second element of tallA incremented with maalB
    tallB[0] += maalB;                          // First element of tallB incremented with maalB
    tallB[1] += maalA;                          // Second element of tallA incremented with maalB

    // Get user input for both teams and assign them to navnA and navnB
    printf("\n%s points: ", navnA);
    scanf("%d", &inputPoengA);           // User input A set to temporary variable
    printf("%s points: ", navnB);
    scanf("%d", &inputPoengB);           // User input B set to temporary variable

    // Add points from user input
    poengA += inputPoengA;                      // Add value from temporary variable to poengA
    poengB += inputPoengB;                      // Add value from temporary variable to poengB

    // Print out first table
    printf("\n\t%-12s %4d %4d-%d %4d\n", navnA, kamper, tallA[0], tallA[1], poengA);
    printf("\t%-12s %4d %4d-%d %4d\n", navnB, kamper, tallB[0], tallB[1], poengB);

    return 0;

}