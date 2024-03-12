/**
 * CS 3307
 * Author: Theo Mulder
 * Last edit: 10 Mar, 2024
 */


// this header is meant to track the player's score, and display it in the top left corner.

#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include <QLCDNumber>

class HighScore : public QLCDNumber
{
    Q_OBJECT
private:
    int score;
    int highScore;
public:
    HighScore(QWidget *parent = nullptr);
    int getScore();
    int getHighScore();
    void updateScore(int points);
    bool checkNewHighScore();
    void resetScore();
};

#endif // HIGHSCORE_H

