/**
 *   L�sningsforslag til oppgave nr 13.
 *
 *   @file	  OPPG_13.C
 *   @author  Frode Haug, NTNU
 */


#include <stdio.h>                //  printf, scanf

const float PI    = 3.14159;      ///<  Consten 'PI'.
const int   HOYDE = 4;            ///<  Legemets faste h�yde.

/**
 *  Hovedprogrammet:
 */
int main()  {
    int radie;

    printf("Sylinderradier opp til:  ");
    scanf("%i", &radie);

    for (int i = 1;  i <= radie;  i++)   //  L�kken g�r gjennom radiene:
        printf("Sylinder med radie %2i og h�yde %i har volumet: %12f\n",
               i, HOYDE, PI * i * i * HOYDE);

    return 0;
}
