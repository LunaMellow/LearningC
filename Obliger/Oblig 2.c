
/**     Oblig 2
 *
 *      Program description:
 *          - Program loops until max limit reached or user inputs 's'
 *          - Takes input of a operator and integer/float with .3 precision
 *          - Adds the values to a array and prints it out
 *          - When user ends the program, print out all operations neatly
 *
 *      @file Oblig 2.c
 *      @date 02/10/23
 *
 *      @author Luna S.
 *      @alias LunaMellow
 */

// Includes
#include <stdio.h>

/// Declare const variables
#define MAXOPERASJONER 50 ///< Maximum allowed operations = 50

/**
 *      Main Program starts here
 */

int main() {

    // Declare variables
    float akkumulator[MAXOPERASJONER] = {0.0};              // Set the initial element to be the value 0.0
    float tall[MAXOPERASJONER];
    char operasjoner[MAXOPERASJONER];
    int indeks = 0, j;

    // While loop for running the code continously while indeks is less than MAXOPERASJONER (=50)
    while (indeks <= MAXOPERASJONER)  {

        // Checks if maximum operations limit reached, or if user entered 's' and stops program
        if (operasjoner[indeks] == 's' || indeks == MAXOPERASJONER){
            printf("\nOperasjonene og tallene involvert:\n");

            // For loop to print out all array elements in their respected order
            for (j = 0; j < indeks; j++)

                // Print out the results in the correct way. 'c' and 't' get printed out with a different format
                if (operasjoner[j] == 'c' || operasjoner[j] == 't')
                    printf("\t%i. utregning: %11.3f %4c\t\t\t\t = %11.3f\n", j+1, akkumulator[j], operasjoner[j], akkumulator[j+1]);
                else {
                    printf("\t%i. utregning: %11.3f %4c %11.3f\t = %11.3f\n",
                           j + 1, akkumulator[j], operasjoner[j], tall[j], akkumulator[j + 1]);
                }

            // Exit the program
            return 0;
        }

        // Input for the user inputted operations
        printf("= %.3f\n\n: ", akkumulator[indeks]);
        scanf(" %c", &operasjoner[indeks]);

        // Switch statement to decide the operation from the given operator
        switch (operasjoner[indeks]) {

            // Command '+': Add the current number with the user input
            case '+': scanf("%f", &tall[indeks]);
                akkumulator[indeks+1] = akkumulator[indeks] + tall[indeks];
                indeks++;
                break;

            // Command '-': Subtract the current number with the user input
            case '-': scanf("%f", &tall[indeks]);
                akkumulator[indeks+1] = akkumulator[indeks] - tall[indeks];
                indeks++;
                break;

            // Command '*': Multiply the current number with the user input
            case '*': scanf("%f", &tall[indeks]);
                akkumulator[indeks+1] = akkumulator[indeks] * tall[indeks];
                indeks++;
                break;

            // Command '/': Divide the current number with the user input
            case '/': scanf("%f", &tall[indeks]);
                if (tall[indeks] != 0)    {
                    akkumulator[indeks+1] = akkumulator[indeks] / tall[indeks];
                    indeks++;
                }
                else
                    printf("Feil! Deling pa null er tull!\n");
                break;

            // Command 'c': Reset akkumulator value back to 0.0
            case 'c':
                akkumulator[indeks+1] = 0.0;
                indeks++;
                break;

            // Command 't': Set the akkumulator value to the number given by the user
            case 't':
                scanf("%f", &akkumulator[indeks+1]);
                operasjoner[indeks] = 't';
                indeks++;
                break;

            // Command 's': End program
            case 's':
                break;

            // If a invalid input is given, it will give a error and promt the user to try again
            default:
                printf("Feil! Ukjent kommando gitt\n");
                break;
        }
    }
    return 0;
}