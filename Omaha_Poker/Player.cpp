#include "Player.h"

Player::Player() : playerHand(new Hand()) {
	cout << "Enter the player's name: ";
	cin >> playerName;
}

Player::~Player()
{
	delete playerHand;
}

void Player::setPlayerName(string& name)
{
	playerName = name;
}

Hand* Player::getPlayerHand()
{
	return playerHand;
}

string Player::getPlayerName()
{
	return playerName;
}
