/**
 *   Programeksempel nr 33 - Pekere - Liste (Last-In-First-Out (LIFO),
                                             stakk/stack).
 *
 *   @file     EKS_33.C
 *   @author   Frode Haug, NTNU
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
                 * persPeker;              //  Peker til EN aktuell Person.

    personListe = NULL;                    //  Initierer til en tom liste.

    do  {                                  //  Oppretter en ny Person.
      persPeker = (struct Person*) malloc(sizeof(struct Person));

      personLesData(persPeker);            //  Leser personen sine data.

      persPeker->neste = personListe;      //  HEKTER INN FORREST !!!!! :

      personListe = persPeker;

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

                                       //  Så lenge ennå ikke tom liste:
    while (personListe)  {             //  NB:  Kortere form ift. den ovenfor.
        persPeker = personListe;       //  Hjelpepeker som 'står igjen', i det
        personListe = personListe->neste;  //  vi går videre til neste Person.
        personSlettData(persPeker);    //  Allokerte data INNI den forrige
        free(persPeker);               //    slettes. Sletter selve structen.
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
