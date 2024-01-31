#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class GameGraphics {
private:
   RenderWindow window;
   Texture startScreenTexture;
   Sprite startScreenSprite;

   void handleEvents();
   void render();

public:
    GameGraphics();
    void run();


};
