#include "Board.h"

int main() {
    Board board;
    board.startGame();
    board.displayPlayerHands();
    board.displayCommunityCards();
    board.evaluateHands();

    return 0;
}