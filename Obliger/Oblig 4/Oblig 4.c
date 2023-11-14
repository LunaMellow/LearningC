
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
 *
 *      HUSK
 *      @brief Om funksjonen
 *      @see Funksjoner brukt
 */

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
};

// Function Declarations
void nyOppgave();
void skrivOppgaver();
void ledigeOppgaver();
void personerTilknyttesOppgave();
void oppgaveTilknyttPersoner(struct Oppgave* oppgave);
void oppgaveSkrivData(const struct Oppgave* oppgave);
bool oppgaveLedigPlass(const struct Oppgave* oppgave);
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
    char kommando = lesChar("\nKommando");

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

        kommando = lesChar("\nKommando");

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

    oppgave->navn = lagOgLesText("Navn");
    oppgave->antallTotalt = lesInt("Antall", 1, MAXPERS);
    oppgave->antallNaa = 0;
    oppgave->hvem[gSisteOppgave] = 0;

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

bool oppgaveLedigPlass(const struct Oppgave* oppgave) {
    if (oppgave->antallNaa < oppgave->antallTotalt) {
        return true;
    }
    else {
        return false;
    }
}

/**
 *  nyOppgave
 */
void nyOppgave() {

    if (gSisteOppgave < MAXOPPG) {

        gOppgavene[gSisteOppgave] = (struct Oppgave *) malloc(sizeof(struct Oppgave));

        oppgaveLesData(gOppgavene[gSisteOppgave++]);
    }
    else {
        printf("Maksimalt antall oppgaver %d oppnådd", MAXOPPG);
    }

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

    printf("\n\nNavn: %s\n"
           "Totalt: %d\n"
           "Antall: %d\n",
           oppgave->navn,
           oppgave->antallTotalt,
           oppgave->antallNaa);
    if (oppgave->antallNaa != 0) {
        printf("Hvem: ");
    }

    for (int i = 0; i < oppgave->antallNaa; i++) {
        printf("%d, ", oppgave->hvem[i]);
    }
}

/**
 *  ledigeOppgaver
 */
void ledigeOppgaver() {
    for (int i = 0; i < gSisteOppgave; i++) {
        if (oppgaveLedigPlass(gOppgavene[i]) == true) {
            oppgaveSkrivData(gOppgavene[i]);
        }
        else {
            printf("Ingen ledige plasser");
        }
    }

}

/**
 *  personerTilknyttesOppgave
 */
void personerTilknyttesOppgave() {
    if (gOppgavene != 0) {

    }
    else {
        printf("Datastrukturen er tom");
    }
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