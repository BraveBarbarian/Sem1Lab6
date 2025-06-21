#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//BlackJack Makros
#define MAX_KARTEN 10
#define DECKGROESSE 312 //312 = 6x52 Karten für ein Standart Blackjack Deck



int blackJack();
void deckInitialisieren(int deck[DECKGROESSE]);
int karteZiehen(int deck[DECKGROESSE]);