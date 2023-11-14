/**
 *   Løsningsforslag til oppgave nr 19.
 *
 *   @file	  OPPG_19.C
 *   @author  Frode Haug, NTNU
 */


#include <stdio.h>                //  printf

const int TALLEN = 20;            ///<  Max. antall tall å håndtere.
/**
 *  Hovedprogrammet:
 */
int main()  {
    int  tall[TALLEN];                       //  De innleste tallene.
    int  antallTall[5] = { 0, 0, 0, 0, 0 };  //  Nullstiller intervallantallet.

    printf("\nDet skal nå skrives inn %i tall:\n\n", TALLEN);

    for (int i = 0;  i < TALLEN;  i++)  {    //  Leser inn alle tallene:
        do  {
          printf("\tSkriv inn tall nr.%3i (1-100):  ", i+1);
          scanf("%i", &tall[i]);
        } while (tall[i] < 1  ||  tall[i] > 100);  //  Sikrer rett intervall.
    }

    for (int i = 0;  i < TALLEN;  i++)       //  Går gjennom alle igjen,
        if (tall[i] <= 20)                   //    og teller opp antallet i
            antallTall[0]++;                 //    hvert intervall:
        else if (tall[i] <= 40)
            antallTall[1]++;
        else if (tall[i] <= 60)
            antallTall[2]++;
        else if (tall[i] <= 80)
            antallTall[3]++;
        else
            antallTall[4]++;

    printf("\n\n");

    for (int i = 0;  i < 5;  i++)  {         //  Går gjennom intervallene:
        printf("Antall tall i intervallet ");
        if (i == 0)                          //  Skriver intervallgrensene:
            printf(" 1 -  20");
        else if (i == 1)
            printf("21 -  40");
        else if (i == 2)
            printf("41 -  60");
        else if (i == 3)
            printf("61 -  80");
        else
            printf("81 - 100");
        printf(":  %i\n", antallTall[i]);  //  Skriver antallet i intervallet.
    }

    return 0;
}
