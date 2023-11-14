/**
 *   Programeksempel nr 27 - Større programeksempel.
 *
 *   som vektlegger:
 *     - struct
 *     - array av structer
 *     - funksjoner
 *     - enum
 *
 *   Programmet:
 *     - inneholder et varelager (datastrukturen)
 *     - lager/skriver oversikt over HELE varelageret
 *     - registrerer en ny vare i varelageret
 *     - mottar flere av en allerede eksisterende vare
 *     - selger noen av en eksisterende vare
 *     - fjerner/sletter HELT en vare fra varelageret
 *
 *   @file     EKS_27.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>              //  printf, scanf
#include <ctype.h>              //  toupper


#define   MAXVARER      100     ///<  Max. antall varer i datastrukturen.
#define   STRLEN         80     ///<  Max. tekstlengde.
const int MAXANTALL = 10000;    ///<  Max. antall av EN vare.
const int MAXPRIS   = 50000;    ///<  Max. pris på/for EN vare.


/**
 *  Endring i antallet av en vare -  motta eller selge.
 */
enum Endring  { Motta, Selge};


/**
 *  Vare (med navn, antall av den og pris pr.stk).
 */
struct Vare  {
    char  navn[STRLEN];
    int   antall;
    float pris;
};


void  endreAntallet(const enum Endring ms);
void  fjernVare();
char  lesKommando();
float lesTall(const char tekst[], const int min, const int max);
void  lesTekst(const char ledetekst[], char tekst[]);
void  nyVare();
void  oversikt();
void  skrivMeny();


struct Vare gVarer[MAXVARER];    ///<  Array med Vare-structer.
int    gAntallVarer = 0;         ///<  Antall varer i datastrukturen.


/**
 *  Hovedprogrammet:
 */
int main ()  {
    char kommando;

    skrivMeny();
    kommando = lesKommando();

    while (kommando != 'Q')  {
        switch (kommando)  {
          case 'O':  oversikt();  break;    //  Oversikt over varelager.
          case 'N':  nyVare();    break;    //  Registrer ny vare.
          case 'M':  endreAntallet(Motta);  break;  // Motta 'x' stk. av vare.
          case 'S':  endreAntallet(Selge);  break;  // Selg 'x' stk. av vare.
          case 'F':  fjernVare(); break;    //  Fjern en vare fra lager.
          default:   skrivMeny(); break;    //  Ikke-eksisterende menyvalg.
        }
        kommando = lesKommando();
    }

    printf("\n\n");
    return 0;
}


/**
 *  Endre (øke/redusere) totalantallet av en vare.
 *
 *  @param   ms  - 'Motta' (øke antallet) eller 'Selge' (redusere antallet)
 */
void endreAntallet(const enum Endring ms)  {
   int endreNr,                            //  Nummeret å endre antallet for.
       endreAntall;                        //  Antallet å øke/minske med.

   if (gAntallVarer > 0)  {                //  Noen vare(r) er registrert:
      printf("\n\nENDRE ANTALLET AV EN VARE .....\n"); //Leser nummer å endre:
      endreNr = (int) lesTall("Varenummer", 1, gAntallVarer);
                                           //  Nåværende lagerbeholdning:
      printf("\n\tAntall av varen på lager:  %i\n", gVarer[endreNr-1].antall);

      if (ms == Motta)  {                  // Mottatt flere:
                                           //  Leser antallet mottatt:
         endreAntall = (int) lesTall("Mottatt antall", 0, MAXANTALL);
         gVarer[endreNr-1].antall += endreAntall;  //  Øker antallet.
      } else  {                            // Selger:
         endreAntall = (int) lesTall("Selge antall", 0, 
                                                    gVarer[endreNr-1].antall);
         gVarer[endreNr-1].antall -= endreAntall;  //  Reduserer antallet.
       }                                   //  Skriver status for nytt antall:
      printf("\n\tVaren har %s antallet med %i til %i stk.\n",
             (ms == Selge) ? "redusert" : "økt",
             endreAntall, gVarer[endreNr-1].antall);
   } else
      printf("\n\tVarelageret er TOMT - umulig å endre ant. av en vare.\n");
}



/**
 *  Fjerner (om mulig) en vare fra lageret.
 */
void fjernVare()  {
   int fjerneNr;                              //  Nummeret som skal fjernes.

   if (gAntallVarer > 0)  {                   //  Noen vare(r) er registrert:
      printf("\n\nFJERN EN VARE .....\n");    //  Leser ønsket nr. å fjerne:
      fjerneNr = (int) lesTall("Varenummer", 0, gAntallVarer);

      if (fjerneNr != 0)  {                   //  Relevant varenummer:
                              //  Kopierer siste vare inn der slettet vare lå:
         gVarer[fjerneNr-1] = gVarer[gAntallVarer-1];
         gAntallVarer--;                      //  "Fjerner" siste vare.
         printf("\n\tVare nr.%i er nå fjernet.\n", fjerneNr);
      } else
         printf("\n\tOK, du angrer - ingen vare er fjernet.\n");
  } else
     printf("\n\tVarelageret er TOMT, derfor umulig å fjerne noen vare.\n");
}


/**
 *  Leser og returnerer ett (upcaset) tegn.
 *
 *  @return  Ett (upcaset) tegn.
 */
 char lesKommando()  {
     char tegn;
     printf("\nSkriv kommando:  ");
     scanf(" %c", &tegn);   getchar();
     return (toupper(tegn));
}


/**
 *  Leser og returnerer et tall mellom to gitte grenser.
 *
 *  @param   tekst  - Ledetekst til brukeren når ber om input/et tall
 *  @param   min    - Minimum for innlest og godtatt tallverdi
 *  @param   max    - Maksimum for innlest og godtatt tallverdi
 *
 *  @return  Godtatt verdi i intervallet 'min - 'max'
 */
float lesTall(const char tekst[], const int min, const int max)  {
   float tall;
   do  {
     printf("\t%s (%i-%i):  ", tekst, min, max);
     scanf("%f", &tall);     getchar();
   } while (tall < min  ||  tall > max);
   return tall;
}


/**
 *  Leser tekst inn i medsendt char-array/tekst/string.
 *
 *  @param   ledetekst  - Ledetekst som utskrift til brukeren om hva lese inn
 *  @param   tekst      - char-array som fylles med innlest tekst
 */
void lesTekst(const char ledetekst[], char tekst[])  {
  printf("\t%s:  ", ledetekst);
  gets(tekst);                    //  Oppdaterer ORIGINALEN/aktuell parameter.
}


/**
 *  Leser og legger (om plass/mulig) en ny vare inn i varelageret.
 */
void nyVare()  {
  if (gAntallVarer < MAXVARER)  {    //  Fortsatt plass/mulig:
     printf("\n\nREGISTRERER NY VARE NR.%i: .....\n", gAntallVarer+1);
     lesTekst("Navn", gVarer[gAntallVarer].navn);
     gVarer[gAntallVarer].antall = (int) lesTall("Antall", 5, MAXANTALL);
     gVarer[gAntallVarer].pris   = lesTall("Pris", 1, MAXPRIS);
     gAntallVarer++;                 //  Teller opp antall varer.
     printf("\n\tAlt om den nye varen er nå ferdig registrert.\n");
  } else                            //  IKKE plass/mulig lengre:
     printf("\n\tVarelageret er FULLT med %i varer allerede.\n", MAXVARER);
}


/**
 *  Viser/skriver ut på skjermen ALLE data om HELE varelageret.
 */
void oversikt()  {
  float totalVerdi = 0.0;            //  Nullstiller (viktig).

  if (gAntallVarer > 0)  {           //  Vare(r) er registrert:
     printf("\n\tVARELAGERET INNEHOLDER FØLGENDE VARER:\n");
     printf("\n\t Nr  Antall      Pris  Navn\n");

     for (int i = 0;  i < gAntallVarer;  i++)  {  //  Går gjennom alle varene:
          printf("\t%3i%8i%10.2f  %s\n", i+1, // Skriver ALLE data om EN vare:
                 gVarer[i].antall, gVarer[i].pris, gVarer[i].navn);
                                            //  Legger til DENNE varens verdi:
          totalVerdi += gVarer[i].antall * gVarer[i].pris;

          if (((i+1) % 20) == 0)  {         //  Stanser for hver 20. vare:
             printf("\t\t\t\t\t\tSkriv kun ENTER/CR .....\n");   getchar();
          }
     }
     printf("\n\tTotalverdi for varelageret:  %.2f\n", totalVerdi);
  } else
     printf("\n\tVarelageret er TOMT, derfor umulig å lage en oversikt.\n");
}


/**
 *  Skriver programmets menyvalg/muligheter på skjermen.
 */
void skrivMeny()  {
   printf("\nFølgende kommandoer er tilgjengelig:\n");
   printf("\tO = Oversikt over varelageret\n");
   printf("\tN = registrer Ny vare\n");
   printf("\tM = Mottatt/fått 'x' stk. av en vare\n");
   printf("\tS = Selg 'x' stk. av en vare\n");
   printf("\tF = Fjern en vare\n");
   printf("\tQ - Quit / avslutt\n");
}
