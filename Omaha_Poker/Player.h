#pragma once
#include "Hand.h"
#include <string>
using namespace std;

class Player {
private:
    Card* playerHand;
    string playerName;
public:
    Player();
    ~Player();

    void setPlayerName(const string& name); 
    string getPlayerName();
    Card* getPlayerHand();
    void setPlayerHandPosition(Card newCard,int index);

};

