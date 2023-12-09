
/**     Numbers Squared
 *      Task 23 in grprog.pdf
 *
 *      Program description:
 *          - Call a function summerKvadrater() with random numbers
 *          - Calculate the squared of all the numbers
 *          - Return the squared integers and the sum
 *
 *      @file Oppgave 23.c
 *      @date 09-Dec-23
 *
 *      @author Luna S.
 *      @alias LunaMellow
 */

// Includes
#include <stdio.h>

// Declare functions
int summerKvadrater(int tall, int tall2, int tall3);

/**
 *      Main Program starts here
 */
int main() {

    // First round of numbers
    printf("\nFørste runde med tall");
    int sum1 = summerKvadrater(10, 100, 1000);
    printf("\nTotal sum for første runde: %d\n", sum1);

    // Second round of numbers
    printf("\nAndre runde med tall");
    int sum2 = summerKvadrater(13, 24, 6);
    printf("\nTotal sum for andre runde: %d\n", sum2);

    return 0;
}

/**
 *  Takes three integers and returns the squared number and sum of the integers
 *
 *  @param   tall   -  Number 1
 *  @param   tall2  -  Number 2
 *  @param   tall3  -  Number 3
 *
 *  @return totalsum - The total sum of the squared numbers
 */
int summerKvadrater(int tall, int tall2, int tall3) {
    // Print given numbers
    printf("\nTall 1: %d\nTall 2: %d\nTall 3: %d\n", tall, tall2, tall3);

    // The given numbers squared
    tall = tall * tall;
    tall2 = tall2 * tall2;
    tall3 = tall3 * tall3;

    // Calculate total sum
    int totalsum = tall + tall2 + tall3;

    printf("\nSummene av tallene kvadrert\nTall 1: %d\nTall 2: %d\nTall 3: %d\n", tall, tall2, tall3);

    return totalsum;
}