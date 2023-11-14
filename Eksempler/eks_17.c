/**
 *   Programeksempel nr 17 - St�rre programeksempel.
 *
 *   som vektlegger:
 *     - l�kker (for, while, do)
 *     - operatorer (relasjon, logiske, artimetiske)
 *     - utskrift/innlesning
 *     - array-bruk
 *     - casting
 *
 *   Programmet:
 *     - leser antall dager i aktuell m�ned
 *     - leser inn min.temp, max.temp og nedb�r for hver dag i m�neden
 *     - oppummerer og regner gjennomsnittet for disse verdiene
 *
 *   @file     EKS_17.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>           //  printf, scanf

const int MINTEMP   = -70;   ///<  Absolutt laveste mulige temperatur.
const int MAXTEMP   =  70;   ///<  Absolutt h�yeste mulige temperatur.
const int MAXNEDBOR = 200;   ///<  Absolutt h�yeste mulige nedb�r pr.d�gn.
const int MINDAGER  =   5;   ///<  Minimum antall dager i en m�ned.
const int MAXDAGER  =  31;   ///<  Maksimum antall dager i en m�ned.

/**
 *  Hovedprogrammet:
 */
int main ()  {
  char svar;                 //  Brukersvar til om vil fortsette eller ei.
  int  antDager,             //  Antall dager i aktuell m�ned.
       min,                  //  Min.temp EN gitt dag.
       max,                  //  Max.temp EN gitt dag.
       nedbor,               //  Nedb�r EN gitt dag.
       totMin,               //  TOTALT min.grader i aktuell m�ned.
       totMax,               //  TOTALT max.grader i aktuell m�ned.
       totNedbor;            //  TOTALT nedb�r i aktuell m�ned.
  int  alleMin[MAXDAGER],    //  ALLE min.temper i m�neden.
       alleMax[MAXDAGER],    //  ALLE max.temper i m�neden.
       alleNedbor[MAXDAGER]; //  ALL nedb�r i m�neden.

  printf("\nLese inn v�rdata for en m�ned (J/n): ");   //  Kj�re programmet?
  scanf(" %c", &svar);

  while (svar != 'N'  &&  svar != 'n') { //  S� lenge �nsker (IKKE svart 'N'):
     do {                    //  Leser antall dager i m�neden (28-31):
        printf("Antall dager i m�neden (%i-%i):  ", MINDAGER, MAXDAGER);
        scanf("%i", &antDager);
     } while (antDager < MINDAGER  ||  antDager > MAXDAGER);

     for (int i = 0;  i < antDager;  i++)  { //  G�r gjennom HELE m�neden:
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

         do {                             //  Leser korrekt nedb�r dag nr.i:
            printf("\tNedb�r (0 til %i): ", MAXNEDBOR);
            scanf("%i", &nedbor);
         } while(nedbor < 0  ||  nedbor > MAXNEDBOR);
         alleNedbor[i] = nedbor;          //  Lagrer unna innlest verdi.
     }

 	 totMin = totMax = totNedbor = 0;          //  Nullstiller totalsummer.
     for (int i = 0;  i < antDager;  i++)  { //  G�r gjennom HELE m�neden:
         totMin    += alleMin[i];            //  Oppsummerer tot.min.
         totMax    += alleMax[i];            //  Oppsummerer tot.max.
         totNedbor += alleNedbor[i];         //  Oppsummerer tot.nedb�r.
     }
                                    //  Skriver gjennomsnitter og EN totalsum:
     printf("\n\nGjennomsnittlig min.temp: %.2f grader C\n",
                                                      (float)totMin/antDager);
   printf("Gjennomsnittlig max.temp: %.2f grader C\n",(float)totMax/antDager);
     printf("Gjennomsnittlig nedb�r:   %.2f mm\n", (float)totNedbor/antDager);
     printf("Total nedb�r i m�neden:   %i mm\n", totNedbor);
                                             //  Kj�re programmet igjen?
     printf("\nLese inn v�rdata for en m�ned til (J/n): ");
     scanf(" %c", &svar);
  }

  printf("\n\n\nHa en fortsatt god (v�r(syk))dag!\n\n");

  return 0;
}
