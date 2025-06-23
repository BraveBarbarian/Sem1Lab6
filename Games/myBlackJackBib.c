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
	printf("- Bildkarten (Bube, Dame, K\x94nig) zählen jeweils 10 Punkte.\n");
	printf("- Ass zählt 1 oder 11 Punkte, je nachdem, was besser ist.\n");
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
	int gesamtWertDealer = 0;
	int gesamtWertSpieler = 0;
	int verloren = 0;
	int kartenAnzahlSpieler = 0;
	int kartenAnzahlDealer = 0;
	spieler[0] = karteZiehen(deck);
	spieler[1] = karteZiehen(deck);
	dealer[0] = karteZiehen(deck);
	dealer[1] = karteZiehen(deck);

	do
	{
		system("cls");
		printf("\n===================== BLACKJACK =====================\n");
		printf("Dealer:\n");
		if (dealer[0] <= 10)
		{
			gesamtWertDealer += dealer[0];
			printf(" [ %d ]", dealer[0]);
		}
		else if (dealer[0] < 14)
		{
			gesamtWertDealer += 10;
			switch (dealer[0])
			{
			case 11:
				printf(" [ B ]");
				break;
			case 12:
				printf(" [ D ]");
				break;
			case 13:
				printf(" [ K ]");
				break;
			default:
				break;
			}
		}
		else
		{
			gesamtWertDealer += 11;
			printf(" [ A ]");
		}

		printf(" [ \xDB ]\n");
		printf("Gesamtwert: %d\n", gesamtWertDealer);

		printf("\n-------------------------------\n");

		printf("Spieler:\n");
		for (int i = 0; spieler[i] != '\0'; i++)
		{
			if (spielZug == 'h')
				spieler[i] = karteZiehen(deck);
			if (spieler[i] <= 10)
			{
				gesamtWertSpieler += spieler[i];
				printf(" [ %d ]", spieler[i]);
			}
			else if (spieler[i] < 14)
			{
				gesamtWertSpieler += 10;
				switch (spieler[i])
				{
				case 11:
					printf(" [ B ]");
					break;
				case 12:
					printf(" [ D ]");
					break;
				case 13:
					printf(" [ K ]");
					break;
				default:
					break;
				}
			}
			else
			{
				if (gesamtWertSpieler <= 10)
					gesamtWertSpieler += 11;
				else
					gesamtWertSpieler += 1;
				printf(" [ A ]");
			}
		}
		printf("\n"); //schleife einfügen, while karte != '\0'
		printf("Gesamtwert: %d\n", gesamtWertSpieler);
		printf("=====================================================\n\n");

		if (gesamtWertSpieler < 21)
		{
			printf("Bitte dr\x81 \bcken Sie 'h' f\x81r Hit und eine andere Taste f\x81r Stand\n");
			spielZug = _getch();
		}
		else if (gesamtWertSpieler > 21) {
			printf("Sie haben das Spiel leider verloren, weil Sie sich \x81 \bberkauft haben!");
			verloren = 1;
			return;
		}

		
	} while (spielZug == 'h' || verloren == 1);


return;
}