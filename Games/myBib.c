#include "mybib.h"



int scanInt() {
	int pruef = 0, zahl = 0;
	do {
		pruef = scanf("%d", &zahl);
		while (getchar() != '\n');
	} while (pruef != 1);
	return zahl;
}