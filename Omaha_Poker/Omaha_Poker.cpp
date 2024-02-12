#include "Board.h"
#include "Dealer.h"
#include "GameGraphics.h"

int main() {
	Dealer dealer;
    //GameGraphics game;
	Board board;
    //game.run();
    // Configurar el número de jugadores
    dealer.setNumPlayers(2);

    // Iniciar el juego
    board.startGame();

    // Mostrar las manos de los jugadores y las cartas comunitarias
    board.displayPlayerHands();
    board.displayCommunityCards();

    // Evaluar las manos de los jugadores y determinar al ganador
    board.evaluateHands();
	return 0;
}

