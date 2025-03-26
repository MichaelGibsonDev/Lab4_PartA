#include "HighScore.h"
#include <sstream>
#include <fstream>
#include <iostream>

HighScore::HighScore(const std::string& csvData, char delimiter) {
    Deserialize(csvData, delimiter);
}

void HighScore::Deserialize(const std::string& csvData, char delimiter) {
    std::istringstream stream(csvData);
    std::getline(stream, name, delimiter);
    stream >> score;
}

std::string HighScore::getName() const {
    return name;
}

void HighScore::setName(const std::string& newName) {
    name = newName;
}

int HighScore::getScore() const {
    return score;
}

void HighScore::setScore(int newScore) {
    score = newScore;
}

std::vector<HighScore> HighScore::LoadHighScores(const std::string& filePath) {
    std::vector<HighScore> highScores;
    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
        return highScores;
    }

    std::string line;
    while (std::getline(file, line)) {
        HighScore score(line, ',');
        highScores.push_back(score);
    }

    file.close();
    return highScores;
}

void HighScore::ShowHighScores(const std::vector<HighScore>& highScores) {
    std::cout << "====High Scores====" << std::endl;
    std::cout << "---------------------------" << std::endl;


    int rank = 1;
    for (const auto& score : highScores) {
        std::cout << rank++ << ". " << score.getName() << " - ";
        std::cout << "[" << score.getScore() << "]" << std::endl;
    }
}