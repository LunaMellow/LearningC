/**
 *   Løsningsforslag til oppgave nr 7.
 *
 *   @file	  OPPG_07.C
 *   @author	Frode Haug, NTNU
 */


#include <stdio.h>                //  printf

/**
 *  Hovedprogrammet:
 */
int main()  {
    int   tall1 = 4,              //  Lager og delvis initierer ulike
          tall2 = 12,             //    heltalls- og flyttals-variable:
          tall3 = 25,
          sum, kvadratSum;
    float flyt1 = 4.2,
          flyt2 = 8.6,
          gjsnittSum, gjsnittKvadrat;

    sum = tall1 + tall2 + tall3;  //  Beregner og skriver sum av heltall:
    printf("%i + %i + %i = %i\n", tall1, tall2, tall3, sum);

                                  //  Beregner og skriver gj.snitt av heltall:
    gjsnittSum = sum / 3.0;       //   (deler med 3.0 så svaret blir en float)
    printf("Gjennomsnittet av disse tallene: %f\n", gjsnittSum);

                                  //  Beregner og skriver kvadratsum:
    kvadratSum = (tall1 * tall1) + (tall2 * tall2) + (tall3 * tall3);
    printf("Summen av deres kvadrater: %i\n", kvadratSum);

                                  //  Beregner og skriver gj.snitt av kv.sum:
    gjsnittKvadrat = kvadratSum / 3.0;   //  3.0 for å få float-regnestykke.
    printf("Gjennomsnittet av deres kvadrater: %f\n", gjsnittKvadrat);

                                 //  Beregner og skriver sj.snitt av 2x float:
                                 //   Så lenge regnestykket består av float,
                                 //   så holder det å dele med 2 (int)
                                 //   - svaret blir jo en float.
    printf("Gjennomsnittet av de to float'ene: %f\n",  (flyt1 + flyt2) / 2);

    return 0;
}
