/**
 *   L�sningsforslag til oppgave nr 32.
 *
 *   @file	  OPPG_32.C
 *   @author  Frode Haug, NTNU
 */


#include <stdio.h>                 //  printf

const int ARRLEN = 20;             ///<  Array-lengde.

/**
 *  Hovedprogrammet:
 */
int main()  {
    int  tall[ARRLEN];       //  Definerer int-array med "s�ppel".
                             //  Lager en passende tekst med bokstavene ABCDE:
    char tekst[] = "ABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDABBCDEEDCBBAABED";
    int  i,                  //  L�kkevariabel.
         *iPeker;            //  Peker til int.
    char *cPeker;            //  Peker til char.

    for (i = 0;  i < ARRLEN;  i++)   //  Initierer int-array til 'indejs+10':
        tall[i] = i + 10;

    printf("\n'tall' f�r:   ");      //  Skriver arrayens n�v�rende verdier:
    for (i = 0;  i < ARRLEN;  i++)
       printf("  %i", tall[i]);

    iPeker = tall;                   //  Setter peker til arrayens start.
    for (i = 0;  i < ARRLEN;  i++)   //  Ganger alle arrayens elementer med 2
        *(iPeker+i) *= 2;            //    ved � bruke pekeren + litt lengre uti.

    printf("\n'tall' etter: ");
    for (i = 0;  i < ARRLEN;  i++)   //  Skriver hele arrayens nye verdier
       printf("  %i", *(iPeker+i));  //    ogs� vha. pekeren.

    printf("\n\n");


 // **************************************************************************

    printf("Teksten f�r:    %s\n", tekst);  //  Skriver char-arrayen/teksten.
    cPeker = tekst;                         //  Initierer peker til tekstens start.

    while (*cPeker)  {                      //  G�r gjennom teksten frem til '\0':
      if   (*cPeker == 'C')    *cPeker = 'X';  //  Bytter ALLE 'C' med 'X'
      else if (*cPeker == 'E') *cPeker = '8';  //    OG ALLE 'E' med '8'.
      cPeker++;                             //  �ker pekeren til det neste tegnet.
    }

    printf("Teksten etter:  ");
    cPeker = tekst;                         //  Resetter pekeren til starten igjen.
    while (*cPeker)                         //  G�r gjennom teksten frem til '\0':
        printf("%c", *cPeker++);            //  Skriver tegnet og �ker til neste tegn.


    printf("\n\n");

    return 0;
}
