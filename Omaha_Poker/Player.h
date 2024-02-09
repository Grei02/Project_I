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
<<<<<<< HEAD
    Hand* getPlayerHand();
=======
    Card* getPlayerHand();
    void setPlayerHandPosition(Card newCard,int index);
>>>>>>> 475e0bd461c094140f83f7179d9835efbd834820

};

