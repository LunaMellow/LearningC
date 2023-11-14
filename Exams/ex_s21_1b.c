/**
 *   Løsningsforslag til kontinuasjonseksamen i GrProg (i C), august 2021, oppgave 1B.
 *
 *   @file     EX_S21_1B.CPP
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>


/**
 *  Oppdaterer ALLE element i en array med produktet fra en annen array,
 *  og returnerer den oppdaterte arrayens TOTALE sum.
 *
 *  @param   arr    -  Arrayen hvis element nr.i ganges med nr.i i 'arr2'
 *  @param   arr2   -  Arrayen som skal ganges med elementer i 'arr'
 *  @param   n      -  Antall elementer i BÅDE 'arr' og 'arr2'
 *  @return  TOTALsummen av ALLE de oppdaterte elementene i 'arr'
 */
int gangArrayer(int arr[], const int arr2[], const int n)  {
    int sum = 0;
    for (int i = 0;  i < n;  i++)
        sum += (arr[i] *= arr2[i]);

    return sum;
}


/**
 *  Skriver ut hele en arrays innhold på skjermen.
 *
 *  @param   arr  -  Arrayen som får skrevet ut hele sitt innhold på skjermen.
 *  @param   n    -  Antall elementer i 'arr'
 */
void skriv(const int arr[], int n)  {
  for (int i = 0;  i < n;  i++)
      printf("%4i", arr[i]);
}


/**
 *   Hovedprogrammet:
 */
int main() {
  int array[]  = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 },
      array2[] = { 2, 2, 2, 4, 4, 4, 8, 8, 8, 16, 16, 16, 32, 32, 32 };
  int summen;

  printf("\n'array'  før:    ");   skriv(array,  15);
  printf("\n'array2' før:    ");   skriv(array2, 15);

  summen = gangArrayer(array, array2, 15);

  printf("\n\n'array'  etter:  ");   skriv(array,  15);
  printf("\nTOTALsummen av 'array':  %i\n\n", summen);

  return 0;
}
