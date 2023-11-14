/**
 *   Programeksempel nr 16 - Flerdimensjonal array.
 *
 *   @file     EKS_16.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>             //  printf, scanf

/**
 *  Hovedprogrammet:
 */
int main ()  {
    int i, j,                                   //  Løkkevariable.
        sum = 0;                                //  Sum av antall dobesøk.
    int tall[3][4] =  { {  1,  2,  3,  4 },     //  Initierer to-dimensjonal
                        {  5,  6,  7,  8 },     //    int-array:
                        {  9, 10, 11, 12 } };
                                         //  Skriver noe utvalgte elementer:
    printf("Element [0][0] i 'tall' er: %i\n",   tall[0][0]); //   1
    printf("Element [1][2] i 'tall' er: %i\n",   tall[1][2]); //   7
    printf("Element [2][3] i 'tall' er: %i\n\n", tall[2][3]); //  12


    for (i = 0;  i < 3;  i++)  {         //  Skriver HELE den to-dimensjonale
        for (j = 0;  j < 4;  j++)        //    arrayens innhold/verdier:
            printf("%5i", tall[i][j]);
        printf("\n");                    //  Linjeskrift etter hver linje/rad.
    }

    printf("\n\n");


// ***************************************************************************
                                         //  Initierer array av/med tekster:
    char ukedager[7][5] = {"Man", "Tirs", "Ons", "Tors", "Fre", "Lør", "Søn"};
                                         //  Skriver noe utvalgte elementer:
    printf("Element [0][0] i 'ukedager' er: %c\n",   ukedager[0][0]); //  M
    printf("Element [1][2] i 'ukedager' er: %c\n",   ukedager[1][2]); //  r
    printf("Element [3][3] i 'ukedager' er: %c\n\n", ukedager[3][3]); //  s

    for (i = 0;  i < 7;  i++)            //  Skriver alle linjene/tekstene:
        printf("Ukedag nr.%i er %sdag\n", i+1, ukedager[i]); //  NB: BARE EN
                                                             //      INDEKS!
    printf("\n\n");


// ***************************************************************************

    int  dobesok[7][3];                  //  2x nye to-dimensjonale arrayer:
    char steder[3][15]  = { "Hjemme", "Jobb", "Andre steder" };

    printf("\n\nBLÆREKATARR-STATISTIKK:");
    for (i = 0;  i < 7;  i++)  {                     //  For hver ukedag:
        printf("\n\tAntall dobesøk %sdag\n", ukedager[i]);  //  Skriver navn.
        for (j = 0;  j < 3;  j++)  {                 //  For hvert sted:
            printf("\t\t%-12s: ", steder[j]);               //  Skriver sted.
            scanf("%i", &dobesok[i][j]);       //  Leser til aktuelt element.
        }
    }

    for (i = 0;  i < 7;  i++)                //  Summerer ALT i HELE arrayen:
        for (j = 0;  j < 3;  j++)
            sum += dobesok[i][j];
                                             //  Skriver denne summen:
    printf("\n\nTotalt antall dobesøk i løpet av uka: %i\n\n", sum);

    return 0;
}
