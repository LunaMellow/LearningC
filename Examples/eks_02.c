/**
 *   Programeksempel nr 2 - Introduserende eksempel til programmering i C.
 *
 *   Med bruk av:
 *     - Samme som i EKS_01.c
 *     - Enkle aritmetiske operasjoner ( + * / )
 *     - Bruk av parenteser i regneuttrykk
 *     - Operatorpresedens
 *     - Desimaler ved heltallsdivisjon
 *     - Bruk av tabulator og linjeskift i utskrift
 *
 *   @file     EKS_02.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>                //  printf


/**
 *  Hovedprogrammet:
 */
int main()  {
    int value1, value2 = 10, sum; //  3x heltallsvariable - initierer den ene.

//  Eller:
//     int value1;
//     int value2 = 10;
//     int sum;
//
//  Eller:
//     int value1,
//         value2 = 10,
//         sum;

                                  //  Utskrift, der 2x inneholder "søppel":
    printf("The sum of %i and %i is %i\n", value1, value2, sum);

    value1 = 20;                  //  Gir 'value1' verdi.

    sum = value1 + (value2 * 3);  //  Litt aritemetkk med/uten parenteser:
    printf("The sum of %i and %i*3 is %i\n", value1, value2, sum);

    sum = value1 + value2 * 3;
    printf("The sum of %i and %i*3 is %i\n", value1, value2, sum);

    sum = (value1 / 3) + (value2 * 3);
    printf("The sum of %i/3 and %i*3 is %i\n", value1, value2, sum);

    sum = value1 / 3 + value2 * 3;
    printf("The sum of %i/3 and %i*3 is %i\n", value1, value2, sum);

    sum = (value1 / 3 + value2) * 3;
    printf("The sum of (%i/3 and %i)*3 is %i\n", value1, value2, sum);

                          //  Konklusjon: '*' og '/' utføres fra venstre
                          //              mot høyre FØR '+' og '-' (om ikke
                          //              annet er angitt ved parentesbruk).
                          //
                          //              Heltallsdivisjon avrundes IKKE opp,
                          //              desimalene mistes/blir bare borte
                          //              (altså ingen avrunding oppover).
                          //
                          //              %d KAN brukes i stedet for %i.
                          //              I dette emnet brukes konsekvent %i.

                          //  Bruk av tabulator ('\t') og linjeskift ('\n'):
    printf("\n\n\t\tInnrykket tekst over");
    printf("\nflere\n\tlinjer\n\n!!!!\n---\n\n");

                          //  Eller EKSAKT ALT det samme i EN setning:
    printf("\n\n\t\tInnrykket tekst over\nflere\n\tlinjer\n\n!!!!\n---\n\n");

    return 0;
}
