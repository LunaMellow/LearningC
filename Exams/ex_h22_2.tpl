/**
 *   Skjelett eksamen i GrProg (i C), desember 2022, oppgave 2.
 *
 *   Programmet holder orden på ulike hendelser (overnattinger,
 *   aktiviteter/gjøremål og bespisning) under en biltur (i Alpene).
 *
 *   @file     EX_H22_2.TPL
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>               //  printf, scanf, FILE
#include <stdlib.h>              //  sizeof, malloc
#include <string.h>              //  strcpy, strlen
#include <stdbool.h>             //  bool, true, false
#include "LesData.h"             //  Verktøykasse for lesing av diverse data


#define   MAXHENDELSER   100     ///<  Max. antall hendelser på turen.
const int STRLEN  =       80;    ///<  Max. tekstlengde.


/**
 *  Type hendelse (ulike type hendelser som kan skje på turen).
 */
enum Type { Attraksjon, Fjelltopp, Hotell, Idrettsarena, Museum, Spisested };


/**
 *  Hendelse (med navn, sted, webside, dato, klokkeslett og hendelsestype).
 */
struct Hendelse {             //  Hendelsens:
  char* navn,                 //     - navn
      * sted,                 //     - sted
      * webside;              //     - webside/URL
  int   dato,                 //     - dato, på formen: MMDD (måned/dag)
        klokken;              //     - klokkeslett, på formen: TTMM (time/min)
  enum Type type;             //     - jfr. ovenstående 'enum'
};


void skrivMeny();                                              //  | Ferdig-
void skrivTypeTekst(const enum Type type);                     //  | laget:
enum Type typeFraChar(const char tegn);                        //  |
void nyHendelse();                                             //  Oppgave 2A
void hendelseLesData(struct Hendelse* hendelse);               //  Oppgave 2A
void skrivAlt();                                               //  Oppgave 2B
void hendelseSkrivData(const struct Hendelse* hendelse);       //  Oppgave 2B
enum Type lesHendelsesType();                                  //  Oppgave 2C
void nyHendelse2();                                            //  Oppgave 2D
void skrivGitteHendelser();                                    //  Oppgave 2E
void datoMedFlestHendelser();                                  //  Oppgave 2F
void lesFraFil();                                              //  Oppgave 2G
void hendelseLesFraFil(FILE* inn, struct Hendelse* hendelse);  //  Oppgave 2G


int    gAntallHendelser;             ///<  Antall hendelser hittil registrert.
struct Hendelse* gHendelser[MAXHENDELSER];  ///<  Alle hendelsene.


/**
 *  Hovedprogrammet:
 */
int main()  {
    char kommando;

    lesFraFil();                                          //  Oppgave 2G

    skrivMeny();
    kommando = lesChar("\nØnske");

    while (kommando != 'Q') {
        switch (kommando) {
          case 'N':  nyHendelse2();             break;    //  Oppgave 2A og 2D
          case 'S':  skrivAlt();                break;    //  Oppgave 2B
          case 'G':  skrivGitteHendelser();     break;    //  Oppgave 2E
          case 'F':  datoMedFlestHendelser();   break;    //  Oppgave 2F
          default:   skrivMeny();               break;
        }
        kommando = lesChar("\nØnske");
    }

//    skrivTilFil();                         //  Ikke del av eksamensoppgaven.

    return 0;
}


/**
 *  Skriver/presenterer programmets muligheter/valg for brukeren.
 */
void skrivMeny() {
    printf("\nFØLGENDE KOMMANDOER ER LOVLIG:\n");
    printf("\tN   = Ny hendelse\n");
    printf("\tS   = Skriv alle hendelser\n");
    printf("\tG   = skriv Gitte hendelser\n");
    printf("\tF   = skriv datoen med Flest hendelser\n");
    printf("\tQ   = Quit/avslutt\n");
}


/**
 *  Skriver ut en Type på skjermen som tekst.
 *
 *  @param   type  -  Hendelsestypen som skrives ut
 */
void skrivTypeTekst(const enum Type type)  {
   switch (type)  {                          //  Skriver enum-verdi som tekst:
     case Attraksjon:    printf("Attraksjon    ");   break;
     case Fjelltopp:     printf("Fjelltopp     ");   break;
     case Hotell:        printf("Hotell        ");   break;
     case Idrettsarena:  printf("Idrettsarena  ");   break;
     case Museum:        printf("Museum        ");   break;
     case Spisested:     printf("Spisested     ");   break;
   }
}


/**
 *  Gjør om en lovlig bokstav til en aktuell enum-verdi.
 *
 *  @param    tegn  -  Bokstav/tegn som skal konverteres til enum-verdi
 *  @return   Enum-verdi ut fra en bokstav/tegn
 */
enum Type typeFraChar(const char tegn)  {
  switch (tegn)  {
    case 'A':  return  Attraksjon;               //  Ut fra bokstav returneres
    case 'F':  return  Fjelltopp;                //    aktuell enum-verdi:
    case 'H':  return  Hotell;
    case 'I':  return  Idrettsarena;
    case 'M':  return  Museum;
    case 'S':  return  Spisested;
  }
}


/**
 *  Oppgave 2A - Legger inn (om mulig) en ny hendelse inn i datastrukturen.
 *
 *  @see      hendelseLesData(...)
 */
void nyHendelse()  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2A - Leser inn ALLE datamedlemmene i EN hendelse.
 *
 *  @param   hendelse  -  Hendelsen som får innlest sine data
 *  @see     lesHendelsesType()
 */
void hendelseLesData(struct Hendelse* hendelse)  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2B - Skriver ALT om ALLE hendelsene.
 *
 *  @see   hendelseSkrivData(...)
 */
void skrivAlt()  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2B - Skriver ALT om EN hendelse ut på skjermen.
 *
 *  @param   hendelse  -  Hendelsen som skrives ut
 */
void hendelseSkrivData(const struct Hendelse* hendelse)  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2C - Leser forbokstaven i de ulike Typene, returnerer aktuell enum.
 *
 *  @return  Enum-verdien ut fra forbokstaven i selve enum-verdien
 */
enum Type lesHendelsesType()  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2D - SMETTER INN (om mulig) en ny hendelse inn i datastrukturen.
 *
 *  @see      skrivAlt()
 *  @see      hendelseLesData(...)
 */
void nyHendelse2()  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2E - Skriver aktuelle hendelser på ønsket dato eller av type.
 *
 *  @see      hendelseSkrivData(...)
 */
void skrivGitteHendelser()  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2F - Skriver (den første) datoen med flest hendelser.
 */
void datoMedFlestHendelser()  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2G - Leser ALLE hendelsene inn fra fil.
 *
 *  @see   hendelseLesFraFil(...)
 */
void lesFraFil() {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2G - Leser ALT om EN hendelse inn fra fil.
 *
 *  @param  inn       -  Filen det skal leses fra
 *  @param  hendelse  -  Hendelsen som får innlest sine data
 */
void hendelseLesFraFil(FILE* inn, struct Hendelse* hendelse) {

   //   LAG INNMATEN
}
