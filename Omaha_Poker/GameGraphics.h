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
    Player player;
    RenderWindow window;
    Texture startScreenTexture;
    Texture instructionsTexture;
    Texture gameBackgroundTexture;
    Sprite startScreenSprite;
    Sprite instructionsSprite;
    Sprite gameBackgroundSprite;
    Font font;
    Text text;
    Text errorMessage;
    Text inputText;
    RectangleShape inputBox;
    bool instructionsScreen = true;
    bool instructionsLoaded = false;
    bool numPlayersEntered = false;
    bool errorMessageActive = false;

    void setupStartScreen();
    void handleEvents();
    void handleMouseEvents( Event event);
    void handleInstructionsLogic();
    bool isInsideSpecificAreaInstruccions( Vector2i mousePosition);
    bool isInsideSpecificArea(Vector2i mousePosition);
    void loadAndSetInstructionsTexture( string filename);
    void loadAndSetGameBackgroundTexture(string filename);
    void showErrorMessage(string message);
    void setupUI();
    void handleTextInput(Uint32 unicode);
    void handleKeyPress(sf::Keyboard::Key key);
    void render();

public:
    GameGraphics();
    void run();
};