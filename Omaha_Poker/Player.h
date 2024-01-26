#pragma once
#include "Hand.h"
#include <string>

class Player {
private:
    string playerName;
public:
    Hand* playerHand;
    Player();
    ~Player();
    Hand* getPlayerHand();
    string getPlayerName();
    void setPlayerName(string& name);
};

