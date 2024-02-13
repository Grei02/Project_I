#include "GameGraphics.h"

GameGraphics::GameGraphics() : window(sf::VideoMode(1200, 650), "Omaha Poker"), deck(*new Deck()), instructionsLoaded(false) {
	setupStartScreen();
	initializePlayerPositions();
	initializeCircleInfo();
	loadCardTextures();
}

void GameGraphics::run() {

	while (window.isOpen()) {
		handleEvents();
		render();
		if (numPlayersEntered && instructionsLoaded) {
			loadAndSetGameBackgroundTexture("images/gameBackground.png");
			instructionsScreen = false;
			drawCircles = true;
		}
	}
}

void GameGraphics::handleEvents() {
	Event event;
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed) {
			window.close();
			continue;
		}

		if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
			if (instructionsScreen) {
				handleMouseEvents(event);
			}
			Vector2i mousePosition = Mouse::getPosition(window);
			cout << "Posición del ratón - x: " << mousePosition.x << ", y: " << mousePosition.y << std::endl;
			continue;
		}

		if (event.type == Event::TextEntered) {
			if (instructionsScreen) {
				handleTextInput(event.text.unicode);
			}
			continue;
		}

		if (event.type == Event::KeyPressed) {
			if (instructionsScreen) {
				handleKeyPress(event.key.code);
			}
		}
	}
}


void GameGraphics::handleMouseEvents(Event event) {
	if (instructionsScreen) {
		
		handleInstructionsLogic();
	}
}

void GameGraphics::handleInstructionsLogic() {

	Vector2i mousePosition = Mouse::getPosition(window);
	cout << "Posición del ratón - x: " << mousePosition.x << ", y: " << mousePosition.y << std::endl;
	if (!instructionsLoaded && isInsideSpecificArea(mousePosition)) {
		loadAndSetInstructionsTexture("images/instructions.png");
	}

	if (numPlayersEntered && instructionsLoaded && isInsideSpecificAreaInstruccions(mousePosition)) {
		loadAndSetGameBackgroundTexture("images/gameBackground.png");
	}
}

void GameGraphics::setupStartScreen() {
	if (!startScreenTexture.loadFromFile("images/inicio.png")) {
		throw runtime_error("Error al cargar la textura : ");
	}
	startScreenSprite.setTexture(startScreenTexture);
}

void GameGraphics::setupUI() {
	if (!font.loadFromFile("fonts/Foldit-VariableFont_wght.ttf")) {
		throw exception("Error al cargar la fuente");
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
	if (unicode >= '2' && unicode <= '6' && inputText.getString().getSize() < 1) {
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
		int numPlayers = stoi(inputText.getString().toAnsiString());
		if (numPlayers >= 2 && numPlayers <= 6) {
			dealer.setNumPlayers(numPlayers);
			cout << numPlayers << endl;
			cout << "Comenzando juego con " << dealer.getNumPlayers() << " jugadores." << std::endl;
			numPlayersEntered = true;
			instructionsScreen = false;
		}
	}
}

bool GameGraphics::isInsideSpecificAreaInstruccions(Vector2i mousePosition) {
	FloatRect specificArea(992, 580, 1172, 630);
	return specificArea.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
}

bool GameGraphics::isInsideSpecificArea(Vector2i mousePosition) {
	FloatRect specificArea(992, 580, 1172, 626);
	return specificArea.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
}

void GameGraphics::loadAndSetInstructionsTexture(string filename) {
	Texture newTexture;
	if (!newTexture.loadFromFile(filename)) {
		throw runtime_error("Error al cargar la textura : ");
	}
	instructionsTexture = newTexture;
	instructionsSprite.setTexture(instructionsTexture);
	setupUI();
	instructionsLoaded = true;
}

void GameGraphics::initializePlayerPositions() {

	playerPositions[0] = sf::Vector2f(794, 114);  
	playerPositions[1] = sf::Vector2f(995, 355);  
	playerPositions[2] = sf::Vector2f(238, 143); 

}
void GameGraphics::drawPlayerCircles() {
	if (numPlayersEntered && instructionsLoaded) {
		for (int i = 0; i < 3; ++i) {
			sf::CircleShape circle(circleRadius);
			circle.setFillColor(playerColors[i]);
			circle.setPosition(playerPositions[i]);
			window.draw(circle);

			Font font;
			if (!font.loadFromFile("fonts/TiltNeon-Regular.ttf")) {
				throw exception("Error al cargar la fuente");
			
			}

			Text text;
			text.setFont(font);
			text.setString(playerNames[i]);
			text.setCharacterSize(9);
			text.setFillColor(Color::Black);
			text.setPosition(playerPositions[i].x, playerPositions[i].y+10);

			window.draw(text); 
		}
	}
}

void GameGraphics::loadAndSetGameBackgroundTexture(string filename) {
    Texture newTexture;
    if (!newTexture.loadFromFile(filename)) {
        throw runtime_error("Error al cargar la textura: " + filename);
    }
    gameBackgroundTexture = newTexture;
    gameBackgroundSprite.setTexture(gameBackgroundTexture);
}

	
void GameGraphics::initializeCircleInfo() {
	circleRadius = 20.0f;
	playerColors[0] = Color::Red;
	playerColors[1] = Color::Green;
	playerColors[2] = Color::Blue;
}

void GameGraphics::loadCardTextures()
{
	for (int i = 0; i < TOTAL_CARDS; ++i) {
		std::string filename = cards[i].getImagePath();
		if (!cardTextures[i].loadFromFile(filename)) {
			std::cerr << "Error cargando la imagen de la carta: " << filename << std::endl;
		}
	}
}

void GameGraphics::drawPlayerHands() {
	for (int i = 0; i < dealer.getNumPlayers(); ++i) {
		Card* hand = playerHands[i];
		for (int j = 0; j < HAND_SIZE; ++j) {
			int cardIndex = hand[j].getIndex(); 
			cardSprites[cardIndex].setPosition(playerHandPositions[i] + sf::Vector2f(j * 50, 0)); 
			window.draw(cardSprites[cardIndex]); 
		}
	}
}

void GameGraphics::render() {
	window.clear();

	if (instructionsScreen && instructionsLoaded) {
		window.draw(instructionsSprite);
		window.draw(text);
		window.draw(inputBox);
		window.draw(inputText);
	}

	if (instructionsScreen && !instructionsLoaded) {
		window.draw(startScreenSprite);
	}

	if (!instructionsScreen && numPlayersEntered && instructionsLoaded) {
		window.draw(gameBackgroundSprite);
		drawCards();
	}

	if (drawCircles) {
		drawPlayerCircles();
	}

	if (!instructionsScreen && !(numPlayersEntered && instructionsLoaded)) {
		window.draw(startScreenSprite);
	}
	window.display();
}
