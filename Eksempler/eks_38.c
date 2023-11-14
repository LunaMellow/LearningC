/**
 *   Programeksempel nr 38 - Filer - Lesing fra fil (FIL3.DTA)
                                     av flere structers data.
 *
 *   @file     EKS_38.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>              //  printf, FILE
#include <stdlib.h>             //  malloc, sizeof, free


#define     STRLEN    80        ///<  Max. tekstlengde.
#define     MAXPERS   10        ///<  Max. antall personer i datastrukturen.


/**
 *  Ansatt (med ansattnr, lønnstrinn, navn, gateadresse og postnr/-sted).
 */
struct Ansatt  {
    int  ansattNr,
         lonnsTrinn,
         postNr;
    char navn[STRLEN],
         gateAdr[STRLEN],
         postSted[STRLEN];
};


void ansattLesFraFil(FILE* inn, struct Ansatt* ansatt, const int n);
void ansattSkrivData(const int nr, const struct Ansatt* ansatt);


struct Ansatt* gAnsatte[MAXPERS];   ///<  Alle ansatte innlest fra fil.
int    gAntallAnsatte = 0;          ///<  Totalt antall ansatte lest fra fil.


/**
 *  Hovedprogrammet:
 */
int main ()  {
    FILE* innfil;                   //  Peker til fil for input.
    int   i, nr;                    //  Løkkevariabel og innlest ansattnummer.

    printf("\n\nLeser fra filen 'FIL3.DTA' .....\n\n\n");

    innfil = fopen("FIL3.DTA", "r");   //  Åpner fil for INPUT - 'r'

    if (innfil)  {                     //  Filen er funnet:

       fscanf(innfil, "%i", &nr);      //  PRØVER Å LESE STARTEN PÅ 1.POSTEN.
                                    //  ENNÅ IKKE FILSLUTT OG PLASS TIL FLERE:
       while (!feof(innfil)  &&  gAntallAnsatte < MAXPERS)  {
                                       //  Oppretter ny struct:
          gAnsatte[gAntallAnsatte] =
                               (struct Ansatt*) malloc(sizeof(struct Ansatt));
                                       //  Den nye ansattes data leses:
          ansattLesFraFil(innfil, gAnsatte[gAntallAnsatte], nr);
          gAntallAnsatte++;            //  Teller opp totalantallet.
          fscanf(innfil, "%i", &nr);   // PRØVER Å LESE STARTEN PÅ NESTE POST.
       }
    } else                             //  Filen ikke funnet/mulig å åpne:
       printf("Klarte ikke å finne filen 'FIL3.DTA'!\n\n");

    fclose(innfil);                    //  Lukker filen.


    printf("De innleste ansattes data:\n");
    for (i = 0;  i < gAntallAnsatte;  i++)// Alt innlest skrives til skjermen:
        ansattSkrivData(i+1, gAnsatte[i]);


    for (i = 0;  i < gAntallAnsatte;  i++)    //  Frigir all allokert memory:
        free(gAnsatte[i]);

    printf("\n\n");

    return 0;
}


/**
*  Leser ALLE data om EN Ansatt fra fil.
*
*  @param   inn     - Filen det skal leses fra
*  @param   ansatt  - Structen som skal få sine verdier innlest fra fil
*  @param   n       - Allerede innlest ansattnummer (som skal unnalagres)
*/
void ansattLesFraFil(FILE* inn, struct Ansatt* ansatt, const int n)  {
   ansatt->ansattNr = n;
   fscanf(inn, "%i %i", &(ansatt->lonnsTrinn), &(ansatt->postNr));
   getc(inn);
   fgets(ansatt->navn,     STRLEN, inn);
   fgets(ansatt->gateAdr,  STRLEN, inn);
   fgets(ansatt->postSted, STRLEN, inn);
}


/**
*  Skriver ALLE data om EN ansatt til skjermen.
*
*  @param   nr      - Den ansattes nummer i datastrukturen (IKKE 'ansattNr')
*  @param   ansatt  - Structen som alt skal skrives ut om
*/
void ansattSkrivData(const int nr, const struct Ansatt* ansatt)  {
   printf("\tNr.%i:  ansattnr: %i, lønnstrinn: %i\n\t\t%s\t\t%s\t\t%i %s",
          nr, ansatt->ansattNr, ansatt->lonnsTrinn, ansatt->navn,
          ansatt->gateAdr, ansatt->postNr, ansatt->postSted);
}
