#pragma once
#include "Hand.h"
#include <unordered_set>

class Straight : public Hand
{
public:
    bool evaluate(Card* communityCards, Card* playerCards);
};


