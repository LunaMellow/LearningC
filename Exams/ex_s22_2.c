/**
 *   Løsningsforslag til kont.eksamen i GrProg (i C), august 2022, oppgave 2.
 *
 *   Programmet holder orden på ulike ting/produkt/saker som
 *   må handles/er handlet inn ifm oppussing (i et hus/leilighet/hybel).
 *
 *   @file     EX_S22_2.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>               //  printf, FILE
#include <stdlib.h>              //  sizeof, malloc
#include <string.h>              //  strcpy, strlen, strstr
#include <stdbool.h>             //  bool, true, false
#include "LesData.h"             //  Verktøykasse for lesing av diverse data


#define   MAXTING        100     ///<  Max. antall ting/produkt som trengs.
const int STRLEN  =       80;    ///<  Max. tekstlengde.


/**
 *  Enhet (ugyldig/udefinert, centimeter, meter, kvadratmeter, stykk, liter).
 */
enum Enhet { ugyldig, cm, m, kvm, stk, l};


/**
 *  Ting (med navn, antall, pris og enhetsmål).
 */
struct Ting {
  char* navn;                    //  Tingens:  - navn
  float antall,                  //            - antallet av tingen
        pris;                    //            - pris pr.enhet
  enum  Enhet enhet;             //            - enhetsmål
};


char  charFraEnum(const enum Enhet enhet);                     //  |
enum  Enhet enumFraChar(const char tegn);                      //  | Ferdig-
char  lesEnhetsBokstav();                                      //  | laget.
void  skrivMeny();                                             //  |
void  nyTing();                                                //  Oppgave 2A
void  tingLesData(struct Ting* ting);                          //  Oppgave 2A
void  skrivAlleTingene();                                      //  Oppgave 2B
void  tingSkrivData(const struct Ting* ting);                  //  Oppgave 2B
void  endrePris();                                             //  Oppgave 2C
void  tingEndrePris(struct Ting* ting);                        //  Oppgave 2C
void  skrivAlleMedTekst();                                     //  Oppgave 2D
bool tingMedTekst(const struct Ting* ting, const char tekst[]);//  Oppgave 2D
void  totalKostnad();                                          //  Oppgave 2E
float tingHentKostnad(const struct Ting* ting);                //  Oppgave 2E
void  skrivTilFil();                                           //  Oppgave 2F
void  tingSkrivTilFil(FILE* ut, const struct Ting* ting);      //  Oppgave 2F
void  lesFraFil();                                             //  Oppgave 2G
void  tingLesFraFil(FILE* inn, struct Ting* ting);             //  Oppgave 2G


int    gAntallTing;                     ///<  Antall ting hittil registrert.
struct Ting* gTing[MAXTING];            ///<  Alle tingene.


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
          case 'N':  nyTing();                     break;    //  Oppgave 2A
          case 'A':  skrivAlleTingene();           break;    //  Oppgave 2B
          case 'E':  endrePris();                  break;    //  Oppgave 2C
          case 'I':  skrivAlleMedTekst();          break;    //  Oppgave 2D
          case 'T':  totalKostnad();               break;    //  Oppgave 2E
          default:   skrivMeny();                  break;
        }
        kommando = lesChar("\nØnske");
    }

    skrivTilFil();                                           //  Oppgave 2F

    return 0;
}


/**
 *  Gjør om en lovlig enum-verdi til ett tegn/bokstav.
 *
 *  @param    enhet  -  Enum-verdi som skal konverteres til bokstav/tegn
 *  @return   En bokstav (C, M, K, S, L) ut fra en enum-verdi
 */
char charFraEnum(const enum Enhet enhet)  {
  switch (enhet)  {                      //  Ut fra enum-verdi returneres
    case  cm:   return 'C';              //    aktuell bokstav:
    case   m:   return 'M';
    case kvm:   return 'K';
    case stk:   return 'S';
    case   l:   return 'L';
  }
}


/**
 *  Gjør om en (lovlig) bokstav til en aktuell enum-verdi.
 *
 *  @param    tegn  -  Bokstav/tegn som skal konverteres til enum-verdi
 *  @return   Enum-verdi ut fra en bokstav/tegn
 */
enum Enhet enumFraChar(const char tegn)  {
  switch (tegn)  {
    case 'C':  return  cm;               //  Ut fra bokstav returneres
    case 'M':  return   m;               //    aktuell enum-verdi:
    case 'K':  return kvm;
    case 'S':  return stk;
    case 'L':  return   l;
    default:   printf("\n\tUgyldig bokstav for Enhet!\n\n");
               return ugyldig;
  }
}


/**
 *  Leser korrekt en lovlig bokstav for en Enhet, og returnerer denne.
 *
 *  @return   En bokstav (C, M, K, S, L) som står for en enhetsbetegnelse
 */
char lesEnhetsBokstav()  {
  char tegn;
  do  {                                     //  Sikrer LOVLIG bokstav-verdi:
    tegn = lesChar("\tEnhetstype (C(m), M, K(vm), S(tk), L)");
  } while (tegn != 'C' && tegn != 'M' &&
           tegn != 'K' && tegn != 'S' && tegn != 'L');
  return tegn;
}


/**
 *  Skriver/presenterer programmets muligheter/valg for brukeren.
 */
void skrivMeny() {
  printf("\nFØLGENDE KOMMANDOER ER LOVLIG:\n");
  printf("\tN   = Ny ting som skal kjøpes\n");
  printf("\tA   = skriv Alle tingene som er kjøpt/skal kjøpes\n");
  printf("\tE   = Endre/legge inn prisen for en ting\n");
  printf("\tI   = skriv alle tingene som Inneholder en tekst i navnet\n");
  printf("\tT   = Totalkostnad (så langt) for alt handlet/oppussingen\n");
  printf("\tQ   = Quit/avslutt\n");
}


/**
 *  Oppgave 2A - Legger inn (om mulig) en ny ting i datastrukturen.
 *
 *  @see   tingLesData(...)
 */
void  nyTing()  {
  if (gAntallTing < MAXTING)  {                   //  Plass til flere ting:
     printf("\n\tNy ting har nr.%i:\n", gAntallTing+1);
                                                  //  Oppretter en ny ting:
     gTing[gAntallTing] = (struct Ting*) malloc(sizeof(struct Ting));
                                                  //  Tingen leser egne data:
     tingLesData(gTing[gAntallTing]);
     gAntallTing++;                               //  Antallet telles opp.
  } else                                          //  Fullt med ting:
     printf("\n\tFullt med %i ting allerede!\n", MAXTING);
}


/**
 *  Oppgave 2A - Leser inn ALLE datamedlemmer i EN ting.
 *
 *  @param   ting -  Tingen som får innlest sine data
 *  @see     enumFraChar(...)
 */
void  tingLesData(struct Ting* ting)  {
  ting->navn   = lagOgLesText("\tNavn");      //  Leser og lager tingens navn.
  ting->antall = lesFloat("\tAntall", 1, 1000);  //  Leser antallet av tingen.
  ting->pris   = lesFloat("\tPris  ", 0, 10000); //  Leser evt. kjent pris.
  ting->enhet  = enumFraChar(lesEnhetsBokstav());
}


/**
 *  Oppgave 2B - Skriver ALT om ALLE tingene.
 *
 *  @see   tingSkrivData(...)
 */
void  skrivAlleTingene()  {
  if (gAntallTing > 0)  {                          //  Ting er registrert:
     printf("\n\tAlle tingene i oversikten:\n");   //  Overskrift.
     for (int i = 0;  i < gAntallTing;  i++) {     //  For hver ting:
         printf("\t   Nr.%3i:  ", i+1);            //  Skriver dens nummer.
         tingSkrivData(gTing[i]);                  //  Hver skriver seg selv.
     }
  } else
     printf("\n\tIngen ting/produkt/saker hittil registrert!\n");
}


/**
 *  Oppgave 2B - Skriver ALT om EN ting ut på skjermen.
 *
 *  @param   ting  -  Tingen som skrives ut
 */
void  tingSkrivData(const struct Ting* ting)  {
  printf("%s\n\t\t\t%.1f ", ting->navn, ting->antall);
  switch (ting->enhet)  {                      //  Ut fra tingens enum-verdi
    case  cm:  printf("cm");      break;       //    skrives aktuell tekst:
    case   m:  printf("meter");   break;
    case kvm:  printf("kvm");     break;
    case stk:  printf("stk");     break;
    case   l:  printf("liter");   break;
    default:   printf("-----");   break;
  }
  printf(" a kr.%.2f\n", ting->pris);
}


/**
 *  Oppgave 2C - Endre en tings pris.
 *
 *  @see   tingEndrePris(...)
 */
void  endrePris()  {
  int tingNr;                                         //  Tingnr.1-->

  if (gAntallTing > 0)  {                             //  Ting finnes:
     tingNr = lesInt("\tTingnr", 1, gAntallTing);
     tingEndrePris(gTing[tingNr-1]);                  //  Tingen endrer selv.
  } else
    printf("\n\tIngen ting ennå registrert!\n");
}


/**
 *  Oppgave 2C - Leser inn EN tings nye pris.
 *
 *  @param    ting  -  Tingen som får endret sin pris
 */
void  tingEndrePris(struct Ting* ting)  {
    printf("\n\tNåværende pris:  %.2f\n", ting->pris);
    ting->pris = lesFloat("\tNy pris", 0, 10000);     //  Ny pris.
    printf("\tNy pris:         %.2f\n", ting->pris);
}


/**
 *  Oppgave 2D - Skriver ALLE tingene som har en gitt (sub)tekst i 'navn'.
 *
 *  @see   tingMedTekst(...)
 *  @see   tingSkrivData(...)
 */
void  skrivAlleMedTekst()  {
  char tekst[STRLEN];
  if (gAntallTing > 0)  {                       //  Ting finnes:
     lesText("\tSøk etter (sub)teksten", tekst, STRLEN);
     for (int i = 0;  i < gAntallTing;  i++)    //  Går gjennom ALLE tingene:
         if (tingMedTekst(gTing[i], tekst))  {  //  Tingen inneholder 'tekst'.
            printf("\t   Nr.%3i:  ", i+1);      //  Skriver tingens nummer.
            tingSkrivData(gTing[i]);            //  Tingen skriver seg selv.
     }
  } else
    printf("\n\tIngen ting ennå registrert!\n");
}


/**
 *  Oppgave 2D - Returnerer om en ting har en gitt tekst i 'navn' eller ei.
 *
 *  @param    ting   -  Tingen som skal sjekkes for om inneholder 'tekst'
 *  @param    tekst  -  Teksten det sjekkes for om er i tingens 'navn'
 *  @return   Om tingens 'navn' inneholder 'tekst' eller ei
 */
bool tingMedTekst(const struct Ting* ting, const char tekst[])  {
  return (strstr(ting->navn, tekst) != NULL);
}


/**
 *  Oppgave 2E - Beregner og skriver TOTALkostand for ALLE tingene HITTIL.
 *
 *  @see   tingHentKostnad((...)
 */
void  totalKostnad()  {
  int antallMedPris = 0;                      //  Antall ting som har en pris.
  float kostnadTing,                          //  EN tings TOTALE kostnad.
        totalt = 0.0;                         //  Kostnad TOTALT ALLE tingene.

  for (int i = 0;  i < gAntallTing;  i++)  {  //  Går gjennom ALLE tingene:
      kostnadTing = tingHentKostnad(gTing[i]);       //  EN tings kostnad.
      if (kostnadTing > 0)  {                        //  Tingen har en pris:
         antallMedPris++;                            //  Teller opp antallet,
         totalt += kostnadTing;                      //    og TOTALkostnaden
      }                                              //    for ALLE tingene.
  }
  printf("\n\tTOTALkostnad for %i ting:  %.2f\n", antallMedPris, totalt);
  printf("\t%i ting er uten pris hittil\n\n", gAntallTing-antallMedPris);
}


/**
 *  Oppgave 2E - Regner ut og returnerer EN tings TOTALE kostnad/pris.
 *
 *  @param    ting  -  Tingen som får sin totalkostnad beregnet
 *  @return   Tingens totale kostnad
 */
float tingHentKostnad(const struct Ting* ting)  {
  return (ting->pris * ting->antall);
}


/**
 *  Oppgave 2F - Skriver ALLE tingene til fil.
 *
 *  @see   tingSkrivTilFil(...)
 */
void skrivTilFil() {
  FILE* utfil = fopen("EX_S22_TING.DT2", "w");   //  Åpner aktuell fil:

  if (utfil) {                                   //  Filen kan åpnes:
    printf("\n\n\tSkriver til filen 'EX_S22_TING.DT2'.....\n\n");

    fprintf(utfil, "%i\n", gAntallTing);         //  Skriver antall ting.

    for (int i = 0; i < gAntallTing; i++)        //  Går gjennom ALLE tingene:
        tingSkrivTilFil(utfil, gTing[i]);        //  Hver ting skrives.
  } else                                   //  Filen ikke funnet/mulig å åpne:
    printf("Klarte ikke å åpne filen 'EX_S22_TING.DT2'!\n\n");

  fclose(utfil);                                 //  Lukker filen.
}


/**
 *  Oppgave 2F - Alle EN tings data skrives ut på fil.
 *
 *  @param   ut    -  Filen det skal skrives til
 *  @param   ting  -  Tingen som skrives til fil
 *  @see     charFraEnum(...)
 */
 void  tingSkrivTilFil(FILE* ut, const struct Ting* ting)  {
   fprintf(ut, "%s\n%.1f %.2f %c\n", ting->navn, ting->antall, ting->pris,
           charFraEnum(ting->enhet));
}


/**
 *  Oppgave 2G - Leser ALLE tingene fra fil.
 *
 *  @see   tingLesFraFil(...)
 */
void  lesFraFil()  {
  FILE* innfil  = fopen("EX_S22_TING.DTA", "r"); //  Åpner aktuell fil:

  if (innfil) {                                  //  Filen finnes:
     fscanf(innfil, "%i", &gAntallTing);         //  Leser antall ting.
     getc(innfil);                               //  Leser avsluttende '\n'.
                                                 //  Alle ting lages og leses:
     for (int i = 0;  i < gAntallTing;  i++) {
       gTing[i] = (struct Ting*) malloc(sizeof(struct Ting));
       tingLesFraFil(innfil, gTing[i]);          // Leser selv.
     }
     printf("\n\tTing er lest inn fra 'EX_S22_TING.DTA'!\n\n");
  } else                                         //  Filen ikke funnet:
     printf("\n\tFant ikke filen 'EX_S22_TING.DTA'!\n\n");

  fclose(innfil);                                //  Lukker åpen fil.
}


/**
 *  Oppgave 2G - Leser ALT om EN ting fra fil.
 *
 *  @param   inn   -  Filen det skal leses fra
 *  @param   ting  -  Tingen som får innlest sine data
 *  @see     enumFraChar(...)
 */
void  tingLesFraFil(FILE* inn, struct Ting* ting)  {
  char tegn;                           //  Bokstav (C, M, K, S, L) for Enhet.
  char buffer[STRLEN];                 //  Buffer for innlest tekst.
                                       //  Leser 'navn':
  fgets(buffer, STRLEN, inn);    buffer[strlen(buffer)-1] = '\0';
  ting->navn = (char*) malloc((strlen(buffer) + 1) * sizeof(char));
  strcpy(ting->navn, buffer);
                                       //  Leser 3x andre datamedlemmer:
  fscanf(inn, "%f %f %c", &ting->antall, &ting->pris, &tegn);
  getc(inn);                           //  Forkaster avsluttende '\n'.

  ting->enhet = enumFraChar(tegn);     //  Setter tingens 'enhet' ut
}                                      //    fra innlest bokstav.
