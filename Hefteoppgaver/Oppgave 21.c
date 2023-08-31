
/**     Timewatcher
 *      Task 21 in grprog.pdf
 *
 *      Program description:
 *          - Write a function for time in this format tt:mm::ss
 *          - Convert time to seconds
 *          - Have a starting 0 (Null) if min or sec is a one-digit number
 *
 *      @file Oppgave 21.c
 *      @date 8/31/2023
 *
 *      @author Luna S.
 *      @alias LunaMellow
 */

// Includes

#include <stdio.h>

// Declare constant variables
const int hourInSeconds = 60*60;             // Declare how many seconds in one hour
const int minuteInSeconds = 60;              // Declare how many seconds in one minute
const int oneSecond = 1;                     // Define a single second

void writeTime(int hour, int min, int sec) {
    printf("%02d:%02d:%02d\n", hour, min, sec);

    int totalSeconds = hour * 3600 + min * 60 + sec;
    printf("Total seconds: %d\n", totalSeconds);
}

/**
 *      Main Program starts here
 */

int main() {
    // Call writeTime function with different values
    writeTime(8, 45, 30);  // Example 1: 08:45:30, Total seconds: 31530
    writeTime(12, 15, 0); // Example 2: 12:15:00, Total seconds: 44100
    writeTime(1, 5, 20);  // Example 3: 01:05:20, Total seconds: 3920

    return 0;
}