#pragma once
#include "Player.h"
#include "board.h"
#include "Card.h"
#include "Hand.h"
#include "Dealer.h"
#include <iostream>
using namespace std;

class Board {
private:
    Dealer dealer;
public:
    Card card;
    void startGame();
    void displayPlayerHands();
    void displayCommunityCards();
};

