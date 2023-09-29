
/**     Project name
 *
 *      Program description:
 *          - This is in in the program
 *          - This is in in the program
 *          - This is in in the program
 *
 *      @file Oblig 2.c
 *      @date 28/09/23
 *
 *      @author Luna Sofie Bergh
 *      @alias LunaMellow
 */

// Includes
#include <stdio.h>

// Declare consts

/**
 *      Main Program starts here
 */

int main() {
    float result = 0.0;
    char operator;
    float number;

    printf("Simple Calculator\n");
    printf("= %.2f\n", result);

    while (1) {
        printf(": ");
        if (scanf(" %c%f", &operator, &number) != 2) {
            printf("Invalid input. Please try again.\n");
            while (getchar() != '\n');  // Clear input buffer
            continue;
        }

        if (operator == 'q' || operator == 'Q') {
            break;
        }

        switch (operator) {
            case 'e':
            case 'E':
                result = 0.0;
                printf("Result reset to 0.0\n");
                while (getchar() != '\n');  // Clear input buffer
                break;
            case '+':
                result += number;
                break;
            case '-':
                result -= number;
                break;
            case '*':
                result *= number;
                break;
            case '/':
                if (number != 0) {
                    result /= number;
                } else {
                    printf("Division by zero is not allowed.\n");
                }
                break;
            default:
                printf("Invalid operator.\n");
                break;
        }

        printf("= %.2f\n", result);
    }

    printf("= %.2f\n", result);
    return 0;
}