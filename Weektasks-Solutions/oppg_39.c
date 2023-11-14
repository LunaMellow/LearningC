/**
 *   Løsningsforslag til oppgave nr 39.
 *
 *   Kun TILEGGSKODE ift. EKS_35.c er skrevet/gitt nedenfor.
 *
 *   @file	  OPPG_39.C
 *   @author  Frode Haug, NTNU
 */


 //  Filen 'MALERIER.DTA' kopieres fra katalogen 'oppgaver' på nettet.

 //  I 'EKS_35.c'  fjernes  '//'  foran 'lesFraFil' og 'skrivTilFil' i 'main'.

 //  Koden i  'EKS_35.c'  utvides/endres med følgende fire funksjoner:


void lesFraFil();
void skrivTilFil();
void maleriLesFraFil(FILE* inn, struct Maleri* m, const char* t);
void maleriSkrivTilFil(FILE* ut, const struct Maleri* m);


/**
 *  Leser HELE datastrukturen (ALLE maleriene) FRA fil.
 *
 *  @see  maleriLesFraFil
 */
void lesFraFil()  {
    FILE* innfil = fopen("MALERIER.DTA", "r");   //  Åpner fil for innlesning.
    char  buffer[STRLEN];

    if (innfil)  {                     //  Filen er funnet:
       printf("\n\nLeser fra filen 'MALERIER.DTA' .....\n\n\n");

       gAntallMaleri = 0;              //  VIKTIG AT ER NULLSTILT! (om IKKE er det allerede)

       fgets(buffer, STRLEN, innfil);  //  Prøver å lese starten på 1.post.
                                       //  Ennå ikke filslutt, og plass til flere:
       while (!feof(innfil)  &&  gAntallMaleri < MAXMALERIER)  {
          buffer[strlen(buffer)-1] = '\0'; //  TAR VEKK AVSLUTTENDE '\n' !!!
                                       //  Oppretter nytt maleri:
          gMalerier[gAntallMaleri] = (struct Maleri*) malloc(sizeof(struct Maleri));
                                       //  Det nye maleriets data leses:
          maleriLesFraFil(innfil, gMalerier[gAntallMaleri], buffer);
          gAntallMaleri++;             //  Teller opp totalantallet.
          fgets(buffer, STRLEN, innfil);  //  Prøver å lese starten på  neste post.
       }
    } else                             //  Filen ikke funnet/mulig å åpne:
       printf("Klarte ikke å finne filen 'MALERIER.DTA'!\n\n");

    fclose(innfil);                    //  Lukker filen.
}


/**
 *  Skriver HELE datastrukturen (ALLE maleriene) TIL fil.
 *
 *  @see  maleriSkrivTilFil
 */
void skrivTilFil()  {
    FILE* utfil = fopen("MALERIER.DT2", "w");   //  Åpner fil for utskrift.

    if (utfil)  {                          //  Filen kan åpnes:
       printf("\n\nSkriver til filen 'MALERIER.DT2' .....\n\n\n");
       for (int i = 0;  i < gAntallMaleri;  i++)  //  Går gjennom ALLE malariene:
           maleriSkrivTilFil(utfil, gMalerier[i]);  //  Hvert maleri skrives.
    } else                                 //  Filen ikke funnet/mulig å åpne:
       printf("Klarte ikke å åpne filen 'MALERIER.DT2'!\n\n");

    fclose(utfil);                         //  Lukker filen.
}


/**
 *  Leser ALLE data om ETT maleri fra fil.
 *
 *  @param   inn  - Filen det skal leses fra
 *  @param   m    - Structen som skal få sine verdier innlest fra fil
 *  @param   t    - Allerede innlest tittel (som skal unnalagres)
 */
void maleriLesFraFil(FILE* inn, struct Maleri* m, const char* t)  {
   char buffer[STRLEN];
                                    //  Lagrer unna medsendt 'tittel':
   m->tittel = (char*) malloc((strlen(t) + 1) * sizeof(char));
   strcpy(m->tittel, t);
                                    //  Leser byens navn:
   fgets(buffer, STRLEN, inn);    buffer[strlen(buffer)-1] = '\0';
   m->by = (char*) malloc((strlen(buffer) + 1) * sizeof(char));
   strcpy(m->by, buffer);
                                    //  Leser stedets navn (i byen):
   fgets(buffer, STRLEN, inn);    buffer[strlen(buffer)-1] = '\0';
   m->sted = (char*) malloc((strlen(buffer) + 1) * sizeof(char));
   strcpy(m->sted, buffer);
                                    //  Leser 3x int'er:
   fscanf(inn, "%i %i %i", &m->aar, &m->bredde, &m->hoyde);

   getc(inn);                       //  LESER '\n' ETTER DE 3x int'ene!!!
}


/**
 *  Skriver ALLE data om ETT maleri til fil.
 *
 *  @param   ut  - Filen det skal skrives til
 *  @param   m   - Structen som alt skal skrives ut om til fil
 */
void maleriSkrivTilFil(FILE* ut, const struct Maleri* m)  {
   fprintf(ut, "%s\n%s\n%s\n%i %i %i\n",     //  Skriver RETT FORMAT:
           m->tittel, m->by, m->sted, m->aar, m->bredde, m->hoyde);
}
