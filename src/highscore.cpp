/**
 * CS 3307
 * Author: Theo Mulder
 * Last edit: 10 Mar, 2024
 */

// header file
#include "headers/HighScore.h"

// initializes with 0 score
HighScore::HighScore() {
    score = 0;
    highScore = 0;
}

// getter functions for score and highscore
int HighScore::getScore(){
    return score;
}

int HighScore::getHighScore(){
    return highScore;
}

// setter function for the score
void HighScore::updateScore(int newScore){
    score = newScore;
}

// pseudo-setter function for the highscore
// (technically not a setter, as it doesn't accept any external values)
// intended to be used after/during the 'Game Over' state
bool HighScore::checkNewHighScore(){
    if (score > highScore){
        highScore = score;
        return true;
    }
    return false;
}

// new run, set/initialize score to 0
void HighScore::resetScore(){
    score = 0;
}

