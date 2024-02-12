#include "GameGraphics.h"

GameGraphics::GameGraphics() : window(VideoMode(1200, 650), "Omaha Poker") {
	setupStartScreen();
	initializePlayerPositions();
	initializeCircleInfo();
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
		}
		else if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
			if (instructionsScreen)
				handleMouseEvents(event);
			Vector2i mousePosition = Mouse::getPosition(window);
			cout << "Posición del ratón - x: " << mousePosition.x << ", y: " << mousePosition.y << std::endl;
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
	if (unicode >= '2' && unicode <= '6' && inputText.getString().getSize() < 1) {
		inputText.setString(inputText.getString() + static_cast<char>(unicode));
	}
}

void GameGraphics::handleKeyPress(sf::Keyboard::Key key) {
	if (key == Keyboard::BackSpace) {
		string inputStr = inputText.getString();
		if (!inputStr.empty()) {
			inputStr.pop_back();
			inputText.setString(inputStr);
		}
	}
	else if (key == sf::Keyboard::Enter) {
		int numPlayers = stoi(inputText.getString().toAnsiString());
		if (numPlayers >= 2 && numPlayers <= 6) {
			dealer.setNumPlayers(numPlayers);
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

void GameGraphics::initializePlayerPositions() {
	
	playerPositions[0] = sf::Vector2f(794, 114);  // Dealer
	playerPositions[1] = sf::Vector2f(995, 355);  // Small Blind
	playerPositions[2] = sf::Vector2f(238, 143);  // Big Blind
	
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
				std::cerr << "Error al cargar la fuente." << std::endl;
				return;
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
	if (newTexture.loadFromFile(filename)) {
		gameBackgroundTexture = newTexture;
		gameBackgroundSprite.setTexture(gameBackgroundTexture);
	}
	else {
		cerr << "Error al cargar la textura del fondo del juego." << endl;
	}
}
void GameGraphics::initializeCircleInfo() {
	circleRadius = 20.0f;
	playerColors[0] = sf::Color::Red;
	playerColors[1] = sf::Color::Green;
	playerColors[2] = sf::Color::Blue;
}

void GameGraphics::render() {
	window.clear();

	if (instructionsScreen) {
		if (instructionsLoaded) {
			window.draw(instructionsSprite);
			window.draw(text);
			window.draw(inputBox);
			window.draw(inputText);
		}
		else {
			window.draw(startScreenSprite);
		}
	}
	else {
		if (numPlayersEntered && instructionsLoaded) {
			window.draw(gameBackgroundSprite);
		}
		else {
			window.draw(startScreenSprite);
		}
	}

	if (drawCircles) {
		
		drawPlayerCircles();
	}
	window.display();
}

