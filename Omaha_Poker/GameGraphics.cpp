#include "GameGraphics.h"
#include <iostream>
using namespace std;

GameGraphics::GameGraphics() : window(VideoMode(1200, 650), "Omaha Poker") {
    startScreenTexture.loadFromFile("inicio.png");
    startScreenSprite.setTexture(startScreenTexture);

    startButton.setSize(Vector2f(150, 50));
    startButton.setFillColor(Color(255, 0, 0, 150));
    startButton.setPosition((window.getSize().x - startButton.getSize().x) / 2, (window.getSize().y - startButton.getSize().y) / 2 + 250);

    if (!font.loadFromFile("Honk-Regular.ttf")) {
        cerr << "Error al cargar la fuente de texto." << endl;
    }

    buttonText.setFont(font);
    buttonText.setString("Inicio");
    buttonText.setCharacterSize(24);
    buttonText.setFillColor(Color::White);
    buttonText.setPosition(startButton.getPosition().x + 20, startButton.getPosition().y + 10);
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
            if (startButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
                
            }
        }
    }
}

void GameGraphics::render() {
    window.clear();
    window.draw(startScreenSprite);
    window.draw(startButton);
    window.draw(buttonText); 
    window.display();
}