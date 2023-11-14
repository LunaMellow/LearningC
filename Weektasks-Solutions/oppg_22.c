/**
 *   L�sningsforslag til oppgave nr 22.
 *
 *   @file	  OPPG_22.C
 *   @author  Frode Haug, NTNU
 */


#include <stdio.h>                 //  printf, scanf

void lagFirkant(int bredde, int hoyde);

/**
 *  Hovedprogrammet:
 */
int main()  {
    int onsketHoyde, onsketBredde;   //  Brukerens �nsker for bredde og h�yde.

    for (int i = 1;  i <= 3;  i++)  {
        printf("Firkantens bredde:  ");  scanf("%i", &onsketBredde);
        printf("Firkantens h�yde:   ");  scanf("%i", &onsketHoyde);
        printf("\n\n");
        lagFirkant(onsketBredde, onsketHoyde);
        printf("\n\n");
    }

    return 0;
}


/**
 *  Skriver en ramme av '*'er med en gitt bredde og h�yde.
 *
 *  @param   bredde - Firkantens bredde/lengde/kolonner
 *  @param   hoyde  - Firkantens h�yde/rader/linjer
 */
void lagFirkant(int bredde, int hoyde)  {
  int i, j;
   for (i = 1;  i <= bredde;  i++)        //  F�rste linje (�verste ramme).
       printf("*");
   printf("\n");                          //  Linjeslutt.
   for (j = 1;  j <= hoyde-2;  j++)  {    //  -2 pga. start- og sluttlinje.
       printf("*");
       for (i = 1;  i <= bredde-2;  i++)  //  -2 pga. '*' i hver ende:
           printf(" ");                   //  Blanke i hele mellomrommet.
       printf("*\n");                     //  Linjeslutt.
   }
   for (i = 1;  i <= bredde;  i++)        //  Siste linje (nederste ramme).
       printf("*");
   printf("\n");                          //  Linjeslutt.
}
