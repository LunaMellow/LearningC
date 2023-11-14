/**
 *   Programeksempel nr 10 - St�rre programeksempel.
 *
 *   som viser bruken av en god del av det vi hittil har l�rt ifm:
 *     - ulike typer variable
 *     - const
 *     - aritmetiske operasjoner
 *     - arrayer
 *     - char-arrayer/tekster/strenger
 *     - utskrift/innlesning
 *     - H-filer
 *
 *   @file     EKS_10.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>             //  printf, scanf
#include <stdlib.h>            //  srand, rand
#include <time.h>              //  Diverse tids-funksjoner

const int STRLEN       =  80;  ///<  Max. tekstlengde.
const int MAXTILFELDIG = 100;  ///<  Max. verdi for tilfeldig tall.
const int MAXFLOAT     =   5;  ///<  Max. antall float i arrayen.

/**
 *  Hovedprogrammet:
 */
int main ()  {
    float sum = 0,             //  Summen av alle tallene i 'tall'-arrayen.
          tall[MAXFLOAT];      //  Array med float'er.
    int   postNr,              //  Postnummer.
          aar,                 //  �rstall.
          dagNummer;           //  En gitt dags nummer et gitt �r.
    char  navn[STRLEN], gateAdr[STRLEN], postSted[STRLEN],  //  Personinfo:
          mail[STRLEN], annenInfo[STRLEN];       //  Dager i ulike m�neder:
    int   mndAntall[12] = { 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    tall[0] = 12.34;   tall[1] = 56.78;                  //  Initierer 2x.
    printf("Skriv inn tre float-verdier: ");
    scanf("%f %f %f", &tall[2], &tall[3], &tall[4]);     //  Leser 3x.
    printf("\n'tall' inneholder n�:\t%f\t%f\t%f\t%f\t%f\n\n",
           tall[0], tall[1], tall[2], tall[3], tall[4]);
                               //  Summerer og beregner gjennomsnittet:
    sum += tall[0] + tall[1] + tall[2] + tall[3] + tall[4];
    printf("Deres sum er: %f\tog gjennomsnittet er: %f\n\n",
           sum, sum/MAXFLOAT);


// ***************************************************************************
// ***************************************************************************

    getchar();             //  P�krevd for � bli kvitt '\n' etter de tre
                           //    float'ene, og f�r innlesning av tekst vha.
                           //    'gets'. 'scanf("%s", ...)' ville ha ventet
                           //    p� noe ikke-blankt (ulikt ' ', '\t' og '\n').
    printf("Navn:        ");   gets(navn);
    printf("Gateadresse: ");   gets(gateAdr);
    printf("Postnummer:  ");   scanf("%i", &postNr);  getchar();   //  NB !
    printf("Poststed:    ");   gets(postSted);
    printf("Mail:        ");   scanf("%s", mail);     getchar();   //  NB !
    printf("Annen info:  ");   gets(annenInfo);

// *****************************************************************
// *****************************************************************
// *****************************************************************
// ***                                                           ***
// ***  NB:  Husk alts� 'getchar()' etter 'scanf(...)' n�r       ***
// ***       det neste som skal leses er en tekst vha. 'gets' !  ***
// ***                                                           ***
// *****************************************************************
// *****************************************************************
// *****************************************************************

    printf("\nInnleste verdier:\n");
    printf("\tNavn:    %s\n",    navn );
    printf("\tGateadr: %s\n",    gateAdr);
    printf("\tSted:    %i %s\n", postNr, postSted);
    printf("\tMail:    %s\n",    mail);
    printf("\tAnnet:   %s\n\n",  annenInfo);


// ***************************************************************************
// ***************************************************************************

   printf("Skriv et �rstall: ");   scanf("%i", &aar);  //  Leser �rstall.
                                                       //  Leser #dager i feb:
   printf("Antall dager i februar i %i: ", aar);  scanf("%i", &mndAntall[1]);
   dagNummer = 7 + mndAntall[0] + mndAntall[1] +       //  Finner dagnummer:
               mndAntall[2] + mndAntall[3] + mndAntall[4];
   printf("7.juni %i var dag nummer %i i det �ret.\n\n", aar, dagNummer);


// ***************************************************************************
// ***************************************************************************

//  Litt "leking" med H-filer ("ut av det bl�"), for � vise et par muligheter:

    time_t result = time(NULL);    //  Henter maskinens tidspunkt.
                                   //  Utskrift p� ulike formater:
    printf("N�v�rende tid i UK:  %s",   asctime(gmtime(&result)));
    printf("N�v�rende tid:       %s\n", asctime(localtime(&result)));


    srand(time(0));         //  Initierer HELT tilfeldig trekking.
                            //  Trekker tilfeldige STORE tall som omgj�res
                            //    til intervallet  1 - 'MAXTILFELDIG':
    int tilfeldigTall = (rand() % MAXTILFELDIG) + 1;
    printf("Tilfeldig tall: [1,%i]: %i\n", MAXTILFELDIG, tilfeldigTall);
    tilfeldigTall = (rand() % MAXTILFELDIG) + 1;
    printf("Tilfeldig tall: [1,%i]: %i\n", MAXTILFELDIG, tilfeldigTall);
    tilfeldigTall = (rand() % MAXTILFELDIG) + 1;
    printf("Tilfeldig tall: [1,%i]: %i\n", MAXTILFELDIG, tilfeldigTall);
    tilfeldigTall = (rand() % MAXTILFELDIG) + 1;
    printf("Tilfeldig tall: [1,%i]: %i\n", MAXTILFELDIG, tilfeldigTall);

    return 0;
}
