/**
 *   Løsningsforslag til kontinuasjonseksamen i GrProg (i C), august 2021, oppgave 1A.
 *
 *   @file     EX_S21_1A.CPP
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>
#include <stdbool.h>


/**
 *  Finner og returnerer den største av 3x int-verdier.
 *
 *  @param    a  -  int-verdi nr.1
 *  @param    b  -  int-verdi nr.2
 *  @param    c  -  int-verdi nr.3
 *  @return   Den største av de 3x int-parameter verdiene
 */
int returnerDenStorste(const int a, const int b, const int c) {
    if (a > b  && a > c)  return a;
    if (b > c) return b;
    return c;
}


/**
 *   Hovedprogrammet:
 */
int main() {

   printf("\nStørst av 16,  8,  4 er:  %i\n", returnerDenStorste(16,  8,  4));
   printf("\nStørst av 16,  4,  8 er:  %i\n", returnerDenStorste(16,  4,  8));
   printf("\nStørst av  8, 16,  4 er:  %i\n", returnerDenStorste( 8, 16,  4));
   printf("\nStørst av  4, 16,  8 er:  %i\n", returnerDenStorste( 4, 16,  8));
   printf("\nStørst av  8,  4, 16 er:  %i\n", returnerDenStorste( 8,  4, 16));
   printf("\nStørst av  4,  8, 16 er:  %i\n", returnerDenStorste( 4,  8, 16));

   return 0;
}
