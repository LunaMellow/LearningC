/**
 *   Løsningsforslag til eksamen i GrProg (i C), august 2023, oppgave 2.
 *
 *   Programmet holder orden på ulike brøytere/strøere og deres kunder.
 *
 *   @file     EX_S23_2.C
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
void skrivAlleBroytStro();                                           // EKSTRA
void broytStroSkrivData(const struct BroyterStroer* broytStro);      // EKSTRA
void nullstillBroytStro();                                           // EKSTRA
void kundeNullstillBroytStro(struct Kunde* kunde);                   // EKSTRA
void broytStroLesFraFil(FILE* inn, struct BroyterStroer* broytStro); // EKSTRA


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
          case 'A':  skrivAlleBroytStro();             break;  //  EKSTRA
          case 'N':  nullstillBroytStro();             break;  //  EKSTRA
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
    printf("   EKSTRA:\n");
    printf("\tA  = skriv Alle brøytere/strøere\n");
    printf("\tN  = Nullstill antall bøytinger/strøinger hos alle kunder\n");
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
  if (gAntallKunder > 0)  {                       //  Kunder finnes:
     printf("\n\tAlle kundene:\n");
     for (int i = 0;  i < gAntallKunder;  i++) {  //  For hver kunde:
        printf("\t   Nr.%3i:  ", i+1);            //  Kundens nummer:  1 -->
        kundeSkrivData(gKunder[i]);               //  Hver skriver seg selv.
     }
  } else
     printf("\n\tTomt for kunder!\n\n");
}


/**
 *  Oppgave 2A - Skriver ALT om EN kunde ut på skjermen.
 *
 *  @param   kunde  -  Kunden som skrives ut
 *  @see     broytStroSkrivNavn(...)
 */
void kundeSkrivData(const struct Kunde* kunde)  {
printf("  %s,  %s,  %i\n\t\tPris pr.gang: %3i,-  #brøyt: %2i  #strø: %2i  av  ",
          kunde->navn, kunde->adresse, kunde->tlf, PRIS[kunde->prisNr],
          kunde->antBroyt, kunde->antStro);
  broytStroSkrivNavn(gBroytereStroere[kunde->BSNr]);
  printf("\n");
}


/**
 *  Oppgave 2B - Legger inn (om mulig) en ny kunde inn i datastrukturen.
 *
 *  @see   kundeLesData(...)
 */
void nyKunde()  {
  if (gAntallKunder < MAXKUNDER)  {             //  Plass til flere kunder:
     printf("\n\tNy kunde nr. %i:\n", gAntallKunder+1);
                                                //  Oppretter en ny kunde:
     gKunder[gAntallKunder] = (struct Kunde*) malloc(sizeof(struct Kunde));
     kundeLesData(gKunder[gAntallKunder]);      //  Kunden leser egne data:
     gAntallKunder++;                           //  Antallet telles opp.
  } else                                        //  Fullt med kunder:
     printf("\n\tFullt med %i kunder allerede!\n", MAXKUNDER);
}


/**
 *  Oppgave 2B - Leser inn ALLE datamedlemmene i EN kunde.
 *
 *  @param   kunde  -  Kunden som får innlest sine data
 */
void kundeLesData(struct Kunde* kunde)  {
  kunde->navn     = lagOgLesText("\tNavn   ");     //  Leser og lager navnet.
  kunde->adresse  = lagOgLesText("\tAdresse");     //  Leser og lager adressen.
  kunde->tlf      = lesInt("\tTelefon", 10000000, 99999999);
  kunde->BSNr     = lesInt("\tBrøyter nr", 1, gAntallBroytStro) - 1;
  kunde->prisNr   = lesInt("\tPrisgruppe", 1, 3) - 1;
  kunde->antBroyt = kunde->antStro = 0; // Nuller antall brøytinger/strøinger.
}


/**
 *  Oppgave 2C - Registrerer brøyting/strøing hos kunder.
 *
 *  @see   kundeBroytetStrodd(...)
 */
void broytetStroddHosKunder()  {
  int nr;

  nr = lesInt("\tBrøytet/strødd hos kunde nr (0=avslutt)", 0, gAntallKunder);
  while (nr > 0)  {                             //  Vil fortsatt registrere:
    kundeBroytetStrodd(gKunder[nr-1]);          //  Oppdaterer hos kunde.
    nr=lesInt("\n\tBrøytet/strødd hos kunde nr (0=avslutt)", 0,gAntallKunder);
  }
}


/**
 *  Oppgave 2C - Registrerer brøyting/strøing hos EN kunde.
 *
 *  @param    kunde  -  Kunden det registreres brøyting/strøing hos
 */
void kundeBroytetStrodd(struct Kunde* kunde)  {
  char bs;

  do  {                                           //  Leser og sikrer enten
    bs = lesChar("\tB(røytet) eller S(trødd)");   //    B(røyting) eller
  } while (bs != 'B'  &&  bs !='S');              //    S(trøing).

  if (bs == 'B')  kunde->antBroyt++;              //  Aktuelt antall
  else            kunde->antStro++;               //    telles opp.
}


/**
 *  Oppgave 2D - Skriver/lager (om mulig) fakturaer for ALLE kundene.
 *
 *  @see   kundeLagFaktura(...)
 */
void lagFakturaer()  {
  if (gAntallKunder > 0)  {                       //  Kunder finnes:
     printf("\n\tFakturaer for alle kundene:\n\n");
     for (int i = 0;  i < gAntallKunder;  i++) {  //  For hver kunde:
        printf("\t   Nr.%3i:  ", i+1);            //  Kundens nummer:  1 -->
        kundeLagFaktura(gKunder[i]);              //  Hver lager faktura selv.
     }
  } else
     printf("\n\tTomt for kunder!\n\n");
}


/**
 *  Oppgave 2D - Skriver ut på skjermen faktura (kostnad) for EN kunde.
 *
 *  @param    kunde  -  Kunden det skrives/lages faktura for
 *  @see      kundeHentKostnad(...)
 *  @see      kundeSkrivData(...)
 */
void kundeLagFaktura(const struct Kunde* kunde)  {
  kundeSkrivData(kunde);                    //  Skriver ALLE data og kostnad:
  printf("\t\tTOTAL KOSTNAD: %5i\n\n", kundeHentKostnad(kunde));
}


/**
 *  Oppgave 2E - Endrer (om mulig) brøyter/strøer for en kunde.
 *
 *  @see   kundeHentKostnad(...)
 *  @see   kundeEndreBroyterStroer(...)
 */
void endreBroyterStroer()  {
  int nr;

  if (gAntallKunder > 0)  {                         //  Kunder finnes:
     nr = lesInt("\tEndre brøyter/strøer for kunde nr", 1, gAntallKunder);
     if (kundeHentKostnad(gKunder[nr-1]) == 0)      //  Antallene er null!!!
        kundeEndreBroyterStroer(gKunder[nr-1]);     //  Endrer brøyter/strøer.
     else
     printf("\n\tKan kun endre når antall brøytinger/strøinger er null!\n\n");
  } else
     printf("\n\tTomt for kunder!\n\n");
}


/**
 *  Oppgave 2E - Endrer en kundes brøyter/strøer.
 *
 *  @param    kunde  -  Kundens som får sin brøyter/strøer endret
 *  @see      broytStroSkrivNavn(...)
 */
void kundeEndreBroyterStroer(struct Kunde* kunde)  {
  printf("\n\tNåværende brøyter/strøer er nr.%i - ", kunde->BSNr+1);
  broytStroSkrivNavn(gBroytereStroere[kunde->BSNr]);

  kunde->BSNr =                  //  Leser/setter ny brøyters/strøers nummer:
             lesInt("\n\tNy brøyter/strøer sitt nr", 1, gAntallBroytStro) - 1;
}


/**
 *  Oppgave 2F - Finner og skriver brøyter/strøer med mest inntjening.
 *
 *  @see   kundeHentBSNr(...)
 *  @see   kundeHentKostnad(...)
 *  @see   broytStroSkrivNavn(...)
 */
void broyterStroerMedMestInntjening()  {
  int i, j,                  //  Løkkevariable.
      nr,                    //  Nummer på brøyter/strøer med mest inntjening.
      sum,                   //  Nåværende akkumulert totalsum.
      mest = -1;             //  Høyeste inntjening så langt.
  bool flere = false;        //  Om flere har samme max.inntjening eller ei.

  for (i = 0;  i < gAntallBroytStro;  i++)  {   //  Går gjennom alle b/s:
      sum = 0;                                  //  Nullstiller kundens sum.
      for (j = 0;  j < gAntallKunder;  j++)     //  Går gjennom alle kunder:
          if (kundeHentBSNr(gKunder[j]) == i)   //  Kunden bruker aktuell b/s!
             sum += kundeHentKostnad(gKunder[j]); //  Øker total inntjening.

      if (sum > mest)  {                     //  Ny høyeste inntjening:
         flere = false;                      //  Er alene om dette.
         mest = sum;                         //  Oppdaterer 'rekorden' og
         nr = i;                             //    brøyters/strøers nummer.
      } else if (sum == mest)                //  Tangering av mest inntjening:
         flere = true;                       //  Flere har da samme sum.
  }

  printf("\n\t");
  broytStroSkrivNavn(gBroytereStroere[nr]);
  printf("  har mest inntjening med:  %i kroner\n\n", mest);

  if (flere)                             //  Flere med samme meste inntjening:
     printf("\tMen andre har også den samme inntjeningen .....\n\n");
}


/**
 *  Oppgave 2G - Leser ALLE kundene (og ALLE brøytere/strøere) inn fra fil.
 *
 *  @see   kundeLesFraFil(...)
 *  @see   broytStroLesFraFil(...)
 */
void lesFraFil() {
  FILE* innfil  = fopen("EX_S23_KUNDER.DTA", "r"); //  Åpner aktuell fil:

  if (innfil) {                                //  Filen finnes:
     fscanf(innfil, "%i", &gAntallKunder);     //  Leser antall kunder.
     getc(innfil);                             //  Leser avsluttende '\n'.
                                               //  Alle kunder lages og leses:
     for (int i = 0;  i < gAntallKunder;  i++) {
       gKunder[i] = (struct Kunde*) malloc(sizeof(struct Kunde));
       kundeLesFraFil(innfil, gKunder[i]);     // Leser selv.
     }
     printf("\n\n\tKunder er lest inn fra 'EX_S23_KUNDER.DTA'.\n\n");
  } else                                       //  Filen ikke funnet:
     printf("\n\tFant ikke filen 'EX_S23_KUNDER.DTA'!\n\n");

  fclose(innfil);                              //  Lukker åpen fil.


//  ****************   EKSTRA (resten av funksjonen):   ******************

  innfil  = fopen("EX_S23_BROYTSTRO.DTA", "r"); //  Åpner aktuell fil:

  if (innfil) {                               //  Filen finnes:
     fscanf(innfil, "%i", &gAntallBroytStro); // Leser antall brøytere/strøere.
     getc(innfil);                            //  Leser avsluttende '\n'.
                                     //  Alle brøytere/strøere lages og leses:
     for (int i = 0;  i < gAntallBroytStro;  i++) {
       gBroytereStroere[i] =
                 (struct BroyterStroer*) malloc(sizeof(struct BroyterStroer));
       broytStroLesFraFil(innfil, gBroytereStroere[i]);     // Leser selv.
     }
     printf("\tBrøytere/støere er lest inn fra 'EX_S23_BROYTSTRO.DTA'.\n\n");
  } else                                       //  Filen ikke funnet:
     printf("\n\tFant ikke filen 'EX_S23_BROYTSTRO.DTA'!\n\n");

  fclose(innfil);                              //  Lukker åpen fil.
}


/**
 *  Oppgave 2G - Leser ALT om EN kunde inn fra fil.
 *
 *  @param  inn    -  Filen det skal leses fra
 *  @param  kunde  -  Kunden som får innlest sine data
 */
void kundeLesFraFil(FILE* inn, struct Kunde* kunde) {
    char buffer[STRLEN];                //  Buffer for innlest tekst.

    fscanf(inn, "%i %i %i %i %i", &kunde->tlf, &kunde->prisNr, &kunde->BSNr,
                                  &kunde->antBroyt, &kunde->antStro);
    getc(inn);                          //  Forkaster ' ' (blank).
                                        //  Leser 'navn':
    fgets(buffer, STRLEN, inn);    buffer[strlen(buffer)-1] = '\0';
    kunde->navn = (char*) malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(kunde->navn, buffer);
                                        //  Leser 'adresse':
    fgets(buffer, STRLEN, inn);    buffer[strlen(buffer)-1] = '\0';
    kunde->adresse = (char*) malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(kunde->adresse, buffer);
}




// **************************************************************************
// **************************************************************************
// **   Alt nedenfor er EKSTRA, og ikke en del av eksamensoppgaven.
// **************************************************************************
// **************************************************************************

/**
 *  EKSTRA - Skriver ALT om ALLE brøytere/strøere ut på skjermen.
 *
 *  @see   broytStroSkrivData(...)
 */
void skrivAlleBroytStro()  {
  if (gAntallBroytStro > 0)  {                    //  Brøytere/strøere finnes:
     printf("\n\tAlle brøyterne/strøerne:\n");
     for (int i = 0;  i < gAntallBroytStro;  i++) { //For hver brøyter/strøer:
        printf("\t   Nr.%3i:  ", i+1);            //  Dens nummer:  1 -->
        broytStroSkrivData(gBroytereStroere[i]);  //  Hver skriver seg selv.
     }
  } else
     printf("\n\tTomt for brøytere/strøere!\n\n");
}


/**
 *  EKSTRA - Skriver ALT om EN brøyter/strøer ut på skjermen.
 *
 *  @param   broytStro  -  Brøyteren/strøeren som skrives ut
 */
void broytStroSkrivData(const struct BroyterStroer* broytStro)  {
  printf("  %s,   %i\n", broytStro->navn, broytStro->tlf);
}


/**
 *  EKSTRA - Nullstiller (om ønskelig) ALLE kunders antall brøyting/strøing.
 *
 *  @see   kundeNullstillBroytStro(...)
 */
void nullstillBroytStro()  {
  char valg =
lesChar("\n\tVil du VIKELIG nullstille ALL brøyting/strøing hos alle kunder (N/j)");

  if (valg == 'J')  {                           //  Ønsker å nullstille:
    for (int i = 0;  i < gAntallKunder;  i++)   //  For hver kunde:
        kundeNullstillBroytStro(gKunder[i]);
    printf("\n\tALLE kundenes antall brøytinger/strøinger er nullstilt!\n\n");
  } else
    printf("\n\tOK - ingen nullstilling har skjedd.\n\n");
}


/**
 *  EKSTRA - Nullstiller antall brøytinger og strøinger hos EN kunde.
 *
 *  @param   Kunde  -  Kunde som får sine ant.brøytinger/strøinger nullstilt
 */
void kundeNullstillBroytStro(struct Kunde* kunde)  {
  kunde->antBroyt = kunde->antStro = 0;
}


/**
 *  EKSTRA - Leser ALT om EN brøyter/strøer inn fra fil.
 *
 *  @param   inn    -  Filen det skal leses fra
 *  @param   kunde  -  Brøyteren/strøen som får innlest sine data
 */
void broytStroLesFraFil(FILE* inn, struct BroyterStroer* broytStro)  {
  char buffer[STRLEN];                //  Buffer for innlest tekst.

  fscanf(inn, "%i", &broytStro->tlf); //  Leser telefonnummer.
  getc(inn);                          //  Forkaster ' ' (blank).
                                      //  Leser 'navn':
  fgets(buffer, STRLEN, inn);    buffer[strlen(buffer)-1] = '\0';
  broytStro->navn = (char*) malloc((strlen(buffer) + 1) * sizeof(char));
  strcpy(broytStro->navn, buffer);
}
