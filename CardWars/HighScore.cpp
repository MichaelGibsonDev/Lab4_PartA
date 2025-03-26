#include "HighScore.h"

HighScore::HighScore(const std::string& name, int score)
    : _name(name), _score(score) {
}

std::string HighScore::getName() const {
    return _name;
}

void HighScore::setName(const std::string& name) {
    _name = name;
}

int HighScore::getScore() const {
    return _score;
}

void HighScore::setScore(int score) {
    _score = score;
}
