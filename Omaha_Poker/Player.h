#pragma once
#include "Hand.h"
#include <string>
using namespace std;

class Player {
private:
    Hand* playerHand;
    string playerName;
public:
    Player();
    ~Player();

    void setPlayerName(const string& name); 
    string getPlayerName();
    Hand* getPlayerHand();

};

