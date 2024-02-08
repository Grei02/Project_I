#include "Straight.h"
using namespace std;


bool Straight::evaluate(Card* communityCards, Card* playerCards)
{
    unordered_set<int> valores_numericos; 

    for (int i = 0; i < 5; ++i) {
        valores_numericos.insert(communityCards[i].getValue());
        valores_numericos.insert(playerCards[i].getValue());
    }

    size_t valores_unicos = valores_numericos.size();

    return (valores_unicos >= 5);
}
