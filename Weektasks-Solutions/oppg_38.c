/**
 *   Løsningsforslag til oppgave nr 38.
 *
 *   @file	  OPPG_38.C
 *   @author  Frode Haug, NTNU
 */


#include <stdio.h>                 //  printf, FILE
#include <string.h>                //  strcpy

#define  STRLEN    60              ///<  Max. tekstelengde.

/**
 *  Båt (med reg.nr, modelltype, eiers navn og telefon, årsmodell og hestekrefter).
 *
 */
struct Baat {
  char regNr[STRLEN/6],
       modellType[STRLEN],
       eierNavn[STRLEN];
  int  telefon,
       aarsModell,
       hesteKrefter;
};


void baatLesFraFil(FILE* inn, struct Baat* b, const char* nr);
void baatSkrivData(const struct Baat* b);


/**
 *  Hovedprogrammet:
 */
int main()  {
    struct Baat baat;
    char   rNr[STRLEN/6];
    FILE*  innfil = fopen("BAATER.DTA", "r"); //  Åpner fil for innlesning.

    if (innfil)  {                    //  Filen er funnet:
       fscanf(innfil, "%s", rNr);     //  Prøver å lese starten på 1.posten.
       while (!feof(innfil))  {       //  Ennå ikke slutt på filen.
          baatLesFraFil(innfil, &baat, rNr);  // Resten om båten leses fra fil.
          baatSkrivData(&baat);       //  ALT om innlest båt skrives på skjermen.
          fscanf(innfil, "%s", rNr);  //  Prøver å lese starten på neste post.
       }
    } else                             //  Filen ikke funnet/mulig å åpne:
       printf("Klarte ikke å finne filen 'BAATER.DTA'!\n\n");

    fclose(innfil);                    //  Lukker filen.

    printf("\n\n");
    return 0;
}


/**
 *  Leser ALLE data om EN båt fra fil.
 *
 *  @param   inn  - Filen det skal leses fra
 *  @param   b    - Structen som skal få sine verdier innlest fra fil
 *  @param   nr   - Allerede innlest reg.nummer (som skal unnalagres)
 */
void baatLesFraFil(FILE* inn, struct Baat* b, const char* nr)  {
  strcpy(b->regNr, nr);               //  Lagrer unna allerede innlest reg.nr.
                                      //  Leser 3x int'er:
  fscanf(inn, "%i %i %i", &b->aarsModell, &b->hesteKrefter, &b->telefon);
  getc(inn);                          //  Skipper EN ' ' (blank).
  fgets(b->eierNavn,   STRLEN, inn);  //  Leser RESTEN av linja som tekst, inkl.'\n'.
  fgets(b->modellType, STRLEN, inn);  //  Leser HELE linja som tekst, inkl.'\n'.
}


/**
 *  Skriver ALLE data om EN båt til skjermen.
 *
 *  @param   b  - Structen som alt skal skrives ut om
 */
void baatSkrivData(const struct Baat* b)  {
  printf("Regnr: %s,  modelltype:  %s\tår: %i,  HK:  %i,  tlf: %i,  eier: %s",
         b->regNr, b->modellType, b->aarsModell,
         b->hesteKrefter, b->telefon, b->eierNavn);
}
