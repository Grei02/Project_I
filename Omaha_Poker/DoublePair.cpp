#include "DoublePair.h"
#include <set>

bool DoublePair::evaluate(Card* communityCards, Card* playerCards) {
    int pairs = 0;
  
    set<int> pairValues;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (communityCards[i].value == playerCards[j].value) {
                pairs++;
                pairValues.insert(communityCards[i].value);
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (communityCards[i].value == communityCards[j].value) {
                pairs++;
                pairValues.insert(communityCards[i].value); 
            }
        }
    }

    return pairValues.size() >= 2; 
}
