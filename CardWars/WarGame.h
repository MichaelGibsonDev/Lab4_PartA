#pragma once
#include <string>
#include <vector>
#include "Card.h"
#include "Player.h"
#include "HighScore.h"

class WarGame {
public:
    WarGame(const std::string& cardsFile);

    static void ShowCards();

    void PlayGame(const std::string& playerName, std::vector<HighScore>& highScores, const std::string& highScoreFile);

private:
    static std::vector<Card> _cards;
    static void shuffle();
    static void LoadCards(const std::string& cardsFile);
};