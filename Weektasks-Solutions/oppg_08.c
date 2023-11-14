/**
 *   Løsningsforslag til oppgave nr 8.
 *
 *   @file	  OPPG_08.C
 *   @author  Frode Haug, NTNU
 */


#include <stdio.h>                //  printf

const int ANTALL = 17;          ///<  Consten 'ANTALL'
 
/**
 *  Hovedprogrammet:
 */
int main()  {                     //  Initierer variable:
    int tall1 = 7, tall2 = 23, tall3 = 14, svar = 0;

    svar = tall1 + tall2 - tall3 + ANTALL;
    printf("Svaret er: %i\n", svar);

    svar = tall1 * tall2 - tall3;      //  Begge disse regnestykkene
    printf("Svaret er: %i\n", svar);  //    gir det samme ssvaret,
                                       //    da '*' og '/' evalueres
    svar = (tall1 * tall2) - tall3;    //    før '+' og '-':
    printf("Svaret er: %i\n", svar);
                                       //  Men, her "tvinges" '-' til
    svar = tall1 * (tall2 - tall3);    //    å bli utført først:
    printf("Svaret er: %i\n", svar);

    svar = (tall1 * (tall2 - tall3)) / tall1 * ANTALL;
    printf("Svaret er: %i\n", svar);

    svar *= ANTALL;
    printf("Svaret er: %i\n", svar);

    svar += tall2 * tall3 + tall3 / tall1;
    printf("Svaret er: %i\n", svar);

    svar /= tall1 + tall3;
    printf("Svaret er: %i\n", svar);
                                         //  Så lenge 'tall++'  og '++tall'
    printf("Tall1 FØR:%i\n", tall1);     //    står alene, så spiller det
    tall1++;   ++tall1;  tall1++;        //    ingen rolle hvor '++' står.
    printf("Tall1 ETTER:%i\n", tall1);   //    Ellers ville slik '++' / '--'
                                         //    bli utført før eller etter at
    printf("Tall2 FØR:%i\n", tall2);     //    resten av uttrykket evalueres.
    tall2--;   --tall2;  --tall2;  tall2--;
    printf("Tall2 ETTER:%i\n", tall2);

    printf("Svaret er: %i\n", (tall1 * tall2) - ANTALL);

    return 0;
}
