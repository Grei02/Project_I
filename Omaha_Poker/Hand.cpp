#include "Hand.h"

Hand::Hand()
{
    for (int i = 0; i < maxHandCards; i++) {
        playerHand[i] = new Card();
    }
}

Hand::~Hand()
{
}