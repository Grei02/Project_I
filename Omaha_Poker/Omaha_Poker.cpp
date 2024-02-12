#include "Board.h"
#include "Dealer.h"
#include "GameGraphics.h"

GameGraphics game;
Board board;

int main() {

	game.run();
	board.startGame();
	board.displayPlayerHands();
	board.displayCommunityCards();
	board.evaluateHands();

	try {
		game.setupStartScreen();
		game.loadAndSetInstructionsTexture("images/instructions.png");
		game.loadAndSetGameBackgroundTexture("images/gameBackground.png");
		game.drawPlayerCards();
		game.drawPlayerCircles();
		game.setupUI();
	}
	catch (const runtime_error& e) {
		cerr << "Error en la carga de la textura. " << e.what() << endl;
	
	}
	catch(const exception& e){
		cerr << "Error en la caraga de la fuente. " << e.what() << endl;
	}
	

	return 0;
}

