/**
 *   Programeksempel nr 3 - Grunnleggende variabeltyper.
 *
 *   Omhandler variabeltypene:
 *     - int        (ikke noe om:  short,  long,  long long)
 *     - float      (ikke noe om:  double)
 *     - char
 *     - bool ( _Bool )
 *     -            (ikke noe om:  signed,  unsigned)
 *
 *   @file     EKS_03.C    (noe likt med Program 3.1 i læreboka)
 *   @author   Stephen G.Kochan / Frode Haug, NTNU
 */


#include <stdio.h>               //  printf
#include <stdbool.h>             //  bool  - Denne SKAL vi bruke/include i
                                 //          dette emnet for å bruke boolean.
                                 //          Vi bruker IKKE  _Bool

/**
 *  Hovedprogrammet:
 */
int main()  {
    int    heltall   =  19940212;
    float  flyttall  =  304.312;
    char   tegn      =  'M';
    _Bool  ok        =  1;        //  _Bool-variable er '0' eller '1'.
    bool   feil      =  false;    //  bool-variable er 'false' eller 'true'.

    printf("Heltall:   %i\n", heltall);
    printf("Flyttall:  %f\n", flyttall);
    printf("Tegn:      %c\n", tegn);
    printf("OK:        %i\n", ok);
    printf("Feil:      %i\n", feil);
    printf("\n\n");
                                  //  Alternative måter å skrive ut float på:
    printf("Flyttall:  %e\n", flyttall);        //  Eksponensielt
    printf("Flyttall:  %g\n", flyttall);        //  Maskinen "velger" ..  :-)
    printf("Flyttall:  %g\n", flyttall*100);    //  Maskinen "velger" ..  :-)
    printf("Flyttall:  %g\n", flyttall*1000);   //  Maskinen "velger" ..  :-)
    printf("Flyttall:  %g\n", flyttall*10000);  //  Maskinen "velger" ..  :-)

    return 0;
}
