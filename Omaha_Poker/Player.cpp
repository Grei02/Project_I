#include "Player.h"

Player::Player() : playerHand() { 
}

void Player::setPlayerName(const string& name) { 
    playerName = name;
}

Hand* Player::getPlayerHand() {
    return playerHand;
}

string Player::getPlayerName() {
    return playerName;
}

Player::~Player() {
    delete playerHand;
}