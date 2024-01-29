#include "HighCard.h"

bool HighCard::evaluate(Card* communityCards, Card* playerCards)
{
    sortCards(communityCards, numCommunityCards);
    sortCards(playerCards, numPlayerCards);

    Card playerHighCard = playerCards[numPlayerCards - 1];
    Card communityHighCard = communityCards[numCommunityCards - 1];
 
    return playerHighCard.value > communityHighCard.value;
}

void HighCard::swap(Card& card1, Card& card2)
{
    Card temp = card1;
    card1 = card2;
    card2 = temp;
}

void HighCard::sortCards(Card* allCards, int size)
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (allCards[j].value > allCards[j + 1].value) {
                swap(allCards[j], allCards[j + 1]);
            }
        }
    }
}
