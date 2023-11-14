/**
 *   Løsningsforslag til oppgave nr 10.
 *
 *   @file	  OPPG_10.C
 *   @author	Frode Haug, NTNU
 */


#include <stdio.h>                //  printf

/**
 *  Hovedprogrammet:
 */
int main()  {
    char   tegn1 = 'F',           //  Initierer variable til angitte verdier:
           tegn2 = 'H';
    float  flyt1 = 17.52,
           flyt2 = 451.87;
                                  //  Skriver variablene baklengs:
    printf("Tegn2: %c   Tegn1: %c   Flyt2: %f   Flyt1: %f\n",
           tegn2, tegn1, flyt2, flyt1);
                                  //  Eksponentiell versjon av 'flyt2':
    printf("Tegn2 eksponentielt: %e\n", flyt2);
                                  //  Kun heltallsdelen av float'ene:
    printf("Heltallsdelen av Flyt1: %i   og av Flyt1: %i\n",
           (int) flyt1, (int) flyt2);
                                  //  Caster 'char' til 'int'. Får da dets
                                  //    nummer/indeks i tegn-tabellen:
    printf("Tabellnummer-verdien til Tegn1:  %i\n", (int) tegn1);
                                  //  'A' = 65, 'B' = 66, 'C' = 67, .....
    printf("Tabellnummer-verdien til Tegn1:  %i\n", (int) 'b');
                                  //  'a' = 97, 'b' = 98, 'c' = 99, .....

    return 0;
}
