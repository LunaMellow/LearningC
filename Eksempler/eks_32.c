/**
 *   Programeksempel nr 32 - Pekere - Array med pekere til tekster og structer.
 *
 *   @file     EKS_32.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>              //  printf, scanf
#include <stdlib.h>             //  sizeof, malloc, free
#include <string.h>             //  strcpy

#define     STRLEN    80        ///<  Max. tekstlengde.
const  int  ARRLEN  =  7;       ///<  Max. array-lengde.

/**
 *  Person (med navn og alder).
 */
struct Person  {
    char navn[STRLEN];
    int  alder;
};



/**
 *  Hovedprogrammet:
 */
int main ()  {
    int i;

    char* ukedager[] = { "Mandag", "Tirsdag", "Onsdag",
                         "Torsdag", "Fredag", "Lørdag", "Søndag" };

    int   lengde;
    char* tekster[ARRLEN];

    printf("\nAlle tekstenes lengde (> 7):  ");   //  Ønskede tekstlengder:
    scanf("%i", &lengde);

    for (i = 0;  i < ARRLEN;  i++)        //  Allokerer plass til ARRAYER:
        tekster[i] = (char*) malloc(lengde * sizeof(char));


    for (i = 0;  i < ARRLEN;  i++)        //  Kopierer over fra andre ARRAYER:
        strcpy(tekster[i], ukedager[i]);


    printf("\nAllokert arrays innhold:\n");   //  Skriver allokert TEKSTER:
    for (i = 0;  i < ARRLEN;  i++)
        printf("\t%s\n", tekster[i]);


    for (i = 0;  i < ARRLEN;  i++)        //  Frigir allokerte ARRAYER:
        free(tekster[i]);


//  Kan selvsagt gjøre noe tilsvarende med arrayer av:  int, float og bool


// ***************************************************************************
// ***************************************************************************

    struct Person* personer[ARRLEN];      //  Pekere til FLERE structer.

    for (i = 0;  i < ARRLEN;  i++)        //  Allokerer FLERE ENKELT-structer:
        personer[i] = (struct Person*) malloc (sizeof(struct Person));


    for (i = 0;  i < ARRLEN;  i++)  {     //  Fyller alle structene med data:
        strcpy(personer[i]->navn, "MIA");
        personer[i]->alder = 18+i;
    }
    printf("\n\n");

    for (i = 0;  i < ARRLEN;  i++)        //  Skriver alle structenes data:
        printf("Person nr. %i:  %s,  %i år\n",
               i+1, personer[i]->navn, personer[i]->alder);


    for (i = 0;  i < ARRLEN;  i++)        //  Frigir allokert memory:
        free(personer[i]);


    printf("\n\n");

    return 0;
}
