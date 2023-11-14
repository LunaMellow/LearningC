/**
 *   Løsning til eksamen i GrProg (i C), november 2021, oppgave 1A.
 *
 *   @file     EX_H21_1A.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>
#include <string.h>
//                      1         2         3         4         5
//            012345678901234567890123456789012345678901234567890123
char txt[] = "ENDELIG-KAN-VI-HA-FYSISK-UNDERVISNING-PAA-SKOLEN-IGJEN";


int main() {
    int i = 43 / 4, j = 12 + 2 * 2,  k;

    k = strlen(txt) / j;
    printf(" %c %c %c\n", txt[i], txt[j], txt[k]);

    do  {
      printf(" %c", txt[i]);
    } while (++i < j);
    printf("\n");

    i = 17 / 3;  j = 17 % 6;
    for (k = i;  k <= 32;  k += j)
        printf(" %c", txt[k]);
    printf("\n");

    i = 17;  j = 29;
    while (i < j) {  i++;  j--;  };
    printf(" %c %c\n", txt[i], txt[j]);

    i = 17;  j = 29;
    while (i++ < j--) ;
    printf(" %c %c\n", txt[i], txt[j]);

    return 0;
}



//   Utskrift:    N A E
//                N - V I - H
//                I N H S U V
//                K K
//                - S
