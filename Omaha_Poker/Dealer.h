#pragma once
#include "Deck.h"
#include "Player.h"
#include <iostream>
using namespace std;

class Dealer {
private:
    static const int MAX_PlAYERS = 6;
    static const int MIN_PLAYERS = 2;
    static const int NUM_CARDS_PER_PLAYER = 4;
    static const int NUM_SHOWED_CARDS = 5;
    static const int TURN_POSITION = 3;
    static const int RIVER_POSITION = 4;
   
    Deck deck;
    int numPlayers;
    Player* players[MAX_PlAYERS];

    void swapCards(Card& card1, Card& card2);

public:
    Card* showedCards[NUM_SHOWED_CARDS];
    Dealer();
    ~Dealer();

    void requestNumPlayers();
    void dealCards();

    Hand** getPlayerHands();
    Card** getFlop();
    Card** getTurn();
    Card** getRiver();
    Card** getShowedCards();
    int getNumPlayers() const;
    Player** getPlayers();
};