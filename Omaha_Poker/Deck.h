#pragma once
#include "Card.h"
#include "Deck.h"
#include <algorithm>
#include <ctime>

static const int TOTAL_CARDS = 52;
class Deck {
private:
    Card cards[TOTAL_CARDS];
    int currentIndex;

public:
    Deck();
    void generateDeck();
    void shuffleDeck();
    Card dealCard();
}; 