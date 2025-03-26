#include "Player.h"

Player::Player(const std::string& playerName) : name(playerName), score(0) {}

std::string Player::getName() const {
    return name;
}

void Player::setName(const std::string& newName) {
    name = newName;
}

int Player::getScore() const {
    return score;
}

void Player::setScore(int newScore) {
    score = newScore;
}

bool Player::HasCards() const {
    return !pile.empty();
}

void Player::PushCard(const Card& card) {
    pile.push_back(card);
}

Card Player::PopCard() {
    if (!pile.empty()) {
        Card topCard = pile.back();
        pile.pop_back();
        return topCard;
    }
}

void Player::WonCards(const std::vector<Card>& wonCards) {
    won.insert(won.end(), wonCards.begin(), wonCards.end());
    score = won.size();
}
