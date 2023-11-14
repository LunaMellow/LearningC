/**
 *   Løsningsforslag til oppgave nr 15.
 *
 *   @file	  OPPG_15.C
 *   @author  Frode Haug, NTNU
 */


#include <stdio.h>                //  printf, scanf

/**
 *  Hovedprogrammet:
 */
int main()  {
    int tall1, tall2;             //  2x tall som stadig leses inn.
    char svar;                    //  Brukersvar til om å vil fortsette.

    do  {
        printf("\n\nSkriv inn tall nr.1: ");  //  Leser inn 2x tall:
        scanf("%i", &tall1);
        printf("Skriv inn tall nr.2: ");
        scanf("%i", &tall2);
                                              //  Utskrifter med beregning:
        printf("\nNoen regnestykker med disse:\n");
        printf("%8i + %8i = %8i\n", tall1, tall2, tall1+tall2);
        printf("%8i - %8i = %8i\n", tall1, tall2, tall1-tall2);
        printf("%8i * %8i = %8i\n", tall1, tall2, tall1*tall2);

        printf("\nVil du fortsette (j/N): "); //  Ber om brukerens valg/ønske.
        scanf(" %c", &svar);
    } while (svar == 'j' || svar == 'J');     //  Gjentar når 'j' eller 'J'.

    return 0;
}
