/**
 *   Programeksempel nr 13 - Logiske operatorer.
 *
 *   @file     EKS_13.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>          //  printf
#include <stdbool.h>        //  bool

/**
 *  Hovedprogrammet:
 */
int main ()  {

//  Logiske operatorer er:
//       &&                  ||             !
//     and (og)          or (eller)        not (ikke, det motsatte, negasjon)
//
//  Disse brukes til å sammenknytte relasjonsuttrykk
//     (evt. ta '!' til en variabel eller et uttrykk i parentes).
//  TOTALSVARET på et slikt uttrykk er ALLTID  'true' (1)  eller 'false' (0).

    int  a = 7,  b = 14,  c = 21;
    bool OK = true;

    printf("\na = %i,  b = %i,  c = %i\n\n", a, b, c);

    printf("a <  b  &&  b < c:    %i\n",  a <    b  &&  b < c);
    printf("a <  c  &&  b >= c:   %i\n",  a <    c  &&  b >= c);
    printf("a <  c  ||  b >= c:   %i\n",  a <    c  ||  b >= c);
    printf("a+b <  c  &&  b > a:  %i\n",  a+b <  c  &&  b > a);
    printf("a+b <  c  ||  b > a:  %i\n",  a+b <  c  ||  b > a);

    printf("OK:                   %i\n",  OK);
    printf("!OK:                  %i\n",  !OK);

    printf("a+b <  c  &&  OK:     %i\n",  a+b <  c  &&  OK);
    printf("a+b <  c  ||  OK:     %i\n",  a+b <  c  ||  OK);
    printf("a+b == c  &&  !OK:    %i\n",  a+b == c  &&  !OK);
    printf("a+b == c  ||  !OK:    %i\n",  a+b == c  ||  !OK);

    printf("a+b == c || (b > a  &&  a > c)  %i\n", a+b == c || (b>a && a>c));
    printf("a+b == c && (b > a  &&  a > c)  %i\n", a+b == c && (b>a && a>c));
    printf("a+b == c && !(b > a  &&  a > c) %i\n", a+b == c && !(b>a && a>c));

    return 0;
}

/*  OPPSUMERT hva saker blir:
       True   &&  True   =  True
       True   &&  False  =  False
       False  &&  True   =  False
       False  &&  False  =  False


       True   ||  True   =  True
       True   ||  False  =  True
       False  ||  True   =  True
       False  ||  False  =  False


       !True   =  False
       !False  =  True
*/
