/**
 *   Programeksempel nr 31 - Pekere - Minneh�ndtering (malloc/free),
 *                           lage arrayer under run-time.
 *
 *   @file     EKS_31.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>              //  printf, scanf
#include <stdbool.h>            //  bool
#include <stdlib.h>             //  calloc, malloc, free, sizeof
#include <string.h>             //  strlen, strcpy


#define    STRLEN2    80        ///<  Max. tekstlengde 2.
const int  STRLEN  =  60;       ///<  Max. tekstlengde 1.


char  gTekst3[STRLEN2];         ///<  Global tekst.


/**
 *  Hovedprogrammet:
 */
int main ()  {
    char  tekst[STRLEN2/2];
    char  tekst2[STRLEN];

    printf("Antall byte i 'tekst':    %i\n",   sizeof(tekst));
    printf("Antall byte i 'tekst2':   %i\n",   sizeof(tekst2));
    printf("Antall byte i 'gTekst3':  %i\n\n", sizeof(gTekst3));

                              //  'sizeof' er en operator !!!
                              //  Selv om det ser ut som en funksjon.

    printf("Antall byte i 'int':     %i\n",   sizeof(int));
    printf("Antall byte i 'float':   %i\n",   sizeof(float));
    printf("Antall byte i 'char':    %i\n",   sizeof(char));
    printf("Antall byte i 'bool':    %i\n\n", sizeof(bool));


    struct Testing  {
        char  t[STRLEN];
        int   a, b, c;
        float d;
     };

     struct Testing test;

  printf("Antall byte i 'test':              %i\n",   sizeof(test));
  printf("Antall byte i 'struct Testing':    %i\n\n", sizeof(struct Testing));

                              // Kan alts� ta 'sizeof':
                              //     - ARRAY
                              //     - DATATYPE (int, float, char, bool)
                              //     - STRUCT
                              //  Men ogs� (dog mer sjeldent):
                              //     - enum
                              //     - enkelt-variabel  inkl. peker
                              //     - uttrykk


// ***************************************************************************

    int  i, lengde;
    char *tPeker, *tPeker2;
                                                 //  En pekers st�rrelse:
    printf("Antall byte i 'tPeker':    %i\n\n",   sizeof(tPeker));


    printf("Hvor lang skal TEKSTEN v�re:  ");    //  Leser �nsket tekstlengde:
    scanf("%i", &lengde);


// ===========================================================================
// ===========================================================================

                        //  TO M�TER � SETTE AV MEMORY-PLASS UNDER RUN-TIME:
    tPeker  = (char*) calloc(sizeof(char), lengde);    //  0 i det tilpekte.

    tPeker2 = (char*) malloc(lengde * sizeof(char));   //  Nullstiller IKKE !

                         //  NB:  Husk � CASTE om til aktuell/�nsket type !!!
// ===========================================================================
// ===========================================================================

    printf("\tTilpekt av 'tPeker':  ");            //  "Utskrift" av 0 ('\0'):
    for (i = 0;  i < strlen(tPeker); i++)
        printf("%c", tPeker[i]);
    printf("\n");

    printf("\tTilpekt av 'tPeker2':  ");           //  Utskrift av "s�ppel":
    for (i = 0;  i < strlen(tPeker2); i++)
        printf("%c", tPeker2[i]);
    printf("\n\n");
                                      //  Arrayens elementer er tilgjengelige
    *tPeker   = 'K';   *(tPeker+1) = 'L';  //   b�de via peker og "som array".
    tPeker[2] = 'M';   tPeker[3]   = '\0';
    printf("'tPeker':     %s\n", tPeker);

    strcpy(tPeker, "EFGHIJKLMNOPQ");
    printf("'tPeker' n�:  %s\n\n", tPeker);


// ***************************************************************************

//  VI BRUKER PRIM�RT  'malloc' !!!
                                   //  Leser �nsket lengde p� array av int'er:
    int  *iPeker, *iPeker2;

    printf("Hvor lang skal INT-ARRAY v�re:  ");
    scanf("%i", &lengde);

    iPeker = (int*) malloc(lengde * sizeof(int));  //  Lager array med int'er.


   *iPeker   = 11;   *(iPeker+1) = 22; // Arrayens elementer er tilgjengelige
   iPeker[2] = 33;   iPeker[3]   = 44; //    b�de via peker og "som array".

    printf("\t'iPeker':  ");
    for (i = 0;  i <= 3;  i++)
        printf("  %i", iPeker[i]);
    printf("\n\n");


// ***************************************************************************

    iPeker2 = (int*) malloc(1000000 * sizeof(int));
    if (iPeker2 == NULL)                          //  B�R testes om gikk bra:
        printf("\nIkke nok memory til S� mange int'er!\n\n");


// ***************************************************************************

    struct Testing* test2;    //  KAN ogs� lage peker til ARRAY med struct'er:

    test2 = (struct Testing*) malloc (100 * sizeof(struct Testing));


                   //  NB:  Dette er alts� en PEKER til array MED/AV structer.
                   //       Det er IKKE en array med FLERE struct-PEKERE.
                   //       DET er det om i EKS_32.c



// ***************************************************************************

    free(tPeker);   //  M� (b�r) ALLTID frigi allokert/avsatt memory !
    free(tPeker2);  //     (om programmet skal st� � kj�re lenge)
    free(iPeker);   //  Ellers risikerer vi 'memory-leak' !
    free(iPeker2);  //  Viktig at fortsatt peker til STARTEN p� det allokerte!
    free(test2);

//  free(test);     //  ULOVLIG, da IKKE er allokert vha. malloc/calloc


    return 0;
}
