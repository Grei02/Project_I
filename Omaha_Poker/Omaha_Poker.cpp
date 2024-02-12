#include "Board.h"
#include "Dealer.h"
#include "GameGraphics.h"

int main() {
    //GameGraphics game;
	Board board;
    board.setNumPlayers(2); 
    board.startGame();
    board.displayPlayerHands();
    board.displayCommunityCards();
    board.evaluateHands();
   //game.run();
	return 0;
}

