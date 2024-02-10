#include "GameGraphics.h"

GameGraphics::GameGraphics() : window(VideoMode(1200, 650), "Omaha Poker") {
    setupStartScreen();
}

void GameGraphics::setupStartScreen() {
    if (!startScreenTexture.loadFromFile("images/inicio.png")) {
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
    static bool instructionsLoaded = false;

    if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
        Vector2i mousePosition = Mouse::getPosition(window);
        if (!instructionsLoaded && isInsideSpecificArea(mousePosition)) {
            loadAndSetInstructionsTexture("images/instructions.png");
            instructionsLoaded = true;
        }
        else if (instructionsLoaded && isInsideSpecificAreaInstruccions(mousePosition)) {
            loadAndSetGameBackgroundTexture("images/gameBackground.png");
        }
    }
}

bool GameGraphics::isInsideSpecificAreaInstruccions(const Vector2i& mousePosition) {
    FloatRect specificArea(992, 580, 1172, 630);
    return specificArea.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
}

bool GameGraphics::isInsideSpecificArea(const Vector2i& mousePosition) {
    FloatRect specificArea(992, 580, 1172, 626);
    return specificArea.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
}

void GameGraphics::loadAndSetInstructionsTexture(const string& filename) {
    if (!instructionsTexture.loadFromFile(filename)) {
        cerr << "Error al cargar la textura 'instructions.png'" << endl;
        return;
    }
    startScreenSprite.setTexture(instructionsTexture);
}

void GameGraphics::loadAndSetGameBackgroundTexture(const string& filename) {
    if (!gameBackgroundTexture.loadFromFile(filename)) {
        cerr << "Error al cargar la textura 'gameBackground.png'" << endl;
        return;
    }
    startScreenSprite.setTexture(gameBackgroundTexture);
}

void GameGraphics::render() {
    window.clear();
    window.draw(startScreenSprite);
    window.display();
}
