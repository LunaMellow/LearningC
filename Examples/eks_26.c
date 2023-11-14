/**
 *   Programeksempel nr 26 - Struct - som parametre til og retur fra funksjoner,
 *                                    samt sammensatte struct'er og initiering av slike.
 *
 *   @file     EKS_26.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>              //  printf, scanf


/**
 *  Tidspunkt (med time, minutt og sekund).
 */
struct Tidspunkt  {
   int time,
       minutt,
       sekund;
};


/**
 *  Tidsangivelse (med både dagnavn og tidspunkt).
 */
struct Tidsangivelse  {
   char   dagNavn[10];
   struct Tidspunkt tp;         //  Struct inni struct!
};


struct Tidspunkt differanse(const struct Tidspunkt t, const struct Tidspunkt t2);
int    lesTall(const char tekst[], const int min, const int max);
void   lesTekst(const char ledetekst[], char tekst[]);
void   skrivTid(const struct Tidspunkt t);
struct Tidspunkt summer(const struct Tidspunkt t, const struct Tidspunkt t2);
void   summerOgSkriv(const struct Tidspunkt t, const struct Tidspunkt t2);


/**
 *  Hovedprogrammet:
 */
int main ()  {
   struct Tidspunkt  tid = { 14, 4, 8 },    //  Definerer 3x structer,
                     tid2, tid3;            //    initierer kun den ene.

   printf("\n'tid':   ");

   skrivTid(tid);                           //  Skriver initiert struct.

   printf("\n\n'tid2' (\"søppel\"):   ");

   skrivTid(tid2);                          //  Skriver tilfeldig "søppel".


//****************************************************************************

   printf("\n\n\nData til 'tid2':\n");      //  Fyller 'tid2' med data:
   tid2.time   = lesTall("Time  ",  0, 200);
   tid2.minutt = lesTall("Minutt ", 0,  59);
   tid2.sekund = lesTall("Sekund ", 0,  59);

   printf("\n\n'tid' + 'tid2' er:\n\t");

   summerOgSkriv(tid, tid2);                //  Summerer OG SKRIVER 2x struct.


//****************************************************************************

   tid3 = summer(tid, tid2);                //  Summerer kun, og får returnert
                                            //    en struct med svaret/summen.
   printf("\n\n'tid' + 'tid2' er altså:\n\t");
   skrivTid(tid);   printf(" + ");          //  Skriver selv de 3x structene:
   skrivTid(tid2);  printf(" = ");
   skrivTid(tid3);


//****************************************************************************

   tid3 = differanse(tid, tid2);         //  Får returnert POSITIV differanse.

   printf("\n\n'tid' - 'tid2' er:\n\t");
   skrivTid(tid);   printf(" - ");          //  Skriver selv de 3x structene:
   skrivTid(tid2);  printf(" = ");
   skrivTid(tid3);


//****************************************************************************

                         //  Definering og INITIERING av array med structer:
 struct Tidspunkt tider[3] = { { 23, 17, 37 }, { 4, 51, 19 }, { 7, 16, 27 } };

//                       NB:  KAN også initialisere bare enkelte datamedlemmer
//                            eller i vilkårlig rekkefølge: side 178-181
//                            Men, vi skal IKKE bruke denne noe (særlig).


//  Litt "leking" med denne arrayen og de allerede ferdiglagde funksjonene:

   printf("\n\n\n'tider[0]':   "); skrivTid(tider[0]);
   printf("\n'tider[1]':   ");     skrivTid(tider[1]);
   printf("\n'tider[2]':   ");     skrivTid(tider[2]);


   printf("\n\n'tider[0]' + 'tider[1]' er:\n\t");
   summerOgSkriv(tider[0], tider[1]);

   tid3 = summer(tider[1], tider[2]);
   printf("\n\n'tider[1]' + 'tider[2]' er:\n\t");
   skrivTid(tider[1]);  printf(" + ");
   skrivTid(tider[2]);  printf(" = ");
   skrivTid(tid3);

   tid3 = summer(tider[1], tid2);
   printf("\n\n'tider[1]' + 'tid2' er:\n\t");
   skrivTid(tider[1]);  printf(" + ");
   skrivTid(tid2);      printf(" = ");
   skrivTid(tid3);

   tid3 = differanse(tider[0], tider[2]);
   printf("\n\n'tider[0]' - 'tider[2]' er:\n\t");
   skrivTid(tider[0]);  printf(" - ");
   skrivTid(tider[2]);  printf(" = ");
   skrivTid(tid3);

   tid3 = differanse(tider[2], tider[0]);
   printf("\n\n'tider[2]' - 'tider[0]' er altså:\n\t");
   skrivTid(tider[2]);  printf(" - ");
   skrivTid(tider[0]);  printf(" = ");
   skrivTid(tid3);


//****************************************************************************

   struct Tidsangivelse ta;                   //  En enkelt sammensatt struct.

   lesTekst("\n\n\tUkedag", ta.dagNavn);      //  Innlesing av data til denne:
   ta.tp.time    = lesTall("Time  ", 0, 200);
   ta.tp.minutt  = lesTall("Minutt ", 0,  59);
   ta.tp.sekund  = lesTall("Sekund ", 0,  59);

   printf("\n'ta' er:  ");                    //  Skriver structens data:
   printf("%s  ", ta.dagNavn);   skrivTid(ta.tp);  printf("\n\n");


                                              //  Definerer og INITIERER:
   struct Tidsangivelse ta2 =  { "Onsdag", { 18, 51, 9 } };

   printf("\n'ta2' er:  ");                   //  Skriver structens data:
   printf("%s  ", ta2.dagNavn);  skrivTid(ta2.tp);  printf("\n\n");


                     //  Definerer og INITIERER array av sammensatte structer:
   struct Tidsangivelse taer[4] =  { "Mandag",  { 14, 47, 17 },
                                     "Fredag" , {  7, 22, 58 },
                                     "Tirsdag", { 21, 39,  2 },
                                     "Lørdag",  { 23,  4, 49 } };

   for (int i = 0;  i < 4;  i++)  {           //  Skriver arrayens data:
      printf("\nTidsangivelse nr.%i:  %-8s  ", i+1, taer[i].dagNavn);
      skrivTid(taer[i].tp);
   }

    printf("\n\n");

    return 0;
}


/**
 *  Tar den POSITIVE differansen mellom to tidspunkt og returnerer svaret.
 *
 *  @param   t   - Tidspunkt nr.1
 *  @param   t2  - Tidspunkt nr.2
 *
 *  @return  Tidspunkt med POSITIV differanse mellom de to parametrene
 */
struct Tidspunkt differanse(const struct Tidspunkt t, const struct Tidspunkt t2)  {
   struct Tidspunkt temp;
   int sekundT  = t.time * 3600   +  t.minutt  * 60  + t.sekund,
       sekundT2 = t2.time * 3600  +  t2.minutt * 60  + t2.sekund,
       diff;

    diff = (sekundT > sekundT2) ? sekundT-sekundT2 : sekundT2-sekundT;

    temp.time   = diff / 3600;
    temp.minutt = (diff % 3600) / 60;
    temp.sekund = diff % 60;

    return temp;
}


/**
 *  Leser og returnerer et tall mellom to gitte grenser.
 *
 *  @param   tekst  - Ledetekst til brukeren når ber om input/et tall
 *  @param   min    - Minimum for innlest og godtatt tallverdi
 *  @param   max    - Maksimum for innlest og godtatt tallverdi
 *
 *  @return  Godtatt verdi i intervallet 'min - 'max'
 */
int lesTall(const char tekst[], const int min, const int max)  {
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
void lesTekst(const char ledetekst[], char tekst[])  {
  printf("\t%s:  ", ledetekst);
  gets(tekst);                    //  Oppdaterer ORIGINALEN/aktuell parameter.
}


/**
 *  Skriver tidspunk på formen:  tt:mm:ss.
 *
 *  @param   t  - Tidspunkt-struct
 */
 void skrivTid(const struct Tidspunkt t)  {
//  printf("%i:%i:%i", t.time, t.minutt, t.sekund);      //  Mest naturlige.

    printf("%2i:%.2i:%.2i", t.time, t.minutt, t.sekund); //  Bedre.
                                                 //  Eventuelt, mer manuelt:
//  printf("%2i:%s%i:%s%i", t.time, ((t.minutt < 10) ? "0":""), t.minutt,
//                                  ((t.sekund < 10) ? "0":""), t.sekund);
 }


/**
 *  Summerer to tidspunkt og returnerer svaret.
 *
 *  @param   t   - Tidspunkt nr.1
 *  @param   t2  - Tidspunkt nr.2
 *
 *  @return  Tidspunkt med summen av de to parametrene
 */
struct Tidspunkt summer(const struct Tidspunkt t, const struct Tidspunkt t2) {
   struct Tidspunkt temp;

   temp.time   = t.time   + t2.time;
   temp.minutt = t.minutt + t2.minutt;
   temp.sekund = t.sekund + t2.sekund;

   if (temp.sekund >= 60)  {  temp.sekund -= 60;   temp.minutt++;  }
   if (temp.minutt >= 60)  {  temp.minutt -= 60;   temp.time++;    }

   return temp;
}



/**
 *  Summerer to tidspunkt og skriver ut summen.
 *
 *  @param   t   - Tidspunkt nr.1
 *  @param   t2  - Tidspunkt nr.2
 */
void summerOgSkriv(const struct Tidspunkt t, const struct Tidspunkt t2)  {
   struct Tidspunkt sum;

   sum.time   = t.time   + t2.time;
   sum.minutt = t.minutt + t2.minutt;
   sum.sekund = t.sekund + t2.sekund;

   if (sum.sekund >= 60)  {  sum.sekund -= 60;   sum.minutt++;  }
   if (sum.minutt >= 60)  {  sum.minutt -= 60;   sum.time++;    }

   skrivTid(t);   printf(" + ");
   skrivTid(t2);  printf(" = ");
   skrivTid(sum);
}
