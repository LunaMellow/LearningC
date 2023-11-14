/**
 *   Løsningsforslag til oppgave nr 13.
 *
 *   @file	  OPPG_13.C
 *   @author  Frode Haug, NTNU
 */


#include <stdio.h>                //  printf, scanf

const float PI    = 3.14159;      ///<  Consten 'PI'.
const int   HOYDE = 4;            ///<  Legemets faste høyde.

/**
 *  Hovedprogrammet:
 */
int main()  {
    int radie;

    printf("Sylinderradier opp til:  ");
    scanf("%i", &radie);

    for (int i = 1;  i <= radie;  i++)   //  Løkken går gjennom radiene:
        printf("Sylinder med radie %2i og høyde %i har volumet: %12f\n",
               i, HOYDE, PI * i * i * HOYDE);

    return 0;
}
