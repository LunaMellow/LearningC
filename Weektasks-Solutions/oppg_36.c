/**
 *   Løsningsforslag til oppgave nr 36.
 *
 *   @file	  OPPG_36.C
 *   @author  Frode Haug, NTNU
 */


#include <stdio.h>              //  printf, scanf
#include <ctype.h>              //  toupper
#include <stdlib.h>             //  sizeof, malloc, free
#include <string.h>             //  strlen, strcpy

const int STRLEN   = 80;        ///<  Max. tekstlengde.

/**
 *  Person (med navn og alder).
 */
struct Person  {
    char* navn;
    int   alder;
    struct Person* neste;
};


int  lesTall(const char* tekst, const int min, const int max);
char lesTegn(const char* t);
void lesTekst(const char* ledetekst, char* tekst);
void personLesData(struct Person* p);
void personSkrivData(const struct Person* p);
void personSlettData(struct Person* p);


/**
 *  Hovedprogrammet:
 */
int main ()  {
    struct Person* personListe,            //  Peker til HELE listen.
                 * siste,           //  NYTT:  Peker til siste/bakerste.
                 * persPeker,              //  Peker til EN aktuell Person.
                 * slettes;                //  Peker til den som skal slettes.

//  NYTT KUN fra her og til slutten av do-while-løkka:

    personListe = siste = NULL;            //  Initierer til en tom liste.

    do  {                                  //  Oppretter en ny Person.
      persPeker = (struct Person*) malloc(sizeof(struct Person));

      personLesData(persPeker);            //  Leser personen sine data.

      if (personListe == NULL)             //  Lista er tom, derfor MÅ BEGGE
                                           //    pekerne oppdateres:
         personListe = siste = persPeker;

      else  {                              //  Inneholder MINST EN Person:

         siste->neste = persPeker;         //  HEKTER INN BAKERST !!! :

         siste = persPeker;
      }

    } while (lesTegn("En ny person til (j/N)") == 'J');  //  Opprette flere?



// ***************************************************************************

    printf("\n\nListens personer:\n");   //  Skriver HELE listens innhold:

    persPeker = personListe;             //  Initierer til listens begynnelse.

    while (persPeker != NULL)  {         //  Så lenge ikke nådd slutten:
        personSkrivData(persPeker);      //  Personen skrives
        persPeker = persPeker->neste;    //  Går videre til neste Person.
    }



// ***************************************************************************

    printf("\n\nSletter hele listen .....\n");

    persPeker = personListe;               //  Initierer (igjen) til listens begynnelse.
                                           //  Så lenge ikke nådd slutten:
    while (persPeker)  {                   //  NB:  Kortere form ift. den ovenfor.
        slettes = persPeker;               //  Hjelpepeker som 'står igjen',
        persPeker = persPeker->neste;      //    i det vi går videre til neste Person.
        personSlettData(slettes);          //  Allokerte data INNI den forrige slettes.
        free(slettes);                     //  Sletter selve structen.
    }


    printf("\n\n");

    return 0;
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
int lesTall(const char* tekst, const int min, const int max)  {
   int tall;
   do  {
     printf("\t%s (%i-%i):  ", tekst, min, max);
     scanf("%i", &tall);     getchar();
   } while (tall < min  ||  tall > max);
   return tall;
}


/**
 *  Leser og returnerer ett (upcaset) tegn.
 *
 *  @param   t  - Ledetekst til brukeren når ber om ett tegn
 *
 *  @return  Ett (upcaset) tegn.
 */
 char lesTegn(const char* t)  {
     char tegn;
     printf("%s:  ", t);
     scanf(" %c", &tegn);   getchar();
     return (toupper(tegn));
}


/**
 *  Leser tekst inn i tilpekt memoryområde med char'er.
 *
 *  @param   ledetekst  - peker til ledetekst om hva som skal leses inn
 *  @param   tekst      - peker til memoryområdet med char'er
 */
void lesTekst(const char* ledetekst, char* tekst)  {
  printf("\t%s:  ", ledetekst);
  gets(tekst);            //  Oppdaterer tilpekte char'er (derfor ORIGINALEN).
}


/**
 *  Leser inn ALLE data til en Person-struct - Allokerer memory.
 */
void personLesData(struct Person* p)  {
   char buffer[STRLEN];             //  Hjelpetekst til å lese navnet.

   lesTekst("Navn ", buffer);       //  Leser personens navn.
                                    //  Allokerer EKSAKT NOK plass til navnet:
   p->navn = (char*) malloc((strlen(buffer) + 1) * sizeof(char));
   strcpy(p->navn, buffer);         //  Kopierer inn navnet.

   p->alder = lesTall("Alder", 0, 120);   //  Leser 'alder'.

   p->neste = NULL;                 //  Setter at ikke har noen etterfølger.

}


/**
 *  Skriver ut ALLE parameterens data ut på skjermen.
 *
 *  @param   p  - Person-structen som skal skrives ut (ALLE data)
 */
void personSkrivData(const struct Person* p)  {
   printf("\tNavn:  %s,  %i år\n", p->navn, p->alder);
}


/**
 *  Sletter/frigir all allokert memory inni en struct.
 *
 *  @param   p  - Person-structen som får slettet all allokert memory
 */
void personSlettData(struct Person* p)  {
   free(p->navn);                           //  Frigir "all" allokert memory.
}
