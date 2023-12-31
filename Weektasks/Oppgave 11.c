
/**     Arrays
 *
 *      Program description:
 *          - Declare 2 int arrays, and 3 char arrays
 *          - Play around with different arrays
 *          - Print out all their changed values and results
 *
 *      @file Oppgave 11.c
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

    // Declare int array variables
    int number[5];
    int number2[] = {6, 2, 10, 12, 19, 3, 7};

    // Declare char array variables
    char text[5];
    char name[] = "Lars Hansen";
    char address[] = "Ringgata 111";

    // Set value of first and second element, of the number[] array
    number[0] = 13;
    number[1] = 67;

    // Set third array element to the sum of the first and second, of the number[] array
    number[2] = number[0] += number[1];

    // Print out third element of the number[] array halved
    printf("Element 3 halved:\n%d\n\n", (number[2]/2));

    // Set the fourth element of the number[] array to the sum of the first four elements of the number2[] array
    number[3] = number2[0] + number2[1] + number2[2] + number2[3];

    // Set the fifth element of the number[] array to the sum of the last three elements of the number2[] array
    number[4] = number2[6] + number2[5] +number2[4];

    // Print out the new number[] array values we just changed
    printf("Element 4:\n%d\n\nElement 5:\n%d\n\n", number[3], number[4]);

    // Increase value of element 4 of the number[] array 3 times
    for (int i = 3; i <= 3; i++) {
        number[2]++;                    // Increment number[2] with one per loop
    }

    // Print out the result after incrementing
    printf("Element 3 incremented:\n%d\n\n", number[2]);

    // Add the char 'A' to the second element of the text[] array and 'E' to the fourth
    text[1] = 'A';
    text[3] = 'E';

    // Copy the sixth element from the name[] array and set it into the text[] arrays first element
    text[0] = name[5];

    // Copy the first element from the name[] array and set it into the text[] arrays third element
    text[2] = name[0];

    // Print out first 4 elements of the text[] array
    printf("Kua har %c%c%c%c\n\n", text[0], text[1], text[2], text[3]);

    // Print out only the last 3 array elements of the address[] array "111"
    printf("Address: %c%c%c\n\n", address[9], address[10], address[11]);

    // Print out the whole name and address arrays on seperate lines
    printf("Name: %s\nAddress: %s\n", name, address);

    return 0;

}