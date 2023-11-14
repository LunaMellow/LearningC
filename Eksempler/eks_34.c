/**
 *   Programeksempel nr 34 - Viser bruken av funksjonene på 'LesData.h'.
 *
 *   @file     EKS_34.C
 *   @author   Frode Haug, NTNU
 */


#include  <stdio.h>              //  printf
#include  "LesData.h"            //  Verktøykasse for lesing av diverse data.

#define  STRLEN  80              ///<  Max. tekstlengde.

/**
 *  Hovedprogrammet:
 */
int main () {
   char  tegn;
   float fTall;
   int   iTall;
   char  buffer[STRLEN];
   char* tekst;
                          //  Viser bruken av verktøykassens ulike funksjoner:

   tegn  = lesChar("Ett tegn");
                              printf("\tInnlest tegn:      %c\n\n", tegn);

   fTall = lesFloat("Flyttall", 2.7,  388.7);
                              printf("\tInnlest flyttall:  %.2f\n\n", fTall);

   iTall = lesInt("Heltall", 0, 200);
                              printf("\tInnlest heltall:   %i\n\n", iTall);

   lesText("Tekst", buffer, STRLEN);
                              printf("\tInnlest tekst:     -%s-\n\n", buffer);

   tekst = lagOgLesText("Annen tekst");
                              printf("\tInnlest tekst:     -%s-\n\n", tekst);
   free(tekst);           //  Frigir memory som funksjonen allokerte/avsatte.

   return 0;
}
