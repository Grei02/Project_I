#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdexcept>
#include <string>
#include "Dealer.h"

using namespace sf;
using namespace std;

class GameGraphics {
public:
	GameGraphics();
	~GameGraphics();
	void run();
	void setupStartScreen();
	void loadAndSetInstructionsTexture(string filename);
	void loadAndSetGameBackgroundTexture(string filename);
	void drawPlayerCircles();
	void setupUI();

private:
	RenderWindow window;
	Texture startScreenTexture;
	Sprite startScreenSprite;
	Texture instructionsTexture;
	Sprite instructionsSprite;
	Texture gameBackgroundTexture;
	Sprite gameBackgroundSprite;
	Text text;
	Font font;
	RectangleShape inputBox;
	Text inputText;
	bool instructionsScreen = true;
	bool instructionsLoaded = false;
	bool drawCircles = false;
	bool numPlayersEntered = false;
	const int numPlayers = 3;
	const int maxPlayers = 6;
	float circleRadius;
	string playersName[3] = {"Dealer","Big Blind","Small Blind"};
	Color playerColors[3];
	Vector2f playerPositions[3];
	Sprite** cardSprites;
	Dealer dealer;

	void handleEvents();
	void handleMouseEvents(Event event);
	void handleInstructionsLogic();
	void handleTextInput(sf::Uint32 unicode);
	void handleKeyPress(sf::Keyboard::Key key);
	bool isInsideSpecificAreaInstruccions(Vector2i mousePosition);
	bool isInsideSpecificArea(Vector2i mousePosition);
	void initializePlayerPositions();
	void initializeCircleInfo();
	bool isValidCard(const Card& card);
	bool isValidSymbol(char symbol);
	void drawPlayerCards();
	void render();
};
