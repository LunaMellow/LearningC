/**
 *   Løsningsforslag til oppgave nr 11.
 *
 *   @file	  OPPG_11.C
 *   @author  Frode Haug, NTNU
 */


#include <stdio.h>                //  printf

/**
 *  Hovedprogrammet:
 */
int main()  {                     //  Definerer noen uinitierte og initierte
    int  tall[5],                 //    int- og char-arrayer:
         tall2[]   = { 6, 2, 10, 12, 19, 3, 7};
    char tekst[5],
         navn[]    = "Lars Hansen",
         adresse[] = "Ringgata 111";

    tall[0] = 13;                 //  Gir enkeltelementer verdier:
    tall[1] = 67;
    tall[2] = tall[0] + tall[1];
    printf("tall[2] = %i\n", tall[2]);  //  Skriver utregnet verdi:

    tall[2] /= 2;                 //  Halverer verdien:
    printf("tall[2] = %i\n", tall[2]);

                                  //  Gjør to stk summeringer:
    tall[3] = tall2[0] + tall2[1] + tall2[2] + tall2[3];
    tall[4] = tall2[4] + tall2[5] + tall2[6];   //  Skriver svaret:
    printf("tall[3] og tall[4] er:  %i %i\n", tall[3], tall[4]);

                                  //  Øker variabel fire enkeltganger:
    tall[2]++;  tall[2]++;  tall[2]++;  tall[2]++;
    printf("tall[2] = %i\n", tall[2]);   //  Skriver resultatet.

                                  //  Gir enkeltelementer verdi:
    tekst[1] = 'A';      tekst[3] = 'E';
    tekst[0] = navn[5];  tekst[2] = navn[0];    //  Skriver deres verdier:
    printf("Kua har %c%c%c%c\n", tekst[0], tekst[1], tekst[2], tekst[3]);

                                  //  Skriver "111":
    printf("%c%c%c\n", adresse[9], adresse[10], adresse[11]);

    printf("Navn:    %s\n", navn);      //  Skriver HELE tekster/strenger:
    printf("Adresse: %s\n", adresse);

    return 0;
}
