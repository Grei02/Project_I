#include "Card.h"

Card::Card(int _value, char _symbol)
{	
	string direction;
	string folder = "Pictures/";
	string format = ".png";
	value = _value;
	symbol = _symbol;
	direction = folder + _symbol + to_string(_value) + format;
	if (!image.loadFromFile(direction)) {
		cerr<<"error al cargar la dirreccion"<<endl;
	}
	spriteImage.setTexture(image);
}

int Card::getValue()
{
	return value;
}

char Card::getSymbol()
{
	return symbol;
}

Texture Card::getImage()
{
	return image;
}

Card::~Card()
{
}