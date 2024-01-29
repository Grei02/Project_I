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
const int MAX_HANDS = 6;
class Board {
private:
    Dealer dealer;
    Hand* hands[MAX_HANDS];
   
public:
    Card card;
    void startGame();
    void displayPlayerHands();
    void displayCommunityCards();
    void evaluateHands();
};

