#pragma once
#include "Hand.h"
#include "Straight.h"
#include "Flush.h"

class StraightFlush:public Hand
{
	public:
		bool evaluate(Card* communityCards, Card* playerCards);
		bool IsTheOriginCorrect(Card* handFormed, Card* communityCards, Card* playerCards);
		void swap(Card& card1, Card& card2);
		void sortCards(Card* allCards, int size);
};

