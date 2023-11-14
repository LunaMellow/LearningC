/**
 *   Programeksempel nr 17 - Større programeksempel.
 *
 *   som vektlegger:
 *     - løkker (for, while, do)
 *     - operatorer (relasjon, logiske, artimetiske)
 *     - utskrift/innlesning
 *     - array-bruk
 *     - casting
 *
 *   Programmet:
 *     - leser antall dager i aktuell måned
 *     - leser inn min.temp, max.temp og nedbør for hver dag i måneden
 *     - oppummerer og regner gjennomsnittet for disse verdiene
 *
 *   @file     EKS_17.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>           //  printf, scanf

const int MINTEMP   = -70;   ///<  Absolutt laveste mulige temperatur.
const int MAXTEMP   =  70;   ///<  Absolutt høyeste mulige temperatur.
const int MAXNEDBOR = 200;   ///<  Absolutt høyeste mulige nedbør pr.døgn.
const int MINDAGER  =   5;   ///<  Minimum antall dager i en måned.
const int MAXDAGER  =  31;   ///<  Maksimum antall dager i en måned.

/**
 *  Hovedprogrammet:
 */
int main ()  {
  char svar;                 //  Brukersvar til om vil fortsette eller ei.
  int  antDager,             //  Antall dager i aktuell måned.
       min,                  //  Min.temp EN gitt dag.
       max,                  //  Max.temp EN gitt dag.
       nedbor,               //  Nedbør EN gitt dag.
       totMin,               //  TOTALT min.grader i aktuell måned.
       totMax,               //  TOTALT max.grader i aktuell måned.
       totNedbor;            //  TOTALT nedbør i aktuell måned.
  int  alleMin[MAXDAGER],    //  ALLE min.temper i måneden.
       alleMax[MAXDAGER],    //  ALLE max.temper i måneden.
       alleNedbor[MAXDAGER]; //  ALL nedbør i måneden.

  printf("\nLese inn værdata for en måned (J/n): ");   //  Kjøre programmet?
  scanf(" %c", &svar);

  while (svar != 'N'  &&  svar != 'n') { //  Så lenge ønsker (IKKE svart 'N'):
     do {                    //  Leser antall dager i måneden (28-31):
        printf("Antall dager i måneden (%i-%i):  ", MINDAGER, MAXDAGER);
        scanf("%i", &antDager);
     } while (antDager < MINDAGER  ||  antDager > MAXDAGER);

     for (int i = 0;  i < antDager;  i++)  { //  Går gjennom HELE måneden:
         printf("\nDag nr.%2i:\n", i+1);

         do {                             //  Leser korrekt min.temp dag nr.i:
           printf("\tMinimumstemp (%2i til %2i): ", MINTEMP, MAXTEMP);
           scanf("%i", &min);
         } while(min < MINTEMP ||  min > MAXTEMP);
         alleMin[i] = min;                //  Lagrer unna innlest verdi.

         do {                             //  Leser korrekt max.temp dag nr.i:
            printf("\tMaksimumstemp (%2i til %2i): ", min, MAXTEMP);
            scanf("%i", &max);
         } while(max < min  ||  max > MAXTEMP);
         alleMax[i] = max;                //  Lagrer unna innlest verdi.

         do {                             //  Leser korrekt nedbør dag nr.i:
            printf("\tNedbør (0 til %i): ", MAXNEDBOR);
            scanf("%i", &nedbor);
         } while(nedbor < 0  ||  nedbor > MAXNEDBOR);
         alleNedbor[i] = nedbor;          //  Lagrer unna innlest verdi.
     }

 	 totMin = totMax = totNedbor = 0;          //  Nullstiller totalsummer.
     for (int i = 0;  i < antDager;  i++)  { //  Går gjennom HELE måneden:
         totMin    += alleMin[i];            //  Oppsummerer tot.min.
         totMax    += alleMax[i];            //  Oppsummerer tot.max.
         totNedbor += alleNedbor[i];         //  Oppsummerer tot.nedbør.
     }
                                    //  Skriver gjennomsnitter og EN totalsum:
     printf("\n\nGjennomsnittlig min.temp: %.2f grader C\n",
                                                      (float)totMin/antDager);
   printf("Gjennomsnittlig max.temp: %.2f grader C\n",(float)totMax/antDager);
     printf("Gjennomsnittlig nedbør:   %.2f mm\n", (float)totNedbor/antDager);
     printf("Total nedbør i måneden:   %i mm\n", totNedbor);
                                             //  Kjøre programmet igjen?
     printf("\nLese inn værdata for en måned til (J/n): ");
     scanf(" %c", &svar);
  }

  printf("\n\n\nHa en fortsatt god (vær(syk))dag!\n\n");

  return 0;
}
