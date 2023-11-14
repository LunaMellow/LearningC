/**
 *   Programeksempel nr 15 - Do-løkke.
 *
 *   @file     EKS_15.C
 *   @author   Frode Haug, NTNU
 *             (noe er basert på Program 4.9 av Stephan G.Kochan)
 */


#include <stdio.h>              //  printf, scanf

/**
 *  Hovedprogrammet:
 */
int main ()  {
    int distanse;               //  Lovlig distanse i et skøyteløp.

    do  {
      printf("\nSkriv en skøytedistanse (500, 1500, 3000, 5000, 10000):  ");
      scanf("%i", &distanse);   //  Leser en distanse.
    } while (distanse != 500   &&  distanse != 1500 &&  distanse != 3000  &&
             distanse != 5000  &&  distanse != 10000);  //  Gjentar til lovlig.
                                //  Skriver den godtatt (til slutt):
    printf("\nInnlest og godtatt distanse:  %i\n\n\n", distanse);


//*******************************************************************

    int tall,                 //  Innlest tall/verdi.
        sisteSiffer,          //  Kun bakerste/siste siffer i 'tall'.
        sum = 0;              //  Summen av alle sifrene (=tverrsummen).

    printf("Skriv et tall (int): ");
    scanf("%i", &tall);       //  Leser inn tall/verdi fra brukeren.

    do  {
      sisteSiffer = tall % 10;  //  Henter/finner bakerste siffer.
      sum += sisteSiffer;       //  Summerer opp ett og ett siffer.
      tall /= 10;               //  Tar vekk bakerste siffer.
    } while (tall != 0);        //  Så lenge noe tall igjen.
                                //  Skriver sluttsummen:
     printf("\nSummen av sifrene i tallet er:  %i\n\n", sum);


//  KONKLUSJON:   do-løkke går EN eller flere ganger.

    return 0;
}
