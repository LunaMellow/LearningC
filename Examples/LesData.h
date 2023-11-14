/**
 *   Enkel verktøykasse for å lese:  tegn,  tall  og  tekst.
 *
 *   @file     LesData.H
 *   @author   Frode Haug, NTNU
 */


#if !defined(__LESDATA_H)
#define  __LESDATA_H


#include <ctype.h>              //  toupper
#include <stdio.h>              //  printf, scanf
#include <stdlib.h>             //  sizeof, malloc
#include <string.h>             //  strlen, strcpy


char  lesChar(const char* t);
float lesFloat(const char* t, const float min, const float max);
int   lesInt(const char* t, const int min, const int max);
char* lagOgLesText(const char* t);
void  lesText(const char* t, char* tekst, const int len);


/**
 *  Leser og returnerer ett (upcaset) tegn.
 *
 *  @param   t  - Ledetekst til brukeren når ber om ett tegn
 *
 *  @return  Ett (upcaset) tegn.
 */
 char lesChar(const char* t)  {
     char tegn;
     printf("%s:  ", t);
     scanf(" %c", &tegn);   getchar();
     return (toupper(tegn));
}


/**
 *  Leser og returnerer et flyttall mellom to gitte grenser.
 *
 *  @param   t    - Ledetekst til brukeren når ber om input/et tall
 *  @param   min  - Minimum for innlest og godtatt tallverdi
 *  @param   max  - Maksimum for innlest og godtatt tallverdi
 *
 *  @return  Godtatt verdi i intervallet 'min' - 'max'
 */
float lesFloat (const char* t, const float min, const float max)  {
   float tall;
   do  {
     printf("%s (%.2f - %.2f):  ", t, min, max);
     scanf("%f", &tall);     getchar();
   } while (tall < min  ||  tall > max);
   return tall;
}


/**
 *  Leser og returnerer et heltall mellom to gitte grenser.
 *
 *  @param   t    - Ledetekst til brukeren når ber om input/et tall
 *  @param   min  - Minimum for innlest og godtatt tallverdi
 *  @param   max  - Maksimum for innlest og godtatt tallverdi
 *
 *  @return  Godtatt verdi i intervallet 'min' - 'max'
 */
int lesInt(const char* t, const int min, const int max)  {
   int tall;
   do  {
     printf("%s (%i - %i):  ", t, min, max);
     scanf("%i", &tall);     getchar();
   } while (tall < min  ||  tall > max);
   return tall;
}


/**
 *  Allokerer memory og returnerer peker til en innlest tekst.
 *
 *  @param   t  - Peker til ledetekst om hva som skal leses inn
 *
 *  @return  Peker til nyopprettet og datafylt tekst
 *           NOTE:  MÅ huske å si 'free' om dette!
 *
 *  @see  lesText(...)
 */
char* lagOgLesText(const char* t)  {
   char buffer[200];               //  Hjelpebuffer til å lese teksten.
   char* temp;                     //  Returnerende innlest tekst.

   lesText(t, buffer, 200);        //  Leser teksten.
                                   //  Allokerer EKSAKT NOK plass til teksten:
   temp = (char*) malloc((strlen(buffer)+1) * sizeof(char));

   if (temp)  {                    //  Allokeringen lyktes:
      strcpy(temp, buffer);        //  Kopierer inn teksten.
      return temp;                 //  Returnerer opprettet og fylt tekst.
   } else  {                       //  Allokeringen mislyktes.
      printf("FEIL i 'lagOgLesText':  Memoryallokering mislyktes!\n");
      return NULL;
   }
}


/**
 *  Leser tekst inn i tilpekt memoryområde med char'er.
 *
 *  @param   t      - Peker til ledetekst om hva som skal leses inn
 *  @param   tekst  - Peker til memoryområdet med char'er
 *  @param   len    - Max. lengde på innlest tekst
 */
void lesText(const char* t, char* tekst, const int len)  {
  printf("%s:  ", t);
  fgets(tekst, len, stdin); // Oppdaterer tilpekte char'er (derfor ORIGINALEN)
  tekst[strlen(tekst)-1] = '\0';  //  Tar vekk avsluttende innlest '\n'.
}

#endif
