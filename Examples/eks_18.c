/**
 *   Programeksempel nr 18 - if - else if - else.
 *
 *   @file     EKS_18.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>              //  printf, scanf
#include <ctype.h>              //  isdigit (0-9), isalpha (A-Z, a-z), toupper
#include <stdbool.h>            //  bool
#include <stdlib.h>             //  atoi
#include <string.h>             //  strlen

const int STRLEN = 80;          ///<  Max. tekstlengde.

/**
 *  Hovedprogrammet:
 */
int main ()  {

    int alder;                  //  (En persons) innleste alder.

    printf("\n1 - Alder:  ");
    scanf("%i", &alder);

    if (alder < 18)             //  Betinget utskrift - dersom 'alder' < 18.
        printf("\tIkke-myndig!\n");
                                //  Ellers hoppes linjen bare over.
    printf("\nDa har vi kommet hit.....\n\n");


//*******************************************************************

    printf("\n2 - Alder:  ");
    scanf("%i", &alder);

    if (alder < 18)             //  Dersom alder < 18:
        printf("\tIkke-myndig!\n");
    else                        //  Dersom alder >= 18:
        printf("\tMyndig!\n");


//*******************************************************************

    printf("\n3 - Alder:  ");
    scanf("%i", &alder);

    if (alder >= 0)  {          //  Alder er positiv (null eller større):
       if (alder < 18)          //  Dersom alder < 18:
          printf("\tIkke-myndig!\n");
       else                     //  Dersom alder >= 18:
          printf("\tMyndig!\n");
    } else                      //  Alder er negativ ( < 0 ):
       printf("\tUmulig med negativ alder!\n");


//*******************************************************************

    printf("\n4 - Alder:  ");
    scanf("%i", &alder);

    if (alder >= 0)  {          //  Alder er positiv (null eller større):
       if (alder <= 12)         //  Alder < 12:
          printf("\tBarn\n");
       else if (alder <= 19)    //  Alder 13-19:
          printf("\tTenåring\n");
       else if (alder <= 30)    //  Alder 20-30:
          printf("\tStudent?\n");
       else if (alder <= 40)    //  Alder 31-40
          printf("\tSmåbarnsforelder?\n");
       else if (alder <= 50)    //  Alder 41-50:
          printf("\tVel etablert? - midt i livet!\n");
       else                     //  Alder 51 -->
          printf("\tGamling!\n");
    } else                      //  Alder er negativ ( < 0 ):
       printf("\tUmulig med negativ alder!\n");


//*******************************************************************

    char tegn;                         //  Innlest tegn.
    int  antallBokstaver = 0,          //  Antall BOKSTAVER lest.
         antallSifre     = 0,          //  Antall SIFRE lest.
         antallAndreTegn = 0;          //  Antall ALLE ANDRE tegn lest.

    printf("\nSkriv tegn, avslutt med '!':  ");
    scanf(" %c", &tegn);               //  Leser ETT tegn.
    while (tegn != '!')  {             //  Så lenge ikke avslutte:
      if (tegn >= '0'  && tegn <= '9')
                                       //  Linjen over KAN erstattes av denne:
                                       //  if (isdigit(tegn))
          antallSifre++;
      else if ((tegn >= 'A' && tegn <= 'Z')  ||  (tegn >= 'a' && tegn <= 'z'))
                                  //  HELE linjen over KAN erstattes av denne:
                                  //  else if (isalpha(tegn))
          antallBokstaver++;
      else
          antallAndreTegn++;

      scanf(" %c", &tegn);             //  Leser neste tegn.
    }                                  //  Skriver status om tellingen:
    printf("\nAntall bokstaver skrevet inn:   %3i\n", antallBokstaver);
    printf("Antall sifre skrevet inn:       %3i\n",   antallSifre);
    printf("Antall andre tegn skrevet inn:  %3i\n\n", antallAndreTegn);


//*******************************************************************

    getchar();                           //  Forkaster gjenliggende  '\n'.

    char tlfNrTekst[STRLEN];             //  Leser telefonnummer som tekst.
    int  tlfNrTall = 0;                  //  Lovlig tekst omgjort til tall.
    bool bareSifre = true;               //  Antar at korrekt åtte sifre.

    printf("\nSkriv et telefonnummer på 8 sifre:  ");
    gets(tlfNrTekst);                    //  Leser tekst.

    if (strlen(tlfNrTekst) == 8)  {      //  Den ER EKSAKT 8 lang:
       if (tlfNrTekst[0] != '0')  {      //  Den starter IKKE med 0 (null):
          for (int i = 0;  i < 8;  i++)  //  Sjekker at er BARE sifre:
              if (!isdigit(tlfNrTekst[i])) bareSifre = false; // Er IKKE det.

          if (bareSifre)  {            //  Er BARE sifre (forutsetning holdt).
             tlfNrTall = atoi(tlfNrTekst);   //  Gjør om tekst til tall.
             //  Linjen over KAN gjøres manuelt ved:
             //    for (int j = 0;  j < 8;  j++)
             //         tlfNrTall = (tlfNrTall*10) + (int)(tlfNrTekst[j]-'0');
             printf("\n\tTelefonnummeret som tall:  %i\n", tlfNrTall);
          } else
            printf("\n\tTelefonnummeret består IKKE av BARE sifre!\n");
       } else
         printf("\n\tTelefonnummeret starter IKKE med '0'!\n");
    } else
      printf("\n\tTelefonnummeret er IKKE eksakt 8 langt!\n");


//*******************************************************************

    char navn[STRLEN];                //  Persons navn.
    bool gyldigNavn;                  //  Om navnet er gyldig/lovlig eller ei.
    int i;                            //  Løkkevaribel.

    do  {
      printf("\n\n\nPersonnavn (bokstaver (a-z), blank eller '-'):\n\t");
      gets(navn);                     //  Leser personens navn.

      gyldigNavn = true;              //  Antar at navnet er gyldig/lovlig.

      for (i = 0;  i < strlen(navn);  i++)  //  Går gjennom HELE navnet:
                                            //  Ugyldig tegn forekommer:
          if (!isalpha(navn[i])  &&  navn[i] != ' '  &&  navn[i] != '-')
// Eller: if (!(isalpha(navn[i]) ||  navn[i] == ' '  ||  navn[i] == '-'))
            gyldigNavn = false;       //  Markerer at dette har skjedd,
                                      //    og skriver isåfall en melding:
      if (!gyldigNavn) printf("\nInneholdt ulovlige tegn!  Prøv igjen:");

    } while (!gyldigNavn);            //  Looper inntil gyldig/lovlig navn.

    printf("\n\nDette er et gyldig/lovlig personnavn!\n\n");

    return 0;
}
