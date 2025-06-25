/*
Bibliothek für das Spiel Blackjack
*/

#include "myBib.h"

int blackJack() {
	int spieler[MAX_KARTEN] = { 0 };
	int dealer[MAX_KARTEN] = { 0 };
	int kartenDeck[DECKGROESSE] = { 0 }; //Kartendeck als Int
	int regelAuswahl = 0;

	deckInitialisieren(kartenDeck);


	printf("Wilkommen zu Blackjack!\n");
	printf("Kennen Sie die Regeln schon, oder soll ich sie noch einmal erkl\x84ren?\n");
	printf("(1) Ich kenne die Regeln\t(2) Ich kenne die Regeln noch nicht\n");
	do
	{
		regelAuswahl = scanInt();
	} while (regelAuswahl > 2 || regelAuswahl < 1);

	system("cls"); //Consolenausgabe Leeren

	if (regelAuswahl == 2)
	{
		regeln();
		system("cls");
	}

	spielerZug(spieler, dealer, kartenDeck);

	return 0;
}

/*
Ziel: Kartendeck mit allen Spielkarten zu initialisieren, die dann gezogen werden
4 Pro Karte pro Deck.

Parameter: Array deck, der beschrieben werden soll

Rückgabe: -
Beschreiben von Array
*/

void deckInitialisieren(int deck[DECKGROESSE]) {
	int kartenWert = 2;

	for (int i = 0; i < DECKGROESSE; i++)
	{
		deck[i] = kartenWert;
		if (kartenWert == VERSCHIEDENE_KARTEN)
			kartenWert = 2;
		else
			kartenWert++;
	}
	return;
}


int karteZiehen(int deck[DECKGROESSE])
{
	int pruef = 0;
	int karte = 0;
	int random = 0;

	do
	{
		random = (rand() / DECKGROESSE);
		karte = deck[random];

		if (karte != 0)
		{
			deck[random] = 0;
			pruef = 1;
		}
	} while (pruef != 1);

	return karte;
}

void regeln() {
	printf("=== Blackjack Regeln ===\n");
	printf("Ziel: Erreiche mit deinen Karten so nah wie m\x94glich 21 Punkte, ohne sie zu \x81 \bberschreiten.\n");
	printf("Kartenwerte:\n");
	printf("- Zahlenkarten z\x84hlen entsprechend ihrem Wert.\n");
	printf("- Bildkarten (Bube, Dame, K\x94nig) z\x84hlen jeweils 10 Punkte.\n");
	printf("- Ass z\x84hlt 1 oder 11 Punkte, je nachdem, was besser ist.\n");
	printf("Spielablauf:\n");
	printf("- Du und der Dealer erhalten jeweils zwei Karten.\n");
	printf("- Deine Karten sind sichtbar, vom Dealer nur eine.\n");
	printf("- Du kannst weitere Karten ziehen ('Hit') oder keine mehr nehmen ('Stand').\n");
	printf("- \x81\bberschreitest du 21 Punkte, verlierst du sofort.\n");
	printf("- Wenn du 'Stand' w\x84hlst, spielt der Dealer nach festen Regeln weiter.\n");
	printf("- Der Dealer zieht Karten bis mindestens 17 Punkte erreicht sind.\n");
	printf("Gewinn:\n");
	printf("- Du gewinnst, wenn du n\x84her an 21 bist als der Dealer ohne \x81 \bber 21 zu gehen.\n");
	printf("- Bei Gleichstand gibt es keinen Gewinn und keinen Verlust.\n\n");
	printf("Bitte Dr\x81 \bcken Sie eine Taste um fortzufahren.");
	int pruef = _getch();
}

void spielerZug(int spieler[MAX_KARTEN], int dealer[MAX_KARTEN], int deck[DECKGROESSE]) {
	char spielZug = 0;
	int verloren = 0;
	int gesamt[SPIELERZAHL] = { 0 };
	int spielerKarten = 0;
	spieler[0] = karteZiehen(deck);
	spieler[1] = karteZiehen(deck);
	dealer[0] = karteZiehen(deck);
	//dealer[1] = karteZiehen(deck);

	do
	{
		if (spielZug == 'h')
		{
			spieler[kartenZaehlen(spieler)] = karteZiehen(deck);
		}

		druckeSpielfeld(spieler, dealer, deck, gesamt);

		if (gesamt[1] < 21)
		{
			printf("Bitte dr\x81 \bcken Sie 'h' f\x81r Hit und eine andere Taste f\x81r Stand\n");
			spielZug = _getch();
		}
		else if (gesamt[1] > 21) {
			printf("Sie haben das Spiel leider verloren, weil Sie sich \x81 \bberkauft haben!\n\n");
			verloren = 1;
			return;
		}


	} while (spielZug == 'h' || verloren == 1);

	if (verloren == 0) {
		while (gesamtWert(kartenZaehlen(dealer), dealer) < 17) {

			dealer[kartenZaehlen(dealer)] = karteZiehen(deck);
			druckeSpielfeld(spieler, dealer, deck, gesamt);
		}
		druckeSpielfeld(spieler, dealer, deck, gesamt);

		if (gesamt[1] > gesamt[0] || gesamt[0] > 21)
			printf("Sehr gut! Sie haben gewonnen!\n\n");
		else if (gesamt[1] < gesamt[0])
			printf("Sie haben leider verloren!\n\n");
		else
			printf("Sie haben gleichstand mit dem Dealer!\n\n");
	}


	return;
}

int kartenZaehlen(int karten[MAX_KARTEN]) {
	int anzahl = 0;
	while (karten[anzahl] != '\0')
	{
		anzahl++;
	}
	return anzahl;
}

int gesamtWert(int anzahlKarten, int karten[MAX_KARTEN]) {
	int gesamtWert = 0;
	for (int i = 0; i < anzahlKarten; i++)
	{
		if (karten[i] <= 10)
		{
			printf(" [ %d ]", karten[i]);
			gesamtWert += karten[i];
		}
		else
		{
			switch (karten[i])
			{
			case 11:
				printf(" [ B ]");
				gesamtWert += 10;
				break;
			case 12:
				printf(" [ D ]");
				gesamtWert += 10;
				break;
			case 13:
				printf(" [ K ]");
				gesamtWert += 10;
				break;
			case 14:
				printf(" [ A ]");
				if (gesamtWert > 10)
					gesamtWert += 1;
				else
					gesamtWert += 11;
				break;
			default:
				break;
			}
		}
	}
	return gesamtWert;
}


void druckeSpielfeld(int spieler[MAX_KARTEN], int dealer[MAX_KARTEN], int deck[DECKGROESSE], int gesamt[SPIELERZAHL]) {

	system("cls");
	printf("\n===================== BLACKJACK =====================\n");
	printf("Dealer:\n");

	gesamt[0] = gesamtWert(kartenZaehlen(dealer), dealer);
	if (kartenZaehlen(dealer) <= 1) {
		printf(" [ \xDB ]\n"); //Verdeckte Karte
	}
	printf("\nGesamtwert: %d\n", gesamt[0]);

	printf("\n-------------------------------\n");

	printf("Spieler:\n");

	printf("\n"); //schleife einfügen, while karte != '\0'
	gesamt[1] = gesamtWert(kartenZaehlen(spieler), spieler);
	printf("\nGesamtwert: %d\n", gesamt[1]);
	printf("=====================================================\n\n");
	return;

}