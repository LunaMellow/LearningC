/**
 *   Programeksempel nr 23 - Funksjoner som kaller hverandre
 *                           Funksjoner med array som parameter.
 *
 *   @file     EKS_23.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>              //  printf, scanf
#include <ctype.h>              //  toupper, isalpha
#include <stdbool.h>            //  bool
#include <string.h>             //  strlen

const int STRLEN  = 80;         ///<  Max.tekstlengde.
const int ANTTEGN = 26;         ///<  Antall bokstaver ('A'-'Z').


int  fakultet(const int n);
int  summerBroker(const int n);
void lesTekst(const char ledetekst[], char tekst[]);
bool palindrom(const char s[]);
void skrivTall(const int tall);
int  finnMinsteElement(const int arr[], const int n);

void initArray(int arr[], const int n);
void tellForekomster(int arr[]);
void skrivHistogram(const int arr[], const int n);

/**
 *  Hovedprogrammet:
 */
int main ()  {

// Funksjoner som returnerer flere steder, og funksjoner som kaller hverandre:

    printf("Summering av brøker etter 1!/1 + 2!/2 + 3!/3 + ... + N!/N :\n");
    printf("\tNår 'N' er  5:  %8i\n",     summerBroker( 5));
    printf("\tNår 'N' er  8:  %8i\n",     summerBroker( 8));
    printf("\tNår 'N' er 12:  %8i\n\n\n", summerBroker(12));
                                 //  Høyere verdier for 'N' vil sprenge 'int'!


//****************************************************************************

//  Arrayer som parametre:

    char buffer[STRLEN];

    lesTekst("Navn    ", buffer);                   //  Aktuell oppdateres !!!
    printf("\tInnlest tekst: -%s-\n\n", buffer);

    lesTekst("Adresse ", buffer);
    printf("\tInnlest tekst: -%s-\n\n", buffer);

    lesTekst("Poststed", buffer);
    printf("\tInnlest tekst: -%s-\n\n\n", buffer);

// NB:  Ved medsendelse av array blir det IKKE tatt kopi av medsendt parameter
//      (verdioverføring), men den AKTUELLE PARAMETEREN (originalen)
//      BRUKES DIREKTE.


//****************************************************************************

    printf("Skriv tekster som skal vurderes som palindrom ");
    printf("(likt forlengs som baklengs): \n\n");

    lesTekst("1.tekst (av 4) å vurdere", buffer);
    printf("\t-%s- er ", buffer);
    if (!palindrom(buffer)) printf("IKKE ");
    printf("et palindrom!\n\n");

    lesTekst("2.tekst (av 4) å vurdere", buffer);  //  Mer kompakt skrivemåte:
    printf("\t-%s- er%s et palindrom!\n\n",
           buffer, ((!palindrom(buffer)) ? " IKKE" : ""));

    lesTekst("3.tekst (av 4) å vurdere", buffer);
    printf("\t-%s- er%s et palindrom!\n\n",
           buffer, ((!palindrom(buffer)) ? " IKKE" : ""));

    lesTekst("4.tekst (av 4) å vurdere", buffer);
    printf("\t-%s- er%s et palindrom!\n\n\n",
           buffer, ((!palindrom(buffer)) ? " IKKE" : ""));


//****************************************************************************

    int tallet = 42;
    int tall[] = { 13, 56, 8, 37, 114, 932, 2, 73, 98, 653, 965, 23, 639, 7 };

    skrivTall(tallet);                           //  Sender med ENKELT-int'er,
    skrivTall(tall[1]);                          //    IKKE en hel array !
    skrivTall(tall[9]);

                                  //  Sender med HELE arrayen, og dens lengde:
    printf("\nMinste element i arrayen har indeks nr.%i\n\n",
           finnMinsteElement(tall, 14));


//  NB:  KAN også sende med fler-dimensjonale arrayer som parameter til
//       funksjoner. Men, da MÅ alle dimensjoner angis eksakt i DEKLARASJONEN,
//       dog KAN fortsatt angivelsen av 1.dimensjon utelates.


//****************************************************************************

//  Teller forekomsten av bokstaver, og lager histogram over dette antallet:

    int bokstavForekomst[ANTTEGN];


    initArray(bokstavForekomst, ANTTEGN);  //  Alle får arrayen tilsendt som
                                           //    parameter, og noen trenger
    tellForekomster(bokstavForekomst);     //    også å vite hvor lang den er:

    skrivHistogram(bokstavForekomst, ANTTEGN);


    printf("\n\n");

    return 0;
}


/**
 *  Regner ut og returnerer N!.
 *
 *  @param   n  - Verdien det skal beregnes N! for
 *
 *  @return  N!  om n >= 0, ellers 0 (null)
 */
int fakultet(const int n)  {
  int sum = 1;                      //  Viktig at er initiett til '1',
                                    //    da både 0! og 1! er lik 1.
  if (n >= 0)  {                    //  'n' er positiv:
     for (int i = 2;  i <= n;  i++) //  Beregner fra 2! og oppover:
         sum *= i;                  //  Produktsum.
     return sum;                    //  Returnerer utregnet sum/svar.
  }
                                    //  'n' er negativ, derfor irrelevant å
  return 0;                         //    beregne. Returnerer derfor 0 (null).
}


/**
 *  Summerer opp og returnerer  1!/1 + 2!/2 + ... + N!/N.
 *
 *  @param   n  - Verdien som det skal bergenes rekkesummen opp til
 *
 *  @return  Rekkesummen om n >= 1, ellers 0 (null)
 *
 *  @see     fakultet(...)
 */
int summerBroker(const int n)  {
  int sum = 0;                      //  Viktig at er initiert til 0 (null).
  if (n >= 1)  {                    //  'n' er større enn 0, skal beregne:
     for (int i = 1;  i <= n;  i++) //  For alle verdiene fra 1 til 'n':
         sum += (fakultet(i)/i);    //  Adder sammen brøkene.
     return sum;                    //  Returnerer utregnet sum/svar.
  }
                                   //  'n' er 0 (null) eller mindre.
  return 0;                        //  Irrelevant å summere opp, returnerer 0.
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
 *  Finner ut om en tekst er er palindrom (likt forlengs og baklengs).
 *
 *  @param   s  - Teksten som skal vurderes
 *
 *  @return  'true' om 's' er et palindom, ellers 'false'
 */
bool palindrom(const char s[])  {
   int n = strlen(s);                 //  Finner tekstens lengde.
   for (int i = 0;  i <= n/2;  i++)   //  Går gjennom den til halvveis:
       if (s[i] != s[n-1-i]) return false; //  IKKE lik fra hver ende.
   return true;                       //  Lik fra begge ender - palindrom!
}


/**
 *  Skriver bare ut medsendt int-parameter på skjermen.
 *
 *  @param   tall  -  Tallet som skal skrives ut
 */
void skrivTall(const int tall)  {
  printf("\tMedsendt tall-parameter er: %i\n", tall);
}


/**
 *  Finner og returnerer indeksen for det minste elementet i en int-array.
 *
 *  @param   arr  - Array det skal gås gjennom og bestemmes minste element i
 *  @param   n    - Antall elementer i 'arr'
 *
 *  @return  Indeksen for det minste elementet i 'arr'
 */
int  finnMinsteElement(const int arr[], const int n)  {
  int indeks = 0;                 //  Initierer til det første elementet.
  for (int i = 1;  i < n;  i++)   //  Går gjennom resten av arrayen:
      if (arr[i] < arr[indeks])   //  Funnet element som er mindre?
         indeks = i;              //  Oppdaterer indeks for der den er.
  return indeks;                  //  Retunerer funnet indeks for den minste.
}


/**
 *  Nullstiller innholdet i en hel int-array.
 *
 *  @param   arr  - Arrayen som skal få hele sitt innhold nullstilt
 *  @param   n    - Antall elementer i 'arr' (dens lengde)
 */
void  initArray(int arr[], const int n)  {
  for (int i = 0;  i < n;  i++)
      arr[i] = 0;
}



/**
 *  Teller opp antall ganger ulike bokstaver forekommer.
 *
 *  @param   arr  - Inneholder antallet for forekomsten av  'A', 'B', ...,'Z'
 */
void  tellForekomster(int arr[])  {
  char tegn;

  printf("\nSkriv tegn (bokstaver), avslutt med '!':\n\n");

  do  {
    scanf(" %c", &tegn);   tegn = toupper(tegn); //  Leser ett og ett tegn.
    if (isalpha(tegn))                           //  Tegnet er: 'A'-'Z':
       ++arr[tegn-'A'];                          //  Teller opp forekomsten.
  } while (tegn != '!');                         //  Leser inntil '!' trykkes.
}


/**
 *  Skriver et horisontalt histogram for forekomsten av bokstavene 'A'-'Z'.
 *
 *  @param   arr  - Forekomsten (antallet) av hver av bokstavene 'A'-'Z'
 *  @param   n    - Antall elementer i 'arr' (dens lengde)
 */
void  skrivHistogram(const int arr[], const int n)  {

   for (int i = 0;  i < n;  i++)  {         // Går gjennom alle bokstavene:
                                            // Skriver bokstaven og antallet:
       printf("%c (%2i): ", (char)i + 'A', arr[i]);
       for (int j = 1;  j <= arr[i];  j++)  // Skriver så mange '*' som
           printf("*");                     //   antall forekomster.
       printf("\n");
   }
}
