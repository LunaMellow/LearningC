/**
 *   L�sningsforslag til oppgave nr 37.
 *
 *   @file	  OPPG_37.C
 *   @author  Frode Haug, NTNU
 */


#include <stdio.h>                 //  printf, FILE


/**
 *  Hovedprogrammet:
 */
int main()  {
    int  dagNr, minT, maxT, nedbor,
         antDager = 0,
         totMin = 0,
         totMax = 0,
         totNedb = 0;
    FILE* innfil = fopen("METEOROLOG.DTA", "r"); //  �pner aktuell fil.
                           //  Filformat:
                           //  <dagnr>    <min.temp>    <max.temp>    <nedb�r>

    if (innfil)  {                   //  Filen er funnet:
       printf("\n\nLeser fra filen 'METEOROLOG.DTA' .....\n\n\n");

       fscanf(innfil, "%i", &dagNr); //  PR�VER � LESE STARTEN P� 1.LINJE.
       while (!feof(innfil))  {      //  Klarte det - IKKE slutt p� filen:
                                     //  Leser 3x andre verdier p� samme linje:
         fscanf(innfil, "%i %i %i", &minT, &maxT, &nedbor);
                                     //  Summerer opp totalene:
         totMin += minT;   totMax += maxT;   totNedb += nedbor;
         antDager++;                 //  Teller opp totalt antall dager innlest.

         fscanf(innfil, "%i", &dagNr); //  PR�VER � LESE STARTEN P� NY LINJE.
       }
                                       //  Beregner og skriver gjennomsnittene:
       printf("\nGjennomsnittlig\n\tMin.temp:  %.1f\n\tMax.temp:  %.1f\n\tNedb�r:    %.1f\n\n",
              (float) totMin/antDager,  (float) totMax/antDager,  (float) totNedb/antDager);

    } else                             //  Filen ikke funnet/mulig � �pne:
       printf("Klarte ikke � finne filen 'METEOROLOG.DTA'!\n\n");

    fclose(innfil);                    //  Lukker filen.
}
