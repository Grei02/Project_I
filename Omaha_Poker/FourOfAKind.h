#pragma once
#include "Hand.h"
#include "Card.h"
class FourOfAKind:public Hand
{
private:
	Card handFormed[4];
public:
	bool IsTheOriginCorrect(Card* handFormed, Card* communityCards, Card* playerCards);
	void swap(Card& card1, Card& card2);
	void sortCards(Card* allCards, int size);
	bool evaluate(Card* communityCards, Card* playerCards);
};

