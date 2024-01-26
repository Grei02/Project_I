#pragma once
#include "Card.h"
#include "Deck.h"
#include <algorithm>
#include <ctime>

class Deck {
private:
    Card cards[52];
    int currentIndex;

public:
    Deck();
    void generateDeck();
    void shuffleDeck();
    Card dealCard();
};