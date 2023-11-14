/**
 *   Programeksempel nr 37 - Filer - 'feof' - End-of-file.
 *
 *   @file     EKS_37.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>              //  printf, FILE
#include <string.h>             //  strlen

const int STRLEN = 80;          ///<  Max. tekstlengde

/**
 *  Hovedprogrammet:
 */
int main ()  {
    int   linjeNr;
    char  tekstLinje[STRLEN];
                                       //  Filformat:
                                       //     <linjenr> <sangtekstlinje>

    printf("\n\nLeser fra filen 'FIL2.DTA' .....\n\n\n");

    FILE* innfil;                      //  Peker til fil for input.

    innfil = fopen("FIL2.DTA", "r");   //  Åpner fil for INPUT - 'r'

    if (innfil)  {                     //  Filen er funnet:

       fscanf(innfil, "%i", &linjeNr); //  PRØVER Å LESE STARTEN PÅ 1.LINJE.
       while (!feof(innfil))  {        //  Klarte det - IKKE slutt på filen:
          getc(innfil);                //  Forkaster ' ' før teksten.
                                       //  Leser resten av linjen som EN
          fgets(tekstLinje, STRLEN, innfil);    //  tekst, evt. inkl. '\n'!
                                       //  KAN evt. fjerne '\n' ved:
          //                          tekstLinje[strlen(tekstLinje)-1] = '\0';

                                       //  Skriver det innleste:
                               printf("Linje %i: %s\n", linjeNr, tekstLinje);

          fscanf(innfil, "%i", &linjeNr); // PRØVER Å LESE STARTEN PÅ NY LINJE.
       }
    } else                             //  Filen ikke funnet/mulig å åpne:
       printf("Klarte ikke å finne filen 'FIL2.DTA'!\n\n");

    fclose(innfil);                    //  Lukker filen.


    printf("\n\n");
    return 0;
}