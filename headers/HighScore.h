/**
 * CS 3307
 * Author: Theo Mulder
 * Last edit: 10 Mar, 2024
 */


// this header is meant to track the player's score

#ifndef HIGHSCORE_H
#define HIGHSCORE_H


class HighScore
{
private:
    int score;
    int highScore;
public:
    int getScore();
    int getHighScore();
    void updateScore(int points);
    bool checkNewHighScore();
    void resetScore();
};

#endif // HIGHSCORE_H

