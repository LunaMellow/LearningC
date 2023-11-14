/**
 *   Programeksempel nr 9 - H-filer og enum (oppramstype).
 *
 *   @file     EKS_09.C
 *   @author   Frode Haug, NTNU
 */


/*  I C11-standarden er det 29 stk H-filer.
      (SE EGNE LINKER under "Ressurser" p� emnets hjemmeside.)
    I dette emnet skal vi prim�rt bruke/se noe p� f�lgende fem stk:
*/
#include <ctype.h>      //  H�ndtering av enkelt-tegn(/bokstaver)
#include <stdbool.h>    //  'bool' med 'true'/'false'  (istedet for '_Bool')
#include <stdio.h>      //  printf, scanf, fil-h�ndtering
#include <stdlib.h>	    //  Memory-h�ndtering, streng-konvertering, mer .....
#include <string.h>	    //  H�ndtering av char-arrayer/tekster/strenger

//  Litt av dette har vi allerede sett p�.  Mer skal brukes etterhvert ......


const int STRLEN = 80;         ///<  Max. tekstlengde.

/**
 *  Noen eksempler p� bruken av enum (oppramstype):
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

//  Bruker NOEN F� av funksjonene/mulighetene p� H-filene nevnt ovenfor:

//  CTYPE.H:
    printf("Skriv en LITEN bokstav: ");
    scanf(" %c", &tegn);
    tegn = toupper(tegn);               //  Gj�r om til STOR bokstav.
    printf("Denne omgjort til STOR bokstav: %c\n\n", tegn);

    printf("Skriv en annen LITEN bokstav: ");
    scanf(" %c", &tegn);                //  SKRIVER ut som STOR bokstav,
    printf("Denne omgjort til STOR bokstav: %c\n",   toupper(tegn));
                                        //    men 'tegn' selv er IKKE omgjort:
    printf("'tegn' er fortsatt en LITEN bokstav: %c\n\n", tegn);
                     //  Tilsvarende med 'tolower' (omgj�r til LITEN bokstav).

//  STDBOOL.H:
    bool  fortsett = true;                      //  Variabeltypren 'bool'.
    printf("'fortsett' er: %i\n\n", fortsett);  //  'true' skrives ut som '1'.
    fortsett = false;
    printf("'fortsett' er n� blitt: %i\n\n", fortsett);   //  'false' som '0'.


//  STDLIB.H:
    printf("Skriv et heltall (blir lest som tekst):  ");
    scanf("%s", tekst);
    printf("Innlest tekst: -%s-\n", tekst);
    tall = atoi(tekst);               //  Tekst gj�res (om mulig) om til tall.
    printf("Innlest tekst som tall: %i\n\n", tall);

    printf("Skriv en tekst (ikke et tall):  ");
    scanf("%s", tekst);
    printf("Innlest tekst: -%s-\n", tekst);        //  Tekst gj�res (om mulig)
    printf("Innlest tekst som tall: %i\n\n", atoi(tekst));   //   om til tall.
                              //  Tilsvarende for 'float' vha. 'atof'.

//  Fra  STRING.H:
    printf("Skriv inn ett ord:  ");
    scanf("%s", tekst);
    printf("Innlest tekst: -%s-\n\n", tekst);
                            //  Finner og skriver tekstens lengde (uten '\0'):
    printf("Antall tegn i '%s': %i\n\n", tekst, strlen(tekst));

    strcpy(tekst2, tekst);  //  Kopierer bakerste tekst til den f�rste.
    printf("Kopiert til 'tekst2': -%s-\n\n", tekst2);

    printf("Forskjellen p� '%s' og '%s' er: %i\n\n",
            tekst, tekst2, strcmp(tekst, tekst2));  //  Sammenligner tekster.

    strcat(tekst2, tekst);  //  Skj�ter siste tekst bakerste p� den f�rste.
    printf("Sammenskj�tet i 'tekst2': -%s-\n\n", tekst2);

    printf("Forskjellen p� tekstene '%s' og '%s' er n�: %i\n\n",
           tekst, tekst2, strcmp(tekst, tekst2));  //  Forskjellen n�,
                                                   //    eller omvendt:
    printf("Forskjellen p� tekstene '%s' og '%s' er ogs�: %i\n\n",
           tekst2, tekst, strcmp(tekst2, tekst));

    strcat(tekst2, " er hyggelig");  //  Mer skj�ting av tekster.
    printf("Mer sammenskj�ting av 'tekst2': -%s-\n\n", tekst2);


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
