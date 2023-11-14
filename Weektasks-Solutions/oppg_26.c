/**
 *   Løsningsforslag til oppgave nr 26.
 *
 *   @file	  OPPG_26.C
 *   @author  Frode Haug, NTNU
 */


#include <stdio.h>                 //  printf, scanf


/**
 *  En dato (med dag, måned og år).
 */
struct Dato  {
   int  dag,
        maaned,
        aar;
};


/**
 *  Hovedprogrammet:
 */
int main()  {
    struct Dato dato, dato2;       //  Definerer 2x Dato-variable.
                                   //  Leser inn data i begge disse structene:
    printf("Dato nr.1\t - Dag (1-31):      ");  scanf("%i", &dato.dag);
    printf("\t\t - Måned (1-12):    ");         scanf("%i", &dato.maaned);
    printf("\t\t - År (2000-2030):  ");         scanf("%i", &dato.aar);
    printf("\n");
    printf("Dato nr.2\t - Dag (1-31):      ");  scanf("%i", &dato2.dag);
    printf("\t\t - Måned (1-12):    ");         scanf("%i", &dato2.maaned);
    printf("\t\t - År (2000-2030):  ");         scanf("%i", &dato2.aar);
    printf("\n\n");
                                   //  Skriver hvilken dato som har laveste år:
    if      (dato.aar < dato2.aar)  printf("Dato nr.1 kommer før dato nr.2");
    else if (dato2.aar < dato.aar)  printf("Dato nr.2 kommer før dato nr.1");
    else printf("Datoene er eksakt samme år!");
    printf("\n\n");

    return 0;
}
