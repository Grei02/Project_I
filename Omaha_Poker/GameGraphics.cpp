#include "GameGraphics.h"

GameGraphics::GameGraphics() : window(VideoMode(1200, 650), "Omaha Poker") {
    setupStartScreen();
}

void GameGraphics::run() {
    while (window.isOpen()) {

        handleEvents();
        render();

        if (numPlayersEntered && instructionsLoaded) {
            loadAndSetGameBackgroundTexture("C:/projects/Project_I/Omaha_Poker/images/gameBackground.png");
            instructionsScreen = false;
        }
    }
}

void GameGraphics::handleEvents() {
    Event event;
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed) {
            window.close();
        }
        else if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
            if (instructionsScreen)
                handleMouseEvents(event);
        }
        else if (event.type == Event::TextEntered) {
            if (instructionsScreen)
                handleTextInput(event.text.unicode);
        }
        else if (event.type == Event::KeyPressed) {
            if (instructionsScreen)
                handleKeyPress(event.key.code);
        }
    }
}

void GameGraphics::handleMouseEvents(const Event& event) {
    if (instructionsScreen) {
        handleInstructionsLogic();
    }
}

void GameGraphics::handleInstructionsLogic() {
    Vector2i mousePosition = Mouse::getPosition(window);

    if (!instructionsLoaded && isInsideSpecificArea(mousePosition)) {
        loadAndSetInstructionsTexture("images/instructions.png");
    
    }

    if (numPlayersEntered && instructionsLoaded && isInsideSpecificAreaInstruccions(mousePosition)) {
        loadAndSetGameBackgroundTexture("images/gameBackground.png");
    }
}

void GameGraphics::setupStartScreen() {
    if (!startScreenTexture.loadFromFile("images/inicio.png")) {
        cerr << "Error al cargar la textura de la pantalla de inicio." << endl;
    }

    startScreenSprite.setTexture(startScreenTexture);
}

void GameGraphics::setupUI() {
    if (!font.loadFromFile("fonts/Foldit-VariableFont_wght.ttf")) {
        cerr << "Error al cargar la fuente." << endl;
        return;
    }

    text.setFont(font);
    text.setString("100");
    text.setCharacterSize(50);
    text.setFillColor(Color::White);
    text.setPosition(74, 13);

    inputBox.setSize(Vector2f(60, 35));
    inputBox.setFillColor(Color::Black);
    inputBox.setOutlineColor(Color::White);
    inputBox.setOutlineThickness(2);
    inputBox.setPosition(1017, 45);

    inputText.setFont(font);
    inputText.setCharacterSize(30);
    inputText.setFillColor(Color::White);
    inputText.setPosition(1045, 45);
}

void GameGraphics::handleTextInput(sf::Uint32 unicode) {
    if (unicode >= '2' && unicode <= '6' && inputText.getString().getSize() < 2) {
        inputText.setString(inputText.getString() + static_cast<char>(unicode));
    }
}

void GameGraphics::handleKeyPress(sf::Keyboard::Key key) {
    if (key == sf::Keyboard::BackSpace) {
        std::string inputStr = inputText.getString();
        if (!inputStr.empty()) {
            inputStr.pop_back();
            inputText.setString(inputStr);
        }
    }

    if (key == sf::Keyboard::Enter) {
        int numPlayers = std::stoi(inputText.getString().toAnsiString());
        if (numPlayers >= 2 && numPlayers <= 6) {
            std::cout << "Comenzando juego con " << numPlayers << " jugadores." << std::endl;
            numPlayersEntered = true;
            instructionsScreen = false; 
        }
        else {
            std::cerr << "Por favor, ingrese un número de jugadores válido (entre 2 y 6)." << std::endl;
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
    Texture newTexture;
    if (newTexture.loadFromFile(filename)) {
        instructionsTexture = newTexture;
        instructionsSprite.setTexture(instructionsTexture);
        setupUI();
        instructionsLoaded = true;
    }
    else {
        cerr << "Error al cargar la textura de las instrucciones desde el archivo: " << filename << endl;
    }
}

void GameGraphics::loadAndSetGameBackgroundTexture(const string& filename) {
    Texture newTexture;
    if (newTexture.loadFromFile(filename)) {
        gameBackgroundTexture = newTexture;
        gameBackgroundSprite.setTexture(gameBackgroundTexture);
        cout << "Imagen cargada correctamente" << endl;
    }
    else {
        cerr << "Error al cargar la textura del fondo del juego." << endl;
    }
}

void GameGraphics::render() {
  
    window.clear();

    if (instructionsScreen) {
        if (instructionsLoaded) {
            window.draw(instructionsSprite);
            window.draw(text);
            window.draw(inputBox);
            window.draw(inputText);
        } else {
            window.draw(startScreenSprite);
        }
    } else {
        if (numPlayersEntered && instructionsLoaded) {
            window.draw(gameBackgroundSprite);
        } else {
            window.draw(startScreenSprite);
        }
    }

    window.display();
}
