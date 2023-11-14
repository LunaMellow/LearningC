/**
 *   Løsningsforslag til eksamen i GrProg (i C), november 2019, oppgave 2.
 *
 *   Programmet holder orden på ansatte på en arbeidsplass, hvilke dager
 *   de (ikke) skal arbeide, og om de har møtt opp eller ei til arbeidet.
 *
 *   @file     EX_H19_2.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>               //  printf, scanf, FILE
#include <stdlib.h>              //  sizeof, malloc, free
#include <string.h>              //  strcpy, strlen
#include <stdbool.h>             //  bool, true, false
#include "LesData.h"             //  Verktøykasse for lesing av diverse data

#define   MAXDAG        31       ///<  Max. antall dager i en måned.
#define   MAXANSATTE   100       ///<  Max. antall ansatte.
const int STRLEN    =   80;      ///<  Max. tekstlengde.


/**
 *  Ansatt (med navn, mailadresse, mobiltlf og hvordan jobber DENNE måneden).
 */
struct Ansatt {
    char* navn,                  //  Ansattes navn.
        * mail;                  //  Mailadresse.
    int   mobil;                 //  Mobiltelefonnummer.
    char  jobbing[MAXDAG];       //  Jobbingen i løpet av måneden
};                               //    ('-'= nei,  'J'= jobbe,  'M'= møtt)


void skrivMeny();
void nyAnsatt();                                           //  Oppgave 2A
void ansattLesOgSettData(struct Ansatt* a);                //  Oppgave 2A
void kommerPaaJobb();                                      //  Oppgave 2B
void ansattAnkommerJobb(struct Ansatt* a);                 //  Oppgave 2B
void oversiktAnsattesJobbing();                            //  Oppgave 2C
void ansattSkrivJobbing(const struct Ansatt* a);           //  Oppgave 2C
void endreEnsJobbingEnDag();                               //  Oppgave 2D
void ansattEndreJobbing(struct Ansatt* a);                 //  Oppgave 2D
void lesJobbingFraFil(const bool lesAlt);                  //  Oppgave 2E
void ansattLesJobbingFraFil(FILE* inn, struct Ansatt* a);  //  Oppgave 2E
void jobbStatistikk();                                     //  Oppgave 2F
void ansatteSkrivStatistikk(const struct Ansatt* a);       //  Oppgave 2F - NY
int  antall(const char* jobb, const int n, const char ch); //  Oppgave 2F - NY
void lesAnsatteFraFil();                                   //  Oppgave 2G
void ansattLesFraFil(FILE* inn, struct Ansatt* a);         //  Oppgave 2G


int gAntallAnsatte,                   ///<  Antall ansatte i bruk i 'gAnsatte'.
    gDagNr,                           ///<  Dagens dato.
    gSisteDag;                        ///<  Aktuell måneds dagantall (28-31).
struct Ansatt* gAnsatte[MAXANSATTE];  ///<  Alle de ansatte.


/**
 *  Hovedprogrammet:
 */
int main()  {
    char kommando;

    lesAnsatteFraFil();                //  Oppgave 2G
    lesJobbingFraFil(false);           //  Oppgave 2E - Henter KUN 'gSisteDag'.
    gDagNr = lesInt("Dato", 1, gSisteDag);  //  Leser dagens dato (1-gSisteDag).

    skrivMeny();
    kommando = lesChar("Ønske");
    while (kommando != 'Q')  {
        switch (kommando)  {
          case 'N': nyAnsatt();                     break;  //  Oppgave 2A
          case 'K': kommerPaaJobb();                break;  //  Oppgave 2B
          case 'O': oversiktAnsattesJobbing();      break;  //  Oppgave 2C
          case 'E': endreEnsJobbingEnDag();         break;  //  Oppgave 2D
          case 'M': lesJobbingFraFil(true);         break;  //  Oppgave 2E
          case 'S': jobbStatistikk();               break;  //  Oppgave 2F
          default:  skrivMeny();                    break;
        }
        kommando = lesChar("Ønske");
    }
//    skrivAnsatteTilFil();       //  Skriver ALLE ansatte tilbake til fil.
    printf("\n\n");
    return 0;
}


/**
 *  Skriver/presenterer programmets muligheter/valg for brukeren.
 */
void skrivMeny() {
    printf("\n\nFØLGENDE KOMMANDOER ER LOVLIG:\n");
    printf("\tN   = Ny ansatt\n");
    printf("\tK   = ansatt Kommer på jobb\n");
    printf("\tO   = Oversikt over alle ansattes jobbing\n");
    printf("\tE   = Endre jobbing for en ansatt på en dag\n");
    printf("\tM   = Månedsskifte (ny jobbplan)\n");
    printf("\tS   = Statistikk over antall dager jobbet/ikke møtt\n");
    printf("\tQ   = Quit/avslutt\n");
}


/**
 *  Oppgave 2A - Legger inn (om mulig) en ny ansatt i datastrukturen.
 *
 *  @see   ansattLesOgSettData(...)
 */
void nyAnsatt() {
  if (gAntallAnsatte < MAXANSATTE) {   //  Plass til flere ansatte:
     printf("\n\tNy ansatt har nr.%i:\n", gAntallAnsatte+1);
                                         //  Oppretter/lager en ny ansatt:
     gAnsatte[gAntallAnsatte] = (struct Ansatt*) malloc(sizeof(struct Ansatt));
                                         //  Ny ansatt leser/setter egne data:
     ansattLesOgSettData(gAnsatte[gAntallAnsatte]);
     gAntallAnsatte++;                   //  Teller opp antall ansatte.
  } else                                 //  Fullt med ansatte:
     printf("\n\tFullt med %i ansatte allerede!\n", MAXANSATTE);;
}


/**
 *  Oppgave 2A - Leser inn og initierer data om EN ansatt.
 *
 *  @param  a - Den ansatte som får innlest/initiert sine data
 */
void ansattLesOgSettData(struct Ansatt* a) {
    int i;
    a->navn  = lagOgLesText("Navn");                //   Leser navn,
    a->mail  = lagOgLesText("Mail");                //     mailadresse og
    a->mobil = lesInt("Mobil", 10000000, 99999999); //     mobiltelefonnummer.
                                         //  Nullstiller irrelevante dager:
    for (i = 0; i < gDagNr - 1; i++)  a->jobbing[i] = '-';
                                         //   Leser jobbing RESTEN av måneden:
    for (int i = gDagNr-1; i < gSisteDag; i++) {
        printf("\tJobber (J) eller ei (-) på dag nr.%i", i+1);
        a->jobbing[i] = lesChar("");   //  Godtar alle slags tegn .....  :-(
    }                                  //  Oppg.2B vil reagere på dette.
}                                      //  Oppg.2D vil tillate at dette endres.


/**
 *  Oppgave 2B - Ansatt har kommet på jobb.
 *
 *  @see   ansattAnkommerJobb(...)
 */
void kommerPaaJobb()  {
    int nr = lesInt("Ansattnr", 1, gAntallAnsatte);  //  Leser aktuelt ansnr.
    ansattAnkommerJobb(gAnsatte[nr - 1]);
}


/**
 *  Oppgave 2B - Registrerer (om mulig) at en ansatt har møtt på jobb.
 *
 *  @param  a - Den ansatte som får registrert at har møtt på jobb
 */
void ansattAnkommerJobb(struct Ansatt* a) {
    if (a->jobbing[gDagNr - 1] == 'J') {       //  SKAL jobbe NÅVÆRENDE dag:
        a->jobbing[gDagNr - 1] = 'M';          //  Setter til 'møtt'.
        printf("\n\tVedkommende registrert som møtt.\n");
    }
    else if (a->jobbing[gDagNr - 1] == '-')    //  Skal pt. IKKE JOBBE i dag:
        printf("\n\tVedkommende jobber ikke i dag!  Endre evt. vha. 'E'.\n");
    else if (a->jobbing[gDagNr - 1] == 'M')    //  Har møtt allerede:
        printf("\n\tVedkommende har møtt allerede!\n");
    else {                                     //  Annet enn '-', 'J' og 'M':
        printf("\n\tNoe er feil med jobbing-oversikten, den inneholder");
        printf(" \'%c\'-tegnet for denne dagen!\n", a->jobbing[gDagNr - 1]);
    }
}


/**
 *  Oppgave 2C - Skriver ALLE de ansattes jobbstatus.
 *
 *  @see   ansattSkrivJobbing(...)
 */
void oversiktAnsattesJobbing()  {
  int i;

  printf("\n");
  for (i = 1; i <= gSisteDag; i++)           //  Skriver dagnumre:
      printf("%-3i", i);
  printf("\n");

  for (i = 0; i < gAntallAnsatte; i++)       //  Hver ansatt skriver seg selv:
      ansattSkrivJobbing(gAnsatte[i]);
  printf("\n");
}


/**
 *  Oppgave 2C - Skriver EN ansatts navn og jobbestatus.
 *
 *  @param  a - Den ene ansatte som jobbstatus skrives for
 */
void ansattSkrivJobbing(const struct Ansatt* a) {
    for (int i = 0;  i < gSisteDag;  i++)
        printf("%-3c", a->jobbing[i]);  //  Skriver jobbstatus ('-', 'J', 'M')
    printf("%s\n", a->navn);            //    og navn.
}


/**
 *  Oppgave 2D - Endre en ansatts jobbing.
 *
 *  @see   ansattEndreJobbing(...)
 */
void endreEnsJobbingEnDag() {
    int nr = lesInt("Ansattnr", 1, gAntallAnsatte);   //  Leser aktuelt ansnr.
    ansattEndreJobbing(gAnsatte[nr - 1]);
}


/**
 *  Oppgave 2D - Endrer (om mulig) status for jobbing.
 *
 *  @param  a - Den ansatte som får endret sin jobbing
 */
void ansattEndreJobbing(struct Ansatt* a) {
   int nr = lesInt("Endre dagnr", gDagNr, gSisteDag); //  Leser dagnr å endre.
   char status;                //  Hjelpevariabel (for å spare lange uttrykk).
                               //  Skriver nåværende status:
   printf("\tNåværende status for dagen: %c\n", a->jobbing[nr-1]);
   do {                        //  Sikrer lovlig status ('-', 'J', 'M'):
       status = lesChar("\tNy status");
   } while (status != '-'  &&  status != 'J'  &&  status != 'M');
                               //  Inneværende dag kan settes til ALT,
   if (nr == gDagNr  ||  status != 'M') //   fremtidige KUN til '-' eller 'J':
       a->jobbing[nr-1] = status;
   else                        //  Ingen fremtidige til 'M':
       printf("\n\tKan ikke sette en fremtidig dag til møtt 'M' allerede!\n");
}


/**
 *  Oppgave 2E - Jobbingen for NESTE måned leses inn i den
 *               allerede eksisterende datastrukturen.
 *
 *  @param   lesAlt - Om HELE filens innhold skal leses, eller KUN 'gSisteDag'
 *  @see     ansattLesJobbingFraFil(...)
 */
void lesJobbingFraFil(const bool lesAlt) {
  FILE* innfil = fopen("EX_H19_JOBBING.DTA", "r");   //  Åpner aktuell fil:
  int ansNr;

  if (innfil)  {                              //  Filen finnes:
     fscanf(innfil, "%i", &gSisteDag);        //  Leser aktuelt dagantall.
     getc(innfil);                            //  Leser avsluttende '\n'.

     if (lesAlt) {                            //  ALT skal (kanskje) leses:
        printf("\n\tDette vil overskrive ALLE nåværende data om jobbing.\n\t");
                                              //  VIL lese inn nye jobbdata:
        if (lesChar("Ønsker du VIRKELIG å gjøre dette(N/j)?") == 'J') {
           fscanf(innfil, "%i", &ansNr);      //  Leser ansattnummer:
                                              //  Lovlig ansattnummer:
           while (!feof(innfil)  &&  ansNr >= 0  &&  ansNr < gAntallAnsatte) {
             ansattLesJobbingFraFil(innfil, gAnsatte[ansNr]); // Leser selv.
             fscanf(innfil, "%i", &ansNr);    //  Leser ansattnummer:
           }
           printf("\n\tNye jobbdata lest inn fra filen 'JOBBING.DTA'!\n\n");
        } else                                //  "Angret" innlesningen:
          printf("\n\tOK - ingenting er lest inn/endret.\n\n");
     }
     fclose(innfil);                          //  Lukker åpen fil.
  } else                                      //  Filen ikke funnet:
    printf("\n\tFant ikke filen 'JOBBING.DTA'!\n\n");
}


/**
 *  Oppgave 2E - Leser KUN jobbstatus for EN ansatt fra fil.
 *
 *  @param  inn - Filen det skal leses fra
 *  @param  a   - Structen som får innlest sine data
 */
void ansattLesJobbingFraFil(FILE* inn, struct Ansatt* a) {
    for (int i = 0; i < gSisteDag; i++)   // Leser KUN antall relevante dager.
        fscanf(inn, " %c", &a->jobbing[i]);
    fgetc(inn);                           //  Forkaster avsluttende '\n'.
}


/**
 *  Oppgave 2F - Statistikk over de ansattes jobbing.
 *
 *  @see   ansattSkrivStatistikk(...)
 */
void jobbStatistikk() {
    for (int i = 0; i < gAntallAnsatte; i++)   //  Går gjennom ALLE ansatte:
        ansatteSkrivStatistikk(gAnsatte[i]);   //  Skriver om (ikke) møtt.
}


/**
 *  Oppgave 2F - NY - Skriver #dager (ikke) møtt og navnet.
 *
 *  @param  Structen som det lages/skrives statistikk for
 *  @see    antall(...)
 */
void ansatteSkrivStatistikk(const struct Ansatt* a) {
  printf("\t#jobbet: %2i   #IKKE møtt: %2i    %s\n",
         antall(a->jobbing, gDagNr, 'M'),            //  Jobbet/møtt.
         antall(a->jobbing, gDagNr, 'J'), a->navn);  //  Jobb - men IKKE møtt.
}


/**
 *  Oppgave 2F - NY - Teller opp og returnerer antall 'ch' i arrayen'jobb'.
 *
 *  @param   jobb - Arrayen det telles opp antall 'ch' i
 *  @param   n    - Arrayens lengde  (leser/bruker indeks  0 - n-1)
 *  @param   ch   - Tegnet det skal telles opp antall av i 'jobb'
 *  @return  Totalt antall 'ch' i arrayen 'jobb' med 'n' elementer
 */
int  antall(const char* jobb, const int n, const char ch) {
    int totalt = 0;                     //  Viktig at er nullstilt!
    for (int i = 0; i < n; i++)         //  Går gjennom aktuelle del av array:
        if (jobb[i] == ch)  totalt++;   //  Tegnet er 'ch' - teller opp.
    return totalt;                      //  Returnerer antall funnet av 'ch'.
}


/**
 *  Oppgave 2G - Leser ALLE ansatte fra fil.
 *
 *  @see     ansattLesFraFil(...)
 */
void lesAnsatteFraFil() {
    FILE* innfil = fopen("EX_H19_ANSATTE.DTA", "r");  //  Åpner aktuell fil:

    if (innfil) {                              //  Filen finnes:
        fscanf(innfil, "%i", &gAntallAnsatte); //  Leser antall ansatte.
        getc(innfil);                          //  Leser avsluttende '\n'.
                                               // Alle ansatte lages og leses:
        for (int i = 0; i < gAntallAnsatte; i++) {
            gAnsatte[i] = (struct Ansatt*) malloc(sizeof(struct Ansatt));
            ansattLesFraFil(innfil, gAnsatte[i]); // Leser selv.
        }
        printf("\n\tAlle ansatte er lest inn fra filen 'ANSATTE.DTA'!\n\n");
        fclose(innfil);                        //  Lukker åpen fil.
    } else                                     //  Filen ikke funnet:
        printf("\n\tFant ikke filen 'ANSATTE.DTA'!\n\n");
}


/**
 *  Oppgave 2G - Leser ALT om EN ansatt fra fil.
 *
 *  @param  inn - Filen det skal leses fra
 *  @param  a   - Structen som får innlest sine data
 */
void ansattLesFraFil(FILE* inn, struct Ansatt* a)  {
    char buffer[STRLEN];                         //  Buffer for innlest tekst.

    fscanf(inn, "%i %s", &a->mobil, buffer);     //  Leser tlf og mail-adr.
    a->mail = (char*) malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(a->mail, buffer);                     //  Lagrer unna mail-adr.
    fgetc(inn);                                  //  Skipper ' ' (blank).
                                                 //  Leser navn, tar vekk '\n:
    fgets(buffer, STRLEN, inn);    buffer[strlen(buffer) - 1] = '\0';
    a->navn = (char*) malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(a->navn, buffer);

    for (int i = 0; i < MAXDAG; i++)      //  Leser jobbingen ('-', 'J', 'M').
        fscanf(inn, " %c", &a->jobbing[i]);
    fgetc(inn);                           //  Forkaster avsluttende '\n'.
}
