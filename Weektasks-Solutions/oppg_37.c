/**
 *   Løsningsforslag til oppgave nr 37.
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
    FILE* innfil = fopen("METEOROLOG.DTA", "r"); //  Åpner aktuell fil.
                           //  Filformat:
                           //  <dagnr>    <min.temp>    <max.temp>    <nedbør>

    if (innfil)  {                   //  Filen er funnet:
       printf("\n\nLeser fra filen 'METEOROLOG.DTA' .....\n\n\n");

       fscanf(innfil, "%i", &dagNr); //  PRØVER Å LESE STARTEN PÅ 1.LINJE.
       while (!feof(innfil))  {      //  Klarte det - IKKE slutt på filen:
                                     //  Leser 3x andre verdier på samme linje:
         fscanf(innfil, "%i %i %i", &minT, &maxT, &nedbor);
                                     //  Summerer opp totalene:
         totMin += minT;   totMax += maxT;   totNedb += nedbor;
         antDager++;                 //  Teller opp totalt antall dager innlest.

         fscanf(innfil, "%i", &dagNr); //  PRØVER Å LESE STARTEN PÅ NY LINJE.
       }
                                       //  Beregner og skriver gjennomsnittene:
       printf("\nGjennomsnittlig\n\tMin.temp:  %.1f\n\tMax.temp:  %.1f\n\tNedbør:    %.1f\n\n",
              (float) totMin/antDager,  (float) totMax/antDager,  (float) totNedb/antDager);

    } else                             //  Filen ikke funnet/mulig å åpne:
       printf("Klarte ikke å finne filen 'METEOROLOG.DTA'!\n\n");

    fclose(innfil);                    //  Lukker filen.
}
