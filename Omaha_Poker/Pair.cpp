#include "Pair.h"

bool Pair::evaluate(Card* communityCards, Card* playerCards) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (communityCards[i].value == playerCards[j].value) {
                return true; 
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (communityCards[i].value == communityCards[j].value) {
                return true;
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (playerCards[i].value == playerCards[j].value) {
                return true; 
            }
        }
    }

    return false; 
}