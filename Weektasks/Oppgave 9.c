
/**     Timeconversion
 *      Task 9 in grprog.pdf
 *
 *      Program description:
 *          - Declare the variables from the task description
 *          - Calculate the hours, minutes and seconds
 *          - Print out the result in the desired format
 * 
 *      @file Oppgave 9.c
 *      @date 31/08/2023
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
    int totalSeconds =  312304;     // Total seconds defined by task description

    int hours;
    int minutes;
    int seconds;

    // Calculate the hours, minutes and seconds using division and modulo
    seconds = totalSeconds % 60;
    minutes = (((totalSeconds - seconds) / 60) % 60);
    hours = (((totalSeconds - seconds) / 60) / 60);

    // Print out the result as asked in the task description
    printf("%i seconds is equivilent to: %i hour(s), %i minute(s), %i second(s)", totalSeconds, hours, minutes, seconds);

    return 0;

}

