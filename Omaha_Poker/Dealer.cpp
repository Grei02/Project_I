#include "Dealer.h"

void Dealer::swapCards(Card& card1, Card& card2)
{
	Card temp = card1;
	card1 = card2;
	card2 = temp;
}

Dealer::Dealer() :numPlayers(0) {
	requestNumPlayers();
}

Dealer::~Dealer()
{
	for (int i = 0; i < numPlayers; i++) {
		delete players[i];
	}
}

Card** Dealer::getPlayerHands()
{
	Card** playerHands = new Card * [numPlayers];

	for (int i = 0; i < numPlayers; i++) {
		playerHands[i] = players[i]->getPlayerHand();
	}

	return playerHands;
}

void Dealer::requestNumPlayers()
{
	do {
		cout << "Enter the number of players (between 2 and 6): ";
		cin >> numPlayers;
	} while (numPlayers < MIN_PLAYERS || numPlayers > MAX_PlAYERS);

	for (int i = 0; i < numPlayers; i++) {
		players[i] = new Player();
	}
}

void Dealer::dealCards()
{
	for (int i = 0; i < numPlayers; i++) {
		for (int j = 0; j < NUM_CARDS_PER_PLAYER; j++) {
			Card tempCard = deck.dealCard();
<<<<<<< HEAD
			/*players[i]->setPlayerHand()->playerHand[j] = Card(tempCard.getValue(), tempCard.getSymbol());*/
=======
			players[i]->setPlayerHandPosition(Card(tempCard.getValue(), tempCard.getSymbol()), j);
>>>>>>> 475e0bd461c094140f83f7179d9835efbd834820
		}
	}

	for (int i = 0; i < NUM_SHOWED_CARDS; i++) {
		Card tempCard = deck.dealCard();
		showedCards[i] = new Card(tempCard.getValue(), tempCard.getSymbol());
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

