#include "Card.h"

Card::Card(int _value, char _symbol)
{	
	string direction;
	string folder = "Pictures/";
	string format = ".png";
	value = _value;
	symbol = _symbol;
	direction = folder + _symbol + to_string(_value) + format;
	if (!imagen.loadFromFile(direction)) {
		cerr<<"error al cargar"<<direction<<endl;
	}
	spriteImagen.setTexture(imagen);
}

int Card::getValue()
{
	return value;
}

char Card::getSymbol()
{
	return symbol;
}

Texture Card::getImagen()
{
	return imagen;
}

Card::~Card()
{
}