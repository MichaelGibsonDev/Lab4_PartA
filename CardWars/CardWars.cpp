#include <iostream>
#include "Console.h"
#include "Input.h"
#include "WarGame.h"
#include "Tester.h"
#include "HighScore.h"

void PrintIntro();

int main()
{
    Tester cardWarsTest;
    Console::ResizeWindow(150, 30);

    int menuSelection = 0;
    std::vector<std::string> menuOptions{ "1. Show Cards", "2. Show High Scores", "3. Play Card Wars", "4. Exit" };
    std::string highScoreFile = "HighScores.csv";
    std::string cardsFile = "cards.csv";

    std::vector<HighScore> highScores = HighScore::LoadHighScores(highScoreFile);

    WarGame war(cardsFile);

    do
    {
        Console::Clear();
        PrintIntro();
        menuSelection = Input::GetMenuSelection(menuOptions);
        Console::Clear();

        //----------------------------------------------------------------
        //                                                              //
        //    Call your methods in the appropriate case statement       //
        //                                                              //
        switch (menuSelection)
        {
        case 1:
            WarGame::ShowCards();
            break;

        case 2:
            HighScore::ShowHighScores(highScores);
            break;

        case 3:
            std::cout << "Starting Card Wars...\n";
            {
                std::string playerName = Input::GetString("Enter your name: ");
                war.PlayGame(playerName, highScores, highScoreFile);
            }
            break;

        default:
            break;
        }

        Input::PressEnter();

    } while (menuSelection != menuOptions.size());

    return 0;
}
