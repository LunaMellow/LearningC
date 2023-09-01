
/**     The volume of a cylinder
 *      Task 13 in grprog.pdf
 *
 *      Program description:
 *          - Define cylinder height and value of PI
 *          - Take user input for the value of the cylinder radius
 *          - Calculate the volume using the formula for cylinder volume
 * 
 *      @file Oppgave 13.c
 *      @date 01/09/2023
 *
 *      @author Luna S.
 *      @alias LunaMellow
 */

// Includes

#include <stdio.h>
#include <math.h>

/**
 *      Main Program starts here
 */

int main() {

    // Declare constant mathematical variables
    const float cylinderHeight = 4;
    const double pi = 3.1415926535;

    // Declare mathematical variables
    float cylinderRadius;
    float cylinderVolume;

    // Get user input with a value between 5-20
    printf("Type a number between 5 and 20 for the highest cylinder radius value:\n");
    scanf("%f", &cylinderRadius);

    printf("The volume for different values:\n\n");                              // Just acting as a header

    // Loop for calculating the radius per incremented value set above by the user
    for (int i = 1; (float)i < cylinderRadius + 1; i++) {
        cylinderVolume = (float)pow((pi * i), 2) * (float)cylinderHeight;      // Volume for cylinder formula (PI*r)^2
        printf("When i = %10i\nVolume = %10.2f\n\n", i, cylinderVolume);        // Print out the result per int i value
    }

    return 0;
}