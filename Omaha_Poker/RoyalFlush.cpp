#include "RoyalFlush.h"

void RoyalFlush::swap(Card& card1, Card& card2)
{
    Card temp = card1;
    card1 = card2;
    card2 = temp;
}

void RoyalFlush::sortCards(Card* allCards, int size)
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (allCards[j].value > allCards[j + 1].value) {
                swap(allCards[j], allCards[j + 1]);
            }
        }
    }
}

bool RoyalFlush::evaluate(Card* communityCards, Card* playerCards)
{
    sortCards(communityCards, 5);
    sortCards(playerCards, 4);
    Card allCards[5];
    for (int i = 0; i < 3; i++) {
        allCards[i] = communityCards[5 - i];
    }
    for (int i = 0; i < 2; i++) {
        allCards[i + 3] = playerCards[4 - i];
    }
    sortCards(allCards, 5);
    if (allCards[0].value < 10) {
        return false;
    }

    sortCards(allCards, 9);
    char suit = allCards[0].symbol;
    for (int i = 4; i < 9; i++) {
        if (allCards[i].symbol != suit) {
            return false;
        }
    }

    for (int i = 4; i < 8; i++) {
        if (allCards[i].value + 1 != allCards[i + 1].value) {
            return false;
        }
    }

    return true;
}