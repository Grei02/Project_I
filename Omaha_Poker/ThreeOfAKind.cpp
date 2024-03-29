#include "ThreeOfAKind.h"

bool ThreeOfAKind::IsTheOriginCorrect(Card* handFormed, Card* communityCards, Card* playerCards)
{
    int playerCardsInTheHand = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (playerCards[i].value == handFormed[j].value) {
                playerCardsInTheHand++;
            }
        }
    }

    int communityCardsInTheHand = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (communityCards[i].value == handFormed[j].value) {
                communityCardsInTheHand++;
            }
        }
    }

    if (playerCardsInTheHand == 2 && communityCardsInTheHand == 1) {
        return true;
    }
    return false;
}

void ThreeOfAKind::swap(Card& card1, Card& card2)
{
    Card temp = card1;
    card1 = card2;
    card2 = temp;
}

void ThreeOfAKind::sortCards(Card* allCards, int size)
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (allCards[j].value > allCards[j + 1].value) {
                swap(allCards[j], allCards[j + 1]);
            }
        }
    }
}

bool ThreeOfAKind::evaluate(Card* communityCards, Card* playerCards)
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

    if (count != 3) {
        return false;
    }

    for (int i = index - 3; i < index; i++) {
        for (int j = 0; j < 3; j++){
            handFormed[j] = allCards[i];
        }
    }

    if (IsTheOriginCorrect(handFormed, communityCards, playerCards)) {
        return false;
    }
    return true;
}
