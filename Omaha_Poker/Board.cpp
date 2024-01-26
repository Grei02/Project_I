#include "Board.h"

void Board::startGame()
{
    dealer.dealCards();
}

void Board::displayPlayerHands() {
    Hand** playerCards = dealer.getPlayerHands();

    for (int i = 0; i < dealer.getNumPlayers(); ++i) {

        cout << dealer.getPlayers()[i]->getPlayerName() << "'s cards: ";
        for (int j = 0; j < 4; ++j) {
            cout << playerCards[i]->playerHand[j]->getValue() << playerCards[i]->playerHand[j]->getSymbol() << " ";
        }
        cout << endl;
    }
}

void Board::displayCommunityCards() {
    Card** flop = dealer.getFlop();
    cout << "Flop: ";
    for (int i = 0; i < 3; ++i) {
        cout << flop[i]->getValue() << flop[i]->getSymbol() << " ";
    }
    cout << endl;

    Card** turn = dealer.getTurn();
    cout << "Turn: ";
    cout << turn[0]->getValue() << turn[0]->getSymbol() << " ";
    cout << endl;

    Card** river = dealer.getRiver();
    cout << "River: ";
    cout << river[0]->getValue() << river[0]->getSymbol() << " ";
    cout << endl;

    Card** showedCards = dealer.getShowedCards();
    cout << "Showed Cards: ";
    for (int i = 0; i < 5; ++i) {
        cout << showedCards[i]->getValue() << showedCards[i]->getSymbol() << " ";
    }
    cout << endl;
}
