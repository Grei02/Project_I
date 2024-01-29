#pragma once
#include "Hand.h"

class Pair : public Hand {
public:
    bool evaluate(Card* communityCards, Card* playerCards); 
};

