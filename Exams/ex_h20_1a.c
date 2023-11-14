/**
 *   Løsningsforslag til eksamen i GrProg (i C), november 2020, oppgave 1A.
 *
 *   @file     EX_H20_1A.CPP
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>
#include <stdbool.h>


/**
 *  Ber om og leser 3x tegn, skriver dem baklengs ut med '-' i mellom,
 *  og returnerer om noen tegn var like eller ei.
 *
 *  @return   Om noen av tre innleste tegn er like eller ei
 */
bool lesSkrivOgReturnerOmTegnErLike() {
    char tegn1, tegn2, tegn3;
    printf("Skriv inn tre tegn:  ");
    scanf(" %c %c %c", &tegn1, &tegn2, &tegn3);
    printf("\nTegnene baklengs: %c-%c-%c\n", tegn3, tegn2, tegn1);
    if (tegn1 == tegn2)  return true;
    if (tegn1 == tegn3)  return true;
    if (tegn2 == tegn3)  return true;
    return false;

//  Eller, fire siste linjer enda mer kompakt:
//    return (tegn1 == tegn2  ||  tegn1 == tegn3  ||  tegn2 == tegn3);
}


/**
 *   Hovedprogrammet:
 */
int main() {

    printf("\n\n%s tegn var like.\n\n",
            (lesSkrivOgReturnerOmTegnErLike()? "" : "ingen"));

    return 0;
}
