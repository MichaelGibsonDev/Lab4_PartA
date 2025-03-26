#pragma once
#include <string>

class HighScore
{
private:
    std::string _name;
    int _score;

public:
    HighScore(const std::string& name, int score);

    // Getters and Setters
    std::string getName() const;
    void setName(const std::string& name);
    int getScore() const;
    void setScore(int score);
};