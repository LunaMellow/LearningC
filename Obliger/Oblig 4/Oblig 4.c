
/**     Oblig 4
 *
 *      Program description:
 *          - This is in in the program
 *          - This is in in the program
 *          - This is in in the program
 *
 *      @file Oblig 4.c
 *      @date 13-Nov-23
 *
 *      @author Luna S.
 *      @alias LunaMellow
 */

// Includes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LesData.h"                    // Toolkit for reading various data

// Const Declarations
#define MAXPERS 6                       ///< Maximum people
#define MAXOPPG 20                      ///< Maximum tasks
#define MAXBOKSTAVER 20                 ///< Maximum letters allowed

// Struct Declarations
struct Oppgave {
    char* navn;
    int   antallTotalt,
          antallNaa;
    int   hvem[MAXPERS];
    struct Oppgave* neste;
};

// Function Declarations
void nyOppgave();
void skrivOppgaver();
void ledigeOppgaver();
void personerTilknyttesOppgave();
void oppgaveTilknyttPersoner(struct Oppgave* oppgave);
void oppgaveSkrivData(const struct Oppgave* oppgave);
void oppgaveLesData(struct Oppgave* oppgave);
void fjernOppgave();
void skrivMeny();

// Global Variable Declarations
struct Oppgave* gOppgavene[MAXOPPG];        ///< Tasks and who they are assigned to
int gSisteOppgave = 0;                      ///< Last task in

/**
 *      Main Program Starts Here
 */
int main ()  {

    // Print out command menu
    skrivMeny();

    // lesChar() from LesData.h . Takes user char input
    char kommando = lesChar("Kommando");

    // Loop menu until 'Q' reached
    while (kommando != 'Q')  {
        switch (kommando)  {
            case 'N':  nyOppgave();                 break;    //  Create new task
            case 'S':  skrivOppgaver();             break;    //  Prints out all info about tasks
            case 'L':  ledigeOppgaver();            break;    //  Available tasks
            case 'T':  personerTilknyttesOppgave(); break;    //  Assign
            case 'F':  fjernOppgave();              break;    //  Find a trolley
            default:   skrivMeny();                 break;    //  Non-existent menu choice
        }
    }

    printf("\n\n");
    return 0;
}
/**
 *  Read data from task
 *
 *  @param oppgave - The task id at hand
 *
 *  @return Updated task information
 */
void oppgaveLesData(struct Oppgave* oppgave) {
    char navn[MAXBOKSTAVER];
    lesText("NAVN", navn, MAXBOKSTAVER);

    // Allocate dynamic memory for oppgave->navn and copy the content
    oppgave->navn = malloc(strlen(navn) + 1);  // +1 for null terminator
    strcpy(oppgave->navn, navn);

    oppgave->antallTotalt = lesInt("PERSONER", 0, 6);
    oppgave->antallNaa = 0;
}

/**
 *  Assigns peopple to tasks
 *
 *  @param oppgave - The task id at hand
 *
 *  @return Updated task information
 */
void oppgaveTilknyttPersoner(struct Oppgave* oppgave) {

}

/**
 *  nyOppgave
 */
void nyOppgave() {
    char svar;

    do {
        if (gSisteOppgave >= MAXOPPG) {
            printf("Maksimalt antall oppgaver %d er nådd. Kan ikke lage flere\n", MAXOPPG);
        }
        else {
            struct Oppgave *nyOppgave = (struct Oppgave *) malloc(sizeof(struct Oppgave));

            oppgaveLesData(nyOppgave);

            nyOppgave->neste = gOppgavene[gSisteOppgave];
            gOppgavene[gSisteOppgave] = nyOppgave;
            gSisteOppgave++;

            lesText("En oppgave til (j/N)",&svar,1); getchar();
        }
    } while (svar != tolower('n'));
}

/**
 *  skrivOppgaver
 */
void skrivOppgaver() {

    for (int i = 0; i < gSisteOppgave; i++) {
        oppgaveSkrivData(gOppgavene[i]);
    }

}

void oppgaveSkrivData(const struct Oppgave* oppgave) {

    printf("NAVN: %s\n"
           "TOTALT: %d\n"
           "ANTALL NÅ: %d\n"
           "PERSONER: %d\n",
           oppgave->navn,
           oppgave->antallTotalt,
           oppgave->antallNaa,
           oppgave->hvem);
}

/**
 *  ledigeOppgaver
 */
void ledigeOppgaver() {

}

/**
 *  personerTilknyttesOppgave
 */
void personerTilknyttesOppgave() {

}

/**
 *  fjernOppgave
 */
void fjernOppgave() {

}

/**
 *  Prints out the menu with a list of commands
 */
void skrivMeny() {
    printf("\n--------------- Velkommen ---------------\n"
           "\n"
           "N = Ny Oppgave\n"
           "S = Se oppgaver\n"
           "L = Ledige oppgaver\n"
           "T = Tilknytt oppgaver\n"
           "F = Fjern oppgaver\n"
           "\n"
           "-----------------------------------------\n");
}