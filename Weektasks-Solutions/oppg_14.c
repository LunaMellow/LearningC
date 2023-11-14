/**
 *   Løsningsforslag til oppgave nr 14.
 *
 *   @file	  OPPG_14.C
 *   @author  Frode Haug, NTNU
 */


#include <stdio.h>                //  printf, scanf

/**
 *  Hovedprogrammet:
 */
int main()  {
    int antallLest = 0,           //  Antall tall lest inn.
        tall,                     //  Siste innleste tall/verdi.
        totalSum = 0;             //  Totalsummen av alle tallene.

     printf("\nSkriv ett tall (negativt for å avslutte):  ");
     scanf("%i", &tall);          //  Leser ett tall.

     while (tall > 0)  {          //  Så lenge et positivt tall:
        ++antallLest;             //  Teller opp antall tall  lest.
        totalSum += tall;         //  Øker totalsummen.
        printf("Skriv ett tall (negativt for å avslutte):  ");
        scanf("%i", &tall);       //  Leser enda ett tall.
     }

     printf("\n\n\n");            //  Utskrift og utregning:
     printf("Antall tall lest:   %i\n",   antallLest);
     printf("Deres totalsum:     %i\n",   totalSum);
     printf("Deres gjennomsnitt: %f\n\n", (float)totalSum/antallLest);
                                 //  NB: Det siste går "galt" om antallLest=0!
     return 0;
}
