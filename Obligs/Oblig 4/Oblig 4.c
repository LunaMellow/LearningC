
/**     Oblig 4
 *
 *      Program description:
 *          - Promt user with command menu
 *          - Using structs, pointers and memory allocation
 *          - Create new task, show tasks, assign tasks or remove tasks
 *
 *      @file Oblig 4.c
 *      @date 13-Nov-23
 *
 *      @author Luna S.
 *      @alias LunaMellow
 *
 */

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LesData.h"                    // Toolkit for reading various data

// Const Declarations
#define MAXPERS 6                       ///< Maximum people
#define MAXOPPG 20                      ///< Maximum tasks

// Struct Declarations
struct Oppgave {
    char* navn;
    int   antallTotalt,
          antallNaa;
    int   hvem[MAXPERS];
};

// Function Declarations
void fjernOppgave();
void ledigeOppgaver();
void nyOppgave();
void oppgaveLesData(struct Oppgave* oppgave);
bool oppgaveLedigPlass(const struct Oppgave* oppgave);
void oppgaveSkrivData(const struct Oppgave* oppgave);
void oppgaveSlettData(struct Oppgave* oppgave);
void oppgaveTilknyttPersoner(struct Oppgave* oppgave);
void personerTilknyttesOppgave();
void skrivMeny();
void skrivOppgaver();

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
    char kommando = lesChar("\n\nKommando");

    // Loop menu until 'Q' reached
    while (kommando != 'Q')  {
        switch (kommando)  {
            case 'N':  nyOppgave();                 break;    //  Create new task
            case 'S':  skrivOppgaver();             break;    //  Prints out all info about tasks
            case 'L':  ledigeOppgaver();            break;    //  Available tasks
            case 'T':  personerTilknyttesOppgave(); break;    //  Assign people to task
            case 'F':  fjernOppgave();              break;    //  Remove a task
            default:   skrivMeny();                 break;    //  Print out command menu
        }

        // lesChar() from LesData.h . Takes user char input
        kommando = lesChar("\n\nKommando");
    }

    printf("\n\n");
    return 0;
}

/**
 * @brief Removes a task from the task list
 */
void fjernOppgave() {

    // Checks if no available tasks
    if (gSisteOppgave == 0) {
        printf("Ingen oppgaver tilgjengelig.\n");
        return;
    }

    // Print out available tasks
    printf("Velg oppgaven du vil fjerne: ");
    int valg = lesInt("0 for avbryt", 0, gSisteOppgave);

    // If user types 0, cancel the operation
    if (valg == 0) {
        printf("Avbrutt.\n");
        return;
    }

    // Prompt user if they really want to remove the task
    printf("Er du sikker på at du vil fjerne oppgave %d? (J/N): ", valg);
    char bekreftelse = lesChar("");

    // If user input is not 'J', cancel the removal
    if (bekreftelse != 'J') {
        printf("Fjerning av oppgave avbrutt.\n");
        return;
    }

    // Free the memory for the task that's being removed
    oppgaveSlettData(gOppgavene[valg - 1]);

    // Move the last task to the removed task's place
    if (valg < gSisteOppgave) {
        gOppgavene[valg - 1] = gOppgavene[gSisteOppgave - 1];
        printf("\n\tSiste ble flyttet til den slettedes plass/nummer.\n\n");
    } else {
        printf("\n\tSiste/bakerste oppgave ble fjernet/slettet.\n\n");
    }

    // Reduce total task number
    gSisteOppgave--;

    printf("Oppgave %d er fjernet.\n", valg);
}

/**
 * @brief Prints information about tasks with available slots
 */
void ledigeOppgaver() {
    // Loops through to check with oppgaveLedigPlass() if tasks are available
    for (int i = 0; i < gSisteOppgave; i++) {
        if (oppgaveLedigPlass(gOppgavene[i]) == true) {
            oppgaveSkrivData(gOppgavene[i]);                // Print out available task description
        }
    }
    printf("Ingen ledige plasser");
}

/**
 * @brief Creates a new task and adds it to the task structure
 */
void nyOppgave() {

    // Checks if maximum tasks are reached
    if (gSisteOppgave <= MAXOPPG) {

        // Allocates memory for new task
        gOppgavene[gSisteOppgave] = (struct Oppgave *) malloc(sizeof(struct Oppgave));

        // Get user input for new task
        oppgaveLesData(gOppgavene[gSisteOppgave++]);
    }
    else {
        printf("Maksimalt antall oppgaver %d oppnådd", MAXOPPG);
    }

}

/**
 * @brief Reads data for a new task
 *
 * @param oppgave - The task for which data will be read
 */
void oppgaveLesData(struct Oppgave* oppgave) {

    // Assigns user input to structs
    oppgave->navn = lagOgLesText("Navn");
    oppgave->antallTotalt = lesInt("Antall", 1, MAXPERS);
    oppgave->antallNaa = 0;
    oppgave->hvem[gSisteOppgave] = 0;

}

/**
 * @brief Checks if there are available slots in a task
 *
 * @param oppgave - The task to be checked
 * @return true if there are available slots, false otherwise
 */
bool oppgaveLedigPlass(const struct Oppgave* oppgave) {

    // Checks if there are available tasks and returns true or false
    if (oppgave->antallNaa < oppgave->antallTotalt) {
        return true;
    }
    else {
        return false;
    }
}

/**
 * @brief Prints information about a task
 *
 * @param oppgave - The task to be printed
 */
void oppgaveSkrivData(const struct Oppgave* oppgave) {

    // Print out task data from struct
    printf("\n\nNavn: %s\n"
           "Totalt: %d\n"
           "Antall: %d\n",
           oppgave->navn,
           oppgave->antallTotalt,
           oppgave->antallNaa);

    // Check if there is anyone assigned to the task
    if (oppgave->antallNaa != 0) {
        printf("Hvem: ");
    }

    // Print the assigned people's id's out
    for (int i = 0; i < oppgave->antallNaa; i++) {
        printf("%d, ", oppgave->hvem[i]);
    }
}

/**
 * @brief Deletes data and frees memory for a task
 *
 * @param oppgave - The task to be deleted
 */
void oppgaveSlettData(struct Oppgave* oppgave) {

    // Makes sure that pointer is not NULL
    if (oppgave != NULL) {
        // Frees the memory for navn
        free(oppgave->navn);
        oppgave->navn = NULL;

        // Reset to 0
        oppgave->antallTotalt = 0;
        oppgave->antallNaa = 0;

        // Frees the memory
        free(oppgave);
    }
}

/**
 * @brief Assigns people to an existing task
 *
 * @param oppgave - The task to which people will be assigned
 */
void oppgaveTilknyttPersoner(struct Oppgave* oppgave) {

    // Checks if there are any tasks
    if (gSisteOppgave == 0) {
        printf("Ingen oppgaver tilgjengelig.\n");
        return;
    }

    // Prints out information about the task
    oppgaveSkrivData(oppgave);

    // Checks for available spots in the task
    if (!oppgaveLedigPlass(oppgave)) {
        printf("Ingen ledige plasser på denne oppgaven.\n");
        return;
    }

    // Find how many available spots in the task
    int antallMangler = oppgave->antallTotalt - oppgave->antallNaa;

    // If full, promt user
    if (antallMangler == 0) {
        printf("Alle plassene på denne oppgaven er allerede fylt.\n");
        return;
    }

    // Let user assign people to task
    printf("Angi antall personer som skal tilknyttes oppgaven", antallMangler);
    int antallTilknytte = lesInt("", 0, antallMangler);

    // Promt user for their ID's
    for (int i = 0; i < antallTilknytte; i++) {
        printf("Angi nummeret til person %d", i + 1);
        int personNummer = lesInt("", 1, 1000);

        // Add people to task
        oppgave->hvem[oppgave->antallNaa++] = personNummer;
    }

    // Update information about task
    oppgaveSkrivData(oppgave);
}

/**
 * @brief Assigns people to an existing task
 */
void personerTilknyttesOppgave() {

    // Checks if available tasks
    if (gSisteOppgave == 0) {
        printf("Ingen oppgaver tilgjengelig.\n");
        return;
    }

    // Print out available tasks
    printf("Velg oppgaven du vil tilknytte personer til, ", gSisteOppgave);
    int valg = lesInt("0 for avbryt", 0, gSisteOppgave);

    if (valg == 0) {
        printf("Avbrutt.\n");
        return;
    }

    // Add people to task
    oppgaveTilknyttPersoner(gOppgavene[valg - 1]);

    printf("\n");
}

/**
 * @brief Prints the command menu
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
                  "Q = Lukk programmet"
                  "\n"
                  "-----------------------------------------\n");
}

/**
 * @brief Prints information about all tasks
 */
void skrivOppgaver() {

    // Prints out all created tasks
    for (int i = 0; i < gSisteOppgave; i++) {
        oppgaveSkrivData(gOppgavene[i]);
    }

}