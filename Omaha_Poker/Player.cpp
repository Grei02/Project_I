#include "Player.h"

Player::Player() : playerHand() {
    
}

void Player::setPlayerName(const string& name) { 
    playerName = name;
}

Card* Player::getPlayerHand() {

    return playerHand;
}

void Player::setPlayerHandPosition(Card newCard, int index)
{
    playerHand[index] = newCard;
}

string Player::getPlayerName() {
    return playerName;
}

Player::~Player() {
}