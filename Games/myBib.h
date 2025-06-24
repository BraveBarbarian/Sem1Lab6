#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //printf, scanf
#include <stdlib.h> //system, rand, srand
#include <time.h> //time für srand
#include <conio.h> // _getch

//BlackJack Makros
#define MAX_KARTEN 11 //Maximale Karten, die ein Spieler Ziehen darf
#define DECKGROESSE 312 //312 = 6x52 Karten für ein Standart Blackjack Deck
#define VERSCHIEDENE_KARTEN 14 //Anzahl verschiedener Karten (2-10, B, D, K, A)



int blackJack();
void deckInitialisieren(int deck[DECKGROESSE]);
int karteZiehen(int deck[DECKGROESSE]);
void regeln();
void spielerZug(int spieler[MAX_KARTEN], int dealer[MAX_KARTEN], int deck[DECKGROESSE]);
int kartenZaehlen(int karten[MAX_KARTEN]);
int gesamtWert(int anzahlKarten, int karten[MAX_KARTEN]);

int scanInt();
