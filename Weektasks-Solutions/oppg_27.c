/**
 *   Løsningsforslag til oppgave nr 27.
 *
 *   @file	  OPPG_27.C
 *   @author  Frode Haug, NTNU
 */


#include <stdio.h>                 //  printf, scanf

#define   STRLEN        80         ///<  Max. tekstlengde.
const int MAXPERSONER = 10;        ///<  Max.antall personer.

/**
 *  Person (med navn, alder og vekt).
 */
struct Person  {
  char  navn[STRLEN];
  int   alder;
  float vekt;
};


float lesTall(const char tekst[], const int min, const int max);
void  lesTekst(const char ledetekst[], char tekst[]);


/**
 *  Hovedprogrammet:
 */
int main()  {
    struct Person personer[MAXPERSONER];  //  Datastrukturen med Person(er).
    int   i,                              //  Løkkevariabel.
          antPers,                        //  Antall personer innlest/brukt.
          totalAlder = 0,                 //  Totalsummen av ALLE alles alder.
          indeksEldst;                    //  Indeks for den med høyest alder.
    float totalVekt = 0.0;                //  Totalsummen av ALLE alles vekt.
                                          //  Finner antallet som skal leses:
    antPers = (int) lesTall("Antall personer å lese inn data om", 1, MAXPERSONER);

    for (i = 0;  i < antPers;  i++)  {    //  Leser ALLE data om personene:
        printf("\nData om person nr.%2i:\n", i+1);
        lesTekst("Navn ", personer[i].navn);                  //  Navn.
        personer[i].alder = (int) lesTall("Alder", 0, 120);   //  Alder.
        personer[i].vekt  = lesTall("Vekt ", 30, 250);        //  Vekt.
        totalAlder += personer[i].alder;  //  Summerer opp ALLES alder.
        totalVekt  += personer[i].vekt;   //  Summerer opp ALLES vekt.
    }

    indeksEldst = 0;                 //  Initierer til at person nr.0 er eldst.
    for (i = 1;  i < antPers;  i++)  //  Går gjennom de andre personene, og
        if (personer[i].alder >  personer[indeksEldst].alder) // finner ut om
           indeksEldst = i;                                   // noen er eldre.

                                     //  Skriver ut fundne/utregnede data:
    printf("\n\nTOTAL alder på ALLE personene:           %i\n", totalAlder);
    printf("GJENNOMSNITTLIG vekt på ALLE personene:  %.1f\n", totalVekt/antPers);
    printf("Eldste person er nr.%i (%s) med %i år.\n\n", indeksEldst+1,
           personer[indeksEldst].navn, personer[indeksEldst].alder);

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
