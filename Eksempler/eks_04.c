/**
 *   Programeksempel nr 4 - Artimetiske operatorer.
 *
 *   Omhandler de aritmetiske operatorene:
 *     - +   -   *   /   %
 *     - +=  -=  *=  /=  %=
 *     - ++  --    (�ke eller minske en verdi med EN)
 *     -  -  (negasjonen til en verdi, f.eks.  -7  eller   -778.24)
 *
 *   @file     EKS_04.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>         //  printf

const int VERDI = 10;      ///<  Consten 'VERDI'

/**
 *  Hovedprogrammet:
 */
int main()  {
   int  tall1 = 11, tall2 = 22, tall3 = 8, tall4 = 5, svar;

   svar = (tall1 * tall2) + (tall3 / tall4);
   printf("Svaret er: %i\n", svar);
                           //  Operatorpresedens gir samme svaret som ovenfor:
   svar = tall1 * tall2 + tall3 / tall4;
   printf("Svaret er: %i\n", svar);
                           //  Ved parentesbruk endres utregningen/svaret:
   svar = ((tall1 * tall2) + tall3) / tall4;
   printf("Svaret er: %i\n", svar);

   svar = tall1 % tall4;   //  11 % 5  = 1 i rest
   printf("Svaret er: %i\n", svar);

   svar = tall2 % tall3;   //  22 % 8  = 6 i rest
   printf("Svaret er: %i\n", svar);

   printf("Negasjonen til 'tall2' og 'tall3' er: %i  %i\n", -tall2, -tall3);

   printf("\n\n'tall2' (%i) ", tall2);
   tall2 = tall2 + VERDI;
   printf("�kt med %i er: %i\n", VERDI, tall2);

   tall2 += VERDI;
   printf("�kt med enda %i er: %i\n", VERDI, tall2);

   tall2 *= VERDI;
   printf("Multiplisert med %i er: %i\n", VERDI, tall2);
                           //  Tilsvarende med:    -=   /=   og  %=

   tall2 += 1;             //  Ulike m�ter � �ke kun med 1:
   printf("�kt med 1 er: %i\n", tall2);

   tall2++;            //  �ker ETTER bruk. Singel setning, s� uten betydning.
   printf("�kt med enda 1 er: %i\n", tall2);

   ++tall2;            //  �ker F�R bruk. Singel setning, s� uten betydning.
   printf("�kt med enda 1 er: %i\n", tall2);

   printf("�kt med enda 1 er: %i\n", ++tall2);     //  �ker F�R bruk.

   printf("�kt ETTERP� med 1 er: %i\n", tall2++);  //  �ker ETTER bruk.

   printf("N� er den �kt: %i\n", tall2);
                       //   Tilsvarende med:    --

   return 0;
}
