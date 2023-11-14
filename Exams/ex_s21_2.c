/**
 *  Løsningsforslag til kontinuasjonseksamen i GrProg (i C), aug 2021, oppg 2.
 *
 *  Programmet holder orden på ulike rakfisk- og pultostprodukter,
 *  og hvem som har produsert disse.
 *
 *  @file     EX_S21_2.C
 *  @author   Frode Haug, NTNU
 */


#include <stdio.h>               //  printf, FILE
#include <stdlib.h>              //  sizeof, malloc
#include <string.h>              //  strcpy, strlen, strstr
#include <stdbool.h>             //  bool, true, false
#include "LesData.h"             //  Verktøykasse for lesing av diverse data


#define   MAXPRODUKTER  200      ///<  Max. antall produkter.
#define   ANTPRODUSENTER  5      ///<  Max. antall produsenter.
const int STRLEN   =     80;     ///<  Max. tekstlengde.
const int MAXKILO  = 100000;     ///<  Max. antall kilo årlig produsert.


/**
 *  Type (et produkt er enten 'Rakfisk' eller 'Pultost').
 */
enum Type { Rakfisk,  Pultost };


/**
 *  Produkt (med navn, produkttype, produsentens nr/indeks og årlige kilo).
 */
struct Produkt {
    char* navn;                  //  Produktets navn/beskrivelse.
    enum Type type;              //  Produkttype:  Rakfisk eller Pultost.
    int produsentNr;             //  Produsentens nr (navn) - 0 til 4.
    int antallKg;                //  Ca. antall kilo i årlig produksjon.
};


void skrivMeny();
enum Type lesType();
void skrivAlleProduktene();                                    //  Oppgave 2A
void produktSkrivData(const struct Produkt* p);                //  Oppgave 2A
void nyttProdukt();                                            //  Oppgave 2B
void produktLesData(struct Produkt* p);                        //  Oppgave 2B
void skrivAlleAvType();                                        //  Oppgave 2C
bool produktErType(const struct Produkt* p, enum Type t);      //  Oppgave 2C
void endreKilo();                                              //  Oppgave 2D
void produktEndreKilo(struct Produkt* p);                      //  Oppgave 2D
void skrivAlleMedNavn();                                       //  Oppgave 2E
bool produktMedSubtekst(const struct Produkt* p,const char* nvn);  // Oppg.2E
void skrivTilFil();                                            //  Oppgave 2F
void produktSkrivTilFil(FILE* ut, const struct Produkt* p);    //  Oppgave 2F
void lesFraFil();                                              //  Oppgave 2G
void produktLesFraFil(FILE* inn, struct Produkt* p);           //  Oppgave 2G


int    gAntallProdukter;             ///<  Antall produkter hittil registrert.
struct Produkt* gProdukter[MAXPRODUKTER];  ///<  Alle produktene.
char*  gProdusent[ANTPRODUSENTER] =        ///<  Aktuelle produsentnavn.
         { "LofossBakken", "TineRøn", "WangenFinden",
           "HaademHolen", "SynnøveNoraker" };


/**
 *  Hovedprogrammet:
 */
int main()  {
    char kommando;

    lesFraFil();                                            //  Oppgave 2G

    skrivMeny();
    kommando = lesChar("\nØnske");

    while (kommando != 'Q') {
        switch (kommando) {
           case 'A': skrivAlleProduktene();         break;  //  Oppgave 2A
           case 'N': nyttProdukt();                 break;  //  Oppgave 2B
           case 'T': skrivAlleAvType();             break;  //  Oppgave 2C
           case 'E': endreKilo();                   break;  //  Oppgave 2D
           case 'I': skrivAlleMedNavn();            break;  //  Oppgave 2E
           default:  skrivMeny();                   break;
        }
        kommando = lesChar("\nØnske");
    }

    skrivTilFil();                                          //  Oppgave 2F

    return 0;
}


/**
 *  Skriver/presenterer programmets muligheter/valg for brukeren.
 */
void skrivMeny() {
    printf("\nFØLGENDE KOMMANDOER ER LOVLIG:\n");
    printf("\tA   = skriv Alle produktene\n");
    printf("\tN   = Ny produkt\n");
    printf("\tT   = skriv produktene av en Type\n");
    printf("\tE   = Endre ca.antall kilo årlig produsert\n");
    printf("\tI   = skriv produktene Inneholdende tekst i navnet\n");
    printf("\tQ   = Quit/avslutt\n");
}


/**
 *  Leser forbokstaven i 'Rakfisk/Pultost', og returnerer aktuell enum-verdi.
 *
 *  @return  Enum-verdi ut fra forbokstaven i enum-verdien
 */
enum Type lesType() {
  char tegn;
  do  {                                               //  Leser og sikrer kun
    tegn = lesChar("\tType (R(akfisk), P(ultost))");  //    bokstavene
  } while (tegn != 'R'  &&  tegn != 'P');             //    'R' og 'P'.
  return ((tegn == 'R') ? Rakfisk : Pultost);         //  Returnerer aktuell
}                                                     //    enum-verdi.


/**
 *  Oppgave 2A - Skriver ALT om ALLE produkter.
 *
 *  @see   produktSkrivData(...)
 */
void skrivAlleProduktene() {
  printf("\n\tAlle produktene i oversikten:\n");
  for (int i = 0;  i < gAntallProdukter;  i++) {  //  Går gjennom ALLE prod:
      printf("\t   Nr.%3i:  ", i+1);              //  Skriver produktnummer.
      produktSkrivData(gProdukter[i]);            //  Hver skriver seg selv.
  }
}


/**
 *  Oppgave 2A - Skriver ALT om ETT produkt ut på skjermen.
 *
 *  @param   p - Produktet som skrives ut
 */
void produktSkrivData(const struct Produkt* p)  {
   printf("%s,  %s,  ca.%i kg,  %s\n", p->navn,    //  Enum skrives som tekst:
                               ((p->type == Rakfisk) ? "RAKFISK" : "PULTOST"),
                                 p->antallKg, gProdusent[p->produsentNr]);
}


/**
 *  Oppgave 2B - Legger inn (om mulig) et nytt produkt i datastrukturen.
 *
 *  @see   produktLesData(...)
 */
void nyttProdukt() {
  if (gAntallProdukter < MAXPRODUKTER) {        // Plass til flere produkter:
     printf("\nNy produkt har nr.%i:\n", gAntallProdukter+1);
     gProdukter[gAntallProdukter] =             //  Oppretter et nytt produkt:
                         (struct Produkt*) malloc(sizeof(struct Produkt));
     produktLesData(gProdukter[gAntallProdukter]);  //  Leser egne data.
     gAntallProdukter++;                            //  Antallet økes.
  } else                                            //  Fullt med produkter:
     printf("\n\tFullt med %i produkter allerede!\n", MAXPRODUKTER);
}


/**
 *  Oppgave 2B - Leser inn alle relevante datamedlemmer.
 *
 *  @param   p -  Produktet som får innlest sine data
 */
void produktLesData(struct Produkt* p) {
  p->navn   = lagOgLesText("\tNavn");           //  Leser 4x datamedlemmer:
  p->type   = lesType();
  p->produsentNr = lesInt("\tProdusentnr  ", 1, ANTPRODUSENTER) - 1;
  p->antallKg    = lesInt("\tCa.kilo årlig", 0, MAXKILO);
}


/**
 *  Oppgave 2C - Skriver (om mulig) ALT om ALLE produkter av EN GITT type.
 *
 *  @see   lesType()
 *  @see   produktErType(...)
 *  @see   produktSkrivData(...)
 */
void skrivAlleAvType() {
  enum Type type;                                   //  Ønsket enum-type.
  bool funn = false;                                //  Foreløpig ingen funn.

  if (gAntallProdukter > 0)  {                      //  Produkt(er) finnes:
      type = lesType();                             //  Leser enum-verdi.
      printf("\n\tAlle produktene i denne kategorien:\n");
      for (int i = 0;  i < gAntallProdukter;  i++)  // Går gjennom produktene:
          if (produktErType(gProdukter[i], type)) { //  Type-match:
             funn = true;                           //  Minst ett funn.
             printf("\t   Nr.%3i:  ", i+1);         //  Skriver produktnummer.
             produktSkrivData(gProdukter[i]);       //  Hver skriver seg selv.
          }
    if (!funn)                                      //  Ingen funn:
        printf("\n\t\tIngen produkter ennå av denne typen i registeret!\n");
  } else                                            //  Ingen produkter:
    printf("\n\tIngen produkter ennå registrert!\n");
}


/**
 *  Oppgave 2C - Returnerer om produktet er av en gitt type.
 *
 *  @param    p  -  Aktuelt produkt å sjekke 'type' for
 *  @param    t  -  Aktuell enum-type å sjekke opp mot
 *  @return   Om produktet 'p' har 'type' lik 't' eller ei
 */
bool produktErType(const struct Produkt* p, enum Type t){
    return (p->type == t);                          //  Typematch eller ei.
}


/**
 *  Oppgave 2D - Endrer (om mulig) et produkts antall kilo årlig produsert.
 *
 *  @see   produktEndreKilo(...)
 */
void endreKilo() {
  int nr;                                             //  Produktnummer.
  if (gAntallProdukter > 0) {                         //  Produkt(er) finnes:
     nr = lesInt("\tProduktnr", 0, gAntallProdukter); //  Leser produktnr.
     if (nr > 0)                                      //  Reelt nummer:
        produktEndreKilo(gProdukter[nr-1]);           //  Endrer selv kiloene.
     else                                             //  '0' - "angrer"
        printf("\n\tOK - ingen produkt endrer kilo-produksjon.\n");
  } else                                              //  Ingen produkter:
    printf("\n\tIngen produkter ennå registrert!\n");
}


/**
 *  Oppgave 2D - Endrer et produkts antall kilo årlig produsert.
 *
 *  @param   p  -  Aktuell produkt å endre antall kilo for
 *  @see     produktSkrivData(...)
 */
void produktEndreKilo(struct Produkt* p) {
  printf("\n\tNåværende data:  ");
  produktSkrivData(p);                              //  Pr.nå lagrede data.
  p->antallKg = lesInt("\n\tCa.kilo årlig", 0, MAXKILO);  //  Leser nye kilo.
  printf("\n\tNytt antall kilo:  %i", p->antallKg); //  Skriver oppdateringen.
}


/**
 *  Oppgave 2E - Skriver (om mulig) ALLE produkter med (sub)tekst i navnet.
 *
 *  @see   produktMedSubtekst(...)
 *  @see   produktSkrivData(...)
 */
void skrivAlleMedNavn() {
  char tekst[STRLEN];                            //  Ønsket (sub)tekst i navn.
  bool funn = false;                             //  Foreløpig ingen funn.

  if (gAntallProdukter > 0)  {                   //  Produkt(er) finnes:
      lesText("\tTekst i produktnavnet", tekst, STRLEN);  //  Leser subtekst.
      printf("\n\tAlle produktene inneholdende dette i navnet:\n");
      for (int i = 0;  i < gAntallProdukter;  i++)  // Går gjennom produktene:
          if (produktMedSubtekst(gProdukter[i], tekst)) { //  Subtekst-match:
             funn = true;                           //  Minst ett funn.
             printf("\t   Nr.%3i:  ", i+1);         //  Skriver produktnummer.
             produktSkrivData(gProdukter[i]);       //  Hver skriver seg selv.
          }
    if (!funn)                                      //  Ingen funn:
        printf("\n\t\tINGEN!\n");
  } else                                            //  Ingen produkter:
    printf("\n\tIngen produkter ennå registrert!\n");
}


/**
 *  Oppgave 2E - Returnerer om produktet innholder en tekst i navnet sitt.
 *
 *  @param    p    -  Aktuelt produkt å sjekke om inneholder subteksten 'nvn'
 *  @param    nvn  -  Aktuell tekst å sjekke om er (sub)tekst i 'p->navn'
 *  @return   Om produktet 'p' inneholder subteksten 'nvn' eller ei
 */
bool produktMedSubtekst(const struct Produkt* p, const char* nvn)  {
   return (strstr(p->navn, nvn));
}


/**
 *  Oppgave 2F - Skriver ALLE produktene til fil.
 *
 *  @see   produktSkrivTilFil(...)
 */
void skrivTilFil() {
  FILE* utfil = fopen("EX_S21_PRODUKT.DT2", "w");  //  Åpner aktuell fil:

  if (utfil) {                                //  Filen kan åpnes:
    printf("\n\n\tSkriver til filen 'EX_S21_PRODUKT.DT2'.....\n\n");

    fprintf(utfil, "%i\n", gAntallProdukter); //  Skriver antall produkter.
                                              //  Går gjennom ALLE produktene:
    for (int i = 0; i < gAntallProdukter; i++)
        produktSkrivTilFil(utfil,gProdukter[i]); // Hvert produkt skrives.
  } else                                   //  Filen ikke funnet/mulig å åpne:
    printf("Klarte ikke å åpne filen 'EX_S21_PRODUKT.DT2'!\n\n");

  fclose(utfil);                              //  Lukker filen.
}


/**
 *  Oppgave 2F - Alle dataene for ETT produkt skrives ut på fil.

 *
 *  @param   ut  - Filen det skal skrives til
 *  @param   p   - Produktet som skrives til fil
 */
void produktSkrivTilFil(FILE* ut, const struct Produkt* p) {
  fprintf(ut, "%s\n%s %i %i\n", p->navn,      //  Skriver 4x datamedlemmer:
          ((p->type == Rakfisk) ? "R" : "P"), p->produsentNr, p->antallKg);
}


/**
 *  Oppgave 2G - Leser ALLE produktene fra fil.
 *
 *  @see     produktLesFraFil(...)
 */
void lesFraFil() {
  FILE* innfil = fopen("EX_S21_PRODUKT.DTA", "r"); //  Åpner aktuell fil:

  if (innfil) {                                    //  Filen finnes:
     fscanf(innfil, "%i", &gAntallProdukter);      //  Leser antall produkter.
     getc(innfil);                                 //  Leser avsluttende '\n'.
                                            //  Alle produkter lages og leses:
     for (int i = 0;  i < gAntallProdukter;  i++) {
       gProdukter[i] = (struct Produkt*) malloc(sizeof(struct Produkt));
       produktLesFraFil(innfil, gProdukter[i]);    // Leser selv.
     }
     printf("\n\tProdukter er lest inn fra 'EX_S21_PRODUKT.DTA'!\n\n");
     fclose(innfil);                               //  Lukker åpen fil.
  } else                                           //  Filen ikke funnet:
     printf("\n\tFant ikke filen 'EX_S21_PRODUKT.DTA'!\n\n");
}


/**
 *  Oppgave 2G - Leser ALT om ETT produkt fra fil.
 *
 *  @param  inn - Filen det skal leses fra
 *  @param  p   - Produktet som får innlest sine data
 */
void produktLesFraFil(FILE* inn, struct Produkt* p) {
    char buffer[STRLEN];                  //  Buffer for innlest navn.
    char tegn;                            //  Innlest 'R' eller 'P' fra filen.
                                          //  Leser produktets navn:
    fgets(buffer, STRLEN, inn);    buffer[strlen(buffer)-1] = '\0';
    p->navn = (char*) malloc((strlen(buffer)+1) * sizeof(char));
    strcpy(p->navn, buffer);
                                          // Leser 3x enkelt-verdier:
    fscanf(inn, " %c %i %i", &tegn, &(p->produsentNr), &(p->antallKg));
    getc(inn);                            //  Leser/forkaster '\n'.
                                          //  Konverterer lest bokstav ('R/P')
    p->type = (tegn == 'R') ? Rakfisk : Pultost;  //  til enum-verdi.
}
