/**
 *   Løsningsforslag til oppgave nr 30.
 *
 *   Oppgaven er basert på oppg.nr.3 fra eksamen 14.desember 1999
 *   i L182A - Grunnleggende datakunnskap og programmering.
 *
 *   @file	  OPPG_30.C
 *   @author  Frode Haug, NTNU
 */


#include <stdio.h>                 //  printf, scanf
#include <ctype.h>                 //  toupper
#include <stdbool.h>               //  bool
#include <string.h>                //  strcmp


#define   MAXTRALLER    30         ///< Max. antall traller til utlån.
#define   STRLEN        80         ///< Max. tekstlengde.


/**
 *  Tralle (med status om utlånt eller ei, og evt. låners navn og tlfnr).
 */
struct Tralle  {
  bool utlaant;
  char navn[STRLEN];
  int  tlfNr;
};


void finnLaaner();
void innlevering();
void ledige();
char lesKommando();
int  lesTall(const char tekst[], const int min, const int max);
void lesTekst(const char ledetekst[], char tekst[]);
void oversikt();
void skrivMeny();
void utlaan();


struct Tralle gTraller[MAXTRALLER];  ///<  Array av Tralle-struct'er.
int    gAntallUtlaant = 0;           ///<  Antall traller som pt. er utlånt.

/**
 *  Hovedprogrammet:
 */
int main()  {
    char kommando;
                                   //  Initierer alle trallene til ikke-utlånt:
    for (int i = 0;  i < MAXTRALLER;  i++)  gTraller[i].utlaant = false;

    skrivMeny();
    kommando = lesKommando();

    while (kommando != 'Q')  {
        switch (kommando)  {
          case 'O':  oversikt();    break;  //  Oversikt over ALLE trallene.
          case 'L':  ledige();      break;  //  Oversikt over KUN LEDIGE traller.
          case 'U':  utlaan();      break;  //  Utlån/leie av en tralle.
          case 'I':  innlevering(); break;  //  Innlevering av en tralle.
          case 'F':  finnLaaner();  break;  //  Finn tralle(r) lånt av pwerson.
          default:   skrivMeny();   break;  //  Ikke-eksisterende menyvalg.
        }
        kommando = lesKommando();
    }

    printf("\n\n");
    return 0;
}


/**
 *  Finner (om mulig) trallen(e) en navngitt person har lånt/leid.
 */
void finnLaaner()  {
  bool funn = false;                      //  Initier med at ingen funnet.
  char navn[STRLEN];                      //  Potensiell trallelåners navn.

  lesTekst("Trallelåners navn", navn);    //  Leser aktuell låners navn.

  printf("\n\tHar lånt trallen(e):");

  for (int i = 0;  i < MAXTRALLER;  i++)   //  Går gjennom ALLE trallene:
      if (!strcmp(gTraller[i].navn, navn))  {   //  Match på navn!:
          printf("%5i", i+1);              //  Skriver trallens nummer.
          funn = true;                     //  Markerer at minst ett funn.
      }
  if (!funn)  printf("  INGEN");           //  Ingren funnet/match.
  printf("\n");
}


/**
 *  Inn-/tilbakeleverer en (ut)lånt tralle.
 */
void innlevering()  {
  int nr;                                 //  Trallenummer.

  if (gAntallUtlaant > 0)  {              //  Minst EN tralle er utlånt:
                                          //  Leser innlevert trallenummer:
      nr = lesTall("Innlevere trallenummer", 1, MAXTRALLER);

     if (gTraller[nr-1].utlaant)  {       //  Trallen er utlånt:
        gTraller[nr-1].utlaant = false;   //  Setter at den nå er ledig.
        gAntallUtlaant--;                 //  Teller ned totalt antall utlånt.
                                          //  Skriver tilbakeleverers navn:
        printf("\n\t%s har levert tralla si.\n", gTraller[nr-1].navn);
     } else                               //  Trallen er IKKE utlånt.
       printf("\n\tDenne trallen er IKKE utlånt!\n");
  } else                                  //  Ingen tralle er utlånt:
     printf("\n\tUmulig å innlevere, da ingen utlånt!\n");
}


/**
 *  Skriver evt. ut nummeret på alle ledige traller.
 */
void ledige()  {
  if (gAntallUtlaant < MAXTRALLER)  {         //  Traller er lånt ut:
     printf("\n\tFØLGENDE TRALLER ER LEDIGE:\n\t");

     for (int i = 0;  i <  MAXTRALLER;  i++)  //  Går gjennom alle trallene:
         if (!gTraller[i].utlaant)            //  Om IKKE utlånt:
            printf("  %i", i+1);              //    Skriver trallens nummer.
     printf("\n");
  } else
     printf("\n\tINGEN traller er for øyeblikket ledige!\n");
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
int lesTall(const char tekst[], const int min, const int max)  {
   int tall;
   do  {
     printf("\t%s (%i-%i):  ", tekst, min, max);
     scanf("%i", &tall);     getchar();
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
  gets(tekst);                      //  Oppdaterer ORIGINALEN/aktuell parameter.
}


/**
 *  Oversikt over status for alle utlånte traller.
 */
void oversikt()  {
  if (gAntallUtlaant > 0)  {                  //  Traller er lånt ut:
     printf("\n\tDATA OM UTLÅNTE TRALLER:\n");

     for (int i = 0;  i <  MAXTRALLER;  i++)  //  Går gjennom alle trallene:
         if (gTraller[i].utlaant)             //  Om utlånt:  skriver ALT:
            printf("\t%3i:  %s,  %i\n", i+1, gTraller[i].navn, gTraller[i].tlfNr);
  } else
     printf("\n\tINGEN traller er for øyeblikket utlånt!\n");
}


/**
 *  Skriver programmets menyvalg/muligheter på skjermen.
 */
void skrivMeny()  {
   printf("\nFølgende kommandoer er tilgjengelig:\n");
   printf("\tO = Oversikt over ALLE trallene\n");
   printf("\tL = oversikt over kun Ledige traller\n");
   printf("\tU - Utlån av tralle\n");
   printf("\tI - Innlevering av tralle\n");
   printf("\tF - Finn trallene(e) lånt av en gitt person\n");
   printf("\tQ - Quit / avslutt\n");
}


/**
 *  Låner ut (om mulig) en ledig nummeritt tralle.
 */
void utlaan()  {
  int nr;                               //  Trallenummer.

  if (gAntallUtlaant < MAXTRALLER)  {   //  Flere traller er til låns:
                                        //  Leser ønsket trallenummer:
     nr = lesTall("Låne trallenummer", 1, MAXTRALLER);

     if (!gTraller[nr-1].utlaant)  {    //  Trallen er ledig:
        gTraller[nr-1].utlaant = true;  //  Setter at aktuelt nummer er utlånt.
        lesTekst("Låners navn", gTraller[nr-1].navn);  //  Leser låners data:
        gTraller[nr-1].tlfNr = lesTall("Telefonnummer", 10000000, 99999999);
        gAntallUtlaant++;               //  Teller opp totalt antall utlånt.
     } else                             //  Ønsket tralle er allerede utlånt:
       printf("\n\tDette trallenummeret er allerede utlånt!\n");
  } else                               //  Alle trallene er lånt ut:
     printf("\n\tUmulig å låne flere, da ALLE trallene er utlånt!\n");
}
