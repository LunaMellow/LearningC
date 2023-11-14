/**
 *   Løsningsforslag til oppgave nr 4.
 *
 *   @file	  OPPG_04.C
 *   @author	Frode Haug, NTNU
 */


#include <stdio.h>                //  printf

/**
 *  Hovedprogrammet:
 */
int main()  {
    int postnummer = 1234,        //  Definerer og initierer 3x variable.
        mobilnummer = 87654321,
        alder = 20;
                                  //  Skriver ut tekster og variable:
    printf("Navn:     Ola Nordmann\n");
    printf("Adresse:  Karl Johans gate 314\n");
    printf("Sted:     %i Oslo\n", postnummer);
    printf("Mobilnr:  %i\n", mobilnummer);
    printf("Alder:    %i\n\n", alder);

    return 0;
}
