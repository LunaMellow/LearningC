/**
 *   Programeksempel nr 1 - Introduserende eksempel til programmering i C.
 *
 *   Med bruk av:
 *     - Inkludere biblioteksfil for I/O
 *     - Hovedprogram
 *     - Heltallsvariabler
 *     - Tilordning
 *     - Aritmetikk
 *     - Utskrift
 *
 *   @file     EKS_01.C  (nesten identisk til Program 2.6 i læreboka)
 *   @author   Stephen G.Kochan  /  Frode Haug, NTNU
 */


#include <stdio.h>                //  printf


/**
 *  Hovedprogrammet:
 */
int main()  {                     //  ALLE program MÅ ha EN 'main'.
                                  //  Blokker omsluttes av '{'  og '}.
    int value1, value2, sum;      //  Definerer 3x heltallsvariable.
                                  //  Programsetninger avsluttes med ';'
                                  //  Ofte EN programsetning pr.linje.

    value1 = 50;                  //  Gir 2x av variablene verdier.
    value2 = 25;
    sum = value1 + value2;        //  Foretar summasjon inn i den tredje.

                                  //  Utskrift av resultatet:
                                  //  %i angir at skal erstattes av en 'int'.
    printf("The sum of %i and %i is %i\n", value1, value2, sum);

    return 0;                     //  Avslutter programmet.


                      //  Noen viktige poenger:
                      //  =====================

                      //  Primært brukes SMÅ bokstaver i SPRÅKET,
                      //              og det er FORSKJELL på store og små.

                      //  Blanke, tab og linjeskift ignoreres av kompilatoren.

                      //  '#' er preprosessordirektiv (flere andre finnes).
}
