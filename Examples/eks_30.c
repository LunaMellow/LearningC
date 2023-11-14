/**
 *   Programeksempel nr 30 - Pekere - Array/peker som parameter,
 *                           return av peker, REFERANSEOVERFØRING.
 *
 *   @file     EKS_30.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>              //  printf, scanf


#define   FIBANT   20           ///<  Max. antall i Fibonacci-array.
const int STRLEN = 80;          ///<  Max. tekstlengde.
const int INTANT = 10;          ///<  Max. int'er i arrayen.


/**
 *  Tidsunkt (med time, minutt og sekund).
 */
struct Tidspunkt  {
   int time,
       minutt,
       sekund;
};


void  bytt(int* t1,  int* t2);
char* finnTegnITekst(char* tekst, const char tegn);
void  fyllArray(int* tall, const int n);
char* fysjOgFoyForEnStyggFunksjonSlikGjorManBareIkke();
int   lesTall(const char* tekst, const int min, const int max);
void  lesTekst(const char   ledetekst[], char  tekst[]);
void  lesTekst2(const char* ledetekst,   char* tekst);
void  mstrcpy(char* s, const char* t);
char* mstrcpy2(char* s, const char* t);
void  oppdaterDato(int* d, int* m, int* a);
void  oppdaterTid(struct Tidspunkt* t);
void  skrivArray(const int* tall, const int n);
int   summer(const int* tall, const int n);


/**
 *  Hovedprogrammet:
 */
int main ()  {
    char tekst[STRLEN];

    lesTekst("Tekst vha. array", tekst);       //  Parametre er arrayer:
    printf("\t\tInnlest tekst:  -%s-\n\n", tekst);
                                               //  Parametre er pekere:
    lesTekst2("Tekst vha. peker", tekst);      //  Kalles/brukes HELT LIKT !!!
    printf("\t\tInnlest tekst:  -%s-\n\n", tekst);


// ***************************************************************************

    int tallene[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };  //  Initierer array.

    int antall =  summer(tallene, INTANT);     //  Henter array-summen.

    printf("\nint-arrayens sum:  %i\n\n\n", antall);


// ***************************************************************************

    int FibonacciTall[FIBANT] =  { 1, 1 };  //  Definerer og DELVIS initierer!

    fyllArray(FibonacciTall, FIBANT);   //  Får array fylt med Fibonacci-tall.

    printf("Det %i første Fibonacci-tallene:\n\t", FIBANT);
    skrivArray(FibonacciTall, FIBANT);  //  Skriver dens nye fylte innhold.
    printf("\n\n\n");


// ***************************************************************************

    char  tekst2[STRLEN];
    char* tekst3;

    mstrcpy(tekst2, tekst);           //  Tekst-kopiering vha. pekere.

    printf("Tidligere innlest tekst:  -%s-\n", tekst);
    printf("Kopiert til 'tekst2':     -%s-\n\n", tekst2);


    lesTekst2("Ny tekst", tekst);     //  Leser en ny tekst.
    printf("\tInnlest tekst:  -%s-\n\n", tekst);
                                      //  Tekst-kopiering vha. pekere
    tekst3 = mstrcpy2(tekst2, tekst); //     OG RETURPEKER TIL RESULTATET!
                                   //  Kan da lage utskrift på TO ULIKE MÅTER:
    printf("Kopiert til 'tekst2':       -%s-\n", tekst2);
    printf("Utskrevet vha. egen peker:  -%s-\n\n", tekst3);


// ***************************************************************************

   char startTegn;
   printf("Fra hvilket tegn i den siste tekst starter utskriften:  ");
   scanf(" %c", &startTegn);
                                  //  Får evt. returnert peker til INNI tekst:
   tekst3 = finnTegnITekst(tekst2, startTegn);

   printf("Utskrevet f.o.m angitt tegn:  -%s-\n\n", tekst3);

   printf("Fra hvilket IKKE-EKSISTERENDE tegn starter utskriften:  ");
   scanf(" %c", &startTegn);        //  Får evt. returnert peker til NULL.
   tekst3 = finnTegnITekst(tekst2, startTegn);
   printf("Utskrevet f.o.m angitt tegn:  -%s-\n\n", tekst3);

   if (tekst3)                      //  Bedre utskrift - når KAN være NULL:
      printf("Utskrevet f.o.m angitt tegn:  -%s-\n\n", tekst3);
   else
      printf("Tegnet ikke funnet i teksten!\n\n");


// ***************************************************************************

                            //  ALDRI returnere PEKER til LOKAL VARIABEL !!!!:

   tekst3 = fysjOgFoyForEnStyggFunksjonSlikGjorManBareIkke();
   printf("FYSJ OG FØY - Forsøk på utskrift av lokal variabel:  -%s-\n\n",
          tekst3);




// ***************************************************************************
// REFERANSEOVERFØRING = "retur" av en eller FLERE verdier UTEN Å BRUKE return
// ***************************************************************************

   struct Tidspunkt tp;            //  Definerer struct-variabel - IKKE peker.

   oppdaterTid(&tp);               //  Sender med ADRESSEN/PEKER til den !!!

                                   //  ORIGINLEN/MEDSENDT ER OPPDATERT!! :
   printf("\n'tp' sine verdier:  %i:%i:%i\n\n\n",
          tp.time, tp.minutt, tp.sekund);


// ***************************************************************************

   int dag, maaned, aar;              //  Definerer int'er - IKKE pekere:

   oppdaterDato(&dag, &maaned, &aar); //  Sender med ADRESSENE/PEKERE til dem!

   printf("\nDato:  %i/%i-%i\n\n", dag, maaned, aar); // ORIGINALER oppdatert!


// ***************************************************************************

   int   tall = 11,  tall2 = 22;                //  Jfr Prog.10.9 i læreboka:
   int*  tPeker = &tall,  *tPeker2 = &tall2;

   printf("Verdier FØR bytte:      %i   %i\n", tall, tall2);

   bytt(&tall, &tall2);
   printf("Verdier ETTER bytte:    %i   %i\n\n", tall, tall2);

   bytt(tPeker, tPeker2);
   printf("Verdier når TILBAKE:    %i   %i\n", tall, tall2);
   printf("Det samme via pekerne:  %i   %i\n\n", *tPeker, *tPeker2);


   return 0;
}



/**
 *  Bytter om verdiene i to int'er (referanseoverførte).
 *
 *  @param   t1  - Peker til den første int'en
 *  @param   t2  - Peker til den andre int'en
 */
void  bytt(int* t1,  int* t2)  {
   int temp = *t1;              //  Rotasjonsombytting vha. en hjelpe-int:
        *t1 = *t2;
        *t2 = temp;
}


/**
 * Leter etter ETT tegn i en tekst, og returnerer (om mulig) peker til tegnet.
 *
 *  @param   tekst  - Teksten det skal letes/søkes i
 *  @param   tegn   - Tegnet det skal letes etter
 *
 *  return   Peker til (om mulig) funnet tegn, ellers returneres NULL
 */
char* finnTegnITekst(char* tekst, const char tegn)  {
   while (*tekst)  {                  //  Letet gjennom teksten frem til '\0'.
                                      //  Tegnet funnet -
      if (*tekst == tegn)  return tekst;  //         returnerer peker til det.
      tekst++;                        //  Går til neste tegn.
   }
   return NULL;                       //  Ingen funn - retur av NULL.
}


/**
 *  Fyller array (som initielt inneholder 1 og 1 i to første elemener)
 *  med Fibonacci-tall.
 *
 *  @param   tall  - int-arrayen som skal fylles
 *  @param   n     - Arrayens lengde
 */
void fyllArray(int* tall, const int n)  {
  int i;                             //  Løkkevariabel
            //  NB - NB:  2x initieringer  og  2x inkrementer (økninger):
  for (i = 2, tall += 2;  i < n;  i++, tall++)
    *tall = *(tall-1) + *(tall-2);   //  Element blir summen av
}                                    //    to forrige elementer.


/**
 *  Fysj- og føy-funksjon - som viser noe man IKKE gjør.
 *
 *  return   PEKER til LOKAL variabel - som ALDRI skal returneres
 */
char* fysjOgFoyForEnStyggFunksjonSlikGjorManBareIkke()  {
   char tekst[] = "Man returnerer IKKE peker til en lokal variabel!!!!\n\n";

   return tekst;       //  NEI, NEI.  Lokal variabel SLETTES jo (snart)
}                      //             så lite poeng å peke utenfra til det !!!


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
 *  Leser tekst inn i medsendt char-array/tekst/string.
 *
 *  @param   ledetekst  - Ledetekst som utskrift til brukeren om hva lese inn
 *  @param   tekst      - char-array som fylles med innlest tekst
 */
void lesTekst(const char ledetekst[], char tekst[])  {
  printf("\t%s:  ", ledetekst);
  gets(tekst);                    //  Oppdaterer ORIGINALEN/aktuell parameter.
}


/**
 *  Leser tekst inn i tilpekt memoryområde med char'er.
 *
 *  @param   ledetekst  - peker til ledetekst om hva som skal leses inn
 *  @param   tekst      - peker til memoryområdet med char'er
 */
void lesTekst2(const char* ledetekst, char* tekst)  {
  printf("\t%s:  ", ledetekst);
  gets(tekst);            //  Oppdaterer tilpekte char'er (derfor ORIGINALEN).
}


/**
 *  Kopierer tilpekt tekst over i et annet tilpekt memoryområde.
 *
 *  @param   s  - Peker til memory det skal kopieres TIL
 *  @param   t  - Peker til memory det skal kopieres FRA
 */
void mstrcpy(char* s, const char* t)  {
  while (*t != '\0')              //  Blar til slutten av 't'.
    *s++ = *t++;                  //  Kopierer over ett og ett tegn.
  *s = '\0';                      //  NB: Legger manuelt inn avsluttende '\0'.
}


/**
 *  Kopierer tilpekt tekst over i et annet tilpekt memoryområde,
 *  returnerer også peker til kopiert område.
 *
 *  @param   s  - Peker til memory det skal kopieres TIL
 *  @param   t  - Peker til memory det skal kopieres FRA
 *
 *  @return  char-peker til det kopierte
 */
char* mstrcpy2(char* s, const char* t)  {
  char* u = s;             //  Tar vare på hvor 's' peker.
  while (*t)               //  Blar til slutten av 't'.
    *s++ = *t++;           //  Kopierer over ett og ett tegn.
  *s = '\0';               //  NB: Legger manuelt inn avsluttende '\0'.
  return u;                //  Returnerer unnalagret peker til starten av 's'.
}


/**
 *  Oppdaterer direkte medsendte int'er (referanseoverførte).
 *
 *  @param   d  - Peker til int (dag)
 *  @param   m  - Peker til int (maaned)
 *  @param   a  - Peker til int (aar)
 *  @see     lesTall(...)
 */
void  oppdaterDato(int* d, int* m, int* a)  {
  *d = lesTall("Dag  ",    1,  31);          //  Oppdaterer 3x ORIGINALER:
  *m = lesTall("Måned",    1,  12);
  *a = lesTall("År   ", 1950,2050);
}


/**
 *  Oppdaterer direkte medsendt struct (referanseoverført).
 *
 *  @param   t  - Peker til aktuell/medsendt struct
 *  @see     lesTall(...)
 */
void  oppdaterTid(struct Tidspunkt* t)  {
  t->time   = lesTall("Time",   0, 200);     //  Oppdaterer ORIGINALENS
  t->minutt = lesTall("Minutt", 0,  59);     //    datamedlemmer:
  t->sekund = lesTall("Sekund", 0,  59);
}


/**
 *  Skriver et visst antall tilpekte int-verdier .
 *
 *  @param   tall  - int-arrayen som skal skrives
 *  @param   n     - Arrayens lengde
 */
void skrivArray(const int* tall, const int n)  {
   for (int i = 0;  i < n;  i++)
       printf("  %i", *tall++);        //  Skriver VERDI - øker til neste int.
}


/**
 *  Summerer alle verdine i en tilpekt int-array og returnerer denne summen.
 *
 *  @param   tall  - int-arrayen som skal summeres
 *  @param   n     - Arrayens lengde
 *
 *  return   Tilpekt int-arrays sum
 */
int  summer(const int* tall, const int n)  {
   int sum = 0;                       //  Definerer og nullstiller(!)

   for (int i = 0;  i < n;  i++)
      sum +=  *tall++;                //  Summerer og øker til neste int.

//   for (int i = 0;  i < n;  i++)    //  ALTERNATIV MÅTE:
//      sum +=  tall[i];              //    "Pekeren sitt element nr.i" !
                                      //    (pekeren økes IKKE !)
   return sum;                        //  Returnerer summen/svaret.
}   //  NB:  Læreboka har en litt annen løsning på dette i Prog.10.11 side 262
