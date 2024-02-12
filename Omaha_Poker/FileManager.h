#pragma once
#include "Card.h"
#include <fstream>
#include <string>
using namespace std;
class FileManager
{
private:
	string fileDirection;
public:
	FileManager(string direction) :fileDirection(direction){}
	void saveHand(Card* hand,int numberOfCard);
	void readHand();

};

