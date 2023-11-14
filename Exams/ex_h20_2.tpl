/**
 *   Skjelett eksamen i GrProg (i C), november 2020, oppgave 2.
 *
 *   Programmet holder orden på ulike gjenstander som skal ryddes ut av
 *   et hus, og hvilken status hver enkelt har.
 *
 *   @file     EX_H20_2.TPL
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

    //   LAG INNMATEN
}


/**
 *  Oppgave 2A - Leser inn relevante data og nullstiller andre.
 *
 *  @param   g -  Gjenstanden som får innlest/initiert sine data
 */
void gjenstandLesData(struct Gjenstand* g) {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2B - Skriver ALT om ALLE gjenstander.
 *
 *  @see   gjenstandSkrivData(...)
 */
void skrivAlleGjenstandene() {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2B - Skriver ALT om EN gjenstand ut på skjermen.
 *
 *  @param   g - Gjenstanden som skrives ut
 */
void gjenstandSkrivData(const struct Gjenstand* g)  {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2C - Skriver ALT om ALLE gjenstander med EN GITT status.
 *
 *  @see   lesKategori()
 *  @see   konverterTilKategori(...)
 *  @see   gjenstandHentStatus(...)
 *  @see   gjenstandSkrivData(...)
 */
void skrivAlleIKategori()  {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2C - Leser LOVLIG kategori ('U', 'F', 'H', 'L', 'S', 'G').
 *
 *  @return  Forbokstaven i en LOVLIG kategori
 */
char lesKategori()  {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2C - Gjør om en (lovlig) bokstav til kategori, returnerer dette.
 *
 *  @param    tegn - Bokstaven som skal gjøres om til en kategori/enum-verdi
 *  @return   Kategori/enum-verdi
 */
enum Kategori konverterTilKategori(const char tegn)  {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2C - Returnerer kun gjentandens status.
 *
 *  @param    g  -  Aktuell gjenstand å returnere 'status' for
 *  @return   Gjenstandens 'status'
 */
enum Kategori gjenstandHentStatus(const struct Gjenstand* g)  {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2D - Endrer (kanskje) EN aktuell gjenstands 'hvem'.
 *
 *  @see   gjenstandSettHvem(...)
 */
void settHvem()  {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2D - Endrer en gjenstands til 'hvem/hvor' den skal.
 *
 *  @param   g  -  Aktuell gjenstand å endre 'hvem' for
 *  @see     gjenstandSkrivData(...)
 */
void gjenstandSettHvem(struct Gjenstand* g)  {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2E - Endrer (kanskje) EN aktuell gjenstands kategori/status.
 *
 *  @see   gjenstandEndreKategori(...)
 */
void endreKategori()  {

    //   LAG INNMATEN
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

    //   LAG INNMATEN
}


/**
 *  Oppgave 2F - Skriver ALLE gjenstandene til fil.
 *
 *  @see   gjenstandSkrivTilFil(...)
 */
void skrivTilFil() {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2F - Alle EN gjenstands data skrives ut på fil.

 *
 *  @param   ut  - Filen det skal skrives til
 *  @param   g   - Gjenstanden som skrives til fil
 */
void gjenstandSkrivTilFil(FILE* ut, const struct Gjenstand* g) {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2G - Leser ALLE gjenstandene fra fil.
 *
 *  @see     gjenstandLesFraFil(...)
 */
void lesFraFil() {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2G - Leser ALT om EN gjenstand fra fil.
 *
 *  @param  inn - Filen det skal leses fra
 *  @param  g   - Gjenstanden som får innlest sine data
 *  @see    konverterTilKategori(...)
 */
void gjenstandLesFraFil(FILE* inn, struct Gjenstand* g) {

    //   LAG INNMATEN
}
