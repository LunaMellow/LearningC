/**
 *   Løsningsforslag til oppgave nr 34.
 *
 *   @file	  OPPG_34.C
 *   @author  Frode Haug, NTNU
 */


#include <stdio.h>                 //  printf
#include <string.h>                //  strlen

void finnTegn(const char* t, char* f, char* m, char* s);


/**
 *  Hovedprogrammet:
 */
int main()  {
    char forste,                //  Definerer 3x char-variable som skal,
         midterste,             //    ved referanseoverføring, få verdier
         siste;                 //    fra en tekst.


    finnTegn("HiG", &forste, &midterste, &siste);

    printf("I teksten \"HiG\" er det\n");
    printf("første tegnet '%c', det midterste er '%c' og det siste er '%c'.\n\n",
           forste, midterste, siste);


    finnTegn("NTNU", &forste, &midterste, &siste);

    printf("I teksten \"NTNU\" er det\n");
    printf("første tegnet '%c', det midterste er '%c' og det siste er '%c'.\n\n",
           forste, midterste, siste);


    finnTegn("Noe særlig artigere blir det ikke", &forste, &midterste, &siste);

    printf("I teksten \"Noe særlig artigere blir det ikke\" er det\n");
    printf("første tegnet '%c', det midterste er '%c' og det siste er '%c'.\n\n",
           forste, midterste, siste);


    finnTegn("X", &forste, &midterste, &siste);

    printf("I teksten \"X\" er det\n");
    printf("første tegnet '%c', det midterste er '%c' og det siste er '%c'.\n\n",
           forste, midterste, siste);


    finnTegn("", &forste, &midterste, &siste);

    printf("I teksten \"\" er det\n");
    printf("første tegnet '%c', det midterste er '%c' og det siste er '%c'.\n\n",
           forste, midterste, siste);

    return 0;
}


/**
 *  Oppdaterer referanseoverførte variable med verdier ut fra medsendt tekst.
 *
 *  @param   t  - Aktuell tekst å hente tegn fra
 *  @param   f  - Det første tegnet i teksten
 *  @param   m  - Det midterste tegnet i teksten
 *  @param   s  - Det siste tegnet i teksten
 */
void finnTegn(const char* t, char* f, char* m, char* s)  {
   int len = strlen(t);  //  Finner tekstens lengde.
   if (len > 0)  {       //  Minst ett tegn i teksten:
      *f = *t;           //  Henter det første tegnet (element nt.0)
      *m = *(t+(len/2)); //  Henter det midterste tegnet.
      *s = *(t+len-1);   //  Henter det siste tegnet ('\0' er element nt.'len'!).
   } else                //  Tom/blank tekst:
     *f = *m = *s = ' '; //  Oppdateres med blank/space.
}
