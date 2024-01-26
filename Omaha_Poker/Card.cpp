#include "Card.h"

Card::Card(int _value, char _symbol)
{
	value = _value;
	symbol = _symbol;
}

int Card::getValue()
{
	return value;
}

char Card::getSymbol()
{
	return symbol;
}

Card::~Card()
{
}