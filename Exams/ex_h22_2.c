/**
 *   Løsningsforslag til eksamen i GrProg (i C), desember 2022, oppgave 2.
 *
 *   Programmet holder orden på ulike hendelser (overnattinger,
 *   aktiviteter/gjøremål og bespisning) under en biltur (i Alpene).
 *
 *   @file     EX_H22_2.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>               //  printf, scanf, FILE
#include <stdlib.h>              //  sizeof, malloc
#include <string.h>              //  strcpy, strlen
#include <stdbool.h>             //  bool, true, false
#include "LesData.h"             //  Verktøykasse for lesing av diverse data


#define   MAXHENDELSER   100     ///<  Max. antall hendelser på turen.
const int STRLEN  =       80;    ///<  Max. tekstlengde.


/**
 *  Type hendelse (ulike type hendelser som kan skje på turen).
 */
enum Type { Attraksjon, Fjelltopp, Hotell, Idrettsarena, Museum, Spisested };


/**
 *  Hendelse (med navn, sted, webside, dato, klokkeslett og hendelsestype).
 */
struct Hendelse {             //  Hendelsens:
  char* navn,                 //     - navn
      * sted,                 //     - sted
      * webside;              //     - webside/URL
  int   dato,                 //     - dato, på formen: MMDD (måned/dag)
        klokken;              //     - klokkeslett, på formen: TTMM (time/min)
  enum Type type;             //     - jfr. ovenstående 'enum'
};


void skrivMeny();                                              //  | Ferdig-
void skrivTypeTekst(const enum Type type);                     //  | laget:
enum Type typeFraChar(const char tegn);                        //  |
void nyHendelse();                                             //  Oppgave 2A
void hendelseLesData(struct Hendelse* hendelse);               //  Oppgave 2A
void skrivAlt();                                               //  Oppgave 2B
void hendelseSkrivData(const struct Hendelse* hendelse);       //  Oppgave 2B
enum Type lesHendelsesType();                                  //  Oppgave 2C
void nyHendelse2();                                            //  Oppgave 2D
void skrivGitteHendelser();                                    //  Oppgave 2E
void datoMedFlestHendelser();                                  //  Oppgave 2F
void lesFraFil();                                              //  Oppgave 2G
void hendelseLesFraFil(FILE* inn, struct Hendelse* hendelse);  //  Oppgave 2G


int    gAntallHendelser;             ///<  Antall hendelser hittil registrert.
struct Hendelse* gHendelser[MAXHENDELSER];  ///<  Alle hendelsene.


/**
 *  Hovedprogrammet:
 */
int main()  {
    char kommando;

    lesFraFil();                                          //  Oppgave 2G

    skrivMeny();
    kommando = lesChar("\nØnske");

    while (kommando != 'Q') {
        switch (kommando) {
          case 'N':  nyHendelse2();             break;    //  Oppgave 2A og 2D
          case 'S':  skrivAlt();                break;    //  Oppgave 2B
          case 'G':  skrivGitteHendelser();     break;    //  Oppgave 2E
          case 'F':  datoMedFlestHendelser();   break;    //  Oppgave 2F
          default:   skrivMeny();               break;
        }
        kommando = lesChar("\nØnske");
    }

//    skrivTilFil();                         //  Ikke del av eksamensoppgaven.

    return 0;
}


/**
 *  Skriver/presenterer programmets muligheter/valg for brukeren.
 */
void skrivMeny() {
    printf("\nFØLGENDE KOMMANDOER ER LOVLIG:\n");
    printf("\tN   = Ny hendelse\n");
    printf("\tS   = Skriv alle hendelser\n");
    printf("\tG   = skriv Gitte hendelser\n");
    printf("\tF   = skriv datoen med Flest hendelser\n");
    printf("\tQ   = Quit/avslutt\n");
}


/**
 *  Skriver ut en Type på skjermen som tekst.
 *
 *  @param   type  -  Hendelsestypen som skrives ut
 */
void skrivTypeTekst(const enum Type type)  {
   switch (type)  {                          //  Skriver enum-verdi som tekst:
     case Attraksjon:    printf("Attraksjon    ");   break;
     case Fjelltopp:     printf("Fjelltopp     ");   break;
     case Hotell:        printf("Hotell        ");   break;
     case Idrettsarena:  printf("Idrettsarena  ");   break;
     case Museum:        printf("Museum        ");   break;
     case Spisested:     printf("Spisested     ");   break;
   }
}


/**
 *  Gjør om en lovlig bokstav til en aktuell enum-verdi.
 *
 *  @param    tegn  -  Bokstav/tegn som skal konverteres til enum-verdi
 *  @return   Enum-verdi ut fra en bokstav/tegn
 */
enum Type typeFraChar(const char tegn)  {
  switch (tegn)  {
    case 'A':  return  Attraksjon;               //  Ut fra bokstav returneres
    case 'F':  return  Fjelltopp;                //    aktuell enum-verdi:
    case 'H':  return  Hotell;
    case 'I':  return  Idrettsarena;
    case 'M':  return  Museum;
    case 'S':  return  Spisested;
  }
}


/**
 *  Oppgave 2A - Legger inn (om mulig) en ny hendelse inn i datastrukturen.
 *
 *  @see      hendelseLesData(...)
 */
void nyHendelse()  {
  if (gAntallHendelser < MAXHENDELSER)  {       //  Plass til flere hendelser:
     printf("\n\tNy hendelse er den %i.\n", gAntallHendelser+1);
                                                //  Oppretter en ny hendelse:
     gHendelser[gAntallHendelser] =
                           (struct Hendelse*) malloc(sizeof(struct Hendelse));
                                                //  Hendelsen leser egne data:
     hendelseLesData(gHendelser[gAntallHendelser]);
     gAntallHendelser++;                        //  Antallet telles opp.
  } else                                        //  Fullt med hendelser:
     printf("\n\tFullt med %i hendelser allerede!\n", MAXHENDELSER);
}


/**
 *  Oppgave 2A - Leser inn ALLE datamedlemmene i EN hendelse.
 *
 *  @param   hendelse  -  Hendelsen som får innlest sine data
 *  @see     lesHendelsesType()
 */
void hendelseLesData(struct Hendelse* hendelse)  {
  hendelse->navn = lagOgLesText("\tNavn");        //  Leser og lager navnet.
  hendelse->sted = lagOgLesText("\tSted");        //  Leser og lager stedet.
  hendelse->webside = lagOgLesText("\tWebside");  //  Leser og lager websiden.
  hendelse->dato    = lesInt("\tDato (MMDD)", 101, 1231);  // Leser datoen.
  hendelse->klokken = lesInt("\tKlokken (TTMM)", 0, 2359); // Leser tidspunkt.
  hendelse->type    = lesHendelsesType();         //  Leser hendelsestypen.
}


/**
 *  Oppgave 2B - Skriver ALT om ALLE hendelsene.
 *
 *  @see   hendelseSkrivData(...)
 */
void skrivAlt()  {
  printf("\n\tAlle hendelsene i oversikten (med deres nåværende numre):\n");
  for (int i = 0;  i < gAntallHendelser;  i++) {
      printf("\t   Nr.%3i:  ", i+1);             //  Skriver nåværende nummer.
      hendelseSkrivData(gHendelser[i]);          //  Hver skriver seg selv.
  }
}


/**
 *  Oppgave 2B - Skriver ALT om EN hendelse ut på skjermen.
 *
 *  @param   hendelse  -  Hendelsen som skrives ut
 */
void hendelseSkrivData(const struct Hendelse* hendelse)  {
  printf("%2i/%.2i kl.%.2i:%.2i - ", hendelse->dato % 100, hendelse->dato / 100,
                           hendelse->klokken / 100, hendelse->klokken % 100);
  skrivTypeTekst(hendelse->type);
  printf("%s, %s\n\t\t\t\t%s\n",
                          hendelse->navn, hendelse->sted, hendelse->webside);
}


/**
 *  Oppgave 2C - Leser forbokstaven i de ulike Typene, returnerer aktuell enum.
 *
 *  @return  Enum-verdien ut fra forbokstaven i selve enum-verdien
 */
enum Type lesHendelsesType()  {
  char tegn;
  do  {                                          //  Leser og sikrer at KUN
    tegn = lesChar("\tType (A F H I M S)");      //    er en av enum'enes
  } while (tegn != 'A'  &&  tegn != 'F'  &&      //    forbokstaver.
           tegn != 'H'  &&  tegn != 'I'  &&
           tegn != 'M'  &&  tegn != 'S');

  switch (tegn)  {                               //  Returnerer aktuell enum:
    case 'A':   return Attraksjon;
    case 'F':   return Fjelltopp;
    case 'H':   return Hotell;
    case 'I':   return Idrettsarena;
    case 'M':   return Museum;
    case 'S':   return Spisested;
  }
//  Evt. kan HELE switch'en erstattes med bare:   return (typeFraChar(tegn));
}


/**
 *  Oppgave 2D - SMETTER INN (om mulig) en ny hendelse inn i datastrukturen.
 *
 *  @see      skrivAlt()
 *  @see      hendelseLesData(...)
 */
void nyHendelse2()  {
  int nrNy;

  if (gAntallHendelser < MAXHENDELSER)  {   //  Plass til flere hendelser:
     skrivAlt();
     printf("\n\tAntall hendelser er:  %i\n", gAntallHendelser);
     nrNy = lesInt("\tNy smettes inn som nr", 1, gAntallHendelser+1);
                                       //  Aktuelle flyttes evt. opp ETT hakk:
     for (int i = gAntallHendelser;  i >= nrNy;  i--)
         gHendelser[i] = gHendelser[i-1];
                                            //  Smetter inn ny hendelse:
     gHendelser[nrNy-1] = (struct Hendelse*) malloc(sizeof(struct Hendelse));
     hendelseLesData(gHendelser[nrNy-1]);   //  Hendelsen leser egne data:
     gAntallHendelser++;                    //  Antallet telles opp.
  } else                                    //  Fullt med hendelser:
     printf("\n\tFullt med %i hendelser allerede!\n", MAXHENDELSER);
}


/**
 *  Oppgave 2E - Skriver aktuelle hendelser på ønsket dato eller av type.
 *
 *  @see      hendelseSkrivData(...)
 */
void skrivGitteHendelser()  {
  char valg;                                   //  Brukerens vlag ('D'/'T').
  int  dato;                                   //  Ønsket dato.
  enum Type type;                              //  Ønsket type hendelse.
  bool funn = false;                           //  Foreløpig inen funn/match.

  if (gAntallHendelser > 0)  {                     //  Hendelser finnes:
     valg = lesChar("\tSkrive hendelser på D(ato) eller T(ype)");
     if (valg == 'D')  {                           //  Dato er valgt:
        dato = lesInt("\tØnsket dato", 101, 1231); //  Leser ønsket dato.
        for (int i = 0;  i < gAntallHendelser;  i++)  //  Går gjennom alle:
            if (gHendelser[i]->dato == dato)  {       //  Av ønsket dato:
               funn = true;  printf("\n\t");          //  Registrerer funn.
               hendelseSkrivData(gHendelser[i]);      //  Skriver hendelsen.
            }
        if (!funn)  printf("\n\tIngen hendelser på denne datoen!\n\n");
     } else if (valg == 'T')  {                //  Type hendelse er valgt:
         type = lesHendelsesType();            //  Leser ønsket type hendelse.
         for (int i = 0;  i < gAntallHendelser;  i++) //  Går gjennom alle:
             if (gHendelser[i]->type == type) {       //  Av ønsket type:
               funn = true;  printf("\n\t");          //  Registrerer funn.
               hendelseSkrivData(gHendelser[i]);      //  Skriver hendelsen.
            }
         if (!funn)  printf("\n\tIngen hendelser av denne typen!\n\n");
     } else                                        //  Ulovlig/uaktuelt valg:
        printf("\n\tUlovlig type hendelse innskrevet!\n\n");
  } else
     printf("\n\tIngen hendelser ennå registrert.\n\n");
}


/**
 *  Oppgave 2F - Skriver (den første) datoen med flest hendelser.
 */
void datoMedFlestHendelser()  {
  int flestHendelser = 0, antHendelser = 0,
      dato, datoFlest, forrigeDato = 0;

  if (gAntallHendelser > 0)  {                  //  Hendelser finnes:
     for (int i = 0;  i < gAntallHendelser;  i++)  {  //  Går gjennom alle:
         dato = gHendelser[i]->dato;            //  Henter aktuell dato.
         if (forrigeDato == dato)               //  Den er lik den forrige:
            antHendelser++;                     //  Antallet telles opp.
         else                                   //  Ny dato (ulik forrige):
            antHendelser = 1;                   //  Antallet tilbakestilles.

         if (antHendelser > flestHendelser)  {  //  Nytt rekordantall?
             flestHendelser = antHendelser;     //  Lagrer isåfall unna dette
             datoFlest = forrigeDato;           //    antallet og datoen.
         }
         forrigeDato = dato;                    //  'forrigedato' oppdateres.
     }
     printf("\n\tDet er flest hendelser på datoen %i/%i med %i stk.\n\n",
             datoFlest%100, datoFlest/100, flestHendelser);
  } else
     printf("\n\tIngen hendelser ennå registrert.\n\n");
}


/**
 *  Oppgave 2G - Leser ALLE hendelsene inn fra fil.
 *
 *  @see   hendelseLesFraFil(...)
 */
void lesFraFil() {
  FILE* innfil  = fopen("EX_H22_HENDELSER.DTA", "r"); //  Åpner aktuell fil:

  if (innfil) {                                //  Filen finnes:
     fscanf(innfil, "%i", &gAntallHendelser);  //  Leser antall hendelser.
     getc(innfil);                          //  Leser avsluttende '\n'.
                                            //  Alle hendelser lages og leses:
     for (int i = 0;  i < gAntallHendelser;  i++) {
       gHendelser[i] = (struct Hendelse*) malloc(sizeof(struct Hendelse));
       hendelseLesFraFil(innfil, gHendelser[i]);     // Leser selv.
     }
     printf("\n\n\tHendelser er lest inn fra 'EX_H22_HENDELSER.DTA'!\n\n");
  } else                                       //  Filen ikke funnet:
     printf("\n\tFant ikke filen 'EX_H22_HENDELSER.DTA'!\n\n");

  fclose(innfil);                              //  Lukker åpen fil.
}


/**
 *  Oppgave 2G - Leser ALT om EN hendelse inn fra fil.
 *
 *  @param  inn       -  Filen det skal leses fra
 *  @param  hendelse  -  Hendelsen som får innlest sine data
 */
void hendelseLesFraFil(FILE* inn, struct Hendelse* hendelse) {
    char buffer[STRLEN];                //  Buffer for innlest tekst.
    char tegn;

    fscanf(inn, "%c %i %i", &tegn, &hendelse->dato, &hendelse->klokken);
    getc(inn);                          //  Forkaster ' ' (blank).
    hendelse->type = typeFraChar(tegn);
                                        //  Leser 'navn':
    fgets(buffer, STRLEN, inn);    buffer[strlen(buffer)-1] = '\0';
    hendelse->navn = (char*) malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(hendelse->navn, buffer);
                                        //  Leser 'sted':
    fgets(buffer, STRLEN, inn);    buffer[strlen(buffer)-1] = '\0';
    hendelse->sted = (char*) malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(hendelse->sted, buffer);

    fscanf(inn, "%s", buffer);          //  Leser 'webside':
    hendelse->webside = (char*) malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(hendelse->webside, buffer);
    getc(inn);                          //  Forkaster avsluttende '\n'.
}
