#include "Hand.h"

void Hand::getPlayerHand()
{
    for (int i = 0; i < maxHandCards; i++) {
        playerHand[i] = new Card();
    }
}
