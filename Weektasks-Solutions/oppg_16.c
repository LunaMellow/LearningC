/**
 *   Løsningsforslag til oppgave nr 16.
 *
 *   @file	  OPPG_16.C
 *   @author  Frode Haug, NTNU
 */


#include <stdio.h>                //  printf, scanf
#include <ctype.h>                //  toupper

const int  INTLEN  =      5;      ///<  Int-arrays lengde.
const int  CHARLEN =     10;      ///<  Char-arrays lengde.
const int  MINVERDI =     1;      ///<  Minste lovlige int-verdi.
const int  MAXVERDI = 10000;      ///<  Største lovlige int-verdi.

/**
 *  Hovedprogrammet:
 */
int main()  {
    int  i,                       //  Løkke-teller.
         tall;                    //  Innlest tall.
    char tegn;                    //  Innlest tegn.
    int  tallene[INTLEN];         //  Alle innleste tall.
    char tegnene[CHARLEN];        //  Alle innleste tegn.

    for (i = 0;  i < INTLEN;  i++)  {     //  Leser alle tallene:
        do  {
            printf("%i.tall (%i-%i): ", i+1, MINVERDI, MAXVERDI);
            scanf("%i", &tall);           //  Leser ett tall.
        } while (tall < MINVERDI  ||  tall > MAXVERDI);  //  Til lovlig verdi.
        tallene[i] = tall;                //  Lagrer unna godtatt verdi.
    }
    printf("\n");

    for (i = 0;  i < INTLEN;  i++)        //  Skriver alle lagrede heltall:
        printf("%i.tall er: %5i\n", i+1, tallene[i]);

    printf("\n\n");


//***************************************************************************

    for (i = 0;  i < CHARLEN;  i++)  {    //  Leser alle tegnene:
        do  {
            printf("%i.tegn (A-Z): ", i+1);
            scanf(" %c", &tegn);          //  Leser ett tegn.
            tegn = toupper(tegn);         //  Gjør om til STOR bokstav.
        } while (tegn < 'A'  ||  tegn > 'Z');  //  Så lenge ulovlig verdi.
        tegnene[i] = tegn;                //  Lagrer unna godtatt verdi.
    }
    printf("\n");

    for (i = 0;  i < CHARLEN;  i++)       //  Skriver alle lagrede bokstaver:
        printf("%2i.tegn er: %c\n", i+1, tegnene[i]);

    printf("\n\n");

    return 0;
}
