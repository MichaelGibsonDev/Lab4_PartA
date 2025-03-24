#include "WarGame.h"
#include <time.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Input.h"


std::vector<Card> WarGame::_cards;

WarGame::WarGame(std::string cardsFile)
{
    LoadCards(cardsFile);
} 

void WarGame::shuffle()
{
    int ndx1, ndx2;
    srand((unsigned int)time(NULL));

    for (size_t i = 0; i < 52; i++)
    {
        ndx1 = rand() % 52;
        ndx2 = rand() % 52;

        Card temp = _cards[ndx1];
        _cards[ndx1] = _cards[ndx2];
        _cards[ndx2] = temp;
    }
}

    void WarGame::LoadCards(const std::string & cardsFile) {
        std::ifstream file(cardsFile);

        if (!file) {
            std::cerr << "Error opening file: " << cardsFile << std::endl;
            return;
        }

        std::string line;

        while(std::getline(file, line)) {
            std::istringstream ss(line);
            std::string value, suit;

            if (std::getline(ss, value, '>') && std::getline(ss, suit)) {
                _cards.push_back(Card(value, suit));
        }
    }
        file.close();

        
}
