/**
 *   Programeksempel nr 29 - Pekere - og array.
 *
 *   @file     EKS_29.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>              //  printf



/**
 *  Hovedprogrammet:
 */
int main ()  {                  //  Definerer vanlig int-array:
    int  tall[10] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

    int* iPeker;                //  Lager int-peker.

    iPeker = &tall[0];          //  Setter til å peke på arrayens start.
    printf("Arrayens første verdi:   %i\n\n", *iPeker);

    iPeker = tall;              //  Setter OGSÅ til å peke på array-start!
    printf("Arrayens første verdi:   %i\n\n", *iPeker);


// ***************************************************************************
// ***************************************************************************
// **                                                                       **
// **      ALTSÅ:  NAVNET PÅ EN ARRAY ER ADRESSEN TIL STARTEN PÅ DEN !      **
// **                                                                       **
// ***************************************************************************
// ***************************************************************************


                                //  EN måte å skrive ut et element på:
    printf("Arrayens syvende verdi:  %i\n\n", tall[6]);
                                //  En ANNEN måte for det samme:
    printf("Arrayens syvende verdi:  %i\n\n", *(iPeker+6));

    iPeker = tall + 6;   //  En tredje måte, MEN NÅ HAR PEKER ENDRET INNHHOLD!
    printf("Arrayens syvende verdi:  %i\n\n", *iPeker);

    iPeker++;                   //  Øker til neste element:
    printf("Arrayens åttende verdi:  %i\n\n", *iPeker);

    iPeker++;                   //  Og neste der igjen:
    printf("Arrayens niende verdi:   %i\n\n", *iPeker);

    iPeker--;                   //  Og tilbake til forrige element:
    printf("Arrayens åttende verdi:  %i\n\n", *iPeker);


// ***************************************************************************

    iPeker = tall;              //  Setter tilbake til arrayens start:

    while (*iPeker < 200)  {    //  Traverserer array så lenge verdi < 200:
      printf("  %i", *iPeker);  //  Skriver pekerens VERDI.
      iPeker++;                 //  Går til neste element.
    }
    printf("\n\n");


//  Det samme, bare litt mer kompakt:
    iPeker = tall;              //  Setter tilbake til arrayens start:

    while (*iPeker < 200)       //  Traverserer array så lenge verdi < 200:
      printf("  %i", *iPeker++);//  Skriver pekerens VERDI OG ØKER den.

    printf("\n\n");


    printf("Verdi til peker når løkke har stanset:  %i\n\n\n\n", *iPeker);


// ***************************************************************************

                                    //  Definerer vanlig char-array.
    char tekst[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char* cPeker = tekst+13;        //  Definerer char-peker, og initierer til
                                    //    et stykke ut i arrayen.

    printf("Alfabetets 14.bokstav:  %c\n\n", *cPeker);

    cPeker += 4;                    //  Øker til 4.element senere:
    printf("Alfabetets 18.bokstav:  %c\n\n", *cPeker);

                                    //  Skriver ALT fra og med peker til '\0':
                                    //  NB: '%s' er brukt.  '*' er borte !
    printf("Alfabetet ETTER 17.bokstav:  %s\n\n", cPeker);


    cPeker = tekst;                //  Setter peker tilbake til tekst-start.
    while (*cPeker != '\0')  {     //  Looper frem til tekstens slutt:
      printf("%c", *cPeker);       //  Skriver pekerens VERDI.
      cPeker++;                    //  Øker til neste tegn/element i array.
    }
    printf("\n\n");


//  LITT mer kompakt:
    cPeker = tekst;
    while (*cPeker)  {        //  != '\0'  dvs.  != '0'  dvs.  ER noe/true !!!
      printf("%c", *cPeker);
      cPeker++;
    }
    printf("\n\n");


// ENDA mer kompakt:
    cPeker = tekst;
    while (*cPeker)
      printf("%c", *cPeker++);     //  Skriver VERDI, og øker peker etterpå.
    printf("\n\n");


// ***************************************************************************

   printf("Går bare videre utover i memory - skriver alt som char'er:\n");
   printf("( ikke da uvanlig at programmet krasjer .....  :-)  )\n\n");
   for (int i = 1;  i <= 1000;  i++)
     printf("%c", *cPeker++);
   printf("\n\n");


// ***************************************************************************


//  KAN også ha peker til MASSE annet, bl.a:
//    - pekere til funksjoner  (side 272-273)
//    - pekere til pekere
//  Men, dette skal vi se på/bruke minimalt - foreløpig ...

    printf("\n\n");

    return 0;
}
