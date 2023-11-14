/**
 *   L�sningsforslag til oppgave nr 24.
 *
 *   @file	  OPPG_24.C
 *   @author  Frode Haug, NTNU
 */


#include <stdio.h>                 //  printf, scanf

/**
 *  Enum for om skal returnere minste eller st�rste verdi fra en funksjon:
 */
enum Hente  { Minst,  Storst };

int hentMinsteVerdi(const int n);
int hentStorsteVerdi(const int n);
int hentVerdi(const char s[], const enum Hente ms, const int n);

/**
 *  Hovedprogrammet:
 */
int main()  {
    int verdi;

    verdi = hentMinsteVerdi(5);
    printf("\nMinste verdi innskrevet:   %8i\n\n\n", verdi);

    verdi = hentStorsteVerdi(8);
    printf("\nSt�rste verdi innskrevet:  %8i\n\n\n", verdi);

    verdi = hentVerdi("Minste", Minst, 5);
    printf("\nMinste verdi innskrevet:   %8i\n\n\n", verdi);

    verdi = hentVerdi("St�rste", Storst, 8);
    printf("\nSt�rste verdi innskrevet:  %8i\n\n\n", verdi);


    return 0;
}


/**
 *  Returnerer minste verdi av de innskrevne.
 *
 *  @param   n     - Antall verdier som skal skrives inn av brukeren
 *
 *  @return  Minste verdi som er innskrevet
 */
int hentMinsteVerdi(const int n)  {
   int verdiHittil = 999999999,        //  Initierer til en STOR verdi.
       verdi;                          //  Innskrevet brukertall.

  printf("Minste verdi vil bli returnert. Skriv inn %i verdier:\n", n);

  for (int i = 1;  i <= n;  i++)  {    //  Leser �nsket antall tall:
      printf("\t%3i.verdi:  ", i);
      scanf("%i", &verdi);
      if (verdi < verdiHittil)         //  Ny minste verdi:
         verdiHittil = verdi;          //  Oppdaterer hittil minste.
  }
  return verdiHittil;                  //  Returnerer funnet minste verdi.
}


/**
 *  Returnerer st�rste verdi av de innskrevne.
 *
 *  @param   n     - Antall verdier som skal skrives inn av brukeren
 *
 *  @return  St�rste verdi som er innskrevet
 */
int hentStorsteVerdi(const int n)  {
   int verdiHittil = -999999999,       //  Initierer til en LITEN verdi.
       verdi;                          //  Innskrevet brukertall.

  printf("St�rste verdi vil bli returnert. Skriv inn %i verdier:\n", n);

  for (int i = 1;  i <= n;  i++)  {    //  Leser �nsket antall tall:
      printf("\t%3i.verdi:  ", i);
      scanf("%i", &verdi);
      if (verdi > verdiHittil)         //  Ny st�rste verdi:
         verdiHittil = verdi;          //  Oppdaterer hittil st�rste.
  }
  return verdiHittil;                  //  Returnerer funnet st�rste verdi.
}


/**
 *  Returnerer minste eller st�rste verdi (parameterstyrt) av de innskrevne.
 *
 *  @param   s   - Ord ('Minste'/'St�rste') i ledeteksten
 *  @param   ms  - Enum-verdien 'Minst'/'Storst'
 *  @param   n   - Antall verdier som skal skrives inn av brukeren
 *
 *  @return  Minste/st�rste verdi som er innskrevet
 */
int hentVerdi(const char s[], const enum Hente ms, const int n)  {
                                       //  Initierer til stor eller liten verdi,
                                       //    ut fra parameteren 'ms':
   int verdiHittil = ((ms == Minst) ? 999999999 : -999999999),
       verdi;                          //  Innskrevet brukertall.

  printf("%s verdi vil bli returnert. Skriv inn %i verdier:\n", s, n);

  for (int i = 1;  i <= n;  i++)  {    //  Leser �nsket antall tall:
      printf("\t%3i.verdi:  ", i);
      scanf("%i", &verdi);
      if ((ms == Minst && verdi < verdiHittil)  ||  //  Ny minste verdi ELLER
          (ms == Storst && verdi > verdiHittil))    //    ny st�rste verdi.
          verdiHittil = verdi;
  }
  return verdiHittil;                  //  Returnerer funnet verdi.
}
