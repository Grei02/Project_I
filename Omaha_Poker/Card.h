#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class Card
{
public:
	int value;
    char symbol;
    sf::Texture image;
    sf::Sprite spriteImage;

    Card() {};
    Card(int _value, char _symbol);
    int getValue() ; 
    char getSymbol();
    const sf::Texture* getImage();
    ~Card();
};
