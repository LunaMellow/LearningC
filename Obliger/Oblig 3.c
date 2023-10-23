
/**     Oblig 3
 *
 *      Program description:
 *          - This happens in the code
 *          - This happens in the code
 *          - This happens in the code
 * 
 *      @file Oblig 3.c
 *      @date 19/10/2023
 *
 *      @author Luna S.
 *      @alias LunaMellow
 */

// Includes
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

// Const variables
const int STRLEN = 80; ///< Max.textlength.
const int ANTINT = 20; ///< the length of the int-array

// Declare functions
int antallIArray(int tall[], const int n, const int min, const int max);
void fyllArray(int tall[], const int n);
char lesKommando();
int lesTall(const char tekst[], const int min, const int max);
void lesTekst(const char ledetekst[], char tekst[]);
bool sjekkTekst(const char tekst[]);
void skrivMeny();

/**
 *      Main Program starts here
 */

int main() {
    // Declare variables
    char kommando;
    int tallene[ANTINT];
    char teksten[STRLEN];
    skrivMeny();
    kommando = lesKommando();
    while (kommando != 'Q') {
        switch (kommando) {
            case 'F': fyllArray(tallene, ANTINT); break;
            case 'A': printf("\n\tAntall i arrayen i intervallet 0-2000: %i\n",
                             antallIArray(tallene, ANTINT, 0, 2000)); break;
            case 'L': lesTekst("Postnummer og -sted", teksten); break;
            case 'S': printf("\n\tTeksten er%s et gyldig postnr og -sted.\n",
                             ((!sjekkTekst(teksten)) ? " IKKE" : "")); break;
            default: skrivMeny(); break;
        }
        kommando = lesKommando();
    }
    return 0;
}

/**
 *  Leser og returnerer mengden tall (0-2000) i en array
 *
 *  @param   tall   - Ledetekst til brukeren når ber om input/et tall
 *  @param   n      - Minimum for innlest og godtatt tallverdi
 *  @param   min    - Minimum for innlest og godtatt tallverdi
 *  @param   max    - Maksimum for innlest og godtatt tallverdi
 *
 *  @return  Mengden tall (0-2000) i tall[]
 */
int antallIArray(int tall[], const int n, const int min, const int max) {
    int teller = 0;
    for (int i = 0; i < n; i++) {
        if (tall[i] < 2000 && tall[i] > 0) {
            teller++;
        }
    }
    return teller;
}

/**
 *  Reads and writes user input integer (0-2000) to an array
 *
 *  @param   tall   - Ledetekst til brukeren når ber om input/et tall
 *  @param   n      - Minimum for innlest og godtatt tallverdi
 *  @param   min    - Minimum for innlest og godtatt tallverdi
 *  @param   max    - Maksimum for innlest og godtatt tallverdi
 *
 * */
void fyllArray(int tall[], const int n) {
    for (int i = 0; i < n; i++) {
        tall[i]=lesTall("Skriv et tall",0,2000);
    }
}

/**
 *  Leser og returnerer ett (upcaset) tegn.
 *
 *  @return  Ett (upcaset) tegn.
 */
char lesKommando() {
    char tegn;
    printf("Skriv kommando:  ");
    scanf(" %c", &tegn);   getchar();
    return (toupper(tegn));
}

/**
 *  Leser og returnerer et tall mellom to gitte grenser.
 *
 *  @param   tekst  - Ledetekst til brukeren når ber om input/et tall
 *  @param   min    - Minimum for innlest og godtatt tallverdi
 *  @param   max    - Maksimum for innlest og godtatt tallverdi
 *
 *  @return  Godtatt verdi i intervallet 'min' - 'max'
 */
int lesTall(const char tekst[], const int min, const int max) {
    int tall;
    do  {
        printf("\t%s (%i-%i):  ", tekst, min, max);
        scanf("%i", &tall);     getchar();
    } while (tall < min  ||  tall > max);
    return tall;
}

/**
 *  Leser tekst inn i medsendt char-array/tekst/string.
 *
 *  @param   ledetekst  - Ledetekst som utskrift til brukeren om hva lese inn
 *  @param   tekst      - char-array som fylles med innlest tekst
 */
void lesTekst(const char ledetekst[], char tekst[]) {
    printf("\t%s:  ", ledetekst);
    gets(tekst);                    //  Updates ORIGINAL/actual parameter.
}

bool sjekkTekst(const char tekst[]) {

}
void skrivMeny() {

}