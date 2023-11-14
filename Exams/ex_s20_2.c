/**
 *   Løsningsforslag til kontinuasjonseksamen i GrProg (i C), august 2020, oppgave 2.
 *
 *   Programmet holder orden på hvilke episoder en person
 *   har sett i de ulike sesongene av en lang, lang serie.
 *
 *   @file     EX_S20_2.C
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
bool sesongNavneMatch(const struct Sesong* s, const char* t);  // Oppg.2D - NY
void sesongerProsentvisSett();                             //  Oppgave 2E
int  sesongProsentSett(const struct Sesong* s);            //  Oppgave 2E - NY
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
  if (gAntallSesonger < MAXSESONG) {      //  Plass til flere sesonger:
     printf("\n\tNy sesong har nr.%i:\n", gAntallSesonger+1);
     gSesonger[gAntallSesonger] =         //  Oppretter en ny sesong:
                               (struct Sesong*) malloc(sizeof(struct Sesong));
     sesongLesData(gSesonger[gAntallSesonger]); // Sesongen leser egne data.
     gAntallSesonger++;                   //  Teller opp antall sesonger.
  } else                                  //  Fullt med sesonger:
     printf("\n\tFullt med %i sesonger allerede!\n", MAXSESONG);
}


/**
 *  Oppgave 2A - Leser inn relevante data og nullstiller andre.
 *
 *  @param  s -  Sesongen som får innlest/initiert sine data
 */
void sesongLesData(struct Sesong* s) {
  s->tittel = lagOgLesText("Tittel"); //  Leser og lager sesongens tittel/emne
  s->antallEpisoder = lesInt("#episoder", 1, MAXEPISODE);  // og ant.episoder.
  for (int i = 0; i < s->antallEpisoder; i++)           //  Har IKKE sett noen
      s->sett[i] = false;                               //    episoder ennå.
}


/**
 *  Oppgave 2B - Skriver ALT om ALLE sesonger.
 *
 *  @see   sesongSkrivData(...)
 */
void skrivAlleSesongene() {
    for (int i = 0;  i < gAntallSesonger;  i++) {
        printf("\tSesong nr.%2i:  ", i+1);   //  Skriver sesongnummer.
        sesongSkrivData(gSesonger[i]);       //  Hver sesong skriver seg selv.
    }
}


/**
 *  Oppgave 2B - Skriver ALT om EN sesong ut på skjermen.
 *
 *  @param  s - Sesongen som skrives ut
 */
void sesongSkrivData(const struct Sesong* s)  {
    int i;
    printf("%s,  %i episoder:\n\t\t", s->tittel, s->antallEpisoder);
    for (i = 0; i < s->antallEpisoder; i++)        //  Skriver episodenumrene:
        printf("%3i", i+1);
    printf("\n\t\t ");
    for (i = 0; i < s->antallEpisoder;  i++)          //  Skriver om sett/
        printf(" %c ", ((s->sett[i]) ? 'X' : '-'));   //    ikke sett episode.
    printf("\n");
}


/**
 *  Oppgave 2C - Sett EN episode en gitt sesong.
 *
 *  @see   sesongSettEpisode(...)
 */
void settEnEpisode() {
    int nr = lesInt("Sesongnummer", 1, gAntallSesonger);   //  Leser sesongnr.
    sesongSettEpisode(gSesonger[nr-1]);
}


/**
 *  Oppgave 2C - Registrerer (om mulig) at EN episode er sett.
 *
 *  @param  s - Sesongen det er sett EN ny episode
 */
void sesongSettEpisode(struct Sesong* s) {
  int nr = lesInt("Episodenummer", 1, s->antallEpisoder); //  Leser episodenr.
  if (!s->sett[nr-1]) {                    //  IKKE sette allerede:
     s->sett[nr-1] = true;                 //  Registrerer at er sett.
     printf("\n\tRegistrert at ny episode er sett.\n");
  } else                                   //  Allerede sett:
     printf("\n\tDenne episoden er allerede sett!\n");
}


/**
 *  Oppgave 2D - Skriver navngitt(e) sesong(er).
 *
 *  @see   sesongNavneMatch(...)
 */
void skrivEnNavngittSesong() {
  char navn[STRLEN];
  bool funn = false;                               //  Ingen funn - foreløpig.

  lesText("Sesongnavn", navn, STRLEN);             //  Leser sesongnavn.
  for (int i = 0;  i < gAntallSesonger;  i++)      //  For hver sesong:
      if (sesongNavneMatch(gSesonger[i], navn)) {  //  Sesongen har navnet:
         funn = true;                              //  Minst ett funn.
         printf("\n\tSesong nr.%2i:  ", i+1);
         sesongSkrivData(gSesonger[i]);            //  Sesongen skrives.
      }
  if (!funn)                                       //  Ingen sesonger funnet:
     printf("\n\tIngen sesong med denne tittelen!\n");
}


/**
 *  Oppgave 2D - NY - Returnerer om sesong INNEHOLDER (del)tittelen 't'.
 *
 *  @param  s - Sesongen som sjekkes om har 't' i sin 's->tittel'
 *  @param  t - Teksten det søkes om er hele eller deler av 's->tittel'
 *  @return     Om teksten 't' ble funnet som HELE eller DELER AV 's->tittel'
 */
bool sesongNavneMatch(const struct Sesong* s, const char* t) {
    return (strstr(s->tittel, t));
}


/**
 *  Oppgave 2E - Skriver % sett av hver sesong, og den mest sette sesongen.
 *
 *  @see     sesongProsentSett(...)
 */
void sesongerProsentvisSett() {
    int   sesongNr = 0,                    //  Sesongen mest sett.
          prosent, storstProsent = -1;     //  % aktuell sesong og mest sette.

    for (int i = 0;  i < gAntallSesonger;  i++) {
        prosent = sesongProsentSett(gSesonger[i]);  //  Sesongens sette %.
        printf("\tSesong nr.%2i  - sett: %i%%\n", i+1, prosent);
        if (prosent > storstProsent) {     //  Ny mest sette sesong?
            storstProsent = prosent;       //  Lagrer unna % sett,
            sesongNr = i;                  //    og sesongnummer.
        }
    }                                      //  Skriver mest sette sesong:
    printf("\n\tMest sette sesong er nr.%i med %i%%\n",
           sesongNr+1, storstProsent);
}


/**
 *  Oppgave 2E - NY - Returnerer prosentandel av sette episoder i sesongen.
 *
 *  @param  s   - Sesongen som det regnes ut prosentdelen for
 *  @return       Prosentandelen av sette episoder i sesongen 's'
 */
int sesongProsentSett(const struct Sesong* s)  {
  int totalt = 0;
  for (int i = 0;  i < s->antallEpisoder;  i++)
      if (s->sett[i])  totalt++;          //  Teller opp antall episoder sett.
  return ((100 * totalt) / s->antallEpisoder);  //  Returnerer % sett.
}


/**
 *  Oppgave 2F - Skriver ALLE sesongene til fil.
 *
 *  @see   sesongSkrivTilFil(...)
 */
void skrivTilFil() {
  FILE* utfil = fopen("EX_S20_SESONGER.DT2", "w");    //  Åpner aktuell fil:
  int i;                                       //  Løkkevariabel.

  if (utfil) {                                 //  Filen kan åpnes:
    printf("\n\nSkriver til filen 'EX_S20_SESONGER.DT2'.....\n\n");

    fprintf(utfil, "%i\n", gAntallSesonger);   //  Skriver antall sesonger.
    for (i = 0; i < gAntallSesonger; i++)      //  Går gjennom ALLE sesongene:
        sesongSkrivTilFil(utfil, gSesonger[i]); // Hver sesong skrives.
  } else                                   //  Filen ikke funnet/mulig å åpne:
    printf("Klarte ikke å åpne filen 'SESONGER.DT2'!\n\n");

  fclose(utfil);                               //  Lukker filen.
}


/**
 *  Oppgave 2F - Alle EN sesongs data skrives ut på fil.
 *
 *  @param   ut  - Filen det skal skrives til
 *  @param   s   - Sesongen som skrives til fil
 */
void sesongSkrivTilFil(FILE* ut, const struct Sesong* s) {
  int i;
  fprintf(ut, "%s\n%i", s->tittel, s->antallEpisoder);    //  Skriver 2x data:
  for (i = 0; i < s->antallEpisoder; i++)        //  Skriver om sett eller ei:
      fprintf(ut, " %c", ((s->sett[i]) ? '+' : '-'));
  fprintf(ut, "\n");
}


/**
 *  Oppgave 2G - Leser ALLE sesongene fra fil.
 *
 *  @see     sesongLesFraFil(...)
 */
void lesFraFil() {
    FILE* innfil = fopen("EX_S20_SESONGER.DTA", "r"); //  Åpner aktuell fil:

    if (innfil) {                            //  Filen finnes:
        fscanf(innfil, "%i", &gAntallSesonger); //  Leser antall sesonger.
        getc(innfil);                        //  Leser avsluttende '\n'.
                                             //  Alle sesonger lages og leses:
        for (int i = 0; i < gAntallSesonger; i++) {
            gSesonger[i] = (struct Sesong*) malloc(sizeof(struct Sesong));
            sesongLesFraFil(innfil, gSesonger[i]); // Leser selv.
        }
       printf("\n\tAlle sesonger er lest inn fra 'EX_S20_SESONGER.DTA'!\n\n");
        fclose(innfil);                      //  Lukker åpen fil.
    } else                                   //  Filen ikke funnet:
        printf("\n\tFant ikke filen 'EX_S20_SESONGER.DTA'!\n\n");
}


/**
 *  Oppgave 2G - Leser ALT om EN sesong fra fil.
 *
 *  @param  inn - Filen det skal leses fra
 *  @param  s   - Sesongen som får innlest sine data
 */
void sesongLesFraFil(FILE* inn, struct Sesong* s) {
    char buffer[STRLEN];                  //  Buffer for innlest tekst.
    char tegn;                            //  Innlest '+' eller '-' fra filen.
                                          //  Leser tittel, tar vekk '\n:
    fgets(buffer, STRLEN, inn);    buffer[strlen(buffer) - 1] = '\0';
    s->tittel = (char*) malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(s->tittel, buffer);

    fscanf(inn, "%i", &s->antallEpisoder);         //  Leser ant.episoder.

    for (int i = 0; i < s->antallEpisoder; i++) {  //  Leser om sett ('+')
        fscanf(inn, " %c", &tegn);                 //    eller ei ('-').
        s->sett[i] = (tegn == '+');                //  Registrerer som 'bool'.
    }
    fgetc(inn);                           //  Forkaster avsluttende '\n'.
}
