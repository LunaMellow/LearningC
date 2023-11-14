/**
 *   Løsning til eksamen i GrProg (i C), august 2023, oppgave 1A.
 *
 *   @file     EX_S231A.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>


char txt[] = "NAA-ER-ENDELIG-SOMMEREN-SLUTT-OG-STUDIENE-KAN-STARTE-IGJEN";


int main() {
    int i = 18, j = i % 5, k = i / j;
    do {
        printf("%c %c\n", txt[i], txt[i + j]);
        i += k;   j *= 2;
    } while (i <= 30);

    i = j = k = 12 - 3 * 2;
    while (k  <  i * j) {
        printf("%c %c\n", txt[k], txt[k * 5 / 3]);
        k += 15;
    }

    return 0;
}


//   Utskrift:    M E
//                S O
//                O K
//                - E
//                E U
