/**
 *   Løsningsforslag til eksamen i GrProg (i C), november 2021, oppgave 2.
 *
 *   Programmet holder orden på ulike kunders lån i ulike banker,
 *   og standardrentene i disse bankene.
 *
 *   @file     EX_H21_2.C
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
void  bankSkrivTilFil(FILE* ut, const struct Bank* bank);      //  EXTRA
void  lesFraFil();                                             //  Oppgave 2G
void  kundeLesFraFil(FILE* inn, struct Kunde* kunde);          //  Oppgave 2G
void  bankLesFraFil(FILE* inn, struct Bank* bank);             //  EXTRA


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
  printf("\n\tAlle bankene i oversikten:\n");
  for (int i = 0;  i < gAntallBanker;  i++) {
      printf("\t   Nr.%3i:  ", i+1);              //  Skriver banknummeret.
      bankSkrivData(gBanker[i]);                  //  Hver skriver seg selv.
  }
}


/**
 *  Oppgave 2A - Skriver ALT om EN bank ut på skjermen.
 *
 *  @param   bank  -  Banken som skrives ut
 */
void bankSkrivData(const struct Bank* bank) {
  printf("%s,   mail: %s,   tlf: %i\n\t\t\t%-60s   RENTE: %.2f\n",
         bank->navn, bank->mail, bank->tlf, bank->adresse, bank->stdRente);
}


/**
 *  Oppgave 2B - Endrer en banks rente.
 *
 *  @see   bankEndreRente(...)
 */
void endreBanksRente() {
  int bankNr;                                         //  Banknr.1-->

  if (gAntallBanker > 0)  {                           //  Banker finnes:
     bankNr = lesInt("\tBanknr", 1, gAntallBanker);
     bankEndreRente(gBanker[bankNr-1]);               //  Banken endrer selv.
  } else
    printf("\n\tIngen banker ennå registrert!\n");
}


/**
 *  Oppgave 2B - Leser inn en banks nye standard rente.
 *
 *  @param   bank  -  Banken som får endret sin rente
 */
void bankEndreRente(struct Bank* bank) {
    printf("\n\tNåværende rente:  %.2f\n", bank->stdRente);
    bank->stdRente = lesFloat("\tNy rente",              // Ny rente: min 0.2
                               0.2, bank->stdRente+2.0); //  max.+2.0 prosent
    printf("\n\tNy standard rente:  %.2f\n", bank->stdRente);
}


/**
 *  Oppgave 2C - Skriver ALLE data om en navngitt kunde.
 *
 *  @see   finnKunde(...)
 *  @see   kundeSkrivData(...)
 */
void skrivEnKunde() {
  int kundeNr;                                 //  Kundenr. 0-->  (evt. -1).
  char navn[STRLEN];                           //  Aktuelt kundenavn.

  if (gAntallKunder > 0)  {                    //  Kunder finnes:
     lesText("\tKundenavn", navn, STRLEN);     //  Leser kundenavn.
     kundeNr = finnKunde(navn);                //  Finner kundens indeks?

     if (kundeNr >= 0)  {                      //  Kunden ble funnet:
        printf("\n\n\tALLE data om kunde nr.%i:\n\n", kundeNr);
        kundeSkrivData(gKunder[kundeNr]);      //  Kunden skriver sine data.
     } else
        printf("\n\tIngen kunde med dette navnet!\n");
  } else
    printf("\n\tIngen kunder ennå registrert!\n");
}


/**
 *  Oppgave 2C - Skriver ALLE data om EN kunde ut på skjermen.
 *
 *  @param   kunde  -  Kunden som får skrevet ut ALLE sine data
 *  @see     bankSkrivNavn(...)
 *  @see     bankHentRente(...)
 */
void kundeSkrivData(const struct Kunde* kunde) {
  float rente;                                 //  Bankrente.
  printf("\t%s,  %s,  %i\n\t\thar lån på kr. %.2f i: ",
         kunde->navn, kunde->mail, kunde->tlf, kunde->laan[0]);
  bankSkrivNavn(gBanker[kunde->bankNr[0]-1]);
  rente = bankHentRente(gBanker[kunde->bankNr[0]-1]);
  printf("    med rente %.2f%%,    dvs.pr.mnd.kr: %.2f\n",
              rente, (kunde->laan[0] * (rente/100)) / 12);    //  Mnd. sum.

  if (kunde->bankNr[1] != 0)  {                //  Samme for evt. andre lånet:
    printf("\t\t og lån på kr. %.2f i: ", kunde->laan[1]);
    bankSkrivNavn(gBanker[kunde->bankNr[1]-1]);
    rente = bankHentRente(gBanker[kunde->bankNr[1]-1]);
    printf("    med rente %.2f%%,    dvs.pr.mnd.kr: %.2f\n",
                rente, (kunde->laan[1] * (rente/100)) / 12);  //  Mnd. sum.
  }
}


/**
 *  Oppgave 2D - Endrer en kundes lån.
 *
 *  @see   finnKunde(...)
 *  @see   kundeEndreLaan(...)
 */
void endreKundesLaan() {
  int kundeNr;                                 //  Kundenr. 0-->  (evt. -1).
  char navn[STRLEN];                           //  Aktuelt kundenavn.

  if (gAntallKunder > 0)  {                    //  Kunder finnes:
     lesText("\tKundenavn", navn, STRLEN);     //  Leser kundenavn.
     kundeNr = finnKunde(navn);                //  Finner kundens indeks?

     if (kundeNr >= 0)                         //  Kunden ble funnet:
        kundeEndreLaan(gKunder[kundeNr]);      //  Kundens ene lån endres.
     else
        printf("\n\tIngen kunde med dette navnet!\n");
  } else
    printf("\n\tIngen kunder ennå registrert!\n");
}


/**
 *  Oppgave 2D - Endrer ett av lånene for en kunde.
 *
 *  @param    kunde  -  Kunden som får endret ETT av sine lån
 *  @see      kundeSkrivData(...)
 */
void kundeEndreLaan(struct Kunde* kunde) {
  int  laanNr;                                       //  Lånenummer 1 eller 2.

  kundeSkrivData(kunde);
  laanNr = lesInt("\n\tHvilket lån skal endres", 1, 2);
                                                     //  Aktuelt lån endres:
  kunde->laan[laanNr-1] = lesFloat("\tNytt lån", 0, MAXLAAN);

  if (kunde->bankNr[laanNr-1] == 0)                  //  Nytt lån - ny bank:
     kunde->bankNr[laanNr-1] = lesInt("\tBanknummer", 1, gAntallBanker);

  printf("\n");
  kundeSkrivData(kunde);
}


/**
 *  Oppgave 2E - Finner og skriver banken med flest lånekunder.
 *
 *  @see      kundeLaanIBank(...)
 *  @see      bankSkrivNavn(...)
 */
void bankMedFlestKunder() {
  int i, j,                                     //  Løkkevariable.
      antall,                                   //  Antall kunder i EN bank.
      flest = 0,                                //  Flest antall kunder.
      bankNr = 0;                               //  Banken med flest kunder.

    for (i = 0;  i < gAntallBanker; i++)  {     //  Går gjennom alle bankene:
        antall = 0;                             //  Nullstiller dens antall.
        for (j = 0;  j < gAntallKunder;  j++)   //  Går gjennom kundene:
            if (kundeLaanIBank(gKunder[j], i+1))  antall++; // Lån i aktuell
                                                            //   bank.
        if (antall > flest)  {                  //  Nytt høyeste antall:
            flest = antall;                     //  Lagrer unna høyeste antall
            bankNr = i+1;                       //    og aktuell banknummer.
        }
    }

    if (bankNr != 0)  {                         //  Bank med flest lånekunder
        printf("\n\tFlest kunder har  ");       //    funnet:
        bankSkrivNavn(gBanker[bankNr-1]);
        printf("  med %i kunder.\n", flest);
    } else
        printf("\n\tIngen aktueller banker funnet.\n");
}


/**
 *  Oppgave 2E - Finner ut om kunden har lån i bank nummer 'nr'.
 *
 *  @param    kunde  -  Aktuell kunde å sjekke for lånebank
 *  @param    nr     -  Nummer/indeks til en bank
 *  @return   Om 'kunde' har lån (true) i bank nr 'nr' eller ei (false)
 */
bool kundeLaanIBank(const struct Kunde* kunde, const int nr) {
  return (kunde->bankNr[0] == nr  ||  kunde->bankNr[1] == nr);
}


/**
 *  Oppgave 2F - Skriver ALLE kundene (og bankene) til fil.
 *
 *  @see   kundeSkrivTilFil(...)
 *  @see   bankSkrivTilFil(...)
 */
void skrivTilFil() {
  FILE* utfil = fopen("EX_H21_KUNDER.DT2", "w"); //  Åpner aktuell fil:

  if (utfil) {                                   //  Filen kan åpnes:
    printf("\n\tSkriver til filen 'EX_H21_KUNDER.DT2'.....\n");

    fprintf(utfil, "%i\n", gAntallKunder);       //  Skriver antall kunder.
                                                 //  Går gjennom ALLE kundene:
    for (int i = 0; i < gAntallKunder; i++)
        kundeSkrivTilFil(utfil, gKunder[i]);     //  Hver kunde skrives.
  } else                                   //  Filen ikke funnet/mulig å åpne:
    printf("Klarte ikke å åpne filen 'EX_H21_KUNDER.DT2'!\n\n");

  fclose(utfil);                                 //  Lukker filen.


//  EXTRA (resten av funksjonen): *******************************************
  utfil = fopen("EX_H21_BANKER.DT2", "w");       //  Åpner aktuell fil:

  if (utfil) {                                   //  Filen kan åpnes:
    printf("\n\tSkriver til filen 'EX_H21_BANKER.DT2'.....\n\n");

    fprintf(utfil, "%i\n", gAntallBanker);       //  Skriver antall banker.
                                                 //  Går gjennom ALLE bankene:
    for (int i = 0; i < gAntallBanker; i++)
        bankSkrivTilFil(utfil, gBanker[i]);      //  Hver bank skrives.
  } else                                   //  Filen ikke funnet/mulig å åpne:
    printf("Klarte ikke å åpne filen 'EX_H21_BANKER.DT2'!\n\n");

  fclose(utfil);                                 //  Lukker filen.
}


/**
 *  Oppgave 2F - Alle EN kundes data skrives ut på fil.
 *
 *  @param   ut     -  Filen det skal skrives til
 *  @param   kunde  -  Kunden som skrives til fil
 */
void kundeSkrivTilFil(FILE* ut, const struct Kunde* kunde) {
  fprintf(ut, "%s\n%s %i %.2f %.2f %i %i\n", kunde->navn, kunde->mail,
               kunde->tlf, kunde->laan[0], kunde->laan[1],
               kunde->bankNr[0], kunde->bankNr[1]);
}


/**
 *  EXTRA - Alle EN banks data skrives ut på fil.
 *
 *  @param   ut    -  Filen det skal skrives til
 *  @param   bank  -  Banken som skrives til fil
 */
void bankSkrivTilFil(FILE* ut, const struct Bank* bank){
  fprintf(ut, "%s\n%s\n%s  %i  %.2f\n", bank->navn, bank->adresse,
               bank->mail, bank->tlf, bank->stdRente);
}


/**
 *  Oppgave 2G - Leser ALLE kundene (og bankene) fra fil.
 *
 *  @see   kundeLesFraFil(...)
 *  @see   bankLesFraFil(...)
 */
void lesFraFil() {
  FILE* innfil  = fopen("EX_H21_KUNDER.DTA", "r"); //  Åpner aktuell fil:

  if (innfil) {                                    //  Filen finnes:
     fscanf(innfil, "%i", &gAntallKunder);         //  Leser antall kunder.
     getc(innfil);                                 //  Leser avsluttende '\n'.
                                               //  Alle kunder lages og leses:
     for (int i = 0;  i < gAntallKunder;  i++) {
       gKunder[i] = (struct Kunde*) malloc(sizeof(struct Kunde));
       kundeLesFraFil(innfil, gKunder[i]);     // Leser selv.
     }
     printf("\n\tKunder er lest inn fra 'EX_H21_KUNDER.DTA'!\n");
  } else                                       //  Filen ikke funnet:
     printf("\n\tFant ikke filen 'EX_H21_KUNDER.DTA'!\n\n");

  fclose(innfil);                              //  Lukker åpen fil.


//  EXTRA (resten av funksjonen): *******************************************
  innfil = fopen("EX_H21_BANKER.DTA", "r");

  if (innfil) {                                //  Filen finnes:
     fscanf(innfil, "%i", &gAntallBanker);     //  Leser antall kunder.
     getc(innfil);                             //  Leser avsluttende '\n'.
                                               //  Alle kunder lages og leses:
     for (int i = 0;  i < gAntallBanker;  i++) {
       gBanker[i] = (struct Bank*) malloc(sizeof(struct Bank));
       bankLesFraFil(innfil, gBanker[i]);      // Leser selv.
     }
     printf("\n\tBanker er lest inn fra 'EX_H21_BANKER.DTA'!\n\n");
     fclose(innfil);                           //  Lukker åpen fil.
  } else                                       //  Filen ikke funnet:
     printf("\n\tFant ikke filen 'EX_H21_BANKER.DTA'!\n\n");
}


/**
 *  Oppgave 2G - Leser ALT om EN kunde fra fil.
 *
 *  @param  inn    -  Filen det skal leses fra
 *  @param  kunde  -  Kunden som får innlest sine data
 */
void kundeLesFraFil(FILE* inn, struct Kunde* kunde) {
    char buffer[STRLEN];                //  Buffer for innlest tekst.
                                        //  Leser 'navn':
    fgets(buffer, STRLEN, inn);    buffer[strlen(buffer)-1] = '\0';
    kunde->navn = (char*) malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(kunde->navn, buffer);
                                        //  Leser 6x andre datamedlemmer:
    fscanf(inn, "%s %i %f %f %i %i", buffer, &kunde->tlf,
                 &kunde->laan[0], &kunde->laan[1],
                 &kunde->bankNr[0], &kunde->bankNr[1]);   //  Lagrer mailen:
    kunde->mail = (char*) malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(kunde->mail, buffer);

    getc(inn);                          //  Forkaster avsluttende '\n'.
}


/**
 *  EXTRA - Leser ALT om EN bank fra fil.
 *
 *  @param  inn   -  Filen det skal leses fra
 *  @param  bank  -  Banken som får innlest sine data
 */
void bankLesFraFil(FILE* inn, struct Bank* bank)  {
    char buffer[STRLEN];                //  Buffer for innlest tekst.
                                        //  Leser 'navn':
    fgets(buffer, STRLEN, inn);    buffer[strlen(buffer)-1] = '\0';
    bank->navn = (char*) malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(bank->navn, buffer);
                                        //  Leser 'adresse':
    fgets(buffer, STRLEN, inn);    buffer[strlen(buffer)-1] = '\0';
    bank->adresse = (char*) malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(bank->adresse, buffer);
                                        //  Leser 'mail', 'tlf' og 'stdRente':
    fscanf(inn, "%s %i %f", buffer, &bank->tlf, &bank->stdRente);
    bank->mail = (char*) malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(bank->mail, buffer);

    getc(inn);                          //  Forkaster avsluttende '\n'.
}
