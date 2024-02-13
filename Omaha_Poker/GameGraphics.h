#pragma once
#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <iostream>
#include "Dealer.h"
#include "Player.h"
#include "Board.h"
#include <cmath>
#define M_PI 3.141592653

using namespace std;
using namespace sf;
const int MAX_PLAYERS = 6;
class GameGraphics {
private:
    Dealer dealer;
    Board board;
    RenderWindow window;
    Sprite** cardSprites;
    Sprite startScreenSprite;
    Texture startScreenTexture;
    Sprite instructionsSprite;
    Texture instructionsTexture;
    Sprite gameBackgroundSprite;
    Texture gameBackgroundTexture;
    int maxPlayers;
    int maxCardsPerPlayer;
    Text text;
    Font font;
    RectangleShape inputBox;
    Text inputText;
    bool instructionsScreen = true;
    bool instructionsLoaded = false;
    bool numPlayersEntered = false;
    bool drawCircles = false;
    bool cardsDrawn = false;
    float circleRadius;
    Color playerColors[3] = { Color::Red,Color::Blue, Color::Green }; 
    string playerNames[3] = { "Dealer", "Small Blind", "Big Blind" };
    Vector2f playerPositions[3];
    int numPlayers;

    
    void handleEvents();
    void handleMouseEvents(Event event);
    void handleInstructionsLogic();
    void handleTextInput(Uint32 unicode);
    void handleKeyPress(Keyboard::Key key);
    bool isInsideSpecificAreaInstruccions(Vector2i mousePosition);
    bool isInsideSpecificArea(Vector2i mousePosition);
    void initializeCircleInfo();
    bool isValidCard(const Card& card);
    void render();

public:
    void setupStartScreen();
    void loadAndSetInstructionsTexture(string filename);
    void initializePlayerPositions();
    void loadAndSetGameBackgroundTexture(string filename);
    bool isValidSymbol(char symbol);
    void drawPlayerCards();
    void drawPlayerCircles();
    void setupUI();
    GameGraphics();
    ~GameGraphics();
    void run();
};