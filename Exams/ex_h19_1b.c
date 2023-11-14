/**
 *   Løsning til eksamen i GrProg (i C), november 2019, oppgave 1B.
 *
 *   @file     EX_H19_1B.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct H19 {
  char txt1[10],  txt2[30];
  int  ant;
};

void H19Funk1(const struct H19 h) {
    printf("%s - %s, %ix", h.txt1, h.txt2, h.ant);  }

int H19Funk2(const struct H19* h1, const struct H19* h2) {
    return ((h1->ant < h2->ant) ? h2->ant : h1->ant);  }

bool H19Funk3(const struct H19 h1, const struct H19 h2) {
    return (h1.txt1[4] == h2.txt1[4]); }

void H19Funk4(struct H19* h1, const struct H19* h2, const struct H19* h3) {
    strcpy(h1->txt1, h2->txt1);  strcpy(h1->txt2, h3->txt2);  h1->ant = h3->ant - 100;  }

void H19Funk5(struct H19* h, const char* t)  {  strcat(h->txt2, t);  }

int main() {
    struct H19 emne1 = { "PROG1001", "GrProg", 150},
               emne2 = { "IMT1031",  "GrProg", 120},
               emne3 = { "IMT2021",  "AlgMet", 220};

    H19Funk1(emne1);   printf("   ");       H19Funk1(emne2);    printf("\n");
    emne1.ant = H19Funk2(&emne3, &emne2);   H19Funk1(emne1);    printf("\n");
    printf("%i\n", H19Funk3(emne2, emne3));
    H19Funk4(&emne1, &emne3, &emne2);       H19Funk1(emne1);    printf("\n");
    H19Funk5(&emne2, " - utgaar herved");   H19Funk1(emne2);    printf("\n");

    return 0;
}


//  Utskrift:  PROG1001 - GrProg, 150x   IMT1031 - GrProg, 120x
//             PROG1001 - GrProg, 220x
//             1
//             IMT2021 - GrProg, 20x
//             IMT1031 - GrProg - utgaar herved, 120x
