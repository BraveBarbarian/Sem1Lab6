/*
Bibliothek für Funktionen und Makros die in dem Tic-Tac-Toe Spiel
verwendet werden.
*/

#include "myBib.h"



void ticTacToe() {
	char spielfeld[SPIELFELD_GROESSE][SPIELFELD_GROESSE] = { 0};


	printf("Wilkommen zu Tic Tac Toe!\n");
    druckeTicTacToe(spielfeld);

}



void druckeTicTacToe(char spielfeld[SPIELFELD_GROESSE][SPIELFELD_GROESSE]) {
    for (int i = 0; i < SPIELFELD_GROESSE; i++) {
        // Jede Zelle ist 3 Zeilen hoch – hier ist die obere Linie
        printf("       |       |       \n");

        // Mittlere Zeile: zeigt das Symbol zentriert
        printf("   %c   |   %c   |   %c   \n", spielfeld[i][0], spielfeld[i][1], spielfeld[i][2]);

        // Untere Linie
        printf("_______|_______|_______\n");
    }

    // Letzte untere Begrenzungslinie nicht ganz verbinden
    printf("       |       |       \n");
}