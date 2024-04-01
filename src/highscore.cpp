/** file that holds everything to do with scoring
 *
 * @author: Theo Mulder
 * Last edit: 1 April, 2024
 *
 * implements methods and public/private attributes from highscore.h, and an LCD-type score display
 * additionally opens a file to keep track of the user's highscore across various games
 */

/// header files
#include "headers/HighScore.h"
#include <QFile>
#include <QString>

/// defines
#define DIGITS_IN_DISPLAY 3



/**
 * @brief   score/highscore constructor
 *
 * constructor is used to set up and show the player's score in the game
 * uses a QLCDNumber object to display the score in a more space-y theme
 *
 * @param *parent   pointer for the parent
 * @param DIGITS_IN_DISPLAY    How many digits can be shown on the score's LCD display
 * @param parent    parent window for the QLCDNumber display to attach to
 */
HighScore::HighScore(QWidget *parent) : QLCDNumber(DIGITS_IN_DISPLAY, parent) {
    score = 0;
    highScore = 0;

    QFile HSFile ("highscore.txt"); /*! the file that holds/saves the highscore */
    HSFile.open(QIODevice::ReadWrite);
    if (!HSFile.atEnd()){
        /// if there's a previous highscore from the file, update the score function
        QString highscoreST = HSFile.readLine();
        highScore = highscoreST.toInt();
    }
    HSFile.close();


    resize(150, 100); /// modifies the LCD display in the top left of the window
    display(score);   /// and updates it to display the current score (0)

}

/**
 * @brief   score getter
 * getter function to return the player's current score
 *
 * @return score (int)
 */
int HighScore::getScore(){
    return score;
}

/**
 * @brief   highscore getter
 * getter function to return the player's highscore
 * can be less than the current score, if it hasn't been updated yet.
 *
 * @return highscore (int)
 */
int HighScore::getHighScore(){
    return highScore;
}

/**
 * @brief   score setter
 * setter function to change the player's current score
 * @param newScore  the new current score
 */
// setter function for the score
void HighScore::updateScore(int newScore){
    score = newScore;
    display(score);
}

/**
 * @brief   highscore checker
 * checks if the score is greater than the highscore,
 * and then updates the highscore var and highscore file to match.
 *
 * technically the highscore's setter method, as it's the only way to update it.
 * intended to be used after dying to an obstacle
 *
 * @return  if the player's score is greater than the highscore
 */
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

/**
 * @brief   score resetter
 * resetter function to change the player's to zero
 * so that they can start a new run
 */
void HighScore::resetScore(){
    score = 0;
    display(score);
}

