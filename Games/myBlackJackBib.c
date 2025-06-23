/*
Bibliothek für das Spiel Blackjack
*/

#include "myBib.h"

int blackJack() {
	char spieler[MAX_KARTEN] = { 0 };
	char dealer[MAX_KARTEN] = { 0 };
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
	}

	for (int i = 0; i < 1; i++)
	{
		int randomkarte = karteZiehen(kartenDeck);
		if (randomkarte <= 10)
			printf("%d\n", randomkarte);
		else
			switch (randomkarte)
			{
			case 11:
				printf("B\n");
				break;
			case 12:
				printf("D\n");
				break;
			case 13:
				printf("K\n");
				break;
			case 14:
				printf("A\n");
				break;
			default:
				break;
			}
	}
	

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
	printf("- Bei Gleichstand gibt es keinen Gewinn und keinen Verlust.\n");
}