/**
 *   Løsning til kontinuasjonseksamen i GrProg (i C), august 2022, oppgave 1B.
 *
 *   @file     EX_S22_1B.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>
#include <stdbool.h>
#include <string.h>


struct Ferie {
  char hvor[30];
  int  antD, antP;
};


void S22Funk1(const struct Ferie* f)  {
  printf("%s, %i dager, %i personer\n", f->hvor, f->antD, f->antP);
}


int S22Funk2(const struct Ferie f1, const struct Ferie f2)    {
  return ((f1.hvor[1] > f2.hvor[3]) ? 17 : 1);
}


bool S22Funk3(const struct Ferie* f1, const struct Ferie* f2)   {
  return (strcmp(f1->hvor, f2->hvor) &&  f1->antP == f2->antP);
}


struct Ferie* S22Funk4(const struct Ferie f1)  {
   struct Ferie* f2 = (struct Ferie*) malloc(sizeof(struct Ferie));
   strcpy(f2->hvor, f1.hvor);  f2->antD = f1.antD + 2;  f2->antP = 1;
}


int main() {
    struct Ferie  ferie1 = { "Hellas",   21, 2 },
                  ferie2 = { "Kroatia",  14, 8 },
                  ferie3 = { "Stavern",   7, 2 };
    struct Ferie* ferie4;

    S22Funk1(&ferie2);
    printf("%i\n", S22Funk2(ferie1,   ferie2));
    printf("%i\n", S22Funk3(&ferie1, &ferie3));
    ferie4 = S22Funk4(ferie3);   S22Funk1(ferie4);
    printf("%i\n", S22Funk3(S22Funk4(ferie1), &ferie3));

    return 0;
}



//  Utskrift:  Kroatia, 14 dager, 8 personer
//             17
//             1
//             Stavern, 9 dager, 1 personer
//             0
