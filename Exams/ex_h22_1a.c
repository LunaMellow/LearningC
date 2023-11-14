/**
 *   Løsning til eksamen i GrProg (i C), desember 2022, oppgave 1A.
 *
 *   @file     EX_H22_1A.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>
#include <string.h>
//                      1         2         3         4         5
//            01234567890123456789012345678901234567890123456789012
char txt[] = "SAMMENKOMSTER-SAMMEN-SAMLER-SALMER-OG-SANGER-SANNELIG";


int main() {
    int i = 7,  j = i*2,  k = i*3;

    while (txt[i] != '\0')  {
        if (txt[i] == 'S') printf("%c ", txt[i+2]);
        ++i;
    }
    printf("\n");

    i +=10;  i %= 9;
    while (txt[i] == txt[j]  &&  txt[j] == txt[k])  {
        i++;  ++j;  ++k;
    }
    printf("%c %c %c\n", txt[i], txt[j], txt[k]);

    char* t = txt;
    k = strlen(txt)-3;  j = 0;
    for (i = 0;  i < k;  i++, t++)
        if (!strncmp(t, "SAM", 3) ||  !strncmp(t, "SAN", 3)) j++;
    printf("%i\n", j);

    i = j = k/2;
    while (txt[--i] != txt[++j])  ;
    printf("%i %i\n", i, j);

    t = &txt[j-i];
    if (strncmp(t, txt, 6)) printf("Martin\n"); else printf("Odegaard\n");

    return 0;
}



//   Utskrift:    E M M L N N
//                M M L
//                5
//                18 32
//                Odegaard
