/**
 *   L�sningsforslag til oppgave nr 38.
 *
 *   @file	  OPPG_38.C
 *   @author  Frode Haug, NTNU
 */


#include <stdio.h>                 //  printf, FILE
#include <string.h>                //  strcpy

#define  STRLEN    60              ///<  Max. tekstelengde.

/**
 *  B�t (med reg.nr, modelltype, eiers navn og telefon, �rsmodell og hestekrefter).
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
    FILE*  innfil = fopen("BAATER.DTA", "r"); //  �pner fil for innlesning.

    if (innfil)  {                    //  Filen er funnet:
       fscanf(innfil, "%s", rNr);     //  Pr�ver � lese starten p� 1.posten.
       while (!feof(innfil))  {       //  Enn� ikke slutt p� filen.
          baatLesFraFil(innfil, &baat, rNr);  // Resten om b�ten leses fra fil.
          baatSkrivData(&baat);       //  ALT om innlest b�t skrives p� skjermen.
          fscanf(innfil, "%s", rNr);  //  Pr�ver � lese starten p� neste post.
       }
    } else                             //  Filen ikke funnet/mulig � �pne:
       printf("Klarte ikke � finne filen 'BAATER.DTA'!\n\n");

    fclose(innfil);                    //  Lukker filen.

    printf("\n\n");
    return 0;
}


/**
 *  Leser ALLE data om EN b�t fra fil.
 *
 *  @param   inn  - Filen det skal leses fra
 *  @param   b    - Structen som skal f� sine verdier innlest fra fil
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
 *  Skriver ALLE data om EN b�t til skjermen.
 *
 *  @param   b  - Structen som alt skal skrives ut om
 */
void baatSkrivData(const struct Baat* b)  {
  printf("Regnr: %s,  modelltype:  %s\t�r: %i,  HK:  %i,  tlf: %i,  eier: %s",
         b->regNr, b->modellType, b->aarsModell,
         b->hesteKrefter, b->telefon, b->eierNavn);
}
