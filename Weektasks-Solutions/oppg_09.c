/**
 *   Løsningsforslag til oppgave nr 9.
 *
 *   @file	  OPPG_09.C
 *   @author	Frode Haug, NTNU
 */


#include <stdio.h>                //  printf

/**
 *  Hovedprogrammet:
 */
int main()  {
    int totaltSekunder =  312304,
        timer,  minutter, sekunder;

    timer    = totaltSekunder / 3600;         //  1 time = 3600 sekunder.
    minutter = (totaltSekunder % 3600) / 60;  //  "Tar vekk" timer og sekunder.
    sekunder = totaltSekunder % 60;           //  Total rest er sekunder.

    printf("%i sekunder tilvarer: %i time(r), %i minutt(er) og %i sekund(er)\n\n",
            totaltSekunder, timer, minutter, sekunder);

    return 0;
}
