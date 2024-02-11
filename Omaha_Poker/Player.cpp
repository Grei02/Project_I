#include "Player.h"

Player::Player() : playerHand() { 
}

void Player::setPlayerName( string& name) { 
    playerName = name;
}

Card* Player::getPlayerHand() {

    return playerHand;
}
 
void Player::setPlayerHandPosition(Card* newCard, int index)
{
    if (index >= 0 && index < NUM_CARDS_PLAYER) {
        playerHand[index] = *newCard;
    }
}

string Player::getPlayerName() {
    return playerName;
}

Player::~Player() {
    delete playerHand;
}