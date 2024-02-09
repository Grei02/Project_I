#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;


class GameGraphics {
private:
    RenderWindow window;
    Texture startScreenTexture;
    Sprite startScreenSprite;

    void setupStartScreen();
    bool loadStartScreenTexture(const string& filename);
    void handleEvents();
    void handleMouseEvents(const Event& event);
    bool isInsideSpecificArea(const Vector2i& mousePosition);
    void loadAndSetInstructionsTexture(const string& filename);
    void render();

public:
    GameGraphics();
    void run();
};
