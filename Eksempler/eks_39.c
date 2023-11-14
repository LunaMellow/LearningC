/**
 *   Programeksempel nr 39 - Større programeksempel.
 *
 *   Eksemplet vektlegger mye av emnets totale pensum.
 *   Det er basert på oppg.nr.2 fra eksamen 10.august 2018
 *   i IMT1031 - Grunnleggende programmering.
 *
 *   Programmet holder orden på EN vinbutikks (enotek/vinotek)
 *   viner, årganger, antallet og de ulike vinenes produsenter.
 *
 *   Programmet:
 *     - skriver ut alt om alle produsentene på skjermen
 *     - skriver ALLE vinene fra en gitt produsent
 *     - legger inn (om mulig/plass) en ny produsent
 *     - legger inn en ny vin
 *     - endrer data om en vin (solgt/fått flasker av en (ny) årgang)
 *     - leser/skriver hele datastrukruren fra/til filer
 *
 *   @file     EKS_39.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>               //  printf, scanf, FILE
#include <stdlib.h>              //  sizeof, malloc, free
#include <string.h>              //  strcpy, strlen, strcmp
#include "LesData.h"             //  Verktøykasse for lesing av diverse data

#define MAXAAR            50     ///<  Max. årganger av EN vin.
#define MAXPRODUSENTER    50     ///<  Max. antall vinprodusenter.
#define MAXVINER         500     ///<  Max. antall viner.
const int STRLEN       =  60;    ///<  Max. tekstlengde.


/**
 *  Produsent (med navn, gate-/stedsadresse, mailadresse og telefon).
 */
struct Produsent  {
    char *navn,
         *adr,
         *mail;
    int  tlf;
};


/**
 *  Vin (med navn, antall årganger, årgangene, antall av hver årgang og 
 *  produsentnummer/-indeks).
 */
struct Vin  {
    char *navn;
    int  antallAarganger;
    int  aargang[MAXAAR],
         antall[MAXAAR];
    int  produsentNr;
};

void endreVin();
int  finnProdusent(const char* nvn);
void frigiAllokertMemory();
void lesFraFil();
void nyProdusent();
void nyVin();
void produsentLesData(struct Produsent* p, char* nvn);
void produsentLesFraFil(FILE* inn, struct Produsent* p);
void produsentSkrivData(const struct Produsent* p);
void produsentSkrivTilFil(FILE* ut, const struct Produsent* p);
void produsentSlettData(struct Produsent* p);
void skrivAlleProdusenter();
void skrivMeny();
void skrivTilFil();
void skrivVinerFraProdusent();
void vinEndre(struct Vin* v);
void vinLesFraFil(FILE* inn, struct Vin* v);
void vinLesOgSettData(struct Vin* v, const int nr);
void vinSkrivData(struct Vin* v);
void vinSkrivTilFil(FILE* ut, const struct Vin* v);
void vinSlettData(struct Vin* v);


struct Produsent* gProdusentene[MAXPRODUSENTER]; ///<  Produsent-oversikten.
int    gAntallProdusenter = 0;                   ///<  Ant.produsenter hittil.
struct Vin* gVinene[MAXVINER];                   ///<  Vinene i oversikten.
int    gAntallViner = 0;                         ///<  Antall viner hittil.


/**
 *  Hovedprogrammet:
 */
int main ()  {
    char kommando;

    lesFraFil();

    skrivMeny();
    kommando = lesChar("\nKommando");

    while (kommando != 'Q')  {
        switch (kommando)  {
          case 'S': skrivAlleProdusenter();    break;
          case 'A': skrivVinerFraProdusent();  break;
          case 'P': nyProdusent();             break;
          case 'V': nyVin();                   break;
          case 'E': endreVin();                break;
          default:  skrivMeny();               break;
        }
        kommando = lesChar("\nKommando");
    }

    skrivTilFil();

    frigiAllokertMemory();

    return 0;
}


/**
 *  Endrer en vin (ny årgang og/eller nytt antall).
 *
 *  @see  vinEndre(...)
 */
void endreVin()  {
    int nr;                             // Ønsket vinnummer å endre på.

    scanf("%i", &nr);                   //  Leser vinens nummer.

    if (nr >= 1 &&  nr <= gAntallViner) //  Nummer i aktuelt intervall:
       vinEndre(gVinene[nr-1]);         //  Ny årgang og/eller nytt antall
    else
      printf("\n\tNummer utenfor aktuelt intervall: 1-%i.\n\n", gAntallViner);
}


/**
 *  Prøver å finne indeksen i 'gProdusentene' for en navngitt produsent.
 *
 *  @param   nvn  - Søkt produsents navn
 *  @return  Indeksen for produsenten, evt. -1 om ikke ble funnet
 */
int  finnProdusent(const char* nvn)  {
    for (int i = 0;  i < gAntallProdusenter;  i++)
        if (!strcmp(gProdusentene[i]->navn, nvn))  return i;   //  Funn/match!

    return -1;                           //  Ikke funnet noen med dette 'nvn'.
}


/**
 *  Frigir ALL allokert memory under run-time.
 *
 *  @see  produsentSlettData(...)
 *  @see  vinSlettData(...)
 */
void frigiAllokertMemory()  {
   int i;
                                            //  Går gjennom ALLE produsentene:
   for (i = 0;  i < gAntallProdusenter;  i++)  { 
       produsentSlettData(gProdusentene[i]);  //  Hver produsent frigir selv 
                                              //    sine allokerte data.
       free(gProdusentene[i]);                //  Selve structen frigis.
   }

   for (i = 0;  i < gAntallViner;  i++) {     //  Går gjennom ALLE vinene:
       vinSlettData(gVinene[i]);              //  Hver vin frigir selv 
                                              //    sine allokerte data.
       free(gVinene[i]);                      //  Selve structen frigis.
   }
}


/**
 *  Leser HELE datastrukturen fra filer.
 *
 *  @see  produsentLesFraFil(...)
 *  @see  vinLesFraFil(...)
 */
void lesFraFil()  {
  FILE* innfil  = fopen("PRODUSENTER.DTA", "r");    //  Åpner aktuelle filer:
  FILE* innfil2 = fopen("VINER.DTA", "r");
  int i;

  if (innfil  &&  innfil2)  {                       //  Begge filene finnes:
    printf("\n\tLeser fra filene 'PRODUSENTER.DTA' og 'VINER.DTA' .....\n\n");

    fscanf(innfil, "%i", &gAntallProdusenter);   //  Leser antall produsenter.
    getc(innfil);                                //  Leser avsluttende '\n'.
    for (i = 0; i  < gAntallProdusenter;  i++)  { //  Ny produsent lages:
        gProdusentene[i] = 
                         (struct Produsent*) malloc(sizeof(struct Produsent));
        produsentLesFraFil(innfil, gProdusentene[i]);  //  Dens data leses.
    }
    fclose(innfil);                               //  Lukker åpen fil.

    fscanf(innfil2, "%i", &gAntallViner);         //  Leser antall viner.
    getc(innfil2);                                //  Leser avsluttende '\n'.
    for (i = 0; i  < gAntallViner;  i++)  {       //  Ny vin lages:
        gVinene[i] = (struct Vin*) malloc(sizeof(struct Vin));
        vinLesFraFil(innfil2, gVinene[i]);        //  Dens data leses.
    }
    fclose(innfil2);                              //  Lukker åpen fil.
  } else
    printf("\n\tFinner ikke minst en av filene det skal leses fra!\n");
}


/**
 *  Legger (om mulig/plass) inn en ny produsent.
 *
 *  @see  finnProdusent(...)
 *  @see  produsentLesData(...)
 */
void nyProdusent()  {
   char* navn;                                 //  Ny produsents navn.

   if (gAntallProdusenter < MAXPRODUSENTER)  { // Plass til flere produsenter:
      navn = lagOgLesText("\tNavn   ");  // Leser/lager ny(?) produsents navn.
      if (finnProdusent(navn) == -1)  {  // Ingen med dette navnet allerede:
                                       // Allokerer plass til en ny produsent:
         gProdusentene[gAntallProdusenter] = 
                         (struct Produsent*) malloc(sizeof(struct Produsent));
                                                          //  Alle data leses:
         produsentLesData(gProdusentene[gAntallProdusenter], navn);  
                                                          //  Øker antallet:
         printf("\n\tNy produsent er nr. %i\n\n", ++gAntallProdusenter); 
      } else  {                     //  Produsenten finnes:
        printf("\n\tFinnes en produsent med dette navnet allerede!\n\n");
        free(navn);                 //  FRIGIR MEMORY, DA SKAL IKKE LAGRES !!!
      }
   } else                                      //  Fullt:
       printf("\n\tFullt med %i produsenter allerede!\n\n", MAXPRODUSENTER);
}


/**
 *  Legger (om mulig/plass og produsent finnes) inn en ny vin.
 *
 *  @see  finnProdusent(...)
 *  @see  vinLesOgSettData(...)
 */
void nyVin()  {
  char navn[STRLEN];                           //  Produsentens navn.
  int nr;                                      //  Dens indeks.

  if (gAntallViner < MAXVINER) {               //  Plass til flere viner:
     lesText("\tProdusentnavn", navn, STRLEN); //  Leser produsentens navn.
     if ((nr = finnProdusent(navn)) != -1) {   //  Produsenten finnes:
                                            //  Allokerer plass til en ny vin:
         gVinene[gAntallViner] = (struct Vin*) malloc(sizeof(struct Vin));
                                            //  Dens data settes og leses:
         vinLesOgSettData(gVinene[gAntallViner], nr);   //  Øker antallet:
         printf("\n\tNy vin er nr. %i\n\n", ++gAntallViner); 
     }  else                                //  Produsenten finnes ikke:
        printf("\n\tFinnes ingen produsent med dette navnet!\n\n");
    } else                                  //  Fullt:
       printf("\n\tFullt med %i viner allerede!\n\n", MAXVINER);
}


/**
 *  Kopierer inn og leser ALLE en structs data.
 *
 *  @param   p    - Structen som får satt og innlest sine data
 *  @param   nvn  - Allerede innlest navn (som unnalagres)
 */
void produsentLesData(struct Produsent* p, char* nvn)  {
   p->navn = nvn;
   p->adr  = lagOgLesText("\tAdresse");
   p->mail = lagOgLesText("\tMail   ");
   p->tlf  = lesInt("\tTlf.nr", 10000000, 99999999);
}


/**
 *  Produsent-struct får innlest alle sine data fra fil.
 *
 *  @param   inn  - Filen det leses fra
 *  @param   p    - Structen som får innlest sine data fra fil
 */
void produsentLesFraFil(FILE* inn, struct Produsent* p)  {
   char buffer[STRLEN];
                                    //  Leser produsentens navn:
   fgets(buffer, STRLEN, inn);    buffer[strlen(buffer)-1] = '\0';
   p->navn = (char*) malloc((strlen(buffer)+1) * sizeof(char));
   strcpy(p->navn, buffer);
                                    //  Leser produsentens adresse:
   fgets(buffer, STRLEN, inn);    buffer[strlen(buffer)-1] = '\0';
   p->adr = (char*) malloc((strlen(buffer)+1) * sizeof(char));
   strcpy(p->adr, buffer);
                                    //  Leser produsentens mailadresse:
   fgets(buffer, STRLEN, inn);    buffer[strlen(buffer)-1] = '\0';
   p->mail = (char*) malloc((strlen(buffer)+1) * sizeof(char));
   strcpy(p->mail, buffer);

   fscanf(inn, "%i", &p->tlf);      //  Leser produsentens telefonnummer:

   getc(inn);                       //  Leser avsluttende '\n' !
}


/**
 *  Alle en structs data skrives ut på skjermen.
 *
 *  @param   p  - Structen som skrives på skjermen
 */
void produsentSkrivData(const struct Produsent* p)  {
   printf("\t%s, %i, %s\n\t\t%s\n", p->navn, p->tlf, p->mail, p->adr);
}


/**
 *  Alle en structs data skrives ut på fil.
 *
 *  @param   ut  - Filen det skal skrives til
 *  @param   p   - Structen som skrives på filen
 */
void produsentSkrivTilFil(FILE* ut, const struct Produsent* p)  {
   fprintf(ut, "%s\n%s\n%s\n%i\n", p->navn, p->adr, p->mail, p->tlf);
}


/**
 *  Sletter ALLE allokerte data inni EN produsent-struct.
 *
 *  @param   p  - Structen som får alle sine allokerte data frigitt
 */
void produsentSlettData(struct Produsent* p)  {
  free(p->navn);
  free(p->adr);
  free(p->mail);
}


/**
 *  Skriver ALLE produsentenes data.
 *
 *  @see  produsentSkrivData(...)
 */
void skrivAlleProdusenter()  {
  for (int i = 0;  i < gAntallProdusenter;  i++)  {  //  For hver produsent:
      printf("\t%3i:", i+1);                         //  Skriver indeks og
      produsentSkrivData(gProdusentene[i]);          //     ALLE data.
    }
}


/**
 *  Skriver programmets menyvalg/muligheter på skjermen.
 */
void skrivMeny()  {
   printf("\nFølgende kommandoer er tilgjengelig:\n");
   printf("\tS - Skriv alle produsenter\n");
   printf("\tA - skriv Alle viner fra en gitt produsent\n");
   printf("\tP - ny Produsent\n");
   printf("\tV - ny Vin\n");
   printf("\tE <nr>  <(nytt) år>  <ant.flasker inn(+)/ut(-)>\n\t");
   printf("      - Endre vin ( (ny) årgang og/eller antall ");
                   printf("(selge/etterfylle) )\n");
   printf("\tQ - Quit / avslutt\n");
}


/**
 *  Skriver HELE datastrukturen (ALLE produsenter og viner) TIL filer.
 *
 *  @see  produsentSkrivTilFil(...)
 *  @see  vinSkrivTilFil(...)
 */
void skrivTilFil()  {
  FILE* utfil  = fopen("PRODUSENTER.DT2", "w");  //  Åpner aktuelle filer:
  FILE* utfil2 = fopen("VINER.DT2", "w");
  int i;                                         //  Løkkevariabel.

  if (utfil  &&  utfil2) {                       //  Begge filene kan åpnes:
    printf("\nSkriver til filene 'PRODUSENTER.DT2' og 'VINER.DT2' .....\n\n");

    fprintf(utfil, "%i\n", gAntallProdusenter); //  Skriver ant.poster/produs.
    for (i = 0;  i < gAntallProdusenter;  i++)  //  Går gjennom ALLE produs.:
        produsentSkrivTilFil(utfil, gProdusentene[i]); // Hver produs.skrives.

    fprintf(utfil2, "%i\n", gAntallViner);      //  Skriver ant.poster/viner.
    for (i = 0;  i < gAntallViner;  i++)        //  Går gjennom ALLE vinene:
        vinSkrivTilFil(utfil2, gVinene[i]);     //  Hver vin skrives.
  } else                                   //  Filen ikke funnet/mulig å åpne:
    printf("Klarte ikke å åpne minst en av filene å skrive til!\n\n");

    fclose(utfil);                         //  Lukker filene.
    fclose(utfil2);
}


/**
 *  Skriver ALLE viner fra EN produsent.
 *
 *  @see  finnProdusent(...)
 *  @see  vinSkrivData(...)
 */
void skrivVinerFraProdusent()  {
  char navn[STRLEN];                             //  Produsentens navn.
  int  nr;                                       //  Produsents indeks.

  lesText("\tVin fra produsent", navn, STRLEN);  //  Leser produsentens navn.
  if ((nr = finnProdusent(navn)) != -1)  {       //  Produsenten finnes:
      for (int i = 0;  i < gAntallViner;  i++)   //  For hver vin:
          if (gVinene[i]->produsentNr == nr)  {  //  Aktuell produsent?
              printf("\t%3i:", i+1);             //  Skriver:  - indeks/nr
              vinSkrivData(gVinene[i]);          //            - data
          }
  } else                                         //  Produsent finnes ikke:
    printf("\n\tFinnes ingen produsent med dette navnet!\n\n");
}


/**
 *  Legger til (om mulig) ny årgang og/eller endrer antallet av en vin.
 *
 *  @param   v  - Vinen som får sitt antall endret av en årgang
 */
void vinEndre(struct Vin* v)  {
  int nr = -1,                                   //  Årgangens indeks.
      aar,                                       //  Aktuelt årgang
      ant;                                       //    og antall.

  scanf("%i %i", &aar, &ant);                    //  Leser årgang og antall.
  getchar();                                     //  Leser '\n'.

  if (aar >= 1900 && aar <= 2019) {              //  Årgang er i OK intervall:

     for (int i = 0;  i < v->antallAarganger;  i++) // Finnes årgang allerede?
         if (v->aargang[i] == aar)  {  nr = i;  break;  }  //  Funn!

     if (nr != -1) {                              //  Årgangen finnes:
        if (ant > 0 || -ant <= v->antall[nr]) {   //  Får nye eller nok igjen:
           v->antall[nr] += ant;                  //  Oppdaterer antall igjen.
           printf("\n\tAntall på lager av årgang %i:  %i\n\n", // Skriver nytt
                 aar, v->antall[nr]);                          //   antall.
        } else                                 //  Prøver å fjerner for mange:
          printf("\n\tHar kun %i stk. på lager!\n\n", v->antall[nr]);

     } else {                                  //  Årgangen er ny:
       if (ant >= 0) {                         //  Positivt antall flasker:
          if (v->antallAarganger < MAXAAR) {   //  Plass til flere årganger:
              nr = v->antallAarganger++;       //  Tar i bruk ny indeks:
              v->aargang[nr] = aar;            //  Oppdaterer begge arrayer:
              v->antall[nr] = ant;             //  Skriver nytt antall:
              printf("\n\tAntall på lager av årgang %i:  %i\n\n",
                     aar, v->antall[nr]);
          } else                                 //  Fullt med årganger:
            printf("\n\tFullt med %i årganger!\n\n", MAXAAR);
       } else                         //  Umulig med negativt nytt antall:
         printf("\n\tUmulig med negativt antall av en ny årgang!\n\n");
     }

  } else                                 //  Årgang utenfor intervall:
    printf("\n\tÅrstall utenfor aktuelt intervall: 1900-2019.\n\n");
}


/**
 *  Vin-struct får innlest alle sine data fra fil.
 *
 *  @param   inn  - Filen det leses fra
 *  @param   v    - Structen som får innlest sine data fra fil
 */
void vinLesFraFil(FILE* inn, struct Vin* v)  {
   char buffer[STRLEN];
   int i;
                                    //  Leser vinens navn:
   fgets(buffer, STRLEN, inn);    buffer[strlen(buffer)-1] = '\0';
   v->navn = (char*) malloc((strlen(buffer) + 1) * sizeof(char));
   strcpy(v->navn, buffer);
                                    //  Leser 2x single data:
   fscanf(inn, "%i %i", &v->produsentNr, &v->antallAarganger);
                                    //  Leser årgangene:
   for (i = 0;  i < v->antallAarganger;  i++)
       fscanf(inn, "%i", &v->aargang[i]);
                                    //  Leser antallet av årgangene:
   for (i = 0;  i < v->antallAarganger;  i++)
       fscanf(inn, "%i", &v->antall[i]);

   getc(inn);                       //  Leser avsluttende '\n' !
}


/**
 *  Kopierer inn, leser og initierer en structs data.
 *
 *  @param   v   - Structen som får satt og innlest sine data
 *  @param   nr  - Allerede innlest produsentnummer (som unnalagres)
 */
void vinLesOgSettData(struct Vin* v, const int nr)  {
  v->produsentNr = nr;               //  Lagrer unna allerede innlest prod.nr.
  v->navn = lagOgLesText("\tVinnavn");   //  Leser navnet
  v->antallAarganger = 0;                //  Initerer til 0 (null)
}                                    //  To arrayer får verdier i 'vinEndre'.


/**
 *  Alle en structs data skrives ut på skjermen.
 *
 *  @param   v  - Structen som skrives på skjermen
 */
void vinSkrivData(struct Vin* v)  {
  printf("\t%s,  #årganger: %i\n\t\t", v->navn, v->antallAarganger);
  for (int i = 0;  i < v->antallAarganger;  i++)  // Alle årgangene og antall:
       printf("%8i (%i)", v->aargang[i], v->antall[i]);
  printf("\n");
}


/**
 *  Alle en structs data skrives ut på fil.
 *
 *  @param   ut  - Filen det skal skrives til
 *  @param   v   - Structen som skrives på filen
 */
void vinSkrivTilFil(FILE* ut, const struct Vin* v)  {
  int i;
                                                //  Skriver 3x single data:
  fprintf(ut, "%s\n%i %i\n", v->navn, v->produsentNr, v->antallAarganger);

  for (i = 0;  i < v->antallAarganger;  i++)    //  Skriver aargang's innhold:
      fprintf(ut, " %i", v->aargang[i]);
  fprintf(ut, "\n");

  for (i = 0;  i < v->antallAarganger;  i++)    //  Skriver antall's innhold:
      fprintf(ut, " %i", v->antall[i]);
  fprintf(ut, "\n");
}


/**
 *  Sletter ALLE allokerte data inni EN vin-struct.
 *
 *  @param   v  - Structen som får "alle" sine allokerte data frigitt
 */
void vinSlettData(struct Vin* v)  {
   free(v->navn);
}
