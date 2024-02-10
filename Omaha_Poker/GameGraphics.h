#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class GameGraphics {
private:
    RenderWindow window;
    Texture startScreenTexture;
    Texture instructionsTexture;
    Texture gameBackgroundTexture;
    Sprite startScreenSprite;
    Sprite instructionsSprite; 
    Sprite gameBackgroundSprite;
    Font font;
    Text text;
    Text inputText;
    RectangleShape inputBox;
    bool instructionsScreen = true;
    bool instructionsLoaded=false;
    bool numPlayersEntered=false;

    void setupStartScreen();
    void handleEvents();
    void handleMouseEvents(const Event& event);
    void handleInstructionsLogic();
    bool isInsideSpecificAreaInstruccions(const Vector2i& mousePosition);
    bool isInsideSpecificArea(const Vector2i& mousePosition);
    void loadAndSetInstructionsTexture(const string& filename);
    void loadAndSetGameBackgroundTexture(const string& filename);
    void setupUI();
    void handleTextInput(sf::Uint32 unicode);
    void handleKeyPress(sf::Keyboard::Key key);
    void render();

public:
    GameGraphics();
    void run();
};
