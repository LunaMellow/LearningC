/**
 *   Løsningsforslag til oppgave nr 31.
 *
 *   @file	  OPPG_31.C
 *   @author  Frode Haug, NTNU
 */


#include <stdio.h>                 //  printf, scanf

#define   STRLEN        80         ///<  Max. tekstlengde.


/**
 *  Person (med navn, skoleklasse (EN char) og skostørrelse).
 */

 struct Person  {
    char navn[STRLEN];
    char klasse;
    int  skoNr;
 };

/**
 *  Hovedprogrammet:
 */
int main()  {
    struct Person  person;       //  Definerer person-struct.
    struct Person* pPeker;       //  Lager peker til person-struct.

    pPeker = &person;            //  Initierer peker til å peke på structen.

    printf("Personens:\n");
                                 //  Leser inn i char-arrayen 'navn':
    printf("\tNavn:              ");    gets(pPeker->navn);
                                 //  De 2x andre: Må som tidligere ha
                                 //    adressen til enkelt-char'en og -int'en:
    printf("\tKlassenavn (A-H):  ");    scanf(" %c", &(pPeker->klasse));
    printf("\tSkonummer:         ");    scanf("%i",  &(pPeker->skoNr));

                          //  Skriver alle struktens datamedlemmer vha. peker:
    printf("\n\nInnleste data om personen:\n");
    printf("\tNavn:\t%s\n\tKlasse:\t%c\n\tSkonr:\t%i\n\n",
           pPeker->navn, pPeker->klasse, pPeker->skoNr);
    printf("\tNavn:\t%s\n\tKlasse:\t%c\n\tSkonr:\t%i\n\n", // Samme vha. struct-
           person.navn, person.klasse, person.skoNr);      //  variabelen.

    return 0;
}
