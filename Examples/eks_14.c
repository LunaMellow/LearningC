/**
 *   Programeksempel nr 14 - While-løkke.
 *
 *   @file     EKS_14.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>          //  printf, scanf

const int STRLEN  =  20;    ///<  Max.tekstlengde.

/**
 *  Hovedprogrammet:
 */
int main ()  {
    float tall, tall2,      //  2x innleste verdier.
          svar;             //  Disse to tallene dividert.

    printf("\nSkriv to tall (gjerne float) som inngår i divisjon:  ");
    scanf("%f%f", &tall, &tall2);    //  Leser 2x verdier
    while (tall2 == 0)  {            //  Kan ikke dividere/dele med null:
      printf("\nÅ dele med null er tull. ");
      printf("Derfor kan ikke det andre tallet være null. Prøv igjen.\n");
      printf("Skriv det andre tallet (gjerne float) som inngår i divisjonen:  ");
      scanf("%f", &tall2);           //  Leser KUN det andre tallet (divisor).
    }
    svar = tall / tall2;             //  Beregner og skriver ut svaret:
    printf("\n%f / %f = %f\n\n", tall, tall2, svar);


//****************************************************************************

    char tegn;                         //  Innlest tegn.
    int  antallTegn = 0;               //  Antall tegn lest inn
                                       //     (ulikt ' ', \t  og \n).
    printf("\nSkriv tegn, avslutt med '!':  ");
    scanf(" %c", &tegn);               //  Leser ETT tegn.
    while (tegn != '!')  {             //  Så lenge ikke avslutte:
        antallTegn++;                  //  Teller opp antall tegn lest.
        scanf(" %c", &tegn);           //  Leser neste tegn.
    }                                  //  Skriver status om tellingen:
    printf("\nAntall tegn skrevet inn (ulikt ' ', '\\t' '\\n'): %i\n\n\n",
           antallTegn);


//****************************************************************************

    int  time, minutt, sekund,         //  3x tidsvariable.
         totaltSekund;                 //  Tid i sekunder.

    printf("\nSkriv tid (tt mm ss, avslutt med kun tt < 0):  ");
    scanf("%i", &time);                //  Leser kun EN verdi.
    while (time >= 0)  {               //  Så lenge positivt tall:
       scanf("%i%i", &minutt, &sekund);  //  Leser 2x neste verdier.
                                         //  Regner om til antall sekunder:
       totaltSekund = (time * 3600) + (minutt * 60) + sekund;
       printf("\t%i:%i:%i tilsvarer i sekunder:  %i\n",
              time, minutt, sekund, totaltSekund);  //  Skriver resultatet.
       printf("\nSkriv tid (tt mm ss, avslutt med kun tt < 0):  ");
       scanf("%i", &time);               //  Leser igjen kun EN verdi.
    }

//  For kompletthets hensyn: Hvordan beregne det motsatte ut fra KUN sekunder:
    time   = totaltSekund / 3600;          //  Antall HELE timer.
    minutt = (totaltSekund % 3600) / 60;   //  Når timer tatt vekk, #HELE min.
    sekund = totaltSekund % 60;            //  Totalresten er sekunder.
    printf("\n%i er altså: %i time(r) %i minutt(er) %i sekund(er).\n\n\n",
           totaltSekund, time, minutt, sekund);   //  Skriver det utregnede.


//****************************************************************************
                              //  NB: Siste leste verdi var en int vha. scanf.
    getchar();                //      Må derfor forkaste '\n' i inputbufferen,
                              //      for skal nå lese ENHVER char som kommer.

    int  indeks;                       //  Indeks for lest tegn i 'tekst'.
    char tekst[STRLEN];                //  Unnalagrede innleste tegn.

                                       //  Leser tekst tre ganger:
                                       //  For å teste/utforske/prøve:
                                       //    1.gang: Skriv tekst på <=19 tegn.
                                       //    2.gang: Kun ENTER (blank tekst).
    for (int i = 1;  i <= 3;  i++)  {  //    3.gang: Tekst >=20 lang
        indeks = 0;                    // Nullstiller innleggelse av nye tegn.
        printf("\nTekst (<=%i lang): ", STRLEN-1);
        scanf("%c", &tegn);          //  Leser ETT tegn (uansett)
                                     //  Ennå ikke ENTER eller for lang tekst.
        while (tegn != '\n'  &&  indeks < STRLEN-1)  {
            tekst[indeks++] = tegn;  //  Lagrer unna, øker til neste indeks.
            scanf("%c", &tegn);      //  Leser ETT tegn (uansett)
        }
        tekst[indeks] = '\0';        //  Avslutter manuelt med '\0'.
        printf("Innlest tekst: -%s-\n", tekst);    //  Skriver lagret tekst.
        printf("\t(Indeks: %i)\n", indeks);        //  Hva 'indeks' nå er.
    }


//  KONKLUSJON:   while-løkke går NULL eller flere ganger.

    return 0;
}
