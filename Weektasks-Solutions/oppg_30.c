/**
 *   L�sningsforslag til oppgave nr 30.
 *
 *   Oppgaven er basert p� oppg.nr.3 fra eksamen 14.desember 1999
 *   i L182A - Grunnleggende datakunnskap og programmering.
 *
 *   @file	  OPPG_30.C
 *   @author  Frode Haug, NTNU
 */


#include <stdio.h>                 //  printf, scanf
#include <ctype.h>                 //  toupper
#include <stdbool.h>               //  bool
#include <string.h>                //  strcmp


#define   MAXTRALLER    30         ///< Max. antall traller til utl�n.
#define   STRLEN        80         ///< Max. tekstlengde.


/**
 *  Tralle (med status om utl�nt eller ei, og evt. l�ners navn og tlfnr).
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
int    gAntallUtlaant = 0;           ///<  Antall traller som pt. er utl�nt.

/**
 *  Hovedprogrammet:
 */
int main()  {
    char kommando;
                                   //  Initierer alle trallene til ikke-utl�nt:
    for (int i = 0;  i < MAXTRALLER;  i++)  gTraller[i].utlaant = false;

    skrivMeny();
    kommando = lesKommando();

    while (kommando != 'Q')  {
        switch (kommando)  {
          case 'O':  oversikt();    break;  //  Oversikt over ALLE trallene.
          case 'L':  ledige();      break;  //  Oversikt over KUN LEDIGE traller.
          case 'U':  utlaan();      break;  //  Utl�n/leie av en tralle.
          case 'I':  innlevering(); break;  //  Innlevering av en tralle.
          case 'F':  finnLaaner();  break;  //  Finn tralle(r) l�nt av pwerson.
          default:   skrivMeny();   break;  //  Ikke-eksisterende menyvalg.
        }
        kommando = lesKommando();
    }

    printf("\n\n");
    return 0;
}


/**
 *  Finner (om mulig) trallen(e) en navngitt person har l�nt/leid.
 */
void finnLaaner()  {
  bool funn = false;                      //  Initier med at ingen funnet.
  char navn[STRLEN];                      //  Potensiell trallel�ners navn.

  lesTekst("Trallel�ners navn", navn);    //  Leser aktuell l�ners navn.

  printf("\n\tHar l�nt trallen(e):");

  for (int i = 0;  i < MAXTRALLER;  i++)   //  G�r gjennom ALLE trallene:
      if (!strcmp(gTraller[i].navn, navn))  {   //  Match p� navn!:
          printf("%5i", i+1);              //  Skriver trallens nummer.
          funn = true;                     //  Markerer at minst ett funn.
      }
  if (!funn)  printf("  INGEN");           //  Ingren funnet/match.
  printf("\n");
}


/**
 *  Inn-/tilbakeleverer en (ut)l�nt tralle.
 */
void innlevering()  {
  int nr;                                 //  Trallenummer.

  if (gAntallUtlaant > 0)  {              //  Minst EN tralle er utl�nt:
                                          //  Leser innlevert trallenummer:
      nr = lesTall("Innlevere trallenummer", 1, MAXTRALLER);

     if (gTraller[nr-1].utlaant)  {       //  Trallen er utl�nt:
        gTraller[nr-1].utlaant = false;   //  Setter at den n� er ledig.
        gAntallUtlaant--;                 //  Teller ned totalt antall utl�nt.
                                          //  Skriver tilbakeleverers navn:
        printf("\n\t%s har levert tralla si.\n", gTraller[nr-1].navn);
     } else                               //  Trallen er IKKE utl�nt.
       printf("\n\tDenne trallen er IKKE utl�nt!\n");
  } else                                  //  Ingen tralle er utl�nt:
     printf("\n\tUmulig � innlevere, da ingen utl�nt!\n");
}


/**
 *  Skriver evt. ut nummeret p� alle ledige traller.
 */
void ledige()  {
  if (gAntallUtlaant < MAXTRALLER)  {         //  Traller er l�nt ut:
     printf("\n\tF�LGENDE TRALLER ER LEDIGE:\n\t");

     for (int i = 0;  i <  MAXTRALLER;  i++)  //  G�r gjennom alle trallene:
         if (!gTraller[i].utlaant)            //  Om IKKE utl�nt:
            printf("  %i", i+1);              //    Skriver trallens nummer.
     printf("\n");
  } else
     printf("\n\tINGEN traller er for �yeblikket ledige!\n");
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
 *  @param   tekst  - Ledetekst til brukeren n�r ber om input/et tall
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
 *  Oversikt over status for alle utl�nte traller.
 */
void oversikt()  {
  if (gAntallUtlaant > 0)  {                  //  Traller er l�nt ut:
     printf("\n\tDATA OM UTL�NTE TRALLER:\n");

     for (int i = 0;  i <  MAXTRALLER;  i++)  //  G�r gjennom alle trallene:
         if (gTraller[i].utlaant)             //  Om utl�nt:  skriver ALT:
            printf("\t%3i:  %s,  %i\n", i+1, gTraller[i].navn, gTraller[i].tlfNr);
  } else
     printf("\n\tINGEN traller er for �yeblikket utl�nt!\n");
}


/**
 *  Skriver programmets menyvalg/muligheter p� skjermen.
 */
void skrivMeny()  {
   printf("\nF�lgende kommandoer er tilgjengelig:\n");
   printf("\tO = Oversikt over ALLE trallene\n");
   printf("\tL = oversikt over kun Ledige traller\n");
   printf("\tU - Utl�n av tralle\n");
   printf("\tI - Innlevering av tralle\n");
   printf("\tF - Finn trallene(e) l�nt av en gitt person\n");
   printf("\tQ - Quit / avslutt\n");
}


/**
 *  L�ner ut (om mulig) en ledig nummeritt tralle.
 */
void utlaan()  {
  int nr;                               //  Trallenummer.

  if (gAntallUtlaant < MAXTRALLER)  {   //  Flere traller er til l�ns:
                                        //  Leser �nsket trallenummer:
     nr = lesTall("L�ne trallenummer", 1, MAXTRALLER);

     if (!gTraller[nr-1].utlaant)  {    //  Trallen er ledig:
        gTraller[nr-1].utlaant = true;  //  Setter at aktuelt nummer er utl�nt.
        lesTekst("L�ners navn", gTraller[nr-1].navn);  //  Leser l�ners data:
        gTraller[nr-1].tlfNr = lesTall("Telefonnummer", 10000000, 99999999);
        gAntallUtlaant++;               //  Teller opp totalt antall utl�nt.
     } else                             //  �nsket tralle er allerede utl�nt:
       printf("\n\tDette trallenummeret er allerede utl�nt!\n");
  } else                               //  Alle trallene er l�nt ut:
     printf("\n\tUmulig � l�ne flere, da ALLE trallene er utl�nt!\n");
}
