/**
 *   Programeksempel nr 12 - For-løkke.
 *
 *   @file     EKS_12.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>          //  printf, scanf
#include <stdlib.h>         //  srand, rand
#include <string.h>         //  strlen
#include <time.h>           //  time

const int MAX     = 10;     ///<  Max. loopinger og array-lengde.
const int STRLEN  = 80;     ///<  Max. tekstlengde.

/**
 *  Hovedprogrammet:
 */
int main ()  {
    int   i, j;             //  STERK sedvane for navn på løkke-teller
                            //    ('i', 'j', 'k', .....)
    int   sum, valgtTall;
    int   tall[MAX];
    char  tekst[STRLEN];


    printf("Bla  Bla  Bla  Bla  Bla  Bla  Bla  Bla  Bla  Bla\n\n");  //  Enten

    for (i = 1;  i <= MAX;  i++)                                     //  Bedre
        printf("Bla  ");


    printf("\n\n'i' i annen:\n");
    for (i = 1;  i <= MAX;  i++)
        printf("\t%i:  %i\n", i, i*i);


    printf("\n\n'i' i tredje - baklengs:\n");
    for (i = MAX;  i >= 3;  i--)
        printf("\t%i:  %i\n", i, i*i*i);


    printf("\n\nFyller og skriver array:\n");               //  EN måte:
    for (i = 0;  i < MAX;  i++)
        tall[i] = i;
    for (i = 0;  i < MAX;  i++)
        printf("\t'tall[%i]' er:  %i\n", i, tall[i]);


    printf("\n\nFyller og skriver array samtidig:\n");      //  En ANNEN måte:
    for (i = 0;  i < MAX;  i++)  {                          //  BLOKK !!!
        tall[i] = i + 10;                                   //    Når flere
        printf("\t'tall[%i]' er:  %i\n", i, tall[i]);       //    setninger.
    }

    printf("\n'i' etter løkka: %i\n", i);     //  'i' har økt T.O.M. 'MAX' !!!

    printf("\n\nLeser inn i halve 'tall':\n");  //  Fyller bare halve arrayen:
    for (i = 0;  i < MAX/2;  i++)  {
       printf("Verdien i element nr.%i:  ", i);
       scanf("%i", &tall[i]);
    }                                     //  Skriver nytt og gammelt innhold:
    printf("\n\nSkriver ut HELE dens innhold nå:\n");
    for (i = 0;  i < MAX;  i++)
        printf("\t'tall[%i]' er:  %i\n", i, tall[i]);


    printf("\n\nGjennomsnittet av tallene i arrayen:\n");
    sum = 0;                               //  Viktig at er nullstilt!
    for (i = 0;  i < MAX;  i++)            //  Summerer opp alle verdiene:
        sum += tall[i];
    printf("\t%i  (som float: %f)\n", sum/MAX, (float)sum / MAX);


// ***************************************************************************

    printf("\n\nHvilken gangetabell vil du se: ");   //  Ønsket gangetabell:
    scanf("%i", &valgtTall);
    for (i = 1;  i <= MAX;  i++)
        printf("\t%2i * %i = %8i\n", i, valgtTall, i*valgtTall);
                                      //  NB: Ett tall etter '%' medfører
                                      //      at utskriften HØYREJUSTERES,
                                      //      og tillegges evt. blanke foran.
                                      //      Et '-' foran tallet igjen,
                                      //      gjør at det VENSTREJUSTERES, og
                                      //      det tillegges evt. blanke etter.

    printf("\n\nSummer opp til:  ");
    scanf("%i", &valgtTall);
    sum = 0;                              //  Huske å nullstille igjen!
    for (i = 1;  i <= valgtTall;  i++)    //  Looper til selvvalgt verdi/tall:
        sum += i;
    printf("\tSummen av alle tallene fra 1 til %i er: %i\n", valgtTall, sum);


// ***************************************************************************

    printf("\n\nAlfabetet:  ");
    for (i = 0;  i < 26;  i++) {
        tekst[i] = 65+i;                   //  A = nr.65, B = nr.66, ...
        printf("%c", tekst[i]);
    }
                                           //  'i' har telt EN for langt.
    tekst[i] = '\0';                       //  Legger derfor inn '\0' i nr.26.
    printf("\nAlfabetet igjen: %s\n", tekst);

    printf("Og baklengs:     ");
    for (i = 25;  i >= 0;  i--)
        printf("%c", tekst[i]);


// ***************************************************************************

    getchar();    //  NB:  Skal nå lese tekst, og det ligger igjen en '\n' i
                  //       input-buffer etter at det sist ble lest int'er
                  //       vha. 'scanf'.

    printf("\n\nSkriv inn en tekst: ");
    gets(tekst);
            //  Leser lengre tekst.
    printf("Innlest tekst:  %s\n", tekst);

    printf("\n\nSkriver ett og ett tegn - veldig manuelt:\n\t\t");
    for (i = 0;  tekst[i] != '\0';  i++)      //  Skriver ett og ett tegn:
        printf("%c", tekst[i]);

    printf("\n\nSkriver ett og ett tegn - mer vanlig/elegant:\n\t\t");
    for (i = 0;  i < strlen(tekst);  i++)     //  Skriver ett og ett tegn:
        printf("%c", tekst[i]);

                                              //  KAN HA LØKKER INNI LØKKER:
    printf("\n\nLeser og skriver tre tekster:\n");
    for (i = 1;  i <= 3;  i++) {
        printf("\nSkriv inn %i.tekst: ", i);
        gets(tekst);
        printf("\tInnlest %i.gang:  ", i);
        for (j = 0;  j < strlen(tekst);  j++) //  Skriver ett og ett tegn:
             printf("%c", tekst[j]);
        printf("\n");
    }
    printf("\n\n");


// ***************************************************************************

    printf("\n\n10 linjer med tilfeldig antall '*' (1-40 stk):\n");
    srand(time(0));
    for (i = 0;  i < MAX;  i++)
        tall[i] = (rand() % 40) + 1;
    for (i = 0;  i < MAX;  i++)  {
        for (j = 1;  j <= tall[i];  j++)
            printf("*");
        printf("\n");
    }
    printf("\n\n");


// ***************************************************************************

    printf("\n\nFibonacci-tall (ethvert tall er summen av de 2x forrige):\n");

    tall[0] = tall[1] = 1;
    for (i = 2;  i < MAX;  i++)
        tall[i] = tall[i-2] + tall[i-1];

    for (i = 0;  i < MAX;  i++)
        printf("   %i", tall[i]);

    printf("\n\n");


// ***************************************************************************

    for (i = 0;  i <= 255;  i++)  {        //  Tegnsettet på maskinen din:
        printf("%3i: %c   ", i, (char)i);  //  Caster i til char ved utskrift.
        if (i % 8 == 0)  printf("\n");     //  8 tegn pr.linje.
    }

    printf("\n\n  æ   ø   å   Æ   Ø   Å \n");   //  Æ Ø Å æ ø å ????? :
    printf("  ‘   ›   †   ’       \n");
    printf("  %c  %c  %c  %c  %c  %c  %c  %c \n",
           145,   148,   155,   134,   146,   153,   157,   143);
    printf("  %c  %c  %c  %c  %c  %c  %c  %c\n\n",
           0x91,  0x94,  0x9B,  0x86,  0x92,  0x99,  0x9D,  0x8F);

    printf("%cse bor p%c g%crd n%cre Mj%csa.\n\n", 143, 134, 134, 145, 148);

// ***************************************************************************

                                    // KAN også (som er MEGET vanlig) definere
    for (int k = 1;  k <= MAX;  k++) //  løkke-telleren ifm. selve for-løkka:
        printf("Bla  ");            // 'k' er da BARE gyldig ifm. selve løkka.

    printf("\n\n");


//  KONKLUSJON:  Svært ofte går for-løkker fra 0 eller 1 og oppover
//               til en eller annen indeks/const/variabel/(regne)uttrykk.

    return 0;
}
