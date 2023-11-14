/**
 *   Løsning til kontinuasjonseksamen i GrProg (i C), august 2020, oppgave 1A.
 *
 *   @file     EX_S20_1A.CPP
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>


/**
 *  Ber om og leser 3x tall, skriver dem baklengs ut og returnerer deres sum.
 *
 *  @return   Summen av 3x innleste tall
 */
int lesSkrivOgReturnerTall() {
    int tall1, tall2, tall3;
    printf("Skriv inn tre heltall:  ");
    scanf("%i %i %i", &tall1, &tall2, &tall3);
    printf("Disse skrevet baklengs:  %i %i %i\n", tall3, tall2, tall1);
    return (tall1 + tall2 + tall3);
}


/**
 *   Hovedprogrammet:
 */
int main() {

    printf("\n\nTallenes sum er: %i\n\n", lesSkrivOgReturnerTall());

    return 0;
}