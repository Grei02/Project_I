#pragma once
#include "Player.h"
#include "board.h"
#include "Card.h"
#include "Hand.h"
#include "Dealer.h"
#include <iostream>
#include "Hand.h"
#include "Pair.h"
#include "DoublePair.h"
#include "Flush.h"
#include "Straight.h"
#include "StraightFlush.h"
#include "FourOfAKind.h"
#include "RoyalFlush.h"
#include "HighCard.h"
#include "Dealer.h"
#include "ThreeOfAKind.h"
#include "FullHouse.h"
using namespace std;
const int MAX_HANDS = 10;

class Board {
private:
    Dealer dealer;
public:
    Card card;
    void startGame();
    void setNumPlayers(int number);
    void displayPlayerHands();
    void displayCommunityCards();
    void evaluateHands();
};

