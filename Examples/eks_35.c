/**
 *   Programeksempel nr 35 - Større programeksempel.
 *
 *   Eksemplet vektlegger mye av pensumet hittil.
 *   Det er basert på oppg.nr.2 fra eksamen 18.august 2017
 *   i IMT1031 - Grunnleggende programmering.
 *
 *   Programmet holder orden på ulike malerier fra EN gitt kunstner,
 *   og hvilke byer og steder (i disse byene) maleriene er å finne.
 *
 *   Programmet:
 *     - Registerer/legger inn et nytt maleri i arkivet/oversikten
 *     - Skriver noe om ALLE maleriene eller ALT om ETT maleri
 *     - Skriver ALLE malerier med et visst minstemål for bredde ELLER høyde
 *     - Skriver ALLE malerier i en gitt by eller på et gitt sted
 *
 *   @file     EKS_35.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>               //  printf
#include <stdbool.h>             //  bool
#include <stdlib.h>              //  sizeof, malloc, free
#include <string.h>              //  strcmp, strstr
#include "LesData.h"             //  Verktøykasse for lesing av diverse data


#define   MAXMALERIER   100       ///<  Max. antall malerier fra kunstneren.
const int STRLEN    =    80;      ///<  Max. tekstlengde.
const int MINMAAL   =    30;      ///<  Minimummål på et maleri.
const int MAXMAAL   =  1000;      ///<  Maksimummål på et maleri.


/**
 *  Lokasjon (som er By eller Sted).
 */
enum Lokasjon  { By, Sted };


/**
 *  Maleri (med tittel, by, sted, år, bredde og høyde).
 */
struct Maleri {
    char *tittel,
         *by,
         *sted;
    int  aar,
         bredde,
         hoyde;
};


void frigiAllokertMemory();
void maleriFrigiMemory(struct Maleri* maleri);
bool maleriMatch(const struct Maleri* maleri, const char* navn,
                 const enum Lokasjon lok);
bool maleriMinst(const struct Maleri* maleri, const int min);
void maleriLesData(struct Maleri* maleri);
void maleriSkrivAlt(const struct Maleri* maleri);
void maleriSkrivNoe(const struct Maleri* maleri);
void nyttMaleri();
void skrivAlleMalerier();
void skrivAltOmEttMaleri();
void skrivMalerierMedMinstemal();
void skrivMalerierPaaLokasjon();
void skrivMeny();


struct Maleri* gMalerier[MAXMALERIER];  ///<  Maleriene i oversikten.
int    gAntallMaleri = 0;               ///<  Antall indekser/"skuffer" brukt.


/**
 *  Hovedprogrammet:
 */
int main ()  {
    char kommando;

//  lesFraFil();

    skrivMeny();
    kommando = lesChar("\nKommando");

    while (kommando != 'Q')  {
        switch (kommando)  {
          case 'N': nyttMaleri();                 break;
          case 'A': skrivAlleMalerier();          break;
          case 'E': skrivAltOmEttMaleri();        break;
          case 'M': skrivMalerierMedMinstemal();  break;
          case 'L': skrivMalerierPaaLokasjon();   break;
          default:  skrivMeny();                  break;
        }
        kommando = lesChar("\nKommando");
    }

//  skrivTilFil();

    frigiAllokertMemory();

    return 0;
}


/**
 *  Frigir ALL allokert memory under run-time.
 *
 *  @see  maleriFrigiMemory(...)
 */
void frigiAllokertMemory()  {
   printf("\n\n\tFrigir ALL allokert/avsatt memory ......\n\n");
   for (int i = 0;  i < gAntallMaleri;  i++) { //  Går gjennom ALLE maleriene:
       maleriFrigiMemory(gMalerier[i]);        //  Hvert maleri frigir selv
                                               //    sine allokerte data.
       free(gMalerier[i]);                     //  Selve structen frigis.
   }
}


/**
 *  Sletter ALLE allokerte data inni EN maleri-struct.
 *
 *  @param   maleri  - Structen som får alle sine allokerte data frigitt
 */
void maleriFrigiMemory(struct Maleri* maleri)  {
  free(maleri->tittel);
  free(maleri->by);
  free(maleri->sted);
}


/**
 *  Returnerer true/false til om maleriet er
 *  i en gitt by ELLER på et gitt sted.
 *
 *  @param   maleri  - Structen som skal sjekkes for by- eller stedsnavn
 *  @param   navn    - Teksten å sammenligne HELE bynavnet ELLER DELER AV
 *                     stedsnavnet med
 *  @param   lok     - Enum'en By eller Sted
 *
 *  @return  Returnerer om 'navn' er HELE bynavnet eller EN DEL AV stedsnavnet
 */
bool maleriMatch(const struct Maleri* maleri, const char* navn,
                 const enum Lokasjon lok)  {
  return ((lok == By    &&  !strcmp(maleri->by,  navn)) ||  //  HELE bynavnet.
          (lok == Sted  &&  strstr(maleri->sted, navn)));   //  DEL AV
}                                                           //    stedsnavnet.


/**
 *  Returnerer true/false til om maleriet har et visst minstemål
 *  for bredde ELLER høyde.
 *
 *  @param   maleri  - Structen som skal sjekkes for minstemål
 *  @param   min     - Ønsket minstemål for bredde eller høyde
 *
 *  @return  Om bredde ELLER høyde har et visst minstemål ('min')
 */
bool maleriMinst(const struct Maleri* maleri, const int min)  {
   return (maleri->bredde >= min  ||  maleri->hoyde >= min);
}                                                     // MINST en er >= 'min'.


/**
 *  Leser inn ALLE dataene til en struct.
 *
 *  @param   maleri  - Structen som får innlest sine data
 */
void maleriLesData(struct Maleri* maleri)  {
  maleri->tittel = lagOgLesText("\tTittel");         //  Bruker les-funksjoner
  maleri->by     = lagOgLesText("\tBy    ");         //    fra verktøykassa:
  maleri->sted   = lagOgLesText("\tSted  ");
  maleri->aar    = lesInt("\tÅr    ", 1500, 2100);
  maleri->bredde = lesInt("\tBredde", MINMAAL, MAXMAAL);
  maleri->hoyde  = lesInt("\tHøyde ", MINMAAL, MAXMAAL);
}


/**
 *  Skriver ut på skjermen ALT om en struct.
 *
 *  @param   maleri  - Structen som får skrevet ut ALLE sine data
 */
void maleriSkrivAlt(const struct Maleri* maleri)  {
  printf("\n\t\"%s\", %i  %ix%i cm\n\t\t%s:  %s\n",  //  På et passende format
         maleri->tittel, maleri->aar, maleri->bredde, //   og utseende:
         maleri->hoyde,  maleri->by,  maleri->sted);
}


/**
 *  Skriver ut på skjermen LITT av datene i en struct.
 *
 *  @param   maleri  - Structen som får skrevet ut DELER AV sine data
 */
void maleriSkrivNoe(const struct Maleri* maleri)  {
  printf("\"%s\" i %s\n", maleri->tittel, maleri->by);
}


/**
 *  Legger inn (om mulig) et nytt maleri.
 *
 *  @see maleriLesData(...)
 */
void nyttMaleri()  {
  if (gAntallMaleri < MAXMALERIER) {             //  Plass til flere malerier:
     printf("\tNytt maleris nr:  %i\n", gAntallMaleri+1); // Lager nytt maleri:
     gMalerier[gAntallMaleri] = (struct Maleri*) malloc(sizeof(struct Maleri));
     maleriLesData(gMalerier[gAntallMaleri]);    //  Maleriets data leses.
     gAntallMaleri++;                            //  Opptelling av #malerier.
  } else                                         //  Fullt med malerier:
     printf("\n\tFullt med %i malerier allerede!\n\n", MAXMALERIER);
}


/**
 *  Skriver ALLE malerienes HOVEDdata.
 *
 *  @see maleriSkrivNoe(...)
 */
void skrivAlleMalerier()  {
  printf("\nHOVEDdata om ALLE maleriene:\n\n");
  for (int i = 0;  i < gAntallMaleri;  i++) { //  For hvert maleri:
      printf("\t%3i:  ", i+1);                //  Skriver maleriets indeks.
      maleriSkrivNoe(gMalerier[i]);           //  Maleriets HOVEDdata skrives.
    }
}


/**
 *  Skriver ALT om ETT nummerangitt maleri.
 *
 *  @see maleriSkrivAlt(...)
 */
void skrivAltOmEttMaleri()  {
  int nr;                                    //  Ønsket malerinummer å se.

  if (gAntallMaleri > 0)  {                  //  Malerier finnes:
                                             //  Leser ønsket nr å se:
     nr = lesInt("\tSe ALT om maleri nr", 1, gAntallMaleri);
     maleriSkrivAlt(gMalerier[nr-1]);        //  Maleriets ALLE data skrives.
  } else                                     //  Malerier finnes IKKE:
     printf("\n\tIngen malerier registrert/lagt inn ennå!\n\n");
}


/**
 *  Skriver ALLE malerier med et visst minstemål for bredde eller høyde:
 *
 *  @see maleriMinst(...)
 *  @see maleriSkrivAlt(...)
 */
void skrivMalerierMedMinstemal()  {
  int antall = 0,                 //  Antall malerier funnet.
      minstemaal;                 //  Ønsket minstemål for bredde ELLER høyde.

  if (gAntallMaleri > 0)  {                    //  Malerier finnes:
    minstemaal = lesInt("Minstemål for bredde ELLER høyde", MINMAAL, MAXMAAL);

     for (int i = 0;  i < gAntallMaleri;  i++)  //  For hvert maleri:
        if (maleriMinst(gMalerier[i], minstemaal)) {  //  Har minstemålet:
            maleriSkrivAlt(gMalerier[i]);       //  ALT om maleriet skrives.
            ++antall;                           //  Teller opp totalantallet.
        }                                       //  Skriver dette antallet:
     printf("\n\tAntall malerier med dette minstemålet:  %i\n", antall);
  } else                                        //  Malerier finnes IKKE:
     printf("\n\tIngen malerier registrert/lagt inn ennå!\n\n");
}


/**
 *  Skriver ALT om ALLE malerier i en gitt by eller på et gitt sted.
 *
 *  @see maleriMatch(...)
 *  @see maleriSkrivAlt(...)
 */
void skrivMalerierPaaLokasjon()  {
  char lokasjonNavn[STRLEN];           //  By- eller stedsnavn.
  char type;                           //  'B' eller 'S'.
  enum Lokasjon lokasjon;              //  By eller Sted
  bool funn = false;                   //  Foreløpig ikke funnet/ingen match.


  if (gAntallMaleri > 0)  {            //  Malerier finnes:
    do {                               //  Leser og SIKRER at 'B' eller 'S':
       type = lesChar("\tB(y) eller S(ted)");
    } while (type != 'B'  &&  type != 'S');
                                           //  Gir enum-variabel verdi ut
    lokasjon = (type == 'B') ? By : Sted;  //   fra inputen av 'type':
                                           //  Leser lokasjonsnavn:
    lesText("\tLokasjon (by- eller stedsnavn)", lokasjonNavn, STRLEN);

    for (int i = 0;  i < gAntallMaleri;  i++)     //  For hvert maleri:
                                                  //  Finnes i by/på sted.
        if (maleriMatch(gMalerier[i], lokasjonNavn, lokasjon)) {
           funn = true;                           //  Minst en match.
           maleriSkrivAlt(gMalerier[i]);          //  Skriver ALT om maleriet.
        }

    if (!funn)                          //  Finnes ikke i noen by/på noe sted:
       printf("\n\tIngen malerier funnet %s!\n",
              (lokasjon == By ? "i denne by" : "på dette sted"));
  } else                                //  Malerier finnes IKKE:
     printf("\n\tIngen malerier registrert/lagt inn ennå!\n\n");
}


/**
 *  Skriver programmets menyvalg/muligheter på skjermen.
 */
void skrivMeny()  {
  printf("\nFølgende kommandoer er tilgjengelig:\n");
  printf("\tN = Nytt maleri\n");
  printf("\tA = skriv HOVEDdata om Alle maleriene\n");
  printf("\tE = skriv ALT om Ett maleri\n");
  printf("\tM = skriv ALLE malerier med et Minstemål (bredde eller høyde)\n");
  printf("\tL = skriv ALLE malerier på en gitt Lokasjon (by eller sted)\n");
  printf("\tQ - Quit / avslutt\n");
}
