/**
 *   Løsning til eksamen i GrProg (i C), desember 2022, oppgave 1B.
 *
 *   @file     EX_H22_1B.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char farger[][10]= { "Blaa", "Gronn", "Gul", "Hvit", "Lilla", "Rod", "Svart"};

struct Lag  {
  char nvn[40];
  int  farge, antall;
};


void H22Funk1(const struct Lag lag)  {
  printf("%s, %s    ", lag.nvn, farger[lag.farge]);
}


int H22Funk2(const struct Lag* l1, const struct Lag* l2)  {
  return ((l2->antall > l1->antall) ? l2->antall : l1->antall);
}


bool H22Funk3(const struct Lag l1, const struct Lag* l2)  {
  return (!strcmp(farger[l1.farge], farger[l2->farge]));
}

struct Lag H22Funk4(const struct Lag l1, const struct Lag l2)  {
  struct Lag lag;
  strcpy(lag.nvn, l1.nvn);  lag.farge = l2.farge;
  lag.antall = (l1.antall > l2.antall) ? l1.antall : l2.antall;
  return lag;
}


int H22Funk5(const struct Lag* l1, const struct Lag* l2)  {
  if (strlen(l1->nvn) >= 4  &&  strlen(l2->nvn) >= 4)  {
     if (l1->nvn[0] > l2->nvn[0])  return 19;
     else {
        if (l2->nvn[2] < l1->nvn[1] &&  l1->nvn[2] < l2->nvn[1]) return 71;
        else if (l1->nvn[3] != l2->nvn[4]) return 94;
        else return 0;
     }
  } else return 0;
}



int main()  {
  struct Lag lag1 = { "Arsenal", 5, 60260 },
             lag2 = { "Tottenham", 3, 62850 },
             lag3 = { "Norwich", 2, 27244 },
             lag4 = { "Manchester United", 5, 74879 },
             lag5;

  H22Funk1(lag1);   H22Funk1(lag3);   H22Funk1(lag2);   printf("\n");

  printf("%i\n", H22Funk2(&lag1, &lag2));

  printf("%i %i\n", H22Funk3(lag2, &lag3), H22Funk3(lag4, &lag1));

  lag5 = H22Funk4(lag2, lag3);  H22Funk1(lag5);
                                printf("%i\n", lag5.antall);

  printf("%i %i\n", H22Funk5(&lag2, &lag3), H22Funk5(&lag1, &lag4));

  return 0;
}



//  Utskrift:  Arsenal, Rod     Norwich, Gul     Tottenham, Hvit
//             62850
//             0 1
//             Tottenham, Gul      62850
//             19 94
