/**
 *   Løsningsforslag til eksamen i GrProg (i C), november 2020, oppgave 2.
 *
 *   Programmet holder orden på ulike gjenstander som skal ryddes ut av
 *   et hus, og hvilken status hver enkelt har.
 *
 *   @file     EX_H20_2.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>               //  printf, FILE
#include <stdlib.h>              //  sizeof, malloc
#include <string.h>              //  strcpy, strlen
#include <stdbool.h>             //  bool, true, false
#include "LesData.h"             //  Verktøykasse for lesing av diverse data


#define   MAXGJENSTANDER 300     ///<  Max. antall gjenstander.
const int STRLEN = 60;           ///<  Max. tekstlengde.


/**
 *  Kategori (ulike kategorier/statuser for en gjenstand).
 */
enum Kategori { Ubestemt, Fjernet, Hentes, Lagres, Selges, Gratis };


/**
 *  Gjenstand (med navn, hvem skal ha den og status for den).
 */
struct Gjenstand {
    char* navn;                  //  Gjenstandens navn/beskrivelse.
    char* hvem;                  //  Hvem skal ha den/hvor skal den sendes.
    enum Kategori status;        //  Status for gjenstanden.
};


void skrivMeny();
void nyGjenstand();                                            //  Oppgave 2A
void gjenstandLesData(struct Gjenstand* g);                    //  Oppgave 2A
void skrivAlleGjenstandene();                                  //  Oppgave 2B
void gjenstandSkrivData(const struct Gjenstand* g);            //  Oppgave 2B
void skrivAlleIKategori();                                     //  Oppgave 2C
char lesKategori();                                            //  Oppgave 2C
enum Kategori konverterTilKategori(const char tegn);           //  Oppgave 2C
enum Kategori gjenstandHentStatus(const struct Gjenstand* g);  //  Oppgave 2C
void settHvem();                                               //  Oppgave 2D
void gjenstandSettHvem(struct Gjenstand* g);                   //  Oppgave 2D
void endreKategori();                                          //  Oppgave 2E
void gjenstandEndreKategori(struct Gjenstand* g);              //  Oppgave 2E
void skrivTilFil();                                            //  Oppgave 2F
void gjenstandSkrivTilFil(FILE* ut, const struct Gjenstand* g);//  Oppgave 2F
void lesFraFil();                                              //  Oppgave 2G
void gjenstandLesFraFil(FILE* inn, struct Gjenstand* g);       //  Oppgave 2G


int    gAntallGjenstander;         ///<  Antall gjenstander hittil registrert.
struct Gjenstand* gGjenstander[MAXGJENSTANDER];       ///<  Alle gjenstandene.


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
           case 'N': nyGjenstand();                 break;  //  Oppgave 2A
           case 'A': skrivAlleGjenstandene();       break;  //  Oppgave 2B
           case 'K': skrivAlleIKategori();          break;  //  Oppgave 2C
           case 'H': settHvem();                    break;  //  Oppgave 2D
           case 'E': endreKategori();               break;  //  Oppgave 2E
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
    printf("\tN   = Ny gjenstand\n");
    printf("\tA   = skriv Alle gjenstandene\n");
    printf("\tK   = skriv gjenstandene i en Kategori\n");
    printf("\tH   = endre/sett til Hvem/Hvor en gjenstand skal\n");
    printf("\tE   = Endre/sett kategori-tilhørighet\n");
    printf("\tQ   = Quit/avslutt\n");
}


/**
 *  Oppgave 2A - Legger inn (om mulig) en ny gjenstand i datastrukturen.
 *
 *  @see   gjenstandLesData(...)
 */
void nyGjenstand() {
  if (gAntallGjenstander < MAXGJENSTANDER) { // Plass til flere gjenstander:
     printf("\n\tNy gjenstand har nr.%i:\n", gAntallGjenstander+1);
     gGjenstander[gAntallGjenstander] =      //  Oppretter en ny gjenstand:
                         (struct Gjenstand*) malloc(sizeof(struct Gjenstand));
                                               // Gjenstanden leser egne data:
     gjenstandLesData(gGjenstander[gAntallGjenstander]);
     gAntallGjenstander++;                     //  Antallet telles opp.
  } else                                       //  Fullt med gjenstander:
     printf("\n\tFullt med %i gjenstander allerede!\n", MAXGJENSTANDER);
}


/**
 *  Oppgave 2A - Leser inn relevant data og nullstiller de andre.
 *
 *  @param   g -  Gjenstanden som får innlest/initiert sine data
 */
void gjenstandLesData(struct Gjenstand* g) {
  g->navn   = lagOgLesText("\tNavn");     //  Leser og lager gjenstandens navn
  g->hvem   = (char*) malloc(4*sizeof(char));  //  Setter av plass til 'hvem',
  strcpy(g->hvem, "---");                      //    og lagrer initielt '---'.
  g->status = Ubestemt;                   //  Initiell status er 'Ubestemt'.
}


/**
 *  Oppgave 2B - Skriver ALT om ALLE gjenstander.
 *
 *  @see   gjenstandSkrivData(...)
 */
void skrivAlleGjenstandene() {
  printf("\n\tAlle gjenstandene i oversikten:\n");
  for (int i = 0;  i < gAntallGjenstander;  i++) {
      printf("\t   Nr.%3i:  ", i+1);              //  Skriver gjenstandnummer.
      gjenstandSkrivData(gGjenstander[i]);        //  Hver skriver seg selv.
  }
}


/**
 *  Oppgave 2B - Skriver ALT om EN gjenstand ut på skjermen.
 *
 *  @param   g - Gjenstanden som skrives ut
 */
void gjenstandSkrivData(const struct Gjenstand* g)  {
   printf("%s,    %s,    ", g->navn, g->hvem);   //  Skriver 'navn' og 'hvem'.
   switch (g->status)  {                         //  Gjør om 'status'
     case Ubestemt: printf("UBESTEMT"); break;   //   (enum-verdi) til tekst:
     case Fjernet:  printf("FJERNET");  break;
     case Hentes:   printf("HENTES");   break;
     case Lagres:   printf("LAGRES");   break;
     case Selges:   printf("SELGES");   break;
     case Gratis:   printf("GRATIS");   break;
   }
   printf("\n");
}


/**
 *  Oppgave 2C - Skriver ALT om ALLE gjenstander med EN GITT status.
 *
 *  @see   lesKategori()
 *  @see   konverterTilKategori(...)
 *  @see   gjenstandHentStatus(...)
 *  @see   gjenstandSkrivData(...)
 */
void skrivAlleIKategori()  {         //  Leser tegn og gjør om til enum-verdi:
  enum Kategori status = konverterTilKategori(lesKategori());

  printf("\n\tAlle gjenstandene i denne kategorien:\n");
  for (int i = 0;  i < gAntallGjenstander;  i++)
      if (gjenstandHentStatus(gGjenstander[i]) == status) { // Status-match:
         printf("\t   Nr.%3i:  ", i+1);           //  Skriver gjenstandnummer.
         gjenstandSkrivData(gGjenstander[i]);     //  Hver skriver seg selv.
      }
}


/**
 *  Oppgave 2C - Leser LOVLIG kategori ('U', 'F', 'H', 'L', 'S', 'G').
 *
 *  @return  Forbokstaven i en LOVLIG kategori
 */
char lesKategori()  {
  char stat;
  do  {
    stat = lesChar("\tKategori (U(bestemt), F(jernet), H(entes), L(agres), S(elges), G(ratis))");
  } while (stat != 'U' && stat != 'F' && stat != 'H' &&  //  Sikrer lovlig
           stat != 'L' && stat != 'S' && stat != 'G');   //    bokstav.
  return stat;
}


/**
 *  Oppgave 2C - Gjør om en (lovlig) bokstav til kategori, returnerer dette.
 *
 *  @param    tegn - Bokstaven som skal gjøres om til en kategori/enum-verdi
 *  @return   Kategori/enum-verdi
 */
enum Kategori konverterTilKategori(const char tegn)  {
  switch (tegn)  {
    case 'U': return Ubestemt;
    case 'F': return Fjernet;
    case 'H': return Hentes;
    case 'L': return Lagres;
    case 'S': return Selges;
    case 'G': return Gratis;
    default:  return Ubestemt;                //  Ulovlig/uaktuell bokstav.
  }
}


/**
 *  Oppgave 2C - Returnerer kun gjentandens status.
 *
 *  @param    g  -  Aktuell gjenstand å returnere 'status' for
 *  @return   Gjenstandens 'status'
 */
enum Kategori gjenstandHentStatus(const struct Gjenstand* g)  {
   return (g->status);
}


/**
 *  Oppgave 2D - Endrer (kanskje) EN aktuell gjenstands 'hvem'.
 *
 *  @see   gjenstandSettHvem(...)
 */
void settHvem()  {
  int nr = lesInt("\tGjenstandnr", 0, gAntallGjenstander);

  if (nr > 0)                                 //  Gjenstandsnr 1 ->
     gjenstandSettHvem(gGjenstander[nr-1]);   //  Gjenstanden endrer 'hvem'.
  else
    printf("\n\tOK - ingen gjenstand endrer 'hvem/hvor'.\n");
}


/**
 *  Oppgave 2D - Endrer en gjenstands til 'hvem/hvor' den skal.
 *
 *  @param   g  -  Aktuell gjenstand å endre 'hvem' for
 *  @see     gjenstandSkrivData(...)
 */
void gjenstandSettHvem(struct Gjenstand* g)  {
  printf("\n\tGjenstanden skal pt til:  %s.\n", g->hvem);

  free(g->hvem);                              //  Sletter nåværende 'hvem'.
  g->hvem = lagOgLesText("\tTil hvem/hvor");  //  Setter ny 'hvem'.

  printf("\nNår hvem/hvor er endret:\n");
  gjenstandSkrivData(g);
}


/**
 *  Oppgave 2E - Endrer (kanskje) EN aktuell gjenstands kategori/status.
 *
 *  @see   gjenstandEndreKategori(...)
 */
void endreKategori()  {
  int nr = lesInt("\tGjenstandnr", 0, gAntallGjenstander);

  if (nr > 0)                                   //  Gjenstandsnr 1 ->
    gjenstandEndreKategori(gGjenstander[nr-1]); //Gjenstandens kategori endres
  else
    printf("\n\tOK - ingen gjenstand endrer kategori/status.\n");
}


/**
 *  Oppgave 2E - Endrer en gjenstands kategori/status.
 *
 *  @param   g  -  Aktuell gjenstand å endre status for
 *  @see     gjenstandSkrivData(...)
 *  @see     lesKategori()
 *  @see     konverterTilKategori(...)
 */
void gjenstandEndreKategori(struct Gjenstand* g)  {

  printf("\nNåværende data om gjenstanden:\n");
  gjenstandSkrivData(g);

  printf("Ny kategori/status skal være:\n");
                                            //  Ny kategori leses og settes:
  g->status = konverterTilKategori(lesKategori());

  printf("\nNår kategori/status er endret:\n");
  gjenstandSkrivData(g);
}


/**
 *  Oppgave 2F - Skriver ALLE gjenstandene til fil.
 *
 *  @see   gjenstandSkrivTilFil(...)
 */
void skrivTilFil() {
  FILE* utfil = fopen("EX_H20_GJENSTANDER.DT2", "w");  //  Åpner aktuell fil:

  if (utfil) {                             //  Filen kan åpnes:
    printf("\n\n\tSkriver til filen 'EX_H20_GJENSTANDER.DT2'.....\n\n");

    fprintf(utfil, "%i\n", gAntallGjenstander);//  Skriver antall gjenstander.
                                           //  Går gjennom ALLE gjenstandene:
    for (int i = 0; i < gAntallGjenstander; i++)
        gjenstandSkrivTilFil(utfil,gGjenstander[i]); //Hver gjenstand skrives.
  } else                                   //  Filen ikke funnet/mulig å åpne:
    printf("Klarte ikke å åpne filen 'EX_H20_GJENSTANDER.DT2'!\n\n");

  fclose(utfil);                           //  Lukker filen.
}


/**
 *  Oppgave 2F - Alle EN gjenstands data skrives ut på fil.

 *
 *  @param   ut  - Filen det skal skrives til
 *  @param   g   - Gjenstanden som skrives til fil
 */
void gjenstandSkrivTilFil(FILE* ut, const struct Gjenstand* g) {
  switch (g->status)  {                          //  Skriver enum (status)
    case Ubestemt: fprintf(ut, "U");  break;     //    ut som EN bokstav:
    case Fjernet:  fprintf(ut, "F");  break;
    case Hentes:   fprintf(ut, "H");  break;
    case Lagres:   fprintf(ut, "L");  break;
    case Selges:   fprintf(ut, "S");  break;
    case Gratis:   fprintf(ut, "G");  break;
  }
  fprintf(ut, " %s\n%s\n", g->navn, g->hvem);    //  Skriver 2x datamedlemmer:
}


/**
 *  Oppgave 2G - Leser ALLE gjenstandene fra fil.
 *
 *  @see     gjenstandLesFraFil(...)
 */
void lesFraFil() {
  FILE* innfil = fopen("EX_H20_GJENSTANDER.DTA", "r"); //  Åpner aktuell fil:

  if (innfil) {                                 //  Filen finnes:
     fscanf(innfil, "%i", &gAntallGjenstander); //  Leser antall gjenstander.
     getc(innfil);                              //  Leser avsluttende '\n'.
                                         //  Alle gjenstander lages og leses:
     for (int i = 0;  i < gAntallGjenstander;  i++) {
       gGjenstander[i] = (struct Gjenstand*) malloc(sizeof(struct Gjenstand));
       gjenstandLesFraFil(innfil, gGjenstander[i]); // Leser selv.
     }
     printf("\n\tGjenstander er lest inn fra 'EX_H20_GJENSTANDER.DTA'!\n\n");
     fclose(innfil);                            //  Lukker åpen fil.
  } else                                        //  Filen ikke funnet:
     printf("\n\tFant ikke filen 'EX_H20_GJENSTANDER.DTA'!\n\n");
}


/**
 *  Oppgave 2G - Leser ALT om EN gjenstand fra fil.
 *
 *  @param  inn - Filen det skal leses fra
 *  @param  g   - Gjenstanden som får innlest sine data
 *  @see    konverterTilKategori(...)
 */
void gjenstandLesFraFil(FILE* inn, struct Gjenstand* g) {
    char buffer[STRLEN];          //  Buffer for innlest tekst.
    char tegn;                    //  Innlest 'UFHLSG' fra filen.

    tegn = getc(inn);             //  Leser 'U', 'F', 'H', 'L', 'S' eller 'G'.
    getc(inn);                    //  Leser/forkaster EN ' ' (blank).
    g->status = konverterTilKategori(tegn); // Setter status ut fra bokstav.

    fgets(buffer, STRLEN, inn);    buffer[strlen(buffer)-1] = '\0';
    g->navn = (char*) malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(g->navn, buffer);

    fgets(buffer, STRLEN, inn);    buffer[strlen(buffer)-1] = '\0';
    g->hvem = (char*) malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(g->hvem, buffer);
}
