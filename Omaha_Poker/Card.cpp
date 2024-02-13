#include "Card.h"

int Card::getValue()
{
	return value;
}

char Card::getSymbol()
{
	return symbol;
}

string Card::getImagePath() {
	return imagePath;
}

Card::~Card()
{
}