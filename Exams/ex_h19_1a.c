/**
 *   Løsning til eksamen i GrProg (i C), november 2019, oppgave 1A.
 *
 *   @file     EX_H19_1A.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>
#include <string.h>

char txt[] = "DETTE-ER-DEN-ALLER-ALLER-FORSTE-EKSAMEN-I-DETTE-NYE-EMNET-PAA-NTNU";

int main() {
    int i = 41 / 3,    j = 1 + 6 * 3,    k = 0,    n = strlen(txt);

    while (txt[i++] == txt[j])
        printf("%c", txt[j++]);
    printf("\n");

    printf("%c %c %c\n", txt[i], txt[i + 3], txt[j]);

    for (i = 1;  i <= n;  i++)
        if (txt[i - 1] == 'E')  k++;
    printf("%i\n", k);

    i = n % 8;    j = (5 * 6) % 9;    k = i * j;
    printf("%c %c %c\n", txt[i - 1], txt[j - 1], txt[k + 3]);

    while (txt[j] != txt[k])  {
        printf(" %c", txt[j]);   j += i;    k += i;    j++;
    }
    printf("\n");

    return 0;
}


//   Utskrift:    ALLER-
//                L R F
//                14
//                E T D
//                 T E D
