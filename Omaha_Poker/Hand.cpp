#include "Hand.h"

Hand::Hand()
{
    for (int i = 0; i < maxHandCards; i++) {
        playerHand[i] = nullptr;
    }
}

Hand::~Hand()
{
    for (int i = 0; i < maxHandCards; i++) {
        playerHand[i] = nullptr;
    }
}