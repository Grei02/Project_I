#pragma once
#include "Hand.h"
const int numCommunityCards = 5;
const int numPlayerCards = 4;
class HighCard :public Hand
{
	bool evaluate(Card* communityCards, Card* playerCards);
	void swap(Card& card1, Card& card2);
	void sortCards(Card* allCards, int size);
};

