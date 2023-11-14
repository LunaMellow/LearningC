/**
 *   Løsningsforslag til oppgave nr 35.
 *
 *   @file	  OPPG_35.C
 *   @author  Frode Haug, NTNU
 */


#include <stdio.h>                 //  printf
#include <stdlib.h>                //  sizeof, malloc, free

const int  ARRLEN = 25;            ///<  Max. array-lengde (int, char).

/**
 *  Hovedprogrammet:
 */
int main()  {
    int   i;                       //  Løkkevariabel.
    int*  tall;                    //  Peker (etterhvert) til int-array.
    char* tegn;                    //  Peker (etterhvert) til char-array.


    tall = (int*) malloc(ARRLEN * sizeof(int)); //  Allokerer int-array-plass.

    for (i = 0;  i < ARRLEN;  i++) //  Fyller med kvadratet av eget elementnr.
        tall[i] = i * i;

    printf("int-array: ");         //  Skriver arrayens innhold:
    for (i = 0;  i < ARRLEN;  i++)
        printf(" %i", tall[i]);
    printf("\n\n");

    free(tall);                    //  Frigir allokert memory.


// ***************************************************************************

    tegn = (char*) malloc(ARRLEN * sizeof(char)); //  Allokerer char-array-plass.

    for (i = 0;  i < ARRLEN-1;  i++)           //  Fyller array med ABCDEFG....
        tegn[i] = (char) ('A' + i);
    tegn[ARRLEN-1] = '\0';                     //  Legger til avsluttende '\0'.

    printf("char-array/tekst:  %s\n\n", tegn); //  Skriver teksten/char-array:

    free(tegn);                                //  Frigir allokert memory.

    return 0;
}
