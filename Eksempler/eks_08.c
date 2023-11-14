/**
 *   Programeksempel nr 8 - Grunnleggende om innlesning
 *                          (og litt mer om utskrift).
 *
 *   @file     EKS_08.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>             //  printf, scanf

const int STRLEN = 10;         ///<  Max. tekstlengde.

/**
 *  Hovedprogrammet:
 */
int main ()  {
    int   heltall, antallLest;
    float flyttall;
    char  tegn, tegn2, tegn3;
    char  tekst[STRLEN],
          tekst2[STRLEN],
          tekst3[STRLEN];

//  Utskrift av noen spesielle tegn:
    printf("\a");                        //  Lydsignal.
                                         //  Utskrift av spesialtegn:
    printf("Tekst med \', \", \\ og \? kan også være ønskelig.\n");


//  INT:
    printf("Skriv inn et heltall:  ");   //  Leser ETT heltall.  HUSK '&' !!!
    scanf("%i", &heltall);               //    Hopper over blanke, \t  og  \n
    printf("Innlest verdi: %i\n\n", heltall);


//  FLOAT:
    printf("Skriv inn et flyttall:  ");  //  Leser ETT flyttall.  HUSK '&' !!!
    scanf("%f", &flyttall);              //    Hopper over blanke, \t  og  \n
    printf("Innlest verdi: %f\n\n", flyttall);


//  CHAR:
    printf("Skriv inn ett tegn:  ");          //  Leser neste tegn - UANSETT,
    scanf("%c", &tegn);                       //    også om det er blanke,
    printf("Innlest verdi: -%c-\n\n", tegn);  //    '\t' eller '\n':
                                              //  HUSK '&' !!!
    printf("Skriv inn ett tegn:  ");
    scanf("%c", &tegn);
    printf("Innlest verdi: -%c-\n\n", tegn);

    printf("Skriv inn ett tegn:  ");          //  Leser neste tegn - IGNORERER
    scanf(" %c", &tegn);                      //   ' ', '\t' og '\n', da har
    printf("Innlest verdi: -%c-\n\n", tegn);  //   ' ' foran %c !!!

    printf("Skriv inn ett tegn:  ");
    scanf(" %c", &tegn);
    printf("Innlest verdi: -%c-\n\n", tegn);

    printf("Skriv inn tre tegn:  ");
    scanf(" %c %c %c", &tegn, &tegn2, &tegn3);
    printf("Innleste verdier: \t-%c-\t-%c-\t-%c-\n\n", tegn, tegn2, tegn3);

//  2 stk andre alternative måter å lese ett tegn på:
//
//  printf("Skriv inn ett tegn:  ");          //  Leser neste tegn - UANSETT,
//  tegn = getchar();                         //    også om det er blanke,
//  printf("Innlest verdi: -%c-\n\n", tegn);  //    '\t' eller '\n':

//  printf("Skriv inn ett tegn:  ");
//  tegn = getc(stdin);
//  printf("Innlest verdi: -%c-\n\n", tegn);



//  ETT OG ETT ORD:
    printf("Skriv inn ETT ord:  ");     //  Leser første ikke-blanke ord.
    scanf("%s", tekst);                 //    Hopper over blanke, \t  og  \n
    printf("Innlest verdi: -%s-\n\n", tekst); //  Skriver med '-' foran/bak.
                                        //  NB:  IKKE '&' ifm. char-arrayer !

    printf("Skriv inn TRE ord:  ");     //  Leser første 3x ikke-blanke ord.
    scanf("%s%s%s", tekst, tekst2, tekst3);  //  Hopper over ' ', \t  og  \n
    printf("Innleste verdier: -%s-\n\t\t-%s-\n\t\t-%s-\n", //  '-' foran/bak.
            tekst, tekst2, tekst3);
                //  NB  NB  NB:  Forkaster/leser '\n' som ligger igjen i
    getchar();  //               input-bufferen etter de tre innleste ordene:


//  SETNING:
    printf("Skriv tekst med blanke:  ");    //  Leser flere ord/setning.
    gets(tekst);                            //  Leser, også '\n', men dette
                                            //    blir IKKE en del av teksten.
    printf("Innlest verdi: -%s-\n\n", tekst);  //  Skriver med '-' foran/bak.

                                     //  NB:  gets - IKKE SIKKER MÅTE, DA OGSÅ
                                     //       LESER INN FOR LANGE TEKSTER,
                                     //       OG BARE SKRIVER UTOVER I MINNET.
                                     //       MEN DEN NYE (i C11) "gets_s" ER
                                     //       DESSVERRE IKKE IMPLEMENTERT  I
                                     //       ALLE KOMPILATORER. Derfor skal
                                     //       vi primært bruke "gets".
    printf("Skriv for lang tekst med blanke:  "); //  Leser flere ord/setning.
    gets(tekst);
    printf("Innlest verdi: -%s-\n\n", tekst);     //  Skriver med '-' foran/bak.


//  2 stk andre alternative måter å lese en setning på:
                                              //   NB: Leser max. STRLEN-1 stk,
//  gets_s(tekst, STRLEN);                    //       for å få plass til '\0'!
//  printf("Innlest verdi: -%s-\n\n", tekst); //  Skriver med '-' foran/bak.


    printf("Skriv for lang tekst med blanke:  "); //  Leser flere ord/setning.
    fgets(tekst, STRLEN, stdin);              //   NB: Leser max. STRLEN-1 stk,
                                              //       for å få plass til '\0'!
    printf("Innlest verdi: -%s-\n\n", tekst); //  Skriver med '-' foran/bak.

    printf("Skriv tekst med blanke:  ");      //  Leser videre om mer i buffer:
    fgets(tekst, STRLEN, stdin);              //   NB: Leser max. STRLEN-1 stk,
                                              //       for å få plass til '\0'!
                            //   NB: Lar evt. også '\n' bli del av teksten!
    printf("Innlest verdi: -%s-\n\n", tekst); //  Skriver med '-' foran/bak.


                              //  Om ikke lykkes å lese/fylle en gitt variabel
                              //    korrekt (f.eks. at bokstav(er) skrives
                              //    istedet for tall), avsluttes innlesningen
                              //    (mer om dette senere en gang ...):
    printf("Skriv ett heltall, en float og ett tegn:  ");
    antallLest = scanf("%i%f %c", &heltall, &flyttall, &tegn);
    printf("Leste: %i %f %c\n", heltall, flyttall, tegn);
    printf("Antall variable lest/fylt korrekt: %i\n\n", antallLest);

    printf("Skriv ett heltall, en float og ett tegn:  ");
    antallLest = scanf("%i%f %c", &heltall, &flyttall, &tegn);
    printf("Antall variable lest/fylt korrekt: %i\n", antallLest);
    printf("Leste: %i %f %c\n", heltall, flyttall, tegn);

    return 0;
}

/*   OPPSUMMERING/KONKLUSJON:

     - int:                                 scanf("%i", &<int-variabel>);

     - float:                               scanf("%f", &<float-variabel>);

     - char - skipper ' ', '\t', '\n':      scanf(" %c", &<char-variabel>);
                                                   NB: ' ' foran %c !!!
            - neste - uansett:              scanf("%c", &<char-variabel>);
                                  ( eller:   <char-variabel> = getchar();
                                    eller:   <char-variabel> = getc(stdin); )

     - tekst - uten blanke:                 scanf("%s", <char-array>);
             - med blanke:                  gets(<char-array>);
                                 ( eller:   gets_s(<char-array>, <len>);
                                   eller:   fgets(<char-array>, <len>, stdin); )

     - scanf lar '\n' ligger igjen i inputbuffer, så om denne må
       forkastes/leses manuelt, så brukes gjerne bare en enkelt:  getchar();
       ('gets' derimot leser '\n', men den blir ikke med i lagret tekst/streng)


    OGSÅ KONKLUSJON:  MYE RART KAN SKJE VED INNLESNING!  :-)
                      (Kjør f.eks. dette programmet, og skriv en bokstav
                       når programmet helt i begynnelsen ber om et heltall.)
*/
