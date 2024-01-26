#pragma once
#include <iostream>
using namespace std;
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
