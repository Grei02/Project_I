#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Dealer.h"
#include "Player.h"

using namespace std;
using namespace sf;
const int MAX_PLAYERS = 6;
class GameGraphics {
private:

    Player* players[MAX_PLAYERS];
    int numPlayers;
    const int  NUM_CARDS_PLAYER = 4;
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
    void drawPlayerCards(Player** players, int numPlayers,Vector2f* playerPositions, int numPositions);
    void generatePlayerPositions(Vector2f* positions, int numPlayers);
    void setupUI();
    void handleTextInput(Uint32 unicode);
    void handleKeyPress(sf::Keyboard::Key key);
    void render();

public:
    GameGraphics();
    void run();
};