#pragma once
#include "Hand.h"
#include <string>
using namespace std;
const int Num_Cards = 4;
class Player {
private:
   
    Card playerHand[Num_Cards];
    string playerName;
public:
    Player();
    ~Player();

    void setPlayerName(const string& name); 
    string getPlayerName();
    Card* getPlayerHand();

    void setPlayerHandPosition(Card newCard,int index);

};

