/**
 *   L�sningsforslag til oppgave nr 17.
 *
 *   @file	  OPPG_17.C
 *   @author  Frode Haug, NTNU
 */


#include <stdio.h>                //  printf, scanf
#include <ctype.h>                //  toupper

const int MAXLOPERE = 10;         ///<  Max. antall l�pere � lese tider for.

/**
 *  Hovedprogrammet:
 */
int main()  {
    int   distanse,               //  Aktuell distanse.
          ant500,                 //  'distanse' best�r av 'ant500' 500-metre.
          min, sek, hundr,        //  Minutt, sekund og hundredeler.
          antallLopere;           //  Antall l�pere det beregnes poengsum for.
    float poeng;                  //  Poengsummen p� distansen.
    char  brukerSvar;             //  Bruker�nske om � gjenta hele programmet.

    do  {
      do  {
        printf("\nSkriv en sk�ytedistanse (500, 1500, 3000, 5000):  ");
        scanf("%i", &distanse);     //  Leser en distanse.
      } while (distanse != 500   &&  distanse != 1500 &&
               distanse != 3000  &&  distanse != 5000); // Gjentar til lovlig.

      ant500 = distanse / 500;      //  Beregner antall 500-metre i distansen.

      do  {
        printf("\nAntall l�pere � lese tider for (1-%i): ", MAXLOPERE);
        scanf("%i", &antallLopere);  //  Leser inntil lovlig l�perantall:
      } while (antallLopere < 1  ||  antallLopere > MAXLOPERE);

      for (int i = 1;  i <= antallLopere;  i++)  {    //  For hver l�per:
          do  {
            printf("\nTid (mm ss hh):  ");
            scanf("%i%i%i", &min, &sek, &hundr);    //  Leser POSITIVE verdier
          } while (min < 0  ||  sek < 0  || hundr < 0);  //   i tiden.
                                                    //  Beregner poengsummen:
          poeng =  ((min*60) + sek + (hundr/100.0)) / ant500;
          printf("\tPoengsum:  %.3f", poeng); // Skriver denne, med 3 desimaler.
      }

      printf("\n\nLese tider om en ny distanse (j/N):  ");
      scanf(" %c", &brukerSvar);
      brukerSvar = toupper(brukerSvar);
    } while (brukerSvar == 'J');              //  Gjenta HELE proogrammet?

    return 0;
}
