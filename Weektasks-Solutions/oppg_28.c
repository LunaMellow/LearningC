/**
 *   Løsningsforslag til oppgave nr 28.
 *
 *   @file	  OPPG_28.C
 *   @author  Frode Haug, NTNU
 */


#include <stdio.h>                 //  printf, scanf

#define   STRLEN        80         ///<  Max. tekstlengde.


/**
 *  Ansatt (med ansattnummer, navn og lønn).
 */
struct Ansatt  {
   int   ansattNr;
   char  navn[STRLEN];
   float lonn;

};


void skriv(const int n, const struct Ansatt ans);


/**
 *  Hovedprogrammet:
 */
int main()  {                      //  Definerer 3x. Initierer den første:
    struct Ansatt ansatt = { 312, "Bjarte Hauge", 480234.50 },
                  ansatt2,
                  temp;            //  Brukes ved ombyttingen av de 2x andre.

    printf("\n\nAnsatt nr.2:\n");  //  Leser Ansatt nr.2 sine data:
    printf("\tAnsattnr:  ");  scanf("%i", &ansatt2.ansattNr);   getchar();
    printf("\tNavn:      ");  gets(ansatt2.navn);
    printf("\tLønn:      ");  scanf("%f", &ansatt2.lonn);

    printf("\n\n");
    skriv(1, ansatt);              //  Skriver begge de 2x Ansattes innhold:
    skriv(2, ansatt2);

    printf("\n\nBytter om de to ansatte .....\n\n");   //  Rotasjonsombytting:
    temp = ansatt;   ansatt = ansatt2;   ansatt2 = temp;

    skriv(1, ansatt);              //  Skriver begge de 2x Ansatte igjen/nå:
    skriv(2, ansatt2);

    printf("\n\n");
    return 0;
}


/**
 *  Skriver en Ansatt-struct sine data ut på skjermen.
 *
 *  @param   n    - Struct-nummeret (1 eller 2)
 *  @param   ans  - Ansatt-struct som skal skrives ut
 */
void skriv(const int n, const struct Ansatt ans)  {
  printf("Ansatt nr.%i\n", n);
  printf("\tNummer: %i\n",   ans.ansattNr);
  printf("\tNavn:   %s\n",   ans.navn);
  printf("\tLønn:   %.2f\n", ans.lonn);
}
