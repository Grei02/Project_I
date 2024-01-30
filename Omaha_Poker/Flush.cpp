#include "Flush.h"

bool Flush::evaluate(Card* communityCards, Card* playerCards) {
    char palo_carta_1 = communityCards->getSymbol();

    for (int i = 1; i < 5; ++i) {
        if (communityCards->getSymbol() != palo_carta_1) {
            return false; 
        }
    }

    for (int i = 0; i < 4; ++i) { 
        if (playerCards[i].getSymbol() != palo_carta_1) {
            return false;
        }
    }

    return true; 
}

