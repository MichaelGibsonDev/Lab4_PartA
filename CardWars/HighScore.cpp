#include "HighScore.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

HighScore::HighScore(const std::string& playerName, int playerScore)
    : name(playerName), score(playerScore) {
}

HighScore::HighScore(const std::string& csvData, char delimiter) {
    Deserialize(csvData, delimiter);
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

void HighScore::Deserialize(const std::string& csvData, char delimiter) {
    std::stringstream sPart(csvData);
    std::getline(sPart, name, delimiter);
    sPart >> score;
}

std::vector<HighScore> HighScore::LoadHighScores(const std::string& filePath) {
    std::vector<HighScore> highScores;
    std::ifstream infile(filePath);
    if (!infile) {
        std::cout << "Unable to open file. " << filePath << std::endl;
        return highScores;
    }
    std::string line;
    while (std::getline(infile, line)) {
        HighScore hs(line, '>');
        highScores.push_back(hs);
    }
    infile.close();
    return highScores;
}

void HighScore::SaveHighScores(const std::string& filePath, const std::vector<HighScore>& highScores) {
    std::ofstream outFile(filePath);
    if (!outFile) {
        std::cout << "Unable to open file. " << filePath << " for writing." << std::endl;
        return;
    }
    for (size_t i = 0; i < highScores.size(); i++) {
        outFile << highScores[i].getName() << ">" << highScores[i].getScore() << "\n";
    }
    outFile.close();
}

void HighScore::ShowHighScores(const std::vector<HighScore>& highScores) {
    std::cout << "High Scores: \n";
    for (size_t i = 0; i < highScores.size(); i++) {
        std::cout << highScores[i].getName() << " - " << highScores[i].getScore() << "\n";
    }
}
