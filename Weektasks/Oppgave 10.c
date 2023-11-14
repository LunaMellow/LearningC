
/**     Floats and chars
 *
 *      Program description:
 *          - Reverse order
 *          - Exponential
 *          - Whole numbers
 *          - Chars as ints
 *
 *      @file Oppgave 10.c
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

    // Declare float variables
    float float1 = 17.52;
    float float2 = 451.87;

    // Declare char variables
    char char1 = 'F';
    char char2 = 'H';

    // Reverse order
    printf("Reverse order:\n%f %f %c %c\n\n",  float2, float1, char2, char1);

    // Exponential
    printf("Exponential:\n%e\n\n", float2);

    // Whole numbers
    printf("Whole numbers:\n%.0f\n%.0f\n\n", float1, float2);

    // Declare 'b' as char
    char b = 'b';

    // Print out chars as ints
    printf("\'%c\' as int:\n%d\n\n", char1, char1);
    printf("\'b\' as int:\n%d", b);

    return 0;

}


