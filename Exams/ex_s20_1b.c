/**
 *   Løsning til kontinuasjonseksamen i GrProg (i C), august 2020, oppgave 1B.
 *
 *   @file     EX_S20_1B.CPP
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>


/**
 *  Skriver alle bokstavene i en char-array, med bindestrek mellom hver.
 *
 *  @param   bokstaver  -  Bokstavene som skal skrives ut en og en
 *  @param   n          -  Antall bokstaver i char-arrayen
 */
void skrivBokstaverMedBindestreker(const char bokstaver[], const int n) {
    for (int i = 0;  i < n;  i++) {
        printf("%c", bokstaver[i]);
        if (i < n-1) printf("-");
    }
    printf("\n");
}


/**
 *   Hovedprogrammet:
 */
int main() {

    printf("\n\n");

    skrivBokstaverMedBindestreker("TAKTEKKERSPESIALIST", 19);

    skrivBokstaverMedBindestreker("DAbleDETikkeSOMMERFERIEpaaIKARIAiAAR", 36);

    printf("\n\n");
    return 0;
}