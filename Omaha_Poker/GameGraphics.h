#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Dealer.h"
#include "Player.h"

using namespace std;
using namespace sf;

class GameGraphics {
private:
    Dealer dealer;
    RenderWindow window;
    Sprite startScreenSprite;
    Texture startScreenTexture;
    Sprite instructionsSprite;
    Texture instructionsTexture;
    Sprite gameBackgroundSprite;
    Texture gameBackgroundTexture;
    Text text;
    Font font;
    RectangleShape inputBox;
    Text inputText;
    bool instructionsScreen = true;
    bool instructionsLoaded = false;
    bool numPlayersEntered = false;
    bool drawCircles = false;
    float circleRadius;
    Color playerColors[3] = { Color::Red,Color::Blue, Color::Green }; 
    string playerNames[3] = { "Dealer", "Small Blind", "Big Blind" };
    Vector2f playerPositions[3];

    void handleEvents();
    void handleMouseEvents(Event event);
    void handleInstructionsLogic();
    void setupStartScreen();
    void setupUI();
    void handleTextInput(Uint32 unicode);
    void handleKeyPress(Keyboard::Key key);
    bool isInsideSpecificAreaInstruccions(Vector2i mousePosition);
    bool isInsideSpecificArea(Vector2i mousePosition);
    void loadAndSetInstructionsTexture(string filename);
    void initializePlayerPositions();
    void drawPlayerCircles();
    void loadAndSetGameBackgroundTexture(string filename);
    void initializeCircleInfo();
    void render();

public:
    GameGraphics();
    void run();
};