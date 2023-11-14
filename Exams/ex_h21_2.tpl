/**
 *   Skjelett eksamen i GrProg (i C), november 2021, oppgave 2.
 *
 *   Programmet holder orden på ulike kunders lån i ulike banker,
 *   og standardrentene i disse bankene.
 *
 *   @file     EX_H21_2.TPL
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>               //  printf, FILE
#include <stdlib.h>              //  sizeof, malloc
#include <string.h>              //  strcpy, strlen, strcmp
#include <stdbool.h>             //  bool, true, false
#include "LesData.h"             //  Verktøykasse for lesing av diverse data


#define   MAXKUNDER      500     ///<  Max. antall kunder.
#define   MAXBANKER       20     ///<  Max. antall banker.
const int STRLEN  =       80;    ///<  Max. tekstlengde.
const int MAXLAAN = 30000000;    ///<  Max. lån (30 millioner).


/**
 *  Kunde (med navn, mailadresse, mobilnr og lånene i max.to ulike banker).
 */
struct Kunde {
  char* navn,                    //  Kundens:  - navn
      * mail;                    //            - mail-adresse
  int   tlf;                     //            - mobilnummer
  float laan[2];                 //            - lånenes størrelse
  int   bankNr[2];               //            - indeksen på lånebankene
};


/**
 *  Bank (med navn, adresse, mail, telefon og nåværende rente).
 */
struct Bank  {
   char* navn,                   //  Bankens:  - navn
       * adresse,                //            - gate- og stedsadresse
       * mail;                   //            - mail-adresse
   int   tlf;                    //            - telefonnummer
   float stdRente;               //            - nåværende standard rente
};


void  skrivMeny();                                             //  |
float bankHentRente(const struct Bank* bank);                  //  | Ferdig-
void  bankSkrivNavn(const struct Bank* bank);                  //  | laget:
int   finnKunde(const char* nvn);                              //  |
bool  kundeHeter(const struct Kunde* kunde, const char* nvn);  //  |
void  skrivAlleBankene();                                      //  Oppgave 2A
void  bankSkrivData(const struct Bank* bank);                  //  Oppgave 2A
void  endreBanksRente();                                       //  Oppgave 2B
void  bankEndreRente(struct Bank* bank);                       //  Oppgave 2B
void  skrivEnKunde();                                          //  Oppgave 2C
void  kundeSkrivData(const struct Kunde* kunde);               //  Oppgave 2C
void  endreKundesLaan();                                       //  Oppgave 2D
void  kundeEndreLaan(struct Kunde* kunde);                     //  Oppgave 2D
void  bankMedFlestKunder();                                    //  Oppgave 2E
bool  kundeLaanIBank(const struct Kunde* kunde, const int nr); //  Oppgave 2E
void  skrivTilFil();                                           //  Oppgave 2F
void  kundeSkrivTilFil(FILE* ut, const struct Kunde* kunde);   //  Oppgave 2F
void  lesFraFil();                                             //  Oppgave 2G
void  kundeLesFraFil(FILE* inn, struct Kunde* kunde);          //  Oppgave 2G


int    gAntallKunder;                   ///<  Antall kunder hittil registrert.
struct Kunde* gKunder[MAXKUNDER];       ///<  Alle kundene.
int    gAntallBanker;                   ///<  Antall banker hittil registrert.
struct Bank*  gBanker[MAXBANKER];       ///<  Alle bankene.


/**
 *  Hovedprogrammet:
 */
int main()  {
    char kommando;

    lesFraFil();                                             //  Oppgave 2G

    skrivMeny();
    kommando = lesChar("\nØnske");

    while (kommando != 'Q') {
        switch (kommando) {
          case 'B':   skrivAlleBankene();          break;    //  Oppgave 2A
          case 'R':   endreBanksRente();           break;    //  Oppgave 2B
          case 'K':   skrivEnKunde();              break;    //  Oppgave 2C
          case 'E':   endreKundesLaan();           break;    //  Oppgave 2D
          case 'F':   bankMedFlestKunder();        break;    //  Oppgave 2E
          default:    skrivMeny();                 break;
        }
        kommando = lesChar("\nØnske");
    }

    skrivTilFil();                                           //  Oppgave 2F

    return 0;
}


/**
 *  Skriver/presenterer programmets muligheter/valg for brukeren.
 */
void skrivMeny() {
    printf("\nFØLGENDE KOMMANDOER ER LOVLIG:\n");
    printf("\tB   = skriv ALLE Bankene\n");
    printf("\tR   = endre en banks standard Rente\n");
    printf("\tK   = skriv EN Kunde\n");
    printf("\tE   = Endre (øke/minske) en kundes lån\n");
    printf("\tF   = skriv banken med Flest kunder\n");
    printf("\tQ   = Quit/avslutt\n");
}


/**
 *  Returnerer en banks for øyeblikket standard rente.
 *
 *  @param    bank  -  Banken som får returnert sin rente
 *  @return   'bank' sin standard rente
 */
float bankHentRente(const struct Bank* bank)  {
  return (bank->stdRente);
}


/**
 *  Skriver KUN en banks navn.
 *
 *  @param   bank  -  Banken som får skrevet ut sitt navn
 */
void bankSkrivNavn(const struct Bank* bank)  {
  printf("%s", bank->navn);
}


/**
 *  Prøver å finne indeksen i 'gKunder' for en navngitt kunde.
 *
 *  @param   nvn  -  Søkt kundes navn
 *  @return  Indeksen for kunden, evt. -1 om ikke ble funnet
 */
int finnKunde(const char* nvn)  {
    for (int i = 0;  i < gAntallKunder;  i++)
        if (!strcmp(gKunder[i]->navn, nvn))  return i;   //  Funn/match!

    return -1;                           //  Ikke funnet noen med dette 'nvn'.
}


/**
 *  Returnerer om en kunde har et gitt navn eller ei.
 *
 *  @param    kunde  -  Kunden som skal sjekkes om har navnet 'nvn'
 *  @param    nvn    -  Navnet å sjekke om 'kunde' har eller ei
 *  @return   Om kunden har navnet (true) 'nvn' eller ei (false)
 */
bool kundeHeter(const struct Kunde* kunde, const char* nvn) {
  return (!strcmp(kunde->navn, nvn));
}


/**
 *  Oppgave 2A - Skriver ALT om ALLE banker.
 *
 *  @see   bankSkrivData(...)
 */
void skrivAlleBankene() {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2A - Skriver ALT om EN bank ut på skjermen.
 *
 *  @param   bank  -  Banken som skrives ut
 */
void bankSkrivData(const struct Bank* bank) {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2B - Endrer en banks rente.
 *
 *  @see   bankEndreRente(...)
 */
void endreBanksRente() {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2B - Leser inn en banks nye standard rente.
 *
 *  @param   bank  -  Banken som får endret sin rente
 */
void bankEndreRente(struct Bank* bank) {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2C - Skriver ALLE data om en navngitt kunde.
 *
 *  @see   finnKunde(...)
 *  @see   kundeSkrivData(...)
 */
void skrivEnKunde() {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2C - Skriver ALLE data om EN kunde ut på skjermen.
 *
 *  @param   kunde  -  Kunden som får skrevet ut ALLE sine data
 *  @see     bankSkrivNavn(...)
 *  @see     bankHentRente(...)
 */
void kundeSkrivData(const struct Kunde* kunde) {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2D - Endrer en kundes lån.
 *
 *  @see   finnKunde(...)
 *  @see   kundeEndreLaan(...)
 */
void endreKundesLaan() {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2D - Endrer ett av lånene for en kunde.
 *
 *  @param    kunde  -  Kunden som får endret ETT av sine lån
 *  @see      kundeSkrivData(...)
 */
void kundeEndreLaan(struct Kunde* kunde) {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2E - Finner og skriver banken med flest lånekunder.
 *
 *  @see      kundeLaanIBank(...)
 *  @see      bankSkrivNavn(...)
 */
void bankMedFlestKunder() {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2E - Finner ut om kunden har lån i bank nummer 'nr'.
 *
 *  @param    kunde  -  Aktuell kunde å sjekke for lånebank
 *  @param    nr     -  Nummer/indeks til en bank
 *  @return   Om 'kunde' har lån (true) i bank nr 'nr' eller ei (false)
 */
bool kundeLaanIBank(const struct Kunde* kunde, const int nr) {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2F - Skriver ALLE kundene til fil.
 *
 *  @see   kundeskrivTilFil(...)
 */
void skrivTilFil() {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2F - Alle EN kundes data skrives ut på fil.
 *
 *  @param   ut     -  Filen det skal skrives til
 *  @param   kunde  -  Kunden som skrives til fil
 */
void kundeSkrivTilFil(FILE* ut, const struct Kunde* kunde) {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2G - Leser ALLE kundene fra fil.
 *
 *  @see   kundeLesFraFil(...)
 */
void lesFraFil() {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2G - Leser ALT om EN kunde fra fil.
 *
 *  @param  inn    -  Filen det skal leses fra
 *  @param  kunde  -  Kunden som får innlest sine data
 */
void kundeLesFraFil(FILE* inn, struct Kunde* kunde) {

    //   LAG INNMATEN
}
