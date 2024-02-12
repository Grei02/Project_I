#include "FullHouse.h"

bool FullHouse::IsTheOriginCorrect(Card* handFormed, Card* communityCards, Card* playerCards)
{
    int playerCardsInTheHand = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (playerCards[i].value == handFormed[j].value) {
                playerCardsInTheHand++;
            }
        }
    }

    int communityCardsInTheHand = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (communityCards[i].value == handFormed[j].value) {
                communityCardsInTheHand++;
            }
        }
    }
    return (playerCardsInTheHand == 2 && communityCardsInTheHand == 3);
}

void FullHouse::swap(Card& card1, Card& card2)
{
    Card temp = card1;
    card1 = card2;
    card2 = temp;
}

void FullHouse::sortCards(Card* allCards, int size)
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (allCards[j].value > allCards[j + 1].value) {
                swap(allCards[j], allCards[j + 1]);
            }
        }
    }
}

bool FullHouse::evaluate(Card* communityCards, Card* playerCards)
{
    Card allCards[9];
    for (int i = 0; i < 5; i++) {
        allCards[i] = communityCards[i];
    }
    for (int i = 0; i < 4; i++) {
        allCards[i + 5] = playerCards[i];
    }
    sortCards(allCards, 9);

    Card handFormed[9]; 
    int index = 0;
    for (int i = 0; i < 9; i++) {
        if (allCards[i].value == allCards[i + 1].value && allCards[i + 1].value == allCards[i + 2].value) {
            handFormed[index] = allCards[i];
            handFormed[index + 1] = allCards[i + 1];
            handFormed[index + 2] = allCards[i + 2];
            index += 3;
        }
        else if (allCards[i].value == allCards[i + 1].value && allCards[i + 1].value != allCards[i + 2].value) {
            handFormed[index] = allCards[i];
            handFormed[index + 1] = allCards[i + 1];
            index += 2;
        }
    }
    return (IsTheOriginCorrect(handFormed, communityCards, playerCards));

}
