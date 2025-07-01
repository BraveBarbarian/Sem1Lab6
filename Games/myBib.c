#include "mybib.h"



int scanInt() {
	int pruef = 0, zahl = 0;
	do {
		pruef = scanf("%d", &zahl);
		while (getchar() != '\n');
	} while (pruef != 1);
	return zahl;
}

char scanChar() {
	int pruef = 0;
	char c = 0;
	do
	{
		pruef = scanf("%c", &c);
		while (getchar() != '\n');
	} while (pruef != 1);
	return c;
}