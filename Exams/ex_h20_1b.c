/**
 *   Løsningsforslag til eksamen i GrProg (i C), november 2020, oppgave 1B.
 *
 *   @file     EX_H20_1B.CPP
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>
#include <ctype.h>        //  toupper


/**
 *  Finner og returnerer TOTALantallet av noen få ulike bokstaver
 *  i en lengre tekst.
 *
 *  @param   tekst      -  Teksten det skal letes etter bokstaver i
 *  @param   n          -  Antall tegn i 'tekst'
 *  @param   bokstaver  -  Enkelt-bokstavene det skal letes etter i 'tekst'
 *  @param   m          -  Antall ulike tegn i 'bokstaver'
 *  @return  TOTALforekomsten av de ulike bokstavene i 'bokstaver' i 'tekst'
 */
int forekomstAvBokstaver(const char tekst[], const int n,
                         const char bokstaver[], const int m) {
    int i, j, antall = 0;
    for (i = 0;  i < m;  i++)
        for (j = 0;  j < n;  j++)
           if (toupper(bokstaver[i]) ==  toupper(tekst[j])) antall++;

    return antall;
}


/**
 *   Hovedprogrammet:
 */
int main() {

  printf("\n\nAntall forekomster av 'aerst' i ");
  printf("'Epler og bAnaneR smakEr Som ofTesT megEt godT':  %i\n\n",
         forekomstAvBokstaver("Epler og bAnaneR smakEr Som ofTesT megEt godT",
                               45, "aerst", 5));

  return 0;
}
