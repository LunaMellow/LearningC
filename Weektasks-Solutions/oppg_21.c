/**
 *   Løsningsforslag til oppgave nr 21.
 *
 *   @file	  OPPG_21.C
 *   @author  Frode Haug, NTNU
 */


#include <stdio.h>                 //  printf

void skrivTid(int time, int min, int sek);

/**
 *  Hovedprogrammet:
 */
int main()  {

    skrivTid(17, 25, 42);
    skrivTid(21, 18, 17);
    skrivTid( 4,  8, 12);
    skrivTid( 9, 37,  6);
    skrivTid( 7,  2,  4);

    return 0;
}


/**
 *  Skriver tid på formatet tt:mm:ss, og dette omgjort til sekunder.
 *
 *  @param   time - Time
 *  @param   min  - Minutter
 *  @param   sek  - Sekund
 */
void skrivTid(int time, int min, int sek)  {
  int totalSekunder = (time*3600) + (min*60) + sek;  //  Regner ut totalt sek.
  printf("Tiden %i:", time);
  if (min < 10) printf("0");   printf("%i:", min);   //  Skriver evt.
  if (sek < 10) printf("0");   printf("%i", sek);    //    innledende '0':
  printf("  er i sekunder:  %i\n\n", totalSekunder);
}
