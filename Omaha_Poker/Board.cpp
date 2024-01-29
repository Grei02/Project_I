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

void Board::evaluateHands() {
	Card** showedCards = dealer.getShowedCards();
	Hand** playerCards = dealer.getPlayerHands();


	Hand* evaluators[8]; 
	evaluators[0] = new RoyalFlush();
	evaluators[1] = new StraightFlush();
	evaluators[2] = new FourOfAKind();
	evaluators[3] = new FullHouse();
	evaluators[4] = new Flush();
	evaluators[5] = new Straight();
	evaluators[6] = new ThreeOfAKind();
	evaluators[1] = new DoublePair();
	evaluators[0] = new Pair();
	evaluators[6] = new HighCard();


	int winningIndex = -1;
	bool isTie = false;

	for (int i = 0; i < dealer.getNumPlayers(); i++) {
		for (int j = 0; j < 7; j++) {
			if (evaluators[j]->evaluate(showedCards[i],getPlayerHands[i]))
				{
				if (winningIndex == -1) {
					winningIndex = i;
				}
				else if (winningIndex != i) {
					isTie = true;
					break;
				}
			}
		}
	}

	if (winningIndex != -1 && !isTie) {
		std::cout << dealer.getPlayers()[winningIndex]->getPlayerName() << " wins!" << std::endl;
	}
	else if (isTie) {
		std::cout << "It's a tie!" << std::endl;
	}
	else {
		std::cout << "No winner found!" << std::endl;
	}
}

