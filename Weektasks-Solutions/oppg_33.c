/**
 *   Løsningsforslag til oppgave nr 33.
 *
 *   @file	  OPPG_33.C
 *   @author  Frode Haug, NTNU
 */


#include <stdio.h>                 //  printf

int   finnLengde(const char* tp);
char* finnLengsteTekst(const char* tp, const char* tp2);


/**
 *  Hovedprogrammet:
 */
int main()  {                                   //  Initierer 2x char-arrayer:
    char tekst[]  = "Dette er en tekst med en viss lengde",
         tekst2[] = "Mens, dette er en helt annen tekst";
    char* tPeker;

    printf("Vi har tekstene:\n\t%s\n\t%s\n\n", tekst, tekst2);
                                                //  Får peker til den lengste:
    tPeker = finnLengsteTekst(tekst, tekst2);

    printf("Lengst av dem er:\n\t%s\n\n\n", tPeker);


                             //  Får peker til lengste av to tekst-konstanter:
    tPeker = finnLengsteTekst("Per og Kari", "Mari og Olav");

    printf("Av 'Per og Kari' og 'Mari og Olav' er den lengste:\n\t%s\n\n",
           tPeker);


    return 0;
}


/**
 *  Finner og returnerer lengden av en tekst.
 *
 *  @param   tp  - Peker til teksten det skal finnes lengden for
 *
 *  @return  Lengden av den tilpekte teksten
 */
int finnLengde(const char* tp)  {
   int lengde = 0;          //  Initierer til 0 (null).
   while (*tp)  {           //  Går frem til '\0':
      lengde++;             //  Teller opp antall tegn.
      tp++;                 //  Øker til neste char/tegn.
   }
   return lengde;           //  Returnerer opptelt lengde.
}


/**
 *  Returnerer peker til den lengste av to tekster.
 *
 *  @param   tp   - Peker til den første teksten
 *  @param   tp2  - Peker til den andre teksten
 *
 *  @return  Peker til den lengste teksten
 */
char* finnLengsteTekst(const char* tp, const char* tp2)  {
   return ((finnLengde(tp) >= finnLengde(tp2)) ?  tp  :  tp2);
}
