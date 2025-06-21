/*
Bibliothek für das Spiel Blackjack
*/

#include "myBib.h"

int blackJack() {
	char spieler[MAX_KARTEN] = { 0 };
	char dealer[MAX_KARTEN] = { 0 };
	int kartenDeck[DECKGROESSE] = { 0 }; //Kartendeck als Int

	deckInitialisieren(kartenDeck);

	for (int i = 0; i < 100; i++)
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

*/

void deckInitialisieren(int deck[DECKGROESSE]) {
	int kartenWert = 2;

	for (int i = 0; i < DECKGROESSE; i++)
	{
		deck[i] = kartenWert;
		if (kartenWert == 14)
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
		int random = (rand() / DECKGROESSE);
		printf("Position im Deck: %d\n", random);
		int karte = deck[random];

		if (karte != 0)
		{
			deck[random] = 0;
			pruef = 1;
		} 
	} while (pruef != 1);

	return karte;
}