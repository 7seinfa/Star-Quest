/**
 * CS 3307
 * Author: Theo Mulder
 * Last edit: 1 April, 2024
 */

// header file
#include "headers/HighScore.h"
#include <QFile>
#include <QString>
//#include <iostream>


// initialize the score display with 0 in score and highscore
HighScore::HighScore(QWidget *parent) : QLCDNumber(3, parent) {
    score = 0;
    highScore = 0;

    QFile HSFile ("highscore.txt");
    HSFile.open(QIODevice::ReadWrite);
    if (!HSFile.atEnd()){
        // if there's a previous highscore, update the score function
        QString highscoreST = HSFile.readLine();
        highScore = highscoreST.toInt();
    }
    HSFile.close();

    resize(150, 100);
    display(score);

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
    display(score);
}

// pseudo-setter function for the highscore
// (technically not a setter, as it doesn't accept any external values)
// intended to be used after/during the 'Game Over' state
bool HighScore::checkNewHighScore(){
    if (score > highScore){
        highScore = score; // update the highScore var

        QFile HSFile ("highscore.txt");
        std::string buffer = std::to_string(highScore);
        const char* playerScore = buffer.c_str();
        HSFile.open(QIODevice::WriteOnly);
        HSFile.write(playerScore); // and update the highscore text file
        return true;
    }
    return false;
}

// new run, set/initialize score to 0
void HighScore::resetScore(){
    score = 0;
    display(score);
}

