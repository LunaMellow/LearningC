/**
 *   Løsningsforslag til oppgave nr 29.
 *
 *   @file	  OPPG_29.C
 *   @author  Frode Haug, NTNU
 */


#include <stdio.h>                 //  printf, scanf


/**
 *  Brøk (bestående av teller og nevner).
 */
struct Brok  {
    int teller,
        nevner;
};


struct Brok lesBrok();
void   skrivBrok(const struct Brok b);
struct Brok addisjon(const struct Brok b, const struct Brok b2);
struct Brok divisjon(const struct Brok b, const struct Brok b2);
struct Brok multiplikasjon(const struct Brok b, const struct Brok b2);
struct Brok subtraksjon(const struct Brok b, const struct Brok b2);


/**
 *  Hovedprogrammet:
 */
int main()  {
    struct Brok  brok, brok2, svar;  //  2x brøker og en med matematiske svar.

    printf("\n1.brøk:\n");           //  Leser inn 2x brøker:
    brok  = lesBrok();
    printf("\n2.brøk:\n");
    brok2 = lesBrok();

    printf("\n\n");
                                     //  Utfører regneoperasjoner og skriver
    svar = addisjon(brok, brok2);    //     involverte brøker og svarene:
    printf("\t");     skrivBrok(brok);  printf("  +  ");  skrivBrok(brok2);
    printf("  =  ");  skrivBrok(svar);  printf("\n");

    svar = subtraksjon(brok, brok2);
    printf("\t");     skrivBrok(brok);  printf("  -  ");  skrivBrok(brok2);
    printf("  =  ");  skrivBrok(svar);  printf("\n");

    svar = multiplikasjon(brok, brok2);
    printf("\t");     skrivBrok(brok);  printf("  *  ");  skrivBrok(brok2);
    printf("  =  ");  skrivBrok(svar);  printf("\n");

    svar = divisjon(brok, brok2);
    printf("\t");     skrivBrok(brok);  printf("  /  ");  skrivBrok(brok2);
    printf("  =  ");  skrivBrok(svar);  printf("\n\n");

    return 0;
}


/**
 *  Leser inn en LOVLIG brøk (teller og nevner) og returnerer den.
 *
 *  @return  En brøk med gyldig teller og nevner
 */
struct Brok lesBrok()  {
  struct Brok temp;

     printf("\tTeller:       ");
     scanf("%i", &temp.teller);

  do {
     printf("\tNevner (> 0): ");
     scanf("%i", &temp.nevner);
  } while (temp.nevner <= 0);

  return temp;
};


/**
 *  Skriver ut en brøk på formen:  teller / nevner.
 *
 *  @param   b   - Brøken som skal skrives ut
 */
void skrivBrok(const struct Brok b)  {
   printf("%i / %i", b.teller, b.nevner);
};


/**
 *  Adderer (plusser) to brøker og returnerer svaret.
 *
 *  @param   b   - Brøk nr.1
 *  @param   b2  - Brøk nr.2
 *
 *  @return  Svar-brøken på de to parameterbrøkene addert
 */
struct Brok addisjon(const struct Brok b, const struct Brok b2)  {
  struct Brok temp;

  temp.teller = b.teller*b2.nevner + b2.teller*b.nevner;
  temp.nevner = b.nevner*b2.nevner;

  return temp;
}


/**
 *  Dividerer (deler) to brøker og returnerer svaret.
 *
 *  @param   b   - Brøk nr.1
 *  @param   b2  - Brøk nr.2
 *
 *  @return  Svar-brøken på de to parameterbrøkene dividert
 */
struct Brok divisjon(const struct Brok b, const struct Brok b2)  {
  struct Brok temp;

  temp.teller = b.teller*b2.nevner;
  temp.nevner = b.nevner*b2.teller;

  return temp;

}


/**
 *  Multipliserer (ganger) to brøker og returnerer svaret.
 *
 *  @param   b   - Brøk nr.1
 *  @param   b2  - Brøk nr.2
 *
 *  @return  Svar-brøken på de to parameterbrøkene multiplisert
 */
struct Brok multiplikasjon(const struct Brok b, const struct Brok b2)  {
  struct Brok temp;

  temp.teller = b.teller*b2.teller;
  temp.nevner = b.nevner*b2.nevner;

  return temp;

}


/**
 *  Subtraherer (trekker fra)) to brøker og returnerer svaret.
 *
 *  @param   b   - Brøk nr.1
 *  @param   b2  - Brøk nr.2
 *
 *  @return  Svar-brøken på de to parameterbrøkene subtrahert
 */
struct Brok subtraksjon(const struct Brok b, const struct Brok b2)  {
  struct Brok temp;

  temp.teller = b.teller*b2.nevner - b2.teller*b.nevner;
  temp.nevner = b.nevner*b2.nevner;

  return temp;
}
