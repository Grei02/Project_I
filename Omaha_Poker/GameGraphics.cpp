#include "GameGraphics.h"

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
        handleMouseEvents(event);
    }
}

void GameGraphics::handleMouseEvents(const Event& event) {
    if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
        Vector2i mousePosition = Mouse::getPosition(window);
        cout << "Mouse pressed at position: (" << mousePosition.x << ", " << mousePosition.y << ")" << endl;
        if (isInsideSpecificArea(mousePosition)) {
            cout << "Click inside the specific area." << endl;
            loadAndSetInstructionsTexture("C:/projects/Project_I/Omaha_Poker/images/instructions.png");
        }
    }
}

bool GameGraphics::isInsideSpecificArea(const Vector2i& mousePosition) {
    FloatRect specificArea(992, 580, 1172, 626);
    return specificArea.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
}

void GameGraphics::loadAndSetInstructionsTexture(const string& filename) {
    if (!startScreenTexture.loadFromFile(filename)) {
        cerr << "Error al cargar la textura 'instructions.png'" << endl;
        return;
    }
    startScreenSprite.setTexture(startScreenTexture);
}

void GameGraphics::render() {
    window.clear();
    window.draw(startScreenSprite);
    window.display();
}
