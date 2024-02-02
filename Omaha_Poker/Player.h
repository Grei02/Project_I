#pragma once
#include "Hand.h"
#include <string>

const int maxHandCards = 4;
class Player {
private:
  
public:
    Player();
    ~Player();
    Hand* playerHand;
    //Card* playerHand[maxHandCards];
    //void getPlayerHand();
    //void deletePlayerHand();
   
  
    
    Hand* getPlayerHand() const;

};

