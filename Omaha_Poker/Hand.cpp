#include "Hand.h"

Hand::Hand()
{
    for (int i = 0; i < maxHandCards; i++) {
        playerHand[i] = Card();
    }
}

Hand::~Hand()
{
}