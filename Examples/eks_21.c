/**
 *   Programeksempel nr 21 - Funksjoner (uten/ med/ parametre).
 *
 *   @file     EKS_21.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>              //  printf, scanf
#include <ctype.h>              //  isalpha
#include <stdbool.h>            //  bool
#include <string.h>             //  strlen


#define  STRLEN   80            ///<  Max. tekstlengde.


//  DEKLARASJON AV FUNKSJONS-HEADINGER/PROTOTYPER:
void fastLinje();                                // NB - NB - NB:
void fleksibelLinje(int antall, char tegn);      //   NORMALT bør disse stå i
void endreTall(int n);                           //   ALFABETISK rekkefølge.
void alleTallSummertOppTil(int n);               //   Men i dette eksemplet
void lesNavn();                                  //   står de i rekkefølgen
void sjekkNavn();                                //   de brukes/vises.


//  GLOBAL VARIABEL:
char gNavn[STRLEN];             ///<  Personnavn.
                                //    NB for den innledene 'g',
                                //       og etterfølgende STOR bokstav.

/**
 *  Hovedprogrammet:
 */
int main ()  {

    printf("\nHittil har vi l%crt om:\n", (char)145);
    fastLinje();                                          //  Kaller funksjon.
    printf("\tint   char   float   bool\n");
    printf("\t+  -  *  /  %  +=  -=  *=  /=  %=  ++  --\n");
    printf("\t<  <=  >  >=  ==  !=  &&  ||  !\n");
    fastLinje();                                          //  Kaller funksjon.
    printf("\tfor   while   do\n");
    printf("\tif - else if - else   switch\n");
    fastLinje();                                          //  Kaller funksjon.

    printf("\n\n");


// ********************************************************************

//  Se HELT til slutt i EKS_19.c  (eksemplet med 'main' utover i høst).


// ********************************************************************

    fleksibelLinje(50, '=');                              //  Kaller funksjon.
    printf("\tint   char   float   bool\n");
    printf("\t+  -  *  /  %  +=  -=  *=  /=  %=  ++  --\n");
    printf("\t<  <=  >  >=  ==  !=  &&  ||  !\n");
    fleksibelLinje(50, '-');                              //  Kaller funksjon.
    printf("\tfor   while   do\n");
    printf("\tif - else if - else   switch\n");
    fleksibelLinje(50, '=');                              //  Kaller funksjon.


// ********************************************************************

    int  antallTegn;                         //  Antall ønskede tegn å skrive.
    char onsketTegn;                         //  Ønsket tegn utskrevet.

    printf("\n\nAntall tegn i skillelinjen:   ");  scanf("%i",  &antallTegn);
    printf("Selve tegnet i skillelinjen:  ");      scanf(" %c", &onsketTegn);
    printf("\n\n");
                                                          //  Kaller funksjon:
    fleksibelLinje(antallTegn, onsketTegn);      //  AKTUELLE parametre.
    printf("\tint   char   float   bool\n");
    printf("\t+  -  *  /  %  +=  -=  *=  /=  %=  ++  --\n");
    printf("\t<  <=  >  >=  ==  !=  &&  ||  !\n");
    fleksibelLinje(antallTegn, onsketTegn);               //  Kaller funksjon.
    printf("\tfor   while   do\n");
    printf("\tif - else if - else   switch\n");
    fleksibelLinje(antallTegn, onsketTegn);               //  Kaller funksjon.


// ********************************************************************

    int tall;

    printf("\n\nSkriv et tall:  ");  scanf("%i", &tall);
    printf("\n\tTallet er:     %i\n", tall);
    endreTall(tall);                                    //  Kaller funksjon.
    printf("\tTallet er nå:  %i\n\n", tall);            // 'tall' IKKE endret!


// ********************************************************************

    alleTallSummertOppTil(6);
    alleTallSummertOppTil(10);
    alleTallSummertOppTil(100);
    alleTallSummertOppTil(200);
    alleTallSummertOppTil(718);
    alleTallSummertOppTil(1000);
    alleTallSummertOppTil(10000);
    alleTallSummertOppTil(100000);
    printf("\n\n");


// ********************************************************************

    getchar();                     //  Forkaster '\n' etter siste 'scanf'.

//  Funksjoner som arbeider på/bruker samme globale variabel
//  (skal snart lære om hvordan sende med array som parameter):

    lesNavn();  printf("\tInnlest navn:  %s\n", gNavn); // Skriv LOVLIG navn.
    lesNavn();  printf("\tInnlest navn:  %s\n", gNavn); // Skriv ULOVLIG navn.
    lesNavn();  printf("\tInnlest navn:  %s\n", gNavn); // Skriv LOVLIG navn.
    sjekkNavn();
    lesNavn();  printf("\tInnlest navn:  %s\n", gNavn); // Skriv ULOVLIG navn.
    sjekkNavn();


// ********************************************************************

/*  ALLE variable som er definert inni blokker kalles LOKALE/AUTOMATIC.
    Vi har hittil KUN sett på slike (ALLE har vært definert
    inni 'main', i funksjoner eller ifm. 'for (int i = .....)').
    Disse inneholder initielt en ukjent verdi ("søppel").
    De er bare synlige og gyldig inni blokken de er laget/definert.

    Variable som er definert UTENFOR alle blokker, dvs. primært i
    starten av programmet, ofte rett før 'main' - kalles GLOBALE.
    Disse blir initiert til 0 (null).
    De er synlige og gyldige i ALL etterfølgende kode på HELE filen.

    Glem det om STATIC variable .....

    NB:   Globale variable skal holdes nede på et minimum!
          KUN datastrukturen, som hele programmet er basert på, er det
          aktuelt/lov å legge globalt (ikke masse små enkelt-variable).
*/
    return 0;
}


//  DEFINISJON AV FUNKSJON(SINNMAT)ER:

/**
 *  Skriver fast 60 stk. '='.
 */
 void fastLinje()  {
    for (int i = 1;  i <= 60;  i++)
        printf("=");
    printf("\n");
 }


/**
 *  Skriver et fleksibelt antall av et gitt tegn.
 *
 *  @param   antall - Antall like 'tegn' som skrives
 *  @param   tegn   - Tegnet som skrives 'antall' ganger
 */
 void fleksibelLinje(int antall, char tegn)  {    //  FORMELLE parametre.
    for (int i = 1;  i <= antall;  i++)           //    (KOPIERES til disse!)
        printf("%c", tegn);
    printf("\n");
 }


/**
 *  Endrer den formelle og KOPIERTE parameteren, men IKKE den aktuelle.
 *
 *  @param   n - Formell parameter som er KOPIERT
 */
 void endreTall(int n)  {
    printf("\t'n' er:        %i\n", n);
    n++;   n++;   ++n;   ++n;   n += 10;     //  Endrer KUN FORMELL parameter.
    printf("\t'n' er nå:     %i\n", n);
 }


/**
 *  Regner og skriver ut summen av alle tallene fra 1 til 'n'.
 *
 *  @param   n - Tallet det skal summerer fra 1 og opp til.
 */
 void alleTallSummertOppTil(int n)  {
    int sum = 0;                             //  Viktig at er nullstilt.
    for (int i = 1;  i <= n;  i++)
        sum += i;

    printf("Summen av alle tallene fra 1 til %5i er:  %8i\n", n, sum);
  }


/**
 *  Leser inn verdi til den globale 'gNavn'.
 */
void lesNavn()  {
  printf("\nSkriv inn NAVN: ");
  gets(gNavn);
}


/**
 *  Sjekker at den globale 'gNavn' KUN inneholder bokstaver, ' ' eller '-'.
 *
 *  Jfr. kode HELT til slutt i EKS_18.c
 */
void sjekkNavn()  {
  int  len  = strlen(gNavn);         //  Beregner bare EN gang - effektivitet!
  bool feil = false;                 //  Antar navnet initielt er uten feil.
  char tegn;                         //  Henter tegn EN gang - effektivitet!
  for (int i = 0;  i < len;  i++)  {
    tegn = gNavn[i];                 //  Inneholder minst ett ULOVLIG tegn;
    if (!isalpha(tegn)  &&  tegn != ' '  && tegn != '-')
       { feil = true;   break;  }    //  Setter at 'feil' har skjedd.
  }                                  //    Avslutter gjennomgangen av teksten.

  if (feil)                          //  Ulovlig tegn har forekommet:
    printf("\tNavnet inneholder ulovlige tegn!\n");
}
