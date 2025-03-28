#pragma once
#include <string>
#include <vector>

class HighScore {
private:
    std::string name;
    int score;
public:
    HighScore(const std::string& playerName, int playerScore);
    HighScore(const std::string& csvData, char delimiter);

    std::string getName() const;
    void setName(const std::string& newName);

    int getScore() const;
    void setScore(int newScore);

    void Deserialize(const std::string& csvData, char delimiter);

    static std::vector<HighScore> LoadHighScores(const std::string& filePath);
    static void SaveHighScores(const std::string& filePath, const std::vector<HighScore>& highScores);
    static void ShowHighScores(const std::vector<HighScore>& highScores);
};
