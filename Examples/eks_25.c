/**
 *   Programeksempel nr 25 - Struct - grunnleggende, initialisering,
 *                           arrayer (inni og av/med).
 *
 *   @file     EKS_25.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>              //  printf, scanf
#include <stdbool.h>            //  bool, true, false
#include <ctype.h>              //  toupper
#include <string.h>             //  strcpy, strstr

#define   STRLEN        80      ///<  Max.tekstlengde.
const int ANTPERSONER = 10;     ///<  Max.antall person-structer,

                                //  DEKLARERER 2x struct'er:
/**
 *  Tidspunkt (med time, minutt og sekund).
 */
struct Tidspunkt  {
   int time,
       minutt,
       sekund;
};


/**
 *  Persondata (navn, adresse og fødselsdato).
 */
struct Person  {
   char navn[STRLEN],
        gateAdresse[STRLEN],
        postAdresse[STRLEN];
   int  fodselsDato;
};


int  lesTall(const char tekst[], const int min, const int max);
void lesTekst(const char ledetekst[], char tekst[]);
char lesValg();


/**
 *  Hovedprogrammet:
 */
int main ()  {
    struct Tidspunkt tid;       //  Definerer struct-variabel.

    tid.time   = 17;            //  Gir struct-medlemmene verdier:
    tid.minutt = 23;
    tid.sekund = 57;
                                //  Skriver structens innhold:
    printf("Tidspunktet er:  %i:%i:%i\n\n", tid.time, tid.minutt, tid.sekund);


    tid.time   = lesTall("Time  ", 0,23);    //  Gir medlemmene verdi vha.
    tid.minutt = lesTall("Minutt", 0,59);    //    en funksjon som returnerer
    tid.sekund = lesTall("Sekund", 0,59);    //    en verdi/et tall:
    printf("Tidspunktet er:  %i:%i:%i\n\n", tid.time, tid.minutt, tid.sekund);

                                             //  Kan bruke i valg/løkker:
    if (tid.time < 12) printf("Dette er natt eller før lunsj.\n\n");
    else printf("Dette er etter lunsj, ettermiddag eller kveld.\n\n");
                                             //  Kan bruke i (regne)uttrykk:
    printf("Antall sekunder siden midnatt:  %i\n\n",
           tid.time*3600 + tid.minutt*60 + tid.sekund);


    struct Tidspunkt tid2 = { 10, 49, 18};   //  DEFINERER OG INITIERER:
    printf("Tidspunktet er:  %i:%i:%i\n\n",
           tid2.time, tid2.minutt, tid2.sekund);


    tid = tid2;                              //  KAN KOPIERE EN HEL STRUCT!
    printf("Tidspunktet er:  %i:%i:%i\n\n",
           tid.time, tid.minutt, tid.sekund);


//****************************************************************************

    struct Person person;       //  Definerer struct-variabel
                                //  Gir struct-medlemmene verdier:
    strcpy(person.navn,        "Kåre Larsen");
    strcpy(person.gateAdresse, "Frognerveien 13B");
    strcpy(person.postAdresse, "0263 Oslo");
    person.fodselsDato = 19940212;
                               //  Skriver structens innhold:
    printf("Persondata:\n\t%s\n\t%s\n\t%s\n\t%i\n\n",
           person.navn,        person.gateAdresse,
           person.postAdresse, person.fodselsDato);
                               //  Skriver structens innhold, med annet format
    printf("Persondata:\n\t%s\n\t%s\n\t%s\n\t%i/%i-%i\n\n",   //  på datoen:
           person.navn,  person.gateAdresse,  person.postAdresse,
           person.fodselsDato%100, (person.fodselsDato/100)%100,
           person.fodselsDato/10000);

    lesTekst("Navn       ", person.navn);        //  Medlemmene får verdi vha.
    lesTekst("Gateadresse", person.gateAdresse); //    ulike funksjoner:
    lesTekst("Postadresse", person.postAdresse);
    person.fodselsDato = lesTall("Fødselsdato", 20000101, 20301231);
    printf("Persondata:\n\t%s\n\t%s\n\t%s\n\t%i\n\n",
           person.navn,         person.gateAdresse,
           person.postAdresse,  person.fodselsDato);

                                //  Definerer og INITIERER:
    struct Person person2 = { "Jo Berg", "Wibesgate 7", "5200 0s", 19930422};
    printf("Persondata:\n\t%s\n\t%s\n\t%s\n\t%i\n\n",
           person2.navn,         person2.gateAdresse,
           person2.postAdresse,  person2.fodselsDato);


    person = person2;           //  KOPIERER en HEL struct, INKL. CHAR-ARRAY!
    printf("Persondata:\n\t%s\n\t%s\n\t%s\n\t%i\n\n",
           person.navn, person.gateAdresse, person.postAdresse,
           person.fodselsDato);


//****************************************************************************

    struct Person personer[ANTPERSONER];    //  ARRAY AV/MED STRUCTER!
    int    antPers = 0;                     //  Antall person-structer brukt.
    char   valg;                            //  Brukerens valg/ønske.
    bool   funn;                            //  Om funn/utskrift har skjedd.


    printf("Person nr.%2i:\n", antPers+1);
    lesTekst("Navn       ", personer[0].navn);   //  Medlemmene får verdi vha.
    lesTekst("Gateadresse", personer[0].gateAdresse);  //    ulike funksjoner:
    lesTekst("Postadresse", personer[0].postAdresse);
    personer[0].fodselsDato = lesTall("Fødselsdato", 20000101, 20301231);
    antPers++;                              //  Antall personer lagt inn økes.

    printf("\nPersondata:\n\t%s\n\t%s\n\t%s\n\t%i\n", // Skriver data om nr.0:
           personer[0].navn, personer[0].gateAdresse,
           personer[0].postAdresse, personer[0].fodselsDato);


    do  {
      printf("\nPerson nr.%2i:\n", antPers+1);   //  Medlemmene får verdi vha.
      lesTekst("Navn       ", personer[antPers].navn); //    ulike funksjoner:
      lesTekst("Gateadresse", personer[antPers].gateAdresse);
      lesTekst("Postadresse", personer[antPers].postAdresse);
      personer[antPers].fodselsDato =
                                   lesTall("Fødselsdato", 20000101, 20301231);
      antPers++;                            //  Antall personer lagt inn økes.
      valg = lesValg();                     //  Registrere flere og NOK PLASS:
    } while (valg == 'J' &&  antPers < ANTPERSONER);

    printf("\n\n");

    for (int i = 0;  i < antPers; i++)      //  Skriver data om ALLE innlest:
      printf("Persondata om nr.%2i:\n\t%s\n\t%s\n\t%s\n\t%i\n", i+1,
             personer[i].navn, personer[i].gateAdresse,
             personer[i].postAdresse, personer[i].fodselsDato);


    funn = false;
    printf("\n\nPersoner født før den 10. i en måned:  ");
    for (int i = 0;  i < antPers; i++)       //  Skriver personer født før den
      if (personer[i].fodselsDato % 100 < 10)  {   //  10. i en måned:
         funn = true;                        //  Funn - utskrift forekommet.
         printf("%i  ", i+1);
      }
    if (!funn) printf("Ingen!");             //  Ingen funn/utskrift.


    funn = false;
    printf("\n\nPersoner med 'er' i navnet:\n");
    for (int i = 0;  i < antPers; i++)       //  Skriver personer med
      if (strstr(personer[i].navn, "er")) {  //    'er' i navnet:
         funn = true;                        //  Funn - utskrift forekommet.
         printf("\t%i:  %s\n", i+1, personer[i].navn);
      }
    if (!funn) printf("\tIngen!");           //  Ingen funn/utskrift.


    printf("\n\n");

    return 0;
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
 *  Leser og returnerer ett (upcaset) tegn.
 *
 *  @return  Ett (upcaset) tegn.
 */
 char lesValg()  {
     char tegn;
     printf("\nLese en person til (j/N):  ");
     scanf(" %c", &tegn);   getchar();
     return (toupper(tegn));
}
