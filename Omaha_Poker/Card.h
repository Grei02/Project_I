#pragma once
#include <iostream>
#include <string>
using namespace std;
class Card
{
public:
	int value;
	char symbol;
	string imagePath;

	Card() {};
	Card(int _value, char _symbol) : value(_value), symbol(_symbol) {};

	int getValue();
	char getSymbol();

	~Card();
};
