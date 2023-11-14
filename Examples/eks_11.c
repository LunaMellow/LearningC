/**
 *   Programeksempel nr 11 - Relasjons-operatorer.
 *
 *   @file     EKS_11.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>          //  printf
#include <stdbool.h>        //  bool

/**
 *  Hovedprogrammet:
 */
int main ()  {
//  Relasjons-operatorene er:
//      <        >             <=                >=          ==      !=
//    Mindre  Større   Mindre-eller-lik  Større-eller-lik    Lik   Ikke-lik
//
//  Disse brukes til å sammenligne verdier/tall/variable.
//  Svaret på en sammenligning er ALLTID  'true' (1)  eller 'false' (0).

    int  a = 7, b = 14, c = 21;
    bool svar;

    printf("\na = 7,  b = 14,  c = 21\n\n");
    printf("'a' <  'b':  %i\n",   a <  b);
    printf("'a' >  'b':  %i\n",   a >  b);
    printf("'a' <= 'b':  %i\n",   a <= b);
    printf("'a' >= 'b':  %i\n",   a >= b);
    printf("'a' == 'b':  %i\n",   a == b);
    printf("'a' != 'b':  %i\n",   a != b);
    printf("'a' == 'b':  %i\n\n", a = b);  //  VANSKELIG FEIL å finne, da
                            //   ALLTID mulig (true) at 'a' SETTES LIK 'b' !!!

    a = 7;                                         //  Tilbakestiller.
    printf("'a' + 'b' <  'c':  %i\n",   a+b <  c);
    printf("'a' + 'b' <= 'c':  %i\n",   a+b <= c);
    printf("'a' + 'b' >= 'c':  %i\n",   a+b >= c);
    printf("'a' + 'b' == 'c':  %i\n\n", a+b == c);

    printf("'a' + 'b' - 'c' == 0:  %i\n\n", a+b-c == 0);

    printf("'a' %% 2 == 'c' %% 2:  %i\n",   a%2 == c%2);
    printf("'a' %% 2 == 'b' %% 2:  %i\n\n", a%2 == b%2);


    svar = ((c - b) == a);      //  KAN lagre sammenligninger i en 'bool'.
    printf("'c' - 'b' == 'a':  %i\n",   svar);

    svar = c - b == a;          //  Utregning gjøres for sammenligning,
                                //    så derfor ikke nødvendig med parenteser.
    printf("'c' - 'b' == 'a':  %i\n\n", svar);

    return 0;
}