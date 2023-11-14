/**
 *   Løsningsforslag til oppgave nr 25.
 *
 *   @file	  OPPG_25.C
 *   @author  Frode Haug, NTNU
 */


#include <stdio.h>                 //  printf, scanf

const int STRLEN  =  80;           ///<  Max.tekstlengde.

int  mstrlen(const char s[]);
void mstrcpy(char s[], const char t[]);
void mstrcat(char s[], const char t[]);
int  mstrcmp(const char s[], const char t[]);

/**
 *  Hovedprogrammet:
 */
int main()  {
    char  str1[STRLEN];
    char  str2[STRLEN];

    printf("\nSTRLEN:\n");
    printf("\t'Kari' har lengden:  %i\n", mstrlen("Kari"));
    printf("\t'PØLSER M/SYLTETØY OG SOFTIS M/RÅ LØK' har lengden:  %i\n",
           mstrlen("PØLSER M/SYLTETØY OG SOFTIS M/RÅ LØK"));
    printf("\t<blank> har lengden:  %i\n", mstrlen(""));


    printf("\nSTRCPY:\n");
    mstrcpy(str1, "KARI & "); printf("\t'KARI & ' til 'str1':  -%s-\n", str1);
    mstrcpy(str2, "BJARNE");  printf("\t'BJARNE' til 'str2':   -%s-\n", str2);
    mstrcpy(str2, "KURT");    printf("\t'KURT' til 'str2':     -%s-\n", str2);


    printf("\nSTRCAT:\n");
    mstrcat(str1, str2);
    printf("\tSkjøter 'str1' med 'str2':  %s\n", str1);
    mstrcat(str1, " er kjærester");
    printf("\tSkjøter 'str1' med ' er kjærester':  %s\n", str1);


    printf("\nSTRCMP:\n");
    printf("\t'str2' med 'KURT':  %i\n",   mstrcmp(str2, "KURT"));
    printf("\t'str2' med 'Kurt':  %i\n",   mstrcmp(str2, "Kurt"));
    printf("\t'KURT' med 'str2':  %i\n",   mstrcmp("KURT", str2));
    printf("\t'Kurt' med 'str2':  %i\n\n", mstrcmp("Kurt", str2));

    printf("\t'AAA' med 'AAA':  %i\n",     mstrcmp("AAA", "AAA"));
    printf("\t'AAA' med 'AAa':  %i\n",     mstrcmp("AAA", "AAa"));
    printf("\t'AAA' med 'AaA':  %i\n",     mstrcmp("AAA", "AaA"));
    printf("\t'AAA' med 'AAAa': %i\n",     mstrcmp("AAA", "AAAa"));
    printf("\t'AAA' med 'AAAA': %i\n",     mstrcmp("AAA", "AAAA"));
    printf("\t'' med 'A':       %i\n",     mstrcmp("", "A"));
    printf("\t'' med '':        %i\n\n",   mstrcmp("", ""));

    return 0;
}


/**
 *  Returnerer lengden til teksten som er i en char-array.
 *
 *  @param   s  - Teksten (char-array) det skal finnes lengden for
 *
 *  @return  Lengden på teksten i 's'
 */
 int  mstrlen(const char s[])  {
   int i = 0;                     //  Initierer til 0 (null).
   while (s[i] != '\0')  i++;     //  Blar og teller opp til når '\0'.
   return i;                      //  Returnerer lengden.
}


/**
 *  Kopierer teksten i en char-array over i en annen char-array.
 *
 *  @param   s  - Char-arrayen det skal kopieres til
 *  @param   t  - Teksten (char-arrayen) det skal kopieres fra
 */
void mstrcpy(char s[], const char t[])  {
  int i = 0;                      //  Initierer til 0 (null).
  while (t[i] != '\0')  {         //  Blar til slutten av 't'.
    s[i] = t[i];                  //  Kopierer over ett og ett tegn.
    i++;                          //  Øker til neste tegn/indeks.
  }
  s[i] = '\0';                    //  NB: Legger manuelt inn avsluttende '\0'.
}


/**
 *  Skjøter/påhekter en tekst bak en annen.
 *
 *  @param   s  - Tekst som blir påskjøtet (er først)
 *  @param   t  - Tekst som skjøtes/legges til (er bakerst)
 */
void mstrcat(char s[], const char t[])  {
    int i = 0, j = 0;
    while (s[i] != '\0') i++;     //  Finner slutten av 's'.
    while (t[j] != '\0')  {       //  Blar til slutten av 't'.
        s[i] = t[j];              //  Kopierer over ett og ett tegn.
        i++;   j++;               //  Øker til de neste tegnene/indeksene.
    }
    s[i] = '\0';                  //  NB: Legger manuelt inn avsluttende '\0'.
}


/**
 *  Sammenligner to tekster. Finner forskjellen på det evt. første ulike tegnet.
 *
 *  @param   s - Første tekst i sammenligningen
 *  @param   t - Andre tekst i sammenligningen
 *
 *  @return  Differansen mellom tegnenes verdi i maskinens tegntabell (der sammenligning stanset)
 */
int  mstrcmp(const char s[], const char t[])  {
    int i = 0;
    while (s[i] != '\0'  &&  t[i] != '\0'  &&  s[i] == t[i])
       i++;
    return ((int)s[i] - (int)t[i]);
}
