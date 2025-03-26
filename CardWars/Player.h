#include <string>
#include <vector>
#include "Card.h"

class Player {
private:
    std::string name;
    int score;
    std::vector<Card> pile;
    std::vector<Card> won;

public:
    Player(const std::string& playerName);

    std::string getName() const;
    void setName(const std::string& newName);

    int getScore() const;
    void setScore(int newScore);

    bool HasCards() const;

    void PushCard(const Card& card);

    Card PopCard();

    void WonCards(const std::vector<Card>& wonCards);
};
