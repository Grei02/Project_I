#include "GameGraphics.h"
GameGraphics::GameGraphics() : window(VideoMode(800, 600), "Omaha Poker") {
    startScreenTexture.loadFromFile("inicio.png");
    startScreenSprite.setTexture(startScreenTexture);
}

void GameGraphics::run() {
    while (window.isOpen()) {
        handleEvents();
        render();
    }
}

void GameGraphics::handleEvents() {
    Event event;
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed)
            window.close();
    }
}

void GameGraphics::render() {
    window.clear();
    window.draw(startScreenSprite);
    window.display();
}
