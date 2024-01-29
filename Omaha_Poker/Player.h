#pragma once
#include "Hand.h"
#include <string>

class Player {
private:
    string playerName;
   // Hand* playerHand;
public:
    Hand* playerHand;
    Player();
    ~Player();
    Hand* getPlayerHand();
    string getPlayerName();
    void setPlayerName(string& name);
};

