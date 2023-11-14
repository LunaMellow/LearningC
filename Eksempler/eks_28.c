/**
 *   Programeksempel nr 28 - Pekere - grunnleggende.
 *
 *   @file     EKS_28.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>              //  printf, scanf


/**
 *  Tidspunkt (med time, minutt og sekund).
 */
struct Tidspunkt  {
   int time,
       minutt,
       sekund;
};


/**
 *  Hovedprogrammet:
 */
int main ()  {
    int heltall = 17,    //  Lager to vanlige 'int'.
        heltall2;
                         //  Skriver ut ADRESSEN til der den er i memory:
    printf("ADRESSEN til 'heltall':  %i\n\n", &heltall);

    int*  intPeker;      //  Lager PEKER til et heltall.
                         //  PEKER ER EN VARIABEL SOM KAN INNEHOLDE EN
                         //    MEMORYADRESSE. Som oftest (for v�r del f�r jul)
                         //    til int, float, char, bool eller struct.

    intPeker = &heltall;  // Lar pekeren bli inneholdende adr. til 'heltall'.
                          // Dvs, setter den til � PEKE P� 'heltall' i memory.

                          //  Skriver pekerens INNHOLD (adressen):
    printf("ADRESSEN/INNHOLDET i 'intPeker':  %i  (%#x)\n\n",
           intPeker, intPeker);

                              //  Det som ER der den peker (VERDIEN):
    printf("VERDIEN til 'intPeker':  %i\n\n", *intPeker);

    *intPeker = 79;           //  Gir ny VERDI til der det pekes!

                              //  Dermed endrer 'heltall' verdi !!!
    printf("VERDIEN til 'intPeker' OG 'heltall':  %i  %i\n\n",
           *intPeker, heltall);

    heltall2 = *intPeker;
    printf("Samme VERDI i alle tre:  %i  %i  %i\n\n",
           *intPeker, heltall, heltall2);


// ***************************************************************************

    char  tegn = 'W';         //  Kan ogs� gj�re det samme med 'char':
    char* charPeker = &tegn;

    printf("Tegnet er:  %c  %c\n\n", tegn, *charPeker);

    *charPeker = 'E';
    printf("Tegnet er:  %c  %c\n\n", tegn, *charPeker);


// ***************************************************************************

    printf("Skriv inn et tegn:       ");    //  Endrer 'tegn' p� vanlig m�te:
    scanf(" %c", &tegn);
    printf("Tegnet er:  %c  %c\n\n", tegn, *charPeker);

    printf("Skriv inn enda et tegn:  ");    //  Endrer 'tegn' vha. pekeren;

    scanf(" %c", charPeker);                //  NB - NB:  IKKE '&' FORAN !!!
    printf("Tegnet er:  %c  %c\n\n", tegn, *charPeker);


//  KAN selvsagt ogs� ha pekere til ENKELT-floater og -booler.


// ***************************************************************************
                                    //  N�:  Struct og pekere:
    struct Tidspunkt  tid =  { 17, 42, 13 };
    struct Tidspunkt* tp = &tid;
                                    //  En m�te � skrive ut verdiene:
    printf("Tiden er:  %i:%i:%i\n\n", tid.time, tid.minutt, tid.sekund);

                                    //  Utskrift vha. pekeren:
    printf("Tiden er:  %i:%i:%i\n\n", (*tp).time, (*tp).minutt, (*tp).sekund);

                                    //  MEST VANLIG m�te ('->') n�r har peker:
    printf("Tiden er:  %i:%i:%i\n\n", tp->time, tp->minutt, tp->sekund);


    printf("Endre time (%i) til:  ", tp->time);
    scanf(" %i", &(tp->time));      //  NB:  'tp->time' er en INT, m� derfor
                                    //       som hele tiden hittil ta
                                    //       adressen ('&') til dette.
    printf("Tiden er n�:  %i:%i:%i\n\n", tp->time, tp->minutt, tp->sekund);


// ***************************************************************************

/*  OPPSUMMERT hittil:

      <type>  <variabel>;                   //  Vanlig variabel (som hittil).

      <type>* <peker>;                      //  Lager en peker-variabel til
                                            //    en eller annen <type>.
      <peker> = &<variabel>;                //  Peker f�r INNHOLD (blir inne-
                                            //    holdende adressen til noe).
      *<peker> = <verdi av typen 'type'>;   //  Peker f�r annen VERDI
                                            //    (det tilpekte endrer verdi).

      Eksempel:
         int  tall;
         int* iPeker;
         iPeker = &tall;
         *iPeker = 42;
         printf("%i", *iPeker);
*/

// ***************************************************************************

/*  CONST OG PEKERE (side 251-252):
    const int* p;     //  Det 'p' peker til (VERDIEN) kan IKKE endres.
                      //    Men, 'p' selv m� gjerne settes til � peke p�
                      //    noe annet (inneholde en ny/annen adresse)!

    int* const p;     //  Pekeren 'p' kan IKKE settes til � peke p� noe annet.
                      //    Men, VERDIEN (det den peker til) m� gjerne endres!

   const int* const p; // Hverken 'p' eller det tilpekte (VERDIEN) kan endres.
*/

    return 0;
}
