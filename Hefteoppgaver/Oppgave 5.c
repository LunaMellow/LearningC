
/**     Volume of a prism
 *      Task 5 in grprog.pdf
 *
 *      Program description:
 *          - This is in in the program
 *          - This is in in the program
 *          - This is in in the program
 *
 *      @file Oppgave 5.c
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

    int height = 8;     // Height is 8cm as mentioned in the task description
    int width = 12;     // Height is 12cm as mentioned in the task description
    int depth = 16;     // Height is 16cm as mentioned in the task description

    // Calculate the volume from the dimensions above
    int totalVolume = height*width*depth;

    // Print out dimensions and total volume of the prism
    printf("Prism dimensions\nHeight: %i\nWidth: %i\nDepth: %i\n\nA total volume of: %i",
           height, width, depth, totalVolume);

    return 0;
}


