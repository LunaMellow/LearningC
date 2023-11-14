/**
 *   Programeksempel nr 5 - Casting og const.
 *
 *   Omhandler:
 *     - Casting/omgjøring mellom ulike variabeltyper
 *     - const
 *
 *   @file     EKS_05.C  (en del er likt med Program 3.5 i læreboka)
 *   @author   Stephen G.Kochan  /  Frode Haug, NTNU
 */


#include <stdio.h>                //  printf

const float  PI = 3.141593;       ///<  Consten 'PI'
const int    RADIE = 4;           ///<  Consten 'RADIE'

/**
 *  Hovedprogrammet:
 */
 int main ()  {
    float flyttall = 123.125, flyttall2;
    int   heltall, heltall2 = -199;

    
    heltall = flyttall;          //  Mister desimaler når float --> int:
    printf("Flyttall (%f) kopiert over i heltall (%i)\n", flyttall, heltall);

    flyttall = heltall2;         //  Får tillagt .000000 når int --> float:
    printf("Heltall (%i) kopiert over i flyttall (%f)\n", heltall2, flyttall);

    flyttall = heltall2 / 100;   //  Heltallsdivisjon - mister ALLE desimaler:
    printf("Heltall (%i) / 100   over i flyttall (%f)\n", heltall2, flyttall);

    flyttall2 = heltall2 / 100.0;   //  int dividert med float - blir korrekt:
    printf("Heltall (%i) / 100.0 over i flyttall (%f)\n", heltall2, flyttall2);

                         //  float-castet int dividert med int - blir korrekt:
    flyttall2 = (float) heltall2 / 100;
    printf("Float-castet heltall (%i) / 100 over i flyttall (%f)\n\n\n",
            heltall2, flyttall2);


// =======================================================================
//  Bruk av const:

    printf("Sylindervolum: %f\n",  PI * RADIE * RADIE * 8);
    printf("Kulevolum:     %f\n", (4.0 / 3) * PI * RADIE * RADIE * RADIE);
    printf("Kjeglevolum:   %f\n", (PI * RADIE * RADIE * 12) / 3);
    printf("Kjeglevolum:   %f\n",  PI * RADIE * RADIE * 12  / 3.0);
    printf("Kjeglevolum:   %f\n",  PI * RADIE * RADIE * 12  / 3);

//  const:   - Bruk dette aktivt/bevisst/"mye"!
//           - Skrives ALLTID med STORE bokstaver
//             (dermed blir de lette å kjenne igjen, dvs. identifiserbare).
//           - Bruk for verdier som ALDRI endrer seg,
//             f.eks:  pi, dager i uken (7), måneder i året (12),
//                     timer i døgnet (24), minutt i time (60),
//                     sekund i minutt (60), .......
//           - BRUKES FOR ALLE HARDKODEDE (skrevet rett i koden) GJENTAGENDE
//             VERDIER I KODEN SOM LETT KAN ENDRE SEG,
//             f.eks:  STRLEN, MINTEMP, MAXANTALL
//             (Bytt RADIE øverst i koden med 12,
//             og ALLE LEGEMENE ENDRER VOLUM!)

    return 0;
}