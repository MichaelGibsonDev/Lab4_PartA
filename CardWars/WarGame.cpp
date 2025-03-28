#include "WarGame.h"
#include "Input.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <random>

std::vector<Card> WarGame::_cards;

WarGame::WarGame(const std::string& cardsFile)
{
	LoadCards(cardsFile);
}

void WarGame::LoadCards(const std::string& cardsFile)
{
	std::ifstream file(cardsFile);
	if (!file)
	{
		std::cerr << " Unable to Open File " << cardsFile << std::endl;
		return;
	}
	_cards.clear();
	std::string line;
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string face;
		std::string suit;
		if (std::getline(iss, face, '>') && std::getline(iss, suit))
		{
			_cards.push_back(Card(suit, face));
		}
	}
	file.close();
	if (_cards.size() != 52)
	{
		std::cerr << "Expected 52 cards, but loaded " << _cards.size() << " cards." << std::endl;
	}
}

void WarGame::shuffle()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::shuffle(_cards.begin(), _cards.end(), gen);
}

void WarGame::ShowCards()
{
	for (size_t i = 0; i < _cards.size(); i++)
	{
		_cards[i].Print();
	}
}

void WarGame::PlayGame(const std::string& playerName, std::vector<HighScore>& highScores, const std::string& highScoreFile)
{
	shuffle();
	Player npc("NPC");
	Player player(playerName);
	for (size_t i = 0; i < _cards.size(); i++)
	{
		if (i % 2 == 0)
			player.PushCard(_cards[i]);
		else
			npc.PushCard(_cards[i]);
	}
	std::vector<Card> unclaimedPile;
	while (player.HasCards() && npc.HasCards())
	{
		Card playerCard = player.PopCard();
		Card npcCard = npc.PopCard();
		std::cout << playerName << " plays: ";
		playerCard.Print();
		std::cout << " vs NPC plays: ";
		npcCard.Print();
		std::cout << std::endl;
		unclaimedPile.push_back(playerCard);
		unclaimedPile.push_back(npcCard);
		int compResult = playerCard.Compare(npcCard);
		if (compResult == -1)
		{
			npc.WonCards(unclaimedPile);
			unclaimedPile.clear();
			std::cout << "NPC wins this round!" << std::endl;
		}
		else if (compResult == 1)
		{
			player.WonCards(unclaimedPile);
			unclaimedPile.clear();
			std::cout << playerName << " wins this round!" << std::endl;
		}
		else
		{
			std::cout << "This round is a tie!" << std::endl;
		}
	}
	std::cout << "\nFinal Scores:" << std::endl;
	std::cout << "NPC: " << npc.getScore() << " | " << playerName << ": " << player.getScore() << std::endl;
	if (npc.getScore() > player.getScore())
	{
		std::cout << "NPC wins the game!" << std::endl;
	}
	else if (npc.getScore() == player.getScore())
	{
		std::cout << "The game is a tie!" << std::endl;
	}
	else
	{
		std::cout << playerName << " wins the game!" << std::endl;
		if (!highScores.empty() && player.getScore() > highScores.back().getScore())
		{
			std::cout << "New High Score!" << std::endl;
			size_t insertIndex = highScores.size();
			for (size_t i = 0; i < highScores.size(); i++)
			{
				if (player.getScore() > highScores[i].getScore())
				{
					insertIndex = i;
					break;
				}
			}
			highScores.insert(highScores.begin() + insertIndex, HighScore(playerName, player.getScore()));
			if (highScores.size() > 10)
				highScores.pop_back();
			HighScore::SaveHighScores(highScoreFile, highScores);
			HighScore::ShowHighScores(highScores);
		}
	}
	int choice = Input::GetInteger("Play again? (1: Yes, 2: No): ", 1, 2);
	if (choice == 1)
	{
		PlayGame(playerName, highScores, highScoreFile);
	}
}

