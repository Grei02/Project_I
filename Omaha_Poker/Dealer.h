#pragma once
#include "Deck.h"
#include "Player.h"
#include <iostream>
using namespace std;

class Dealer {
private:
    static const int MAX_PLAYERS = 6;
    static const int NUM_CARDS_PER_PLAYER = 4;
    static const int NUM_SHOWED_CARDS = 5;

    Deck deck;
    Card* showedCards[NUM_SHOWED_CARDS];
    int numPlayers;
    Player* players[MAX_PLAYERS];

    void swapCards(Card& card1, Card& card2);

public:
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