#include "GameGraphics.h"
#include <iostream>

using namespace std;
using namespace sf;

GameGraphics::GameGraphics() : window(VideoMode(1200, 650), "Omaha Poker") {
    setupStartScreen();
}

void GameGraphics::setupStartScreen() {
    if (!startScreenTexture.loadFromFile("C:/projects/Project_I/Omaha_Poker/images/inicio.png")) {
        cerr << "Error al cargar la textura de la pantalla de inicio." << endl;
    }
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

        if (event.type == Event::Closed) {
            window.close();
        }

        if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {

            Vector2i mousePosition = Mouse::getPosition(window);
            cout << "Mouse pressed at position: (" << mousePosition.x << ", " << mousePosition.y << ")" << endl;
            FloatRect specificArea(992, 580, 1172, 626);
            if (specificArea.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
                cout << "Click inside the specific area." << endl;
                Texture instructionsTexture;
                if (instructionsTexture.loadFromFile("C:/projects/Project_I/Omaha_Poker/images/instructions.png")) {
                    startScreenSprite.setTexture(instructionsTexture);
                }
                else {
                    cerr << "Error al cargar la textura 'instructions.png'" << endl;
                }
            }
        }
    }
}

void GameGraphics::render() {
    window.clear();
    window.draw(startScreenSprite);
    window.display();
}
