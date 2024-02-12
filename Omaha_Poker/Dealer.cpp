#include "Dealer.h"

void Dealer::swapCards(Card& card1, Card& card2)
{
	Card temp = card1;
	card1 = card2;
	card2 = temp;
}

Dealer::Dealer()
{
}

Dealer::~Dealer()
{
	for (int i = 0; i < numPlayers; i++) {
		delete players[i];
	}
}

Card** Dealer::getPlayerHands() {
   
    if (numPlayers <= 0) {
        
        cerr << "Error: numPlayers no es válido." << endl;
        return nullptr;
    }
    Card** playerHands = new Card * [numPlayers];

    if (!playerHands) {
     
        cerr << "Error: no se pudo asignar memoria para playerHands." << endl;
        return nullptr;
    }

    for (int i = 0; i < numPlayers; i++) {
        if (!players[i]) {
            cerr << "Error: getPlayerHand() devolvió nullptr para el jugador " << i << "." << endl;
           
            for (int j = 0; j < i; j++) {
                delete[] playerHands[j];
            }
            delete[] playerHands;
            return nullptr;
        }
        playerHands[i] = players[i]->getPlayerHand();
    }

    return playerHands;
}


void Dealer::setNumPlayers(int number) {
	numPlayers = number;

	/*for (int i = 0; i < numPlayers; i++) {
		players[i] = new Player();
	}*/
}
void Dealer::dealCards()
{
	for (int i = 0; i < numPlayers; i++) {
		for (int j = 0; j < NUM_CARDS_PER_PLAYER; j++) {
			Card tempCard = deck.dealCard();
			players[i]->setPlayerHandPosition(Card(tempCard.getValue(), tempCard.getSymbol()), j);
		}
	}

	for (int i = 0; i < NUM_SHOWED_CARDS; i++) {
		Card tempCard = deck.dealCard();
		showedCards[i] = new Card(tempCard.value, tempCard.symbol);
	}
}

Card** Dealer::getFlop()
{
	return showedCards;
}

Card** Dealer::getTurn()
{
	return showedCards + TURN_POSITION;
}

Card** Dealer::getRiver()
{
	return showedCards + RIVER_POSITION;
}

Card** Dealer::getShowedCards()
{
	return showedCards;
}

int Dealer::getNumPlayers()
{
	return numPlayers;
}

Player** Dealer::getPlayers()
{
	return players;
}

