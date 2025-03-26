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

    std::vector<HighScore> highScores;
    highScores.push_back(HighScore("Eddie", 100));
    highScores.push_back(HighScore("Mike", 200));
    highScores.push_back(HighScore("Roman", 150));

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
        {
            war.ShowCards();
            break;
        }
        case 2:
        {
            std::cout << "High Scores:" << std::endl;
            for (const auto& score : highScores)
            {
                std::cout << score.getName() << " - " << score.getScore() << std::endl;
            }
            break;
        }
        case 3:
        {
            break;
        }
        default:
            break;
        }

        Input::PressEnter();

    } while (menuSelection != menuOptions.size());

}