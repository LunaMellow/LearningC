/**
 *   Programeksempel nr 7 - Grunnleggende om char-array / tekst / streng.
 *
 *   @file     EKS_07.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>             //  printf

/**
 *  Hovedprogrammet:
 */
 int main ()  {
    char tekst[10];            //  Definerer uinitiert char-array.

    tekst[0] = 'x';            //  Initierer noen av elementene/skuffene:
    tekst[1] = '6';
    tekst[2] = '+';
    tekst[3] = 'R';
                               //  Skriver ut initierte elementer:
    printf("Tekst: %c %c %c %c\n", tekst[0], tekst[1], tekst[2], tekst[3]);


    tekst[6] = 'N';            //  Initierer andre av elementene/skuffene:
    tekst[7] = 'T';
    tekst[8] = 'N';
    tekst[9] = 'U';
                               //  Skriver ut nye initierte elementer:
    printf("Tekst: %c %c %c %c\n", tekst[6], tekst[7], tekst[8], tekst[9]);

                               //  Skriver ut uinitierte elementer:
    printf("Søppeltekst: %c %c\n", tekst[4], tekst[5]);

                               //  Skriver ut (ulovlig) utenfor arrayen:
    printf("FYDA!!! %c %c %c\n", tekst[10], tekst[11], tekst[12]);

                               //  Initierer meget manuelt char-array:
    char tekst2[] = { 'M', 'A', 'N', 'U'};
    char ch = 'u';

    printf("Mer tekst: %c%c%c%c", tekst2[0], tekst2[1], tekst2[2], tekst2[3]);
    printf("%c%c%c%c%c%c%c%c%c%c\n", ch, ch, ch, ch, ch, ch, ch, ch, ch, ch);

                               //  Kan heldigvis initiere char-arrayer slik:
    char tekst3[] = "Arsenal ruler!!!";

                               //  Skriver ut noen av bokstavene i teksten:
    printf("Bokstaver: %c %c %c\n", tekst3[3], tekst3[14], tekst3[11]);

                               //  Skriver HELE char-arrayen/teksten/strenger:
    printf("Hele teksten: %s\n", tekst3);

    tekst3[8] = 'k';
    tekst3[11] = tekst3[12] = tekst3[13];
    printf("Ny endret tekst: %s\n", tekst3);


//  NB:  'tekst3' inneholder totalt 16 tegn.
//       MEN VED SLIK INITIERING MED BRUK AV GÅSØYNE/ANFØRSELSTEGN
//       LEGGES DET AUTOMATISK TIL '\0' BAKERST. DERFOR ER TEKSTEN 17 LANG,
//       der tegnene (altså inkludert '\0') har indeksene 0-16.
//
//       (Mye mer om dette senere .....)

    tekst3[16] = 'X';          //  FYDA:  Overskriver avsluttende '\0' !!!
    printf("FYSJ OG FØY:  Ny merkelig tekst: %s\n", tekst3);


    return 0;
}
