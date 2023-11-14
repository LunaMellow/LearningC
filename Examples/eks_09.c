/**
 *   Programeksempel nr 9 - H-filer og enum (oppramstype).
 *
 *   @file     EKS_09.C
 *   @author   Frode Haug, NTNU
 */


/*  I C11-standarden er det 29 stk H-filer.
      (SE EGNE LINKER under "Ressurser" på emnets hjemmeside.)
    I dette emnet skal vi primært bruke/se noe på følgende fem stk:
*/
#include <ctype.h>      //  Håndtering av enkelt-tegn(/bokstaver)
#include <stdbool.h>    //  'bool' med 'true'/'false'  (istedet for '_Bool')
#include <stdio.h>      //  printf, scanf, fil-håndtering
#include <stdlib.h>	    //  Memory-håndtering, streng-konvertering, mer .....
#include <string.h>	    //  Håndtering av char-arrayer/tekster/strenger

//  Litt av dette har vi allerede sett på.  Mer skal brukes etterhvert ......


const int STRLEN = 80;         ///<  Max. tekstlengde.

/**
 *  Noen eksempler på bruken av enum (oppramstype):
 */
enum Ukedag   { mandag, tirsdag, onsdag, torsdag, fredag, lordag, sondag };
enum Maaned   { januar, februar, mars, april, mai, juni,
                juli, august, september, oktober, november, desember };
enum Type     { Hjerter, Ruter, Klover, Spar };
enum Bryter   { on, off};
enum Medie    { LP, MC, CD, mp3 };
enum Brikke   { Bonde, Hest, Loper, Taarn, Dronning, Konge };
enum Farge    { hvit, svart, rod, gul, gronn, blaa, fiolett, rosa };


/**
 *  Hovedprogrammet:
 */
int main ()  {
   int   tall;
   char  tegn;
   char  tekst[STRLEN], tekst2[STRLEN];

//  Bruker NOEN FÅ av funksjonene/mulighetene på H-filene nevnt ovenfor:

//  CTYPE.H:
    printf("Skriv en LITEN bokstav: ");
    scanf(" %c", &tegn);
    tegn = toupper(tegn);               //  Gjør om til STOR bokstav.
    printf("Denne omgjort til STOR bokstav: %c\n\n", tegn);

    printf("Skriv en annen LITEN bokstav: ");
    scanf(" %c", &tegn);                //  SKRIVER ut som STOR bokstav,
    printf("Denne omgjort til STOR bokstav: %c\n",   toupper(tegn));
                                        //    men 'tegn' selv er IKKE omgjort:
    printf("'tegn' er fortsatt en LITEN bokstav: %c\n\n", tegn);
                     //  Tilsvarende med 'tolower' (omgjør til LITEN bokstav).

//  STDBOOL.H:
    bool  fortsett = true;                      //  Variabeltypren 'bool'.
    printf("'fortsett' er: %i\n\n", fortsett);  //  'true' skrives ut som '1'.
    fortsett = false;
    printf("'fortsett' er nå blitt: %i\n\n", fortsett);   //  'false' som '0'.


//  STDLIB.H:
    printf("Skriv et heltall (blir lest som tekst):  ");
    scanf("%s", tekst);
    printf("Innlest tekst: -%s-\n", tekst);
    tall = atoi(tekst);               //  Tekst gjøres (om mulig) om til tall.
    printf("Innlest tekst som tall: %i\n\n", tall);

    printf("Skriv en tekst (ikke et tall):  ");
    scanf("%s", tekst);
    printf("Innlest tekst: -%s-\n", tekst);        //  Tekst gjøres (om mulig)
    printf("Innlest tekst som tall: %i\n\n", atoi(tekst));   //   om til tall.
                              //  Tilsvarende for 'float' vha. 'atof'.

//  Fra  STRING.H:
    printf("Skriv inn ett ord:  ");
    scanf("%s", tekst);
    printf("Innlest tekst: -%s-\n\n", tekst);
                            //  Finner og skriver tekstens lengde (uten '\0'):
    printf("Antall tegn i '%s': %i\n\n", tekst, strlen(tekst));

    strcpy(tekst2, tekst);  //  Kopierer bakerste tekst til den første.
    printf("Kopiert til 'tekst2': -%s-\n\n", tekst2);

    printf("Forskjellen på '%s' og '%s' er: %i\n\n",
            tekst, tekst2, strcmp(tekst, tekst2));  //  Sammenligner tekster.

    strcat(tekst2, tekst);  //  Skjøter siste tekst bakerste på den første.
    printf("Sammenskjøtet i 'tekst2': -%s-\n\n", tekst2);

    printf("Forskjellen på tekstene '%s' og '%s' er nå: %i\n\n",
           tekst, tekst2, strcmp(tekst, tekst2));  //  Forskjellen nå,
                                                   //    eller omvendt:
    printf("Forskjellen på tekstene '%s' og '%s' er også: %i\n\n",
           tekst2, tekst, strcmp(tekst2, tekst));

    strcat(tekst2, " er hyggelig");  //  Mer skjøting av tekster.
    printf("Mer sammenskjøting av 'tekst2': -%s-\n\n", tekst2);


 //  ENUM (litt enkel bruk, mye mer senere):
    enum Ukedag dag1, dag2;
    dag1 = fredag;    dag2 = tirsdag;     //  Initierer/gir verdi.
    printf("Antall dager mellom Fredag og Tirsdag er:  %i\n\n", dag1-dag2);

    enum Type kortT;
    int  kortV;
    kortT = Spar;  kortV = 8;                 //  Initierer/gir verdi.
                                              //  1.verdi blir automatisk nr.0
    printf("Kortet er: %i %i\n\n", kortV, kortT); //    derfor er 'Spar' nr.3:
                               //  Mer om fornuftig I/O av enum'er senere ....
    return 0;
}
