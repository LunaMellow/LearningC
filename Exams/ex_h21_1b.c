/**
 *   Løsning til eksamen i GrProg (i C), november 2021, oppgave 1B.
 *
 *   @file     EX_H21_1B.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>
#include <stdbool.h>
#include <string.h>


struct Dose {
  char hva[30];
  int  dato;
};


void H21Funk1(const struct Dose d)  {
  printf("%s, satt den %i/%i-%i\n", d.hva,
                                d.dato%100,  (d.dato/100)%100,  d.dato/10000);
}


int H21Funk2(const struct Dose* d1, const struct Dose* d2)  {
  return ((d1->dato > d2->dato) ? d2->dato : d1->dato);
}


bool H21Funk3(const struct Dose d1, const struct Dose* d2)  {
  return (d1.hva[4] == d2->hva[5]);
}


int H21Funk4(const struct Dose* d1, const struct Dose* d2)  {
  return( (!strcmp(d1->hva, d2->hva)) ? d1->dato : d2->dato);
}


void H21Funk5(const struct Dose* d1, const struct Dose* d2, struct Dose* d3) {
  strcat(d3->hva, d2->hva);   strcat(d3->hva, d1->hva);
}


int main() {
    struct Dose dose1 = { "Pfizer",   210615},
                dose2 = { "Moderna",  210817},
                dose3 = { "Aquavit",  211224};

    H21Funk1(dose2);
    printf("%i\n", H21Funk2(&dose3, &dose1));
    printf("%i\n", H21Funk3(dose2,  &dose1));
    strcpy(dose2.hva, dose1.hva);
    printf("%i\n", H21Funk4(&dose2, &dose1));
    H21Funk5(&dose1, &dose2, &dose3);  H21Funk1(dose3);

    return 0;
}



//  Utskrift:  Moderna, satt den 17/8-21
//             210615
//             1
//             210817
//             AquavitPfizerPfizer, satt den 24/12-21
