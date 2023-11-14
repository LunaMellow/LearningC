/**
 *   Programeksempel nr 24 - Større programeksempel.
 *
 *   som vektlegger funksjoner som:
 *     - har parametre
 *     - bruker return
 *     - returnerer flere steder
 *     - kaller andre funksjoner
 *     - har array lokalt definert
 *
 *   Programmet:
 *     - spør brukeren om og leser inn en dato:  dag maaned og aar
 *     - finner ut om det er en gyldig/lovlig dato
 *       (tatt i betraktning antall månedsdager og om det er skuddår eller ei)
 *     - skriver om så ut hvilket dagnummer i året dette er
 *       (f.eks. 06 03 1994 er dag nr. 65) ellers skrives 0 (null)
 *     - looper til brukeren skriver inn en ugyldig dato
 *
 *   @file     EKS_24.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>                //  printf, scanf
#include <stdbool.h>              //  bool

                                  //  FUNKSJONER I ALFABETISK REKKEFØLGE!
int  dagNummer(const int dag, const int maaned, const int aar);
int  lesTall(const char tekst[], const int min, const int max);
bool skuddaar(const int aar);

/**
 *  Hovedprogrammet:
 */
int main() {
    int dag,
        maaned,
        aar,
        dagNr;

    printf("\nSkriv inn datoer, og få vite hvilket dagnummer det er i året.");
    printf("\nAvslutt med en ulovlig dato, f.eks. 30.februar ");
    printf("et eller annet år.\n\n");

    do  {
        dag    = lesTall("Dag  ", 1, 31);
        maaned = lesTall("Måned", 1, 12);
        aar    = lesTall("År   ", 1600, 2100);

        if ((dagNr = dagNummer(dag, maaned, aar)) != 0) // Skriver dagummeret:
           printf("Datoens nummer i det året:  %3i\n\n", dagNr);
        else
           printf("\nUgyldig dato.  Programmet avsluttes.\n\n");

  } while (dagNr != 0);                         // Looper sålenge lovlig dato.

  return 0;
}


/**
 *  Beregner (om mulig) dagnummeret i året for en gitt dato.
 *
 *  @param   dag     - Dag
 *  @param   maaned  - Måned
 *  @param   aar     - År
 *
 *  @return  Dagnummeret i året (om gyldig dato) ellers 0 (null)
 *
 *  @see     skuddaar(...)
 */
int dagNummer(const int dag, const int maaned, const int aar) {
                                     //  Setter opp antall dager i månedene.
                                     //    Verdien for februar settes senere:
    int dagerPrMaaned[] = { 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int totalDagnr;                  //  Utregnet (om mulig) dagnummer i året.

    if (aar < 1600 || aar > 2100)  return 0;   //  Ulovlig år.
    if (maaned < 1 || maaned > 12) return 0;   //  Ulovlig måned.
                                               //  Ut fra om året er skuddår
                                               //    eller ei, så settes
                                               //    verdien for februar:
    dagerPrMaaned[1] = (skuddaar(aar)) ? 29 : 28;
    if (dag < 1 || dag > dagerPrMaaned[maaned-1])  return 0; // Ulovlig dag:
                                         //  Garantert at er en lovlig dato !!
    totalDagnr = dag;
    for (int i = 0;  i < maaned-1;  i++)       // Regner ut datoens dagnummer.
        totalDagnr += dagerPrMaaned[i];

    return totalDagnr;                         // Returnerer dagnummeret.
}


/**
 *  Leser og returnerer et tall mellom to gitte grenser.
 *
 *  @param   tekst  - Ledetekst til brukeren når ber om input/et tall
 *  @param   min    - Minimum for innlest og godtatt tallverdi
 *  @param   max    - Maksimum for innlest og godtatt tallverdi
 *
 *  @return  Godtatt verdi i intervallet 'min' - 'max'
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
 *  Sjekker om et visst år er skuddår eller ei.
 *
 *  @param   aar  - Årstallet som skal sjekkes om er skuddår eller ei
 *
 *  @return  'true' dersom 'aar' er skuddår, ellers 'false'
 */
bool skuddaar(const int aar)  {     //  Skuddår dersom: delelig med 400
                                    //    ELLER delelig med 4 OG IKKE med 100:
  return ((aar % 400 == 0) || ((aar % 4 == 0) && (aar % 100) != 0));
}
