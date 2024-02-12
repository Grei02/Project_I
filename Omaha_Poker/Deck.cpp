#include "Player.h"
#include "Dealer.h"

Deck::Deck() : currentIndex(0) {
    generateDeck();
    shuffleDeck();
}

void Deck::generateDeck() 
{
    const char suits[] = { 'H', 'D', 'C', 'S' };
    const int ranks[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
    
    int index = 0;
    for (int i = 0; i < sizeof(suits) / sizeof(suits[0]); i++) {
        char suit = suits[i];
        for (int j = 0; j < sizeof(ranks) / sizeof(ranks[0]); j++) {
            int rank = ranks[j];
            
            cards[index++] = Card(rank, suit);
        }
    }
}

void Deck::shuffleDeck()
{
    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(cards, cards + TOTAL_CARDS);
}

Card Deck::dealCard() {
    if (currentIndex < TOTAL_CARDS) {
        return cards[currentIndex++];
    }
    return Card();
}