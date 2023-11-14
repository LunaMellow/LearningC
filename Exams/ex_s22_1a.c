/**
 *   Løsning til kontinuasjonseksamen i GrProg (i C), august 2022, oppgave 1A.
 *
 *   @file     EX_S22_1A.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>
#include <string.h>
//                      1         2         3         4         5
//            012345678901234567890123456789012345678901234567890123456789
char txt[] = "ENDELIG-VAR-DEN-TILBAKELAGTE-SOMMEREN-NOENLUNDE-NORMAL-IGJEN";


int main() {
    int i = 31 / 4, j = 17 - 14 % 2,  k;

    k = strlen(txt) / i;
    printf(" %c %c %c\n", txt[k], txt[j], txt[i]);

    for (i = 0;  i < 60;  i += 15)
        printf(" %c", txt[i]);
    printf("\n");

    i = 14;  j = 36;  k = 59;
    while (txt[i] == txt[j]  &&  txt[j] == txt[k])  {
       i--;  --j;  --k;
    }
    printf(" %c %c %c\n", txt[i], txt[j], txt[k]);

    i = 29;  j = i + 2;
    while (txt[i--] != txt[j++])  ;
    printf(" %c %c\n", txt[i], txt[j]);

    i = 34;   j = 1;
    while (txt[i] >= 'R'  ||  txt[i] < 'H')  {
        i -= 5;  j *=2;
    }
    printf(" %c %c\n", txt[i], txt[j]);

    return 0;
}



//   Utskrift:    V I -
//                E - O D
//                D R J
//                T R
//                N T
