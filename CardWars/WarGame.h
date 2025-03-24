#pragma once
#include <string>
#include <vector>
#include "Card.h"

class WarGame
{

public:
	WarGame(std::string cardsFile);
	 


private:
	static std::vector<Card> _cards;

	static void shuffle();

	static void LoadCards(const std::string& cardsFile);
};

