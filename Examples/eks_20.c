/**
 *   Programeksempel nr 20 - St�rre programeksempel.
 *
 *   som vektlegger:
 *     - l�kker (for, do, while)
 *     - valg (if  (, switch))
 *     - arrayer (int, char)
 *     - const
 *
 *   Programmet:
 *     - inneholder navn og priser for varene i en liten enkel (strand)kiosk
 *     - leser en kundes varekj�p og antall
 *     - skriver til slutt kundens kvittering (oppsummering av hele kj�pet)
 *     - behandler evt. flere kunder etter hverandre
 *
 *   @file     EKS_20.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>                //  printf, scanf
#include <ctype.h>                //  toupper

const int MAXKJOP   = 10;         ///<  Max. antall ULIKE kj�p av EN kunde.
const int MAXANTALL = 10;         ///<  Max. antall av EN vare.
const int MAXVARER  = 20;         ///<  Max. antall ulike varer.

/**
 *  Hovedprogrammet:
 */
int main() {
    char valg,                   //  Brukervalg til om fortsette eller ei.
         varer[][20] =           //  Navn p� ALLE aktuelle varer i kiosken:
            { "Banan", "Eple", "Popcorn", "Potetgull", "Ostepop",
              "Kvikk-lunsj", "Japp", "Hobby", "Melkesjokolade", "Firkl�ver",
              "Kroneis", "Lollipop", "Sandwich", "Pin-Up", "B�tis",
              "Sm�godt", "S�te drops", "Salte drops", "VG", "Dagbladet" };
                                 //  Stk.prisen p� ALLE varene:
    int  pris[] = { 5,  5, 20, 25, 20, 20, 20, 20, 20, 20,
                   30, 20, 25, 20, 30, 15, 20, 20, 30, 30 };
    int  nummer,                 //  Valgt varenummer (0-MAXVARER).
         antall,                 //  Antall av varen (1-MAXANTALL).
         antallVarerKjopt,       //  TOTALT antall varer kj�pt av EN kunde.
         hvaKjopt[MAXKJOP],      //  INDEKSEN i 'varer' for varene kj�pt.
         antallKjopt[MAXKJOP],   //  Antallet av kj�p nr.i.
         vareTotal,              //  Totalsummen for EN vare (hos kunden).
         kundeTotal;             //  Totalsummen for ALLE varene (hos kunden).

    do {
        antallVarerKjopt = 0;    //  MEGET viktig at disse nullstilles
        kundeTotal = 0;          //     pr.kunde!

        printf("Kj�p av vare nr:\n");      //  Skriver vare-menyen:
        for (int i = 0;  i < MAXVARER;  i++)
            printf("%2i: %2i kr - %s\n", i+1, pris[i], varer[i]);
        printf(" 0: AVSLUTT denne kundens kj�p\n\n");

        do {                     //  Leser aktuelt varenummer:
           printf("Varenummer (0-%i):  ", MAXVARER);
           scanf("%i", &nummer);       //  Leser LOVLIG varenummer:
        } while (nummer < 0 || nummer > MAXVARER);
                             //  Ikke avslutte, eller ikke oppn�dd max.antall.
                             //  Behandler da EN og EN vare for kunden:
        while (nummer != 0)  {
           do {
              printf("\tAntall kj�pt av %-15s (1-%i):  ",
              varer[nummer - 1], MAXANTALL);
              scanf("%i", &antall);        //  Leser LOVLIG vareantsall:
           } while (antall <= 0 || antall > MAXANTALL);

                                           //  LAGRER UNNA HELE KJ�PET:
           hvaKjopt[antallVarerKjopt] = nummer - 1;  //  Varens indeks.
           antallKjopt[antallVarerKjopt] = antall;   //  Antallet.
           antallVarerKjopt++;                       //  Totalt kj�pt.

           if (antallVarerKjopt < MAXKJOP)  {
              do {                         //  Leser aktuelt varenummer igjen:
                 printf("Varenummer (0-%i):  ", MAXVARER);
                 scanf("%i", &nummer);     //  Leser LOVLIG varenummer:
              } while (nummer < 0 || nummer > MAXVARER);
           } else
              nummer = 0;
        }
                                              //  Skriver slutt-kvittering:
        printf("\nKvittering/faktura:  \n");
        for (int i = 0;  i < antallVarerKjopt;  i++) {  //  For hvert kj�p:
            vareTotal = pris[hvaKjopt[i]] * antallKjopt[i]; //Regner varepris.
            kundeTotal += vareTotal;                   // Oppsummerer totalen.
            printf("%2i stk av %-15s a kr.%3i  =  %4i\n",
                   antallKjopt[i], varer[hvaKjopt[i]], // Skriver EN linje p�
                   pris[hvaKjopt[i]], vareTotal);      //   kvitteringe.
        }
        printf("\n\t\t\t\tTOTALT: %i", kundeTotal);    // Skriver totalsummen.

        printf("\n\nEkspedere enda en kunde (J/n):  "); //  En kunde til?
        scanf(" %c", &valg);   valg = toupper(valg);
        printf("\n\n");
    } while (valg != 'N');                         //  S� lenge annet enn 'N'.

    return 0;
}
