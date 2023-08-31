
/**     Phone-numbers to pseudo
 *      Task 20 in grprog.pdf
 *
 *      Program description:
 *          - Take a input of a phone number
 *          - Turn that number and convert to text
 *          - Add "-" between and print error messages
 *
 *      @file Telefonnummere.c
 *      @date 8/31/2023
 *
 *      @author Luna S.
 *      @alias LunaMellow
 */

// CODE STARTS BELOW THIS LINE

#include <stdio.h>

/**
 *      Main Program starts here
 */

int main() {

    // Declare variable for a integer input
    int phoneNum;

    // Get user phone number input and determines if it is a valid number
    printf("Enter an integer: \n");
    if (scanf("%d", &phoneNum) != 1) {

        // Input is not a valid integer
        printf("Invalid input. Try again.\n");
        return 1; // Exit the program with an error code
    }

    // Determine the number of digits in the input number
    int temp = phoneNum;
    int digitCount = 0;

    while (temp != 0) {
        temp /= 10;
        digitCount++;
    }

    // Determine the user input contains exactly 8 digits (Norwegian Number Length)
    if (digitCount != 8) {
        printf("This is not a Norwegian number. Try again.\n");
        return 1; // Exit the program with an error code
    }

    // Define a array to store the digits
    int digits[digitCount];

    // Extract and store the digits in correct order
    temp = phoneNum;
    for (int i = digitCount - 1; i >= 0; i--) {
        digits[i] = temp % 10;
        temp /= 10;
    }

    printf("\nYour phone number in pseudo:\n");

    /**
     *      Converting the digits in the array to readable pseudo text
     */

    for (int i = 0; i < digitCount; i++) {      // For loop to go through all the array ints
        switch (digits[i]) {                    // Switch statement to convert each int to pseudo text
            case 1:
                printf("one");
                break;
            case 2:
                printf("two");
                break;
            case 3:
                printf("three");
                break;
            case 4:
                printf("four");
                break;
            case 5:
                printf("five");
                break;
            case 6:
                printf("six");
                break;
            case 7:
                printf("seven");
                break;
            case 8:
                printf("eight");
                break;
            case 9:
                printf("nine");
                break;
            case 10:
                printf("ten");
                break;
            default:
                printf("zero");
                break;
        }
        if (i < digitCount - 1) {
            printf("-");
        }
    }

    return 0;
}