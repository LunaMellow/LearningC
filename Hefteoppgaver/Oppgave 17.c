
/**     Ice-skating
 *      Task 17 in grprog.pdf
 *
 *      Program description:
 *          - This happens in the code
 *          - This happens in the code
 *          - This happens in the code
 * 
 *      @file Oppgave 17.c
 *      @date 02/09/2023
 *
 *      @author Luna S.
 *      @alias LunaMellow
 */

// Includes

#include <string.h>
#include <stdio.h>

/**
 *      Main Program starts here
 */

int main() {

    char text[] = "apple";

    int array_length = strlen(text);
    char array_backwards[5];
    int j = 0;

    for (int i = array_length; i > 0; i--) {
            array_backwards[i] = text[j];
            j++;
    }

    printf("%s", array_backwards);w

}