
/**     Continue? [Y] or [N]?
 *      Task 15 in grprog.pdf
 *
 *      Program description:
 *          - Give two user inputs
 *          - Calculate addition, subtraction and multiplication
 *          - Ask if user wants to continue or not. Do accordingly to the answer
 * 
 *      @file Oppgave 15.c
 *      @date 02/09/2023
 *
 *      @author Luna S.
 *      @alias LunaMellow
 */

// Includes

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/**
 *      Main Program starts here
 */

int main() {

    // Declare variables
    int input1;
    int input2;
    char answer[] = "";
    bool isTrue = true;

    // Make a while loop for the isTrue statement. This while run while true
    while (isTrue == true) {

        // Take two user inputs
        printf("\n\nPlease input two different numbers\n1. Input: ");
        scanf("%d", &input1);
        printf("2. Input: ");
        scanf("%d", &input2);

        // Calculate and print the results
        printf("\nAdded: %d\nSubtracted: %d\nMultiplied: %d\n\n", (input1+input2),(input1-input2),(input1*input2));

        // Promt user to continue or stop
        printf("Would you like to continue? [Y] or [N]\n> ");
        scanf("%s", answer);

        // Check if user input was [Y], if so, continue. Else stop the loop and leave a nice message
        if (strcmp(answer, "Y") == 0) {
            continue;
        }
        // If conditions are not met above, then do this
        else {
            printf("\nOkay. Have a nice day! <3");
            isTrue = false; // Stops the while loop
        }
    }
    return 0;
}