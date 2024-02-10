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

    void setupStartScreen();
    void handleEvents();
    void handleMouseEvents(const Event& event);
    bool isInsideSpecificAreaInstruccions(const Vector2i& mousePosition);
    bool isInsideSpecificArea(const Vector2i& mousePosition);
    void loadAndSetInstructionsTexture(const string& filename);
    void loadAndSetGameBackgroundTexture(const string& filename);
    void render();

public:
    GameGraphics();
    void run();
};
