/**
 *   Programeksempel nr 22 - Returverdi fra funksjon
 *                           Også retur flere steder.
 *
 *   @file     EKS_22.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>              //  printf, scanf
#include <ctype.h>              //  toupper

char  lesKommando();
float celsiusTilFahrenheit(const float celcius);
int   lesTall(const char tekst[], const int min, const int max);
int   dageriMaaned(const int maaned, const int aar);

/**
 *  Hovedprogrammet:
 */
int main ()  {
   char kommando;

   kommando = lesKommando();
   printf("\tInnlest kommando/tegn:  %c\n\n", kommando);


//*****************************************************************

//  Jfr. typisk 'main' utover i emnet (litt endret ift. EKS_19.c):

    //  lesFraFil(();
    //  skrivMeny();

    kommando = lesKommando();

    while (kommando != 'Q')  {
        switch (kommando)  {
          case 'N':   /*  nyPerson();       */    break;
          case 'S':   /*  skrivPerson();    */    break;
          case 'A':   /*  skrivPersoner();  */    break;
          case 'E':   /*  endrePerson();    */    break;
          case 'F':   /*  fjernPerson();    */    break;
          case 'K':   /*  kopierPerson();   */    break;
          default:    /*  skrivMeny();      */    break;
        }

        kommando = lesKommando();
    }
    //  skrivTilFil();

    printf("\n\n");


//*******************************************************************

    float cGrader, fGrader;

    cGrader = 24.2;
    fGrader = celsiusTilFahrenheit(cGrader);

    printf("%.1f grader Celsius tilsvarer %.1f grader Fahrenheit.\n",
           cGrader, fGrader);

    printf("38.6 grader Celsius tilsvarer %.1f grader Fahrenheit.\n",
           celsiusTilFahrenheit(38.6));

    printf("0.0 grader Celsius tilsvarer %.1f grader Fahrenheit.\n",
           celsiusTilFahrenheit(0.0));

    printf("-32.0 grader Celsius tilsvarer %.1f grader Fahrenheit.\n",
           celsiusTilFahrenheit(-32.0));

    printf("-17.77 grader Celsius tilsvarer %.1f grader Fahrenheit.\n\n",
           celsiusTilFahrenheit(-17.77));


//***********************************************************************

    int verdi;

    verdi = lesTall("Alder:  ", 0, 120);
    printf("\tGodtatt verdi:  %i\n\n", verdi);

    verdi = lesTall("Temperatur:  ", -70, 70);
    printf("\tGodtatt verdi:  %i\n\n", verdi);

    printf("\tGodtatt verdi:  %i\n\n\n",
           lesTall("Antall passasjerer i bussen", 1, 20));


//**************************************************************************

    printf("Månedsdager april    1999:  %i\n",     dageriMaaned( 4, 1999));
    printf("Månedsdager desember 2002:  %i\n",     dageriMaaned(12, 2002));
    printf("Månedsdager oktober  1995:  %i\n",     dageriMaaned(10, 1995));
    printf("Månedsdager februar  2010:  %i\n",     dageriMaaned( 2, 2010));
    printf("Månedsdager mai      1971:  %i\n",     dageriMaaned( 5, 1971));
    printf("Månedsdager xxxxxx   2019:  %i\n\n\n", dageriMaaned(17, 2019));


//**************************************************************************

//  NB:  Hvordan funksjoner kan "returnere" FLERE verdier (to eller flere),
//       skal vi lære om når vi senere har lært om PEKERE.

//**************************************************************************

    return 0;
}


/**
 *  Leser og returnerer ett (upcaset) tegn.
 *
 *  @return  Ett (upcaset) tegn.
 */
 char lesKommando()  {
     char tegn;
     printf("Skriv kommando:  ");
     scanf(" %c", &tegn);   getchar();
     return (toupper(tegn));
}


/**
 *  Omgjør Celsius grader til Fahrenheit grader.
 *
 *  @param   celcius  - Antall grader etter Celsius-skalaen
 *
 *  @return  Tilsvarende grader etter Fahrenheit-skalaen
 */
float celsiusTilFahrenheit(const float celcius)  {
   return ((celcius * 9/5) + 32);
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
 *  Finner antall dager i en måned et gitt år.
 *
 *  @param   maaned  - Måneden det skal beregnes antall dager i
 *  @param   aar     - Året det er snakk om (skuddår eller ei?)
 *
 *  @return  Dagantallet i aktuell måned, evt. 0 om ulovlig månedsummer.
 */
int dageriMaaned(const int maaned, const int aar)  {
   switch (maaned)  {
      case 1:  case 3:  case  5:
      case 7:  case 8:  case 10:  case 12:   return 31;
      case 4:  case 6:  case  9:  case 11:   return 30;
      case 2:  /* if (skuddaar(aar))           return 29;   //  Se EKS_24.c
               else  */                      return 28;
      default: printf("Ugyldig måned!\n");   return  0;
   }
//  Normalt gjør vi dette litt mer elegant/annerledes.
//  Men for eksemplets del, med 'return' flere steder,
//  så gjør vi det slik her nå.  Bedre/mer i EKS_24.c

}
