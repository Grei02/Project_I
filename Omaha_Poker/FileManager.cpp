#include "FileManager.h"

void FileManager::saveHand(Card* hand, int numberOfCard)
{
    ofstream cardsFile(fileDirection, ios::app);

    if (!cardsFile.is_open()) {
        cerr << "No se pudo abrir el archivo para escribir.\n";
    }
 
    for (int i = 0; i < numberOfCard; i++) {
        cardsFile << hand[i].getSymbol() << hand[i].getValue();
        if (i < numberOfCard - 1) {
            cardsFile << ", ";
        }
    }
    cardsFile << endl;
    cardsFile.close();
    
}

void FileManager::readHand()
{
    ifstream file(fileDirection);
    string fileLine;

    if (!file.is_open()) {
       cerr << "No se pudo abrir el archivo para leer.\n";
    }
    
    cout << "Contenido del archivo:"<<endl;
    while (getline(file, fileLine)) {
        cout << fileLine << endl;
    }
    file.close();
}


