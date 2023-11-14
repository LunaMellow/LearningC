/**
 *   Løsning til eksamen i GrProg (i C), august 2023, oppgave 1B.
 *
 *   @file     EX_S231B.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>
#include <stdbool.h>
#include <string.h>


struct Hall {
    char hall[30], by[30];
    int  tilskuere;
};

void HallFunk1(const struct Hall h)  {
    printf("%s: %s (%i)", h.hall, h.by, h.tilskuere);
}

bool HallFunk2(const struct Hall* h1, const struct Hall* h2)  {
    return (h1->tilskuere  <  h2->tilskuere);
}

bool HallFunk3(const struct Hall* h, const char* t)  {
    return (strstr(h->by, t));
}

void HallFunk4(struct Hall* h, const char* t)  {
    strcat(h->by, t);
}

struct Hall HallFunk5(const struct Hall h1, const struct Hall* h2) {
    struct Hall h;
    strcpy(h.hall, h1.hall);   strcpy(h.by, h2->by);
    h.tilskuere = h1.tilskuere + h2->tilskuere;
    return h;
}


int main() {
    struct Hall hall1 = { "Telenor Arena", "Oslo", 25000 },
                hall2 = { "Oslo Spektrum", "Oslo", 10500 },
                hall3 = { "Koengen", "Bergen", 24000 };

    HallFunk1(hall1);   printf("   ");   HallFunk1(hall3);   printf("\n");
    if (HallFunk2(&hall2, &hall3)) printf("Banan\n");  else  printf("Eple\n");
    printf("%i %i\n", HallFunk3(&hall1, "Oslo"), HallFunk3(&hall3, "Oslo"));
    HallFunk4(&hall3, "/Festning");    HallFunk1(hall3);     printf("\n");
    hall2 = HallFunk5(hall3, &hall1);  HallFunk1(hall2);     printf("\n");

    return 0;
}


//  Utskrift:  Telenor Arena : Oslo (25000)   Koengen : Bergen (24000)
//             Banan
//             1 0
//             Koengen: Bergen/Festning (24000)
//             Koengen: Oslo (49000)
