/**
 *   Skjelett for kontinuasjonseksamen i GrProg (i C), august 2020, oppgave 2.
 *
 *   Programmet holder orden på hvilke episoder en person
 *   har sett i de ulike sesongene av en lang, lang serie.
 *
 *   @file     EX_S20_2.TPL
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>               //  printf, scanf, FILE
#include <stdlib.h>              //  sizeof, malloc, free
#include <string.h>              //  strcpy, strlen, strstr
#include <stdbool.h>             //  bool, true, false
#include "LesData.h"             //  Verktøykasse for lesing av diverse data


#define   MAXSESONG    100       ///<  Max. antall sesonger.
#define   MAXEPISODE    20       ///<  Max. antall episoder EN sesong.
const int STRLEN = 60;           ///<  Max. tekstlengde.


/**
 *  Sesong (med tittel, antall episoder og hvilke som er sett).
 */
struct Sesong {
    char* tittel;                //  Sesongens tittel/emne.
    int   antallEpisoder;        //  Antall episoder i vedkommende sesong.
    bool  sett[MAXEPISODE];      //  Sett episode eller ei.
};


void skrivMeny();
void nySesong();                                           //  Oppgave 2A
void sesongLesData(struct Sesong* s);                      //  Oppgave 2A
void skrivAlleSesongene();                                 //  Oppgave 2B
void sesongSkrivData(const struct Sesong* s);              //  Oppgave 2B
void settEnEpisode();                                      //  Oppgave 2C
void sesongSettEpisode(struct Sesong* s);                  //  Oppgave 2C
void skrivEnNavngittSesong();                              //  Oppgave 2D
void sesongerProsentvisSett();                             //  Oppgave 2E
void skrivTilFil();                                        //  Oppgave 2F
void sesongSkrivTilFil(FILE* ut, const struct Sesong* s);  //  Oppgave 2F
void lesFraFil();                                          //  Oppgave 2G
void sesongLesFraFil(FILE* inn, struct Sesong* s);         //  Oppgave 2G


int    gAntallSesonger;               ///<  Antall sesonger hittil registrert.
struct Sesong* gSesonger[MAXSESONG];  ///<  Alle sesongene.


/**
 *  Hovedprogrammet:
 */
int main()  {
    char kommando;

    lesFraFil();                                            //  Oppgave 2G
    skrivMeny();
    kommando = lesChar("Ønske");

    while (kommando != 'Q') {
        switch(kommando) {
           case 'N': nySesong();                     break;  //  Oppgave 2A
           case 'A': skrivAlleSesongene();           break;  //  Oppgave 2B
           case 'E': settEnEpisode();                break;  //  Oppgave 2C
           case 'S': skrivEnNavngittSesong();        break;  //  Oppgave 2D
           case 'P': sesongerProsentvisSett();       break;  //  Oppgave 2E
           default:  skrivMeny();                    break;
        }
        kommando = lesChar("Ønske");
    }

    skrivTilFil();                                          //  Oppgave 2F
    printf("\n\n");
    return 0;
}


/**
 *  Skriver/presenterer programmets muligheter/valg for brukeren.
 */
void skrivMeny() {
    printf("\nFØLGENDE KOMMANDOER ER LOVLIG:\n");
    printf("\tN   = Ny sesong\n");
    printf("\tA   = skriv Alle sesongene\n");
    printf("\tE   = sett en ny Episode\n");
    printf("\tS   = skriv en navngitt Sesong\n");
    printf("\tP   = sesonger Prosentvis sett\n");
    printf("\tQ   = Quit/avslutt\n");
}


/**
 *  Oppgave 2A - Legger inn (om mulig) en ny sesong i datastrukturen.
 *
 *  @see   sesongLesData(...)
 */
void nySesong() {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2A - Leser inn relevante data og nullstiller andre.
 *
 *  @param  s -  Sesongen som får innlest/initiert sine data
 */
void sesongLesData(struct Sesong* s) {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2B - Skriver ALT om ALLE sesonger.
 *
 *  @see   sesongSkrivData(...)
 */
void skrivAlleSesongene() {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2B - Skriver ALT om EN sesong ut på skjermen.
 *
 *  @param  s - Sesongen som skrives ut
 */
void sesongSkrivData(const struct Sesong* s)  {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2C - Sett EN episode en gitt sesong.
 *
 *  @see   sesongSettEpisode(...)
 */
void settEnEpisode() {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2C - Registrerer (om mulig) at EN episode er sett.
 *
 *  @param  s - Sesongen det er sett EN ny episode
 */
void sesongSettEpisode(struct Sesong* s) {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2D - Skriver navngitt(e) sesong(er).
 */
void skrivEnNavngittSesong() {

    //   LAG INNMATEN OG ANNEN KODE/FUNKSJON(ER)
}


/**
 *  Oppgave 2E - Skriver % sett av hver sesong, og den mest sette sesongen.
 */
void sesongerProsentvisSett() {

    //   LAG INNMATEN OG ANNEN KODE/FUNKSJON(ER)
}


/**
 *  Oppgave 2F - Skriver ALLE sesongene til fil.
 *
 *  @see   sesongSkrivTilFil(...)
 */
void skrivTilFil() {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2F - Alle EN sesongs data skrives ut på fil.
 *
 *  @param   ut  - Filen det skal skrives til
 *  @param   s   - Sesongen som skrives til fil
 */
void sesongSkrivTilFil(FILE* ut, const struct Sesong* s) {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2G - Leser ALLE sesongene fra fil.
 *
 *  @see     sesongLesFraFil(...)
 */
void lesFraFil() {

    //   LAG INNMATEN
}


/**
 *  Oppgave 2G - Leser ALT om EN sesong fra fil.
 *
 *  @param  inn - Filen det skal leses fra
 *  @param  s   - Sesongen som får innlest sine data
 */
void sesongLesFraFil(FILE* inn, struct Sesong* s) {

    //   LAG INNMATEN
}
