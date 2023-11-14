/**
 *   L�sningsforslag til oppgave nr 20.
 *
 *   @file	  OPPG_20.C
 *   @author  Frode Haug, NTNU
 */


#include <stdio.h>                 //  printf, scanf
#include <stdbool.h>               //  bool
#include <string.h>                //  strlen

const int  STRLEN = 80;            ///<  Max. tekstlengde.

/**
 *  Hovedprogrammet:
 */
int main()  {
    char  tlfNr[STRLEN];           //  Telefonnummer som en tekst.
    bool  feil = false;            //  Ingen feil i teksten - forel�pig.

    printf("\nTelefonnummer:  ");  //  Leser telefonnummer:
    gets(tlfNr);

    printf("\nDette skrevet med bokstaver:\n\t");

    for (int i = 0;  i < strlen(tlfNr);  i++)  {    //  G�r gjennom teksten:
        switch (tlfNr[i])  {
           case ' ':                     break;     //  ' ' - ingenting skjer.
           case '0':  printf("null");    break;
           case '1':  printf("en");      break;
           case '2':  printf("to");      break;
           case '3':  printf("tre");     break;
           case '4':  printf("fire");    break;
           case '5':  printf("fem");     break;
           case '6':  printf("seks");    break;
           case '7':  printf("syv");     break;
           case '8':  printf("�tte");    break;
           case '9':  printf("ni");      break;     //  Ulovlig tegn:
           default:   printf("\n\tUlovlig tegn! Avslutter ....\n");
                      feil = true;       break;     //  Feil har da skjedd.
        }
        if (feil) break;                            //  G�R UT AV FOR-L�KKEN !
                                     //  Mer igjen, og siste IKKE blank (' '):
        if (i < strlen(tlfNr)-1  &&  tlfNr[i] != ' ') printf("-");
    }

    printf("\n\n");

    return 0;
}
