/**
 *   Programeksempel nr 6 - Grunnleggende om (int-)array.
 *
 *   @file     EKS_06.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>                //  printf

/**
 *  Hovedprogrammet:
 */
 int main ()  {
    int   heltall,  heltall2;     //  Har hittil laget/brukt slike
                                  //    ENKELTVARIABLE.

                                  //  NÅ:
    int  itall[10];               //  Lager 10 stk(!) int-variable.
                                  //  Med indeks/nummer 0-9 (IKKE nr.10!):
                                  //  itall[0], itall[1], ...., itall[9]


    itall[0] = 982;               //  Tilordning/initiering:
    itall[1] = 737;
    itall[3] = 619;
                                  //  Utskrift av elementer/skuffer:
    printf("3x heltall: %i %i %i\n", itall[0], itall[1], itall[3]);

    printf("2x 'søppel': %i %i\n", itall[2], itall[9]);

                                  //  Mer tilordning/initiering:
    itall[2] = 13;   itall[4] = 97;  itall[5] = 31;

    itall[6] = itall[4] + itall[5];    //  Kan utføre de vanlige:  + - * / %

    printf("Summen av 'skuff' nr.4 og nr.5: %i \n", itall[6]);

    itall[7] = itall[6] / itall[2];

    printf("Divisjonen av 'skuff' nr.6 med nr.2: %i \n", itall[7]);

    itall[7] *= 8;                //  Kan utføre de vanlige:  += -= *= /=  %=

    printf("Multiplikasjon av 'skuff' nr.7 med 8: %i \n", itall[7]);

                                  //  Kan utføre de vanlige:  ++  og  --
    itall[7]++;   ++itall[7];  itall[7]++;   ++itall[7];

    printf("'Skuff' nr.7 økt fire ganger: %i \n", itall[7]);


                                  //  Definerer OG INITIERER:
    int tall[10] = { 34, 7, 29, 12, 9, 0, 76, 123, 98, 90};

    printf("3x heltall: %i %i %i\n", tall[0], tall[7], tall[2]);

                                  //  Definerer og initierer,
                                  //    UTEN Å ANGI LENGDEN:
    int tall2[] = { 24, 56, 18, 13, 7, 49, 18};

    printf("3x heltall: %i %i %i\n", tall2[6], tall2[1], tall2[4]);

                                  //  Definerer og initierer,
                                  //    MEN BARE NOEN av elementene:
    int tall3[20] = { 24, 56, 18, 13, 7, 49, 18, [13] = 88, [17] = 42};

    printf("3x heltall: %i %i %i\n", tall3[1], tall3[13], tall3[17]);


//  Kan gjøre tilsvarende tilordninger og regneoperasjoner
//  (unntatt ++ og --)  med 'float'.

//  'char'-arrayer:  EKS_07.C

//  Kan også lage 'bool'-arrayer (mer om dette senere en gang).

    return 0;
}
