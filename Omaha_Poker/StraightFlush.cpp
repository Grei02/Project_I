#include "StraightFlush.h"

bool StraightFlush::IsTheOriginCorrect(Card* handFormed, Card* communityCards, Card* playerCards)
{
    int playerCardsInTheHand = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (playerCards[i].value == handFormed[j].value) {
                playerCardsInTheHand++;
            }
        }
    }

    int communityCardsInTheHand = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (communityCards[i].value == handFormed[j].value) {
                communityCardsInTheHand++;
            }
        }
    }
    if (playerCardsInTheHand == 2 && communityCardsInTheHand == 3) {
        return true;
    }
    return false;
}

void StraightFlush::swap(Card& card1, Card& card2)
{
    Card temp = card1;
    card1 = card2;
    card2 = temp;
}

void StraightFlush::sortCards(Card* allCards, int size)
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (allCards[j].value > allCards[j + 1].value) {
                swap(allCards[j], allCards[j + 1]);
            }
        }
    }
}

bool StraightFlush::evaluate(Card* communityCards, Card* playerCards)
{
    Card allCards[9];
    for (int i = 0; i < 5; i++) {
        allCards[i] = communityCards[i];
    }
    for (int i = 0; i < 4; i++) {
        allCards[i + 5] = playerCards[i];
    }
    sortCards(allCards, 9);


    int count = 0;
    int index;
    for (int i = 0; i < 9; i++) {
        if (allCards[i].value + 1 == allCards[i + 1].value) {
            count++;
            index = i;
        }
    }

    if (count != 5) {
        return false;
    }

    Card* handFormed;
    for (int i = index - 5; i < index; i++) {
        for (int j = 0; j < 5; j++) {
            handFormed[j] = allCards[i];
        }
    }

    char suit = allCards[0].symbol;
    for (int i = 4; i < 9; i++) {
        if (handFormed[i].symbol != suit) {
            return false;
        }
    }

    if (!IsTheOriginCorrect(handFormed, communityCards, playerCards)) {
        return false;
    }
    return true;
}