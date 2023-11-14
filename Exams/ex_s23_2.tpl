/**
 *   Skjelett eksamen i GrProg (i C), august 2023, oppgave 2.
 *
 *   Programmet holder orden på ulike brøytere/strøere og deres kunder.
 *
 *   @file     EX_S23_2.TPL
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>               //  printf, scanf, FILE
#include <stdlib.h>              //  sizeof, malloc
#include <string.h>              //  strcpy, strlen
#include <stdbool.h>             //  bool, true, false
#include "LesData.h"             //  Verktøykasse for lesing av diverse data


#define   MAXBROYTSTRO  20       ///<  Max. antall brøytere/strøere.
#define   MAXKUNDER    100       ///<  Max. antall kunder.
const int STRLEN  =     80;      ///<  Max. tekstlengde.
const int PRIS[]  = { 175, 325, 475};  ///<  Faste priser for ulike arealer.


/**
 *  Brøyter/strøer (med kun navn og (mobil)telefon).
 */
struct BroyterStroer {        //  Brøyters/strøers:
  char* navn;                 //     - navn
  int   tlf;                  //     - (mobil)telefonnummer
};


/**
 *  Kunde (med navn, adresse, (mobil)telefon, prisgruppe, brøyter/strøer-nr,
 *          antall brøytinger/strøinger hittil i løpet av sesongen).
 */
struct Kunde {                //  Kundens:
  char* navn,                 //     - navn
      * adresse;              //     - adresse
  int   tlf,                  //     - (mobil)telefonnummer
        prisNr,               //     - prisgruppenummer (0-2)
        BSNr,                 //     - brøyter/strøers REELLE nummer/indeks
                              //                         (fra 0 og oppover)
        antBroyt,             //     - antall brøytinger (hittil)
        antStro;              //     - antall strøinger (hittil)
};


void skrivMeny();                                              //  |
int  kundeHentBSNr(const struct Kunde* kunde);                 //  | Ferdig-
int  kundeHentKostnad(const struct Kunde* kunde);              //  |  -laget.
void broytStroSkrivNavn(const struct BroyterStroer* broytStro);//  |
void skrivAlleKunder();                                        //  Oppgave 2A
void kundeSkrivData(const struct Kunde* kunde);                //  Oppgave 2A
void nyKunde();                                                //  Oppgave 2B
void kundeLesData(struct Kunde* kunde);                        //  Oppgave 2B
void broytetStroddHosKunder();                                 //  Oppgave 2C
void kundeBroytetStrodd(struct Kunde* kunde);                  //  Oppgave 2C
void lagFakturaer();                                           //  Oppgave 2D
void kundeLagFaktura(const struct Kunde* kunde);               //  Oppgave 2D
void endreBroyterStroer();                                     //  Oppgave 2E
void kundeEndreBroyterStroer(struct Kunde* kunde);             //  Oppgave 2E
void broyterStroerMedMestInntjening();                         //  Oppgave 2F
void lesFraFil();                                              //  Oppgave 2G
void kundeLesFraFil(FILE* inn, struct Kunde* kunde);           //  Oppgave 2G


int    gAntallBroytStro;      ///<  Antall brøytere/strøere hittil registrert.
struct BroyterStroer* gBroytereStroere[MAXBROYTSTRO];  ///<  Brøytere/strøere.
int    gAntallKunder;         ///<  Antall kunder hittil registrert.
struct Kunde* gKunder[MAXKUNDER];                      ///<  Alle kundene.



/**
 *  Hovedprogrammet.
 */
int main()  {
    char kommando;

    lesFraFil();                                               //  Oppgave 2G

    skrivMeny();
    kommando = lesChar("\nValg");

    while (kommando != 'Q') {
        switch (kommando) {
          case 'S':  skrivAlleKunder();                break;  //  Oppgave 2A
          case 'K':  nyKunde();                        break;  //  Oppgave 2B
          case 'G':  broytetStroddHosKunder();         break;  //  Oppgave 2C
          case 'F':  lagFakturaer();                   break;  //  Oppgave 2D
          case 'E':  endreBroyterStroer();             break;  //  Oppgave 2E
          case 'I':  broyterStroerMedMestInntjening(); break;  //  Oppgave 2F
          default:   skrivMeny();                      break;
        }
        kommando = lesChar("\nValg");
    }

//    skrivTilFil();                         //  Ikke del av eksamensoppgaven.

    return 0;
}


/**
 *  Skriver/presenterer programmets muligheter/valg for brukeren.
 */
void skrivMeny() {
    printf("\nFØLGENDE KOMMANDOER ER LOVLIG:\n");
    printf("\tS   = Skriv alle kunder\n");
    printf("\tK   = ny Kunde\n");
    printf("\tG   = gjort Gjøremål (brøytet/strødd) hos kunde(r)\n");
    printf("\tF   = lag/skriv Fakturaer\n");
    printf("\tE   = Endre til annen brøyter/strøer for en kunde\n");
    printf("\tI   = finn og skriv brøyter/strøer med mest Inntjening\n");
    printf("\tQ   = Quit/avslutt\n");
}


/**
 *  Retunerer nummeret/indeksen for brøyteren/strøeren til en kunde.
 *
 *  @param    Kunde  -  Aktuell kunde å returnere nummeret for
 *  @return   Brøyterens/strøerens nummer/indeks for en kunde
 */
int kundeHentBSNr(const struct Kunde* kunde)  {
   return (kunde->BSNr);
}


/**
 *   Returnerer kundens totale kostnad/sum for all brøyting/strøing.
 *
 *   @param   kunde  -  Kunden det hentes kostnad for
 */
int kundeHentKostnad(const struct Kunde* kunde)  {
  return ((kunde->antBroyt + kunde->antStro) * PRIS[kunde->prisNr]);
}


/**
 *  Skriver eb brøyters/strøers navn ut på skjermen.
 *
 *  @param    broytStro  -  Aktuell brøyter/strøer å skrive ut navnet for
 */
void broytStroSkrivNavn(const struct BroyterStroer* broytStro)  {
   printf("%s", broytStro->navn);
}


/**
 *  Oppgave 2A - Skriver ALT om ALLE kunder ut på skjermen.
 *
 *  @see   kundeSkrivData(...)
 */
void skrivAlleKunder()  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2A - Skriver ALT om EN kunde ut på skjermen.
 *
 *  @param   kunde  -  Kunden som skrives ut
 *  @see     broytStroSkrivNavn(...)
 */
void kundeSkrivData(const struct Kunde* kunde)  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2B - Legger inn (om mulig) en ny kunde inn i datastrukturen.
 *
 *  @see   kundeLesData(...)
 */
void nyKunde()  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2B - Leser inn ALLE datamedlemmene i EN kunde.
 *
 *  @param   kunde  -  Kunden som får innlest sine data
 */
void kundeLesData(struct Kunde* kunde)  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2C - Registrerer brøyting/strøing hos kunder.
 *
 *  @see   kundeBroytetStrodd(...)
 */
void broytetStroddHosKunder()  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2C - Registrerer brøyting/strøing hos EN kunde.
 *
 *  @param    kunde  -  Kunden det registreres brøyting/strøing hos
 */
void kundeBroytetStrodd(struct Kunde* kunde)  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2D - Skriver/lager (om mulig) fakturaer for ALLE kundene.
 *
 *  @see   kundeLagFaktura(...)
 */
void lagFakturaer()  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2D - Skriver ut på skjermen faktura (kostnad) for EN kunde.
 *
 *  @param    kunde  -  Kunden det skrives/lages faktura for
 *  @see      kundeHentKostnad(...)
 *  @see      kundeSkrivData(...)
 */
void kundeLagFaktura(const struct Kunde* kunde)  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2E - Endrer (om mulig) brøyter/strøer for en kunde.
 *
 *  @see   kundeHentKostnad(...)
 *  @see   kundeEndreBroyterStroer(...)
 */
void endreBroyterStroer()  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2E - Endrer en kundes brøyter/strøer.
 *
 *  @param    kunde  -  Kundens som får sin brøyter/strøer endret
 *  @see      broytStroSkrivNavn(...)
 */
void kundeEndreBroyterStroer(struct Kunde* kunde)  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2F - Finner og skriver brøyter/strøer med mest inntjening.
 *
 *  @see   kundeHentBSNr(...)
 *  @see   kundeHentKostnad(...)
 *  @see   broytStroSkrivNavn(...)
 */
void broyterStroerMedMestInntjening()  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2G - Leser ALLE kundene (og ALLE brøytere/strøere) inn fra fil.
 *
 *  @see   kundeLesFraFil(...)
 *  @see   broytStroLesFraFil(...)
 */
void lesFraFil() {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2G - Leser ALT om EN kunde inn fra fil.
 *
 *  @param  inn    -  Filen det skal leses fra
 *  @param  kunde  -  Kunden som får innlest sine data
 */
void kundeLesFraFil(FILE* inn, struct Kunde* kunde) {

   //   LAG INNMATEN
}
