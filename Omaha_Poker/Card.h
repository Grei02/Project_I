#pragma once
#include <iostream>
class Card
{
public:
	int value;
	char symbol;
	Card() {};
	Card(int _value, char _symbol);
	int getValue();
	char getSymbol();
	~Card();
};
