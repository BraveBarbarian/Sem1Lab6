//Autoren: Lars Rippert, Fiona Wilhelm
//Datum: 28.06.2025
//Version: 1.0
//Beschreibung: Das Programm wandelt Groß- in Kleinbuchstaben um und andersherum

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <ctype.h>


int main() {
	char buchstabe = 0; //Eingelesener Buchstabe
	char ausgabe = 0; //Auszugebener Buchstabe
	char erneut = 0; //zum eventuellen weiteren Start des Programms
	int pruef = 0; //Prüfsumme

	do { //Schleife zum erneuten Startes des Programms
		do {//Abfrage des Buchstabens
			printf("Bitte geben Sie einen Buchstaben ein:\n");
			pruef = scanf("%c", &buchstabe);
			while (getchar() != '\n');
		} while (pruef != 1 || buchstabe < 65 || buchstabe > 122);

		//Umwandlung und Ausgabe des Buchstabens
		if (buchstabe > 96 && buchstabe < 123) {
			ausgabe = toupper(buchstabe);
			printf("Grosser Buchstabe = %c\n\n", ausgabe);
		}
		if (buchstabe > 64 && buchstabe < 91) {
			ausgabe = tolower(buchstabe);
			printf("Kleiner Buchstabe = %c\n\n", ausgabe);
		}
		printf("Fuer Umwandlung eines weiteren Buchstabens bitte 'J' eingeben\n");
		pruef = scanf("%c", &erneut);
		while (getchar() != '\n');
	} while (erneut == 'J' || erneut == 'j');

	return 0;
}