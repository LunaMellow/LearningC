/**
 *   Løsningsforslag til oppgave nr 23.
 *
 *   @file	  OPPG_23.C
 *   @author  Frode Haug, NTNU
 */

#include <stdio.h>           //  printf

int summerKvadrater(const int tall, const int tall2, const int tall3);

/**
 *  Hovedprogrammet:
 */
int main()  {

    int t1, t2, t3,                      //  3x tall som skal kvadratsummeres.
        sum;                             //  Kvadratsummen av de 3x tallene.

    t1 = 1;     t2 = 2;     t3 = 3;
    sum = summerKvadrater(t1, t2, t3);
    printf("Kvadratsummen av %3i  %3i  %3i  er:  %6i\n", t1, t2, t3, sum);

    t1 = 6;     t2 = 4;     t3 = 60;
    sum = summerKvadrater(t1, t2, t3);
    printf("Kvadratsummen av %3i  %3i  %3i  er:  %6i\n", t1, t2, t3, sum);

    t1 = 62;     t2 = 6;     t3 = 7;
    sum = summerKvadrater(t1, t2, t3);
    printf("Kvadratsummen av %3i  %3i  %3i  er:  %6i\n", t1, t2, t3, sum);

    t1 = 9;     t2 = 29;     t3 = 91;
    sum = summerKvadrater(t1, t2, t3);
    printf("Kvadratsummen av %3i  %3i  %3i  er:  %6i\n", t1, t2, t3, sum);

    return 0;
}


/**
 *  Summerer sammen kvadratene av 3x parametre.
 *
 *  @param   tall  - 1.tallet
 *  @param   tall2 - 2.tallet
 *  @param   tall3 - 3.tallet
 *
 *  @return  Summen av de 3x tallene kvadrert
 */
int summerKvadrater(const int tall, const int tall2, const int tall3)  {
   return ( (tall*tall) + (tall2*tall2) + (tall3*tall3) );

//  Evt (litt mer detaljert):
//     int svar;
//     svar = (tall*tall) + (tall2*tall2) + (tall3*tall3);
//     return svar;
}
