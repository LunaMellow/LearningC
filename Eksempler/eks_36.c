/**
 *   Programeksempel nr 36 - Filer - Enkel utskrift/innlesning,
                                     med fileksistenssjekk.
 *
 *   @file     EKS_36.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>              //  printf, FILE

const int STRLEN = 80;          ///<  Max. tekstlengde.

/**
 *  Hovedprogrammet:
 */
int main ()  {
    int   iTall = 45,                         iTall2;
    float fTall = 78.34,                      fTall2;
    char  tegn  = 'W',                        tegn2,               svar;
    char  tekst[] = "Dette er filens tekst",  tekst2[STRLEN];


    printf("\n\nSkriver til filen 'FIL1.DTA' .....\n\n");

    FILE* utfil;                      //  Peker til fil for output.

    utfil = fopen("FIL1.DTA", "w");   //  Åpner fil for OUTPUT - 'w'.
                                      //  Filen legges på PROSJEKTKATALOGEN!!!
    if (utfil)                  //   if (utfil != NULL)  - mulig å åpne filen.
                                      //  Skriver variable/verdier til filen:
       fprintf(utfil, "%i %f %c\n%s", iTall, fTall, tegn, tekst);
    else                              //  Umulig å opprette filen.
       printf("Klarte ikke å åpne filen 'FIL1.DTA' for skriving!\n\n");

    fclose(utfil);                    //  Lukker filen.


//                                     Brukes om endrer filnavnet manuelt:
//    printf("\t\t\t\t\t\tSkriv ett tegn .....");    scanf(" %c", &svar);

//****************************************************************************

    printf("\n\nLeser fra filen 'FIL1.DTA' .....\n\n");

    FILE* innfil;                     //  Peker til fil for input.

    innfil = fopen("FIL1.DTA", "r");  //  Åpner fil for INPUT - 'r'.
                                      //  Filen ligger på PROSJEKTKATALOGEN!!!
    if (innfil)  {                    //  =  if (innfil != NULL)
                                      //  Leser 3x enkeltverdier/-variable:
       fscanf(innfil, "%i %f %c", &iTall2, &fTall2, &tegn2);
       getc(innfil);               //  MÅ HUSKE Å FORKASTE '\n' etter 1.linje!
       fgets(tekst2, STRLEN, innfil); //  Leser tekst(linje).
                                      //  NB: Evt. '\n' BLIR DEL AV TEKSTEN!!!
    } else                            //  Filen ikke funnet/mulig å åpne:
       printf("Klarte ikke å finne filen 'FIL1.DTA'!\n\n");

    fclose(innfil);                    //  Lukker filen.


                                   //  Utskrift av innleste verdier fra filen:
    printf("\n\niTall2:  %i\nfTall2:  %.2f\ntegn2:   %c\ntekst2:  %s\n\n\n",
            iTall2, fTall2, tegn2, tekst2);

    return 0;
}
