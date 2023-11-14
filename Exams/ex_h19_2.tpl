/**
 *   Skjelett for eksamen i GrProg (i C), november 2019, oppgave 2.
 *
 *   Programmet holder orden på ansatte på en arbeidsplass, hvilke dager
 *   de (ikke) skal arbeide, og om de har møtt opp eller ei til arbeidet.
 *
 *   @file     EX_H19_2.TPL
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>               //  printf, scanf, FILE
#include <stdlib.h>              //  sizeof, malloc, free
#include <string.h>              //  strcpy, strlen
#include <stdbool.h>             //  bool, true, false
#include "LesData.h"             //  Verktøykasse for lesing av diverse data

#define   MAXDAG        31       ///<  Max. antall dager i en måned.
#define   MAXANSATTE   100       ///<  Max. antall ansatte.
const int STRLEN    =   80;      ///<  Max. tekstlengde.


/**
 *  Ansatt (med navn, mailadresse, mobiltlf og hvordan jobber DENNE måneden).
 */
struct Ansatt {
    char* navn,                  //  Ansattes navn.
        * mail;                  //  Mailadresse.
    int   mobil;                 //  Mobiltelefonnummer.
    char  jobbing[MAXDAG];       //  Jobbingen i løpet av måneden
};                               //    ('-'= nei,  'J'= jobbe,  'M'= møtt)


void skrivMeny();
void nyAnsatt();                                           //  Oppgave 2A
void ansattLesOgSettData(struct Ansatt* a);                //  Oppgave 2A
void kommerPaaJobb();                                      //  (Oppgave 2B)
void ansattAnkommerJobb(struct Ansatt* a);                 //  Oppgave 2B
void oversiktAnsattesJobbing();                            //  Oppgave 2C
void ansattSkrivJobbing(const struct Ansatt* a);           //  Oppgave 2C
void endreEnsJobbingEnDag();                               //  (Oppgave 2D)
void ansattEndreJobbing(struct Ansatt* a);                 //  Oppgave 2D
void lesJobbingFraFil(const bool lesAlt);                  //  Oppgave 2E
void ansattLesJobbingFraFil(FILE* inn, struct Ansatt* a);  //  Oppgave 2E
void jobbStatistikk();                                     //  Oppgave 2F
void lesAnsatteFraFil();                                   //  Oppgave 2G
void ansattLesFraFil(FILE* inn, struct Ansatt* a);         //  Oppgave 2G


int gAntallAnsatte,                   ///<  Antall ansatte i bruk i 'gAnsatte'.
    gDagNr,                           ///<  Dagens dato.
    gSisteDag;                        ///<  Aktuell måneds dagantall (28-31).
struct Ansatt* gAnsatte[MAXANSATTE];  ///<  Alle de ansatte.


/**
 *  Hovedprogrammet:
 */
int main()  {
    char kommando;

    lesAnsatteFraFil();                //  Oppgave 2G
    lesJobbingFraFil(false);           //  Oppgave 2E - Henter KUN 'gSisteDag'.
    gDagNr = lesInt("Dato", 1, gSisteDag);  //  Leser dagens dato (1-gSisteDag).

    skrivMeny();
    kommando = lesChar("Ønske");
    kommando = 'F';
    while (kommando != 'Q')  {
        switch (kommando)  {
          case 'N': nyAnsatt();                     break;  //  Oppgave 2A
          case 'K': kommerPaaJobb();                break;  //  Oppgave 2B
          case 'O': oversiktAnsattesJobbing();      break;  //  Oppgave 2C
          case 'E': endreEnsJobbingEnDag();         break;  //  Oppgave 2D
          case 'M': lesJobbingFraFil(true);         break;  //  Oppgave 2E
          case 'S': jobbStatistikk();               break;  //  Oppgave 2F
          default:  skrivMeny();                    break;
        }
        kommando = lesChar("Ønske");
    }
//    skrivAnsatteTilFil();       //  Skriver ALLE ansatte tilbake til fil.
    printf("\n\n");
    return 0;
}


/**
 *  Skriver/presenterer programmets muligheter/valg for brukeren.
 */
void skrivMeny() {
    printf("\n\nFØLGENDE KOMMANDOER ER LOVLIG:\n");
    printf("\tN   = Ny ansatt\n");
    printf("\tK   = ansatt Kommer på jobb\n");
    printf("\tO   = Oversikt over alle ansattes jobbing\n");
    printf("\tE   = Endre jobbing for en ansatt på en dag\n");
    printf("\tM   = Månedsskifte (ny jobbplan)\n");
    printf("\tS   = Statistikk over antall dager jobbet/ikke møtt\n");
    printf("\tQ   = Quit/avslutt\n");
}


/**
 *  Oppgave 2A - Legger inn (om mulig) en ny ansatt i datastrukturen.
 *
 *  @see   ansattLesOgSettData(...)
 */
void nyAnsatt() {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2A - Leser inn og initierer data om EN ansatt.
 *
 *  @param  a - Den ansatte som får innlest/initiert sine data
 */
void ansattLesOgSettData(struct Ansatt* a) {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2B - Ansatt har kommet på jobb.
 *
 *  @see   ansattAnkommerJobb(...)
 */
void kommerPaaJobb()  {
    int nr = lesInt("Ansattnr", 1, gAntallAnsatte);  //  Leser aktuelt ansnr.
    ansattAnkommerJobb(gAnsatte[nr - 1]);
}


/**
 *  Oppgave 2B - Registrerer (om mulig) at en ansatt har møtt på jobb.
 *
 *  @param  a - Den ansatte som får registrert at har møtt på jobb
 */
void ansattAnkommerJobb(struct Ansatt* a) {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2C - Skriver ALLE de ansattes jobbstatus.
 *
 *  @see   ansattSkrivJobbing(...)
 */
void oversiktAnsattesJobbing()  {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2C - Skriver EN ansatts navn og jobbestatus.
 *
 *  @param  a - Den ene ansatte som jobbstatus skrives for
 */
void ansattSkrivJobbing(const struct Ansatt* a) {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2D - Endre en ansatts jobbing.
 *
 *  @see   ansattEndreJobbing(...)
 */
void endreEnsJobbingEnDag() {
    int nr = lesInt("Ansattnr", 1, gAntallAnsatte);   //  Leser aktuelt ansnr.
    ansattEndreJobbing(gAnsatte[nr - 1]);
}


/**
 *  Oppgave 2D - Endrer (om mulig) status for jobbing.
 *
 *  @param  a - Den ansatte som får endret sin jobbing
 */
void ansattEndreJobbing(struct Ansatt* a) {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2E - Jobbingen for NESTE måned leses inn i den
 *               allerede eksisterende datastrukturen.
 *
 *  @param   lesAlt - Om HELE filens innhold skal leses, eller KUN 'gSisteDag'
 *  @see     ansattLesJobbingFraFil(...)
 */
void lesJobbingFraFil(const bool lesAlt) {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2E - Leser KUN jobbstatus for EN ansatt fra fil.
 *
 *  @param  inn - Filen det skal leses fra
 *  @param  a   - Structen som får innlest sine data
 */
void ansattLesJobbingFraFil(FILE* inn, struct Ansatt* a) {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2F - Statistikk over de ansattes jobbing.
 */
void jobbStatistikk() {

    //   LAG INNMATEN OG ANNEN KODE/FUNKSJON(ER) 
}


/**
 *  Oppgave 2G - Leser ALLE ansatte fra fil.
 *
 *  @see     ansattLesFraFil(...)
 */
void lesAnsatteFraFil() {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2G - Leser ALT om EN ansatt fra fil.
 *
 *  @param  inn - Filen det skal leses fra
 *  @param  a   - Structen som får innlest sine data
 */
void ansattLesFraFil(FILE* inn, struct Ansatt* a)  {

    //   LAG INNMATEN
}