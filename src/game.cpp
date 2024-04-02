/**
 * @file Game.cpp
 * @brief Implementation of the Game class.
 *
 * game class implements drectives, private, and public attributes and methods declared by Game.h
 *
 * @author Hussein Abdallah
 * @date March 11, 2024
 */

//header file for this
#include "headers/Game.h"

//includes
#include <QTimer>
#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGuiApplication>
#include <QScreen>
#include <time.h>
#include <QMessageBox>
#include <QPushButton>

/**
 * @brief Constructs a Game object.
 *
 * constructor is used to set up the window of the game
 *
 * @param parent The parent QWidget for this instance (optional).
 * @return none
 */
Game::Game(QWidget *parent)
    : QMainWindow(parent)
{

    srand(time(NULL));
    QPixmap bg("img/background.png");
    background = new Background(bg, 0, 0, QGuiApplication::screens()[0]->availableGeometry().width()*2,
                                QGuiApplication::screens()[0]->availableGeometry().height(), 25, this);


    //create obstacles
    firstObstacleX=600;
    distBetweenObstacles=340;
    obstacleGap=280;
    obstacleWidth=100;
    QPixmap obT("img/obstacleTop.png");
    QPixmap obB("img/obstacleBot.png");
    for (int i = 0; i < (QGuiApplication::screens()[0]->availableGeometry().width()/(distBetweenObstacles+obstacleWidth))+1; i++) {
        Obstacle* obTop = new Obstacle(obT, firstObstacleX+i*(distBetweenObstacles+obstacleWidth), 0, obstacleWidth, this);
        Obstacle* obBot = new Obstacle(obB, firstObstacleX+i*(distBetweenObstacles+obstacleWidth), obTop->getHeight()+obstacleGap, obstacleWidth, this);
        obstacles.push_back(obTop);
        obstacles.push_back(obBot);
    }

    //create the scoreing function
    score = new HighScore(this);

    //run update function every millisecond
    QTimer *timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(10);

    QPixmap spaceshipPixmap("img/spaceship.png");
    int initialX = 100; // X position
    int initialY = QGuiApplication::screens()[0]->availableGeometry().height() / 2; // Y position
    int spaceshipWidth = 100; // Spaceship width
    int spaceshipHeight = 80; // Spaceship height
    qreal gravity = 1.0;
    qreal jump = 15;

    player = new Player(spaceshipPixmap, initialX, initialY, spaceshipWidth, spaceshipHeight, gravity, jump, this);
}

/**
 * @brief Handles key press events to control the player.
 *
 * used to receive key presses to notify player
 *
 * @param event The key event.
 * @return none
 */
void Game::keyPressEvent(QKeyEvent *event) {
    if (player) {
        player->keyPressEvent(event);
    }
}

/**
 * @brief Handles key release events.
 *
 * used to receive key releases to notify player
 *
 * @param event The key event.
 * @return none
 */
void Game::keyReleaseEvent(QKeyEvent *event) {
    if (player) {
        player->keyReleaseEvent(event);
    }
}

/**
 * @brief Periodically updates the game state.
 *
 * runs periodically, time between each run set by QTimer in the constructor function
 * updates the obstacles position
 * updates the player's score (if passing and obstacle)
 * updates the game state (if the player collided with an object) to 'game over'
 *
 * @authors Joud Al-lahham, Theo Mulder, Hussein Abdallah
 * @param none
 * @return none
 */
void Game::update(){
    //background->update();
    for (unsigned int i = 0; i < obstacles.size()/2; i++) {
        /// update obstacles
        obstacles.at(2*i)->update(0);
        obstacles.at(2*i+1)->update(obstacles.at(2*i)->getHeight()+obstacleGap);

        /// update player score (if passing an obstacle)
        int obstaclesPosition = (obstacles.at(2*i)->getX() + (obstacles.at(2*i)->getWidth() / 2));
        if (obstaclesPosition == player->getX()) {
            score->updateScore(score->getScore()+1);
        }

        /// if player hits an obstacle, display the 'game over' screen
        if (player->collidesWith(dynamic_cast<Object*>(obstacles.at(2 * i))) ||
            player->collidesWith(dynamic_cast<Object*>(obstacles.at(2 * i + 1))) ||
            player->getY() > QGuiApplication::screens()[0]->availableGeometry().height() ||
            player->getY() + player->getHeight() < 0) {

            gameOver();
            return;
        }
    }
}


/**
 * @brief Displays the game over screen.
 *
 * Displays a game over popup with options to restart the game or exit.
 * @author Joud Al-lahham
 * @param no parameters
 * @return no value returned
 */
void Game::gameOver() {
    QMessageBox msgBox;
    msgBox.setWindowTitle("Game Over");

    QString gameOverText = "Game Over!\nYour Score was: ";
    int playerScore = score->getScore();
    gameOverText.append(QString::number(playerScore));
    if (score->checkNewHighScore()){
        gameOverText.append("\nNew highscore!");
    } else{
        gameOverText.append("\nHighscore: ");
        gameOverText.append(QString::number(score->getHighScore()));
    }
    gameOverText.append("\nWould you like to restart or exit?");
    msgBox.setText(gameOverText);

    QPushButton *restartButton = msgBox.addButton(tr("Restart"), QMessageBox::ActionRole);
    QPushButton *exitButton = msgBox.addButton(tr("Exit"), QMessageBox::ActionRole);

    msgBox.exec(); // Blocks until a button is clicked

    if (msgBox.clickedButton() == restartButton) {
        restartGame();
    } else if (msgBox.clickedButton() == exitButton) {
        this->close(); // Close if "Exit" is chosen
    }
}

/**
 * @brief Resets the game to its initial state.
 *
 * Resets the game to its initial state, including player position and score.
 *
 * @author Joud Al-lahham
 * @param no parameters
 * @return no value returned
 */
void Game::restartGame() {
    player->setX(100);
    player->setY(QGuiApplication::screens()[0]->availableGeometry().height() / 2);
    player->resetVelocity();
    score->resetScore();
    resetObstacles();
}

/**
 * @brief Resets obstacles for a new game session.
 *
 * Reconfigures obstacles' positions and dimensions for a new game, ensuring variety in the game's challenge.
 *
 * @author Joud Al-lahham
 * @param no parameters
 * @return no value returned
 */
void Game::resetObstacles() {
    int firstObstacleX = 600;
    int screenHeight = QGuiApplication::screens()[0]->availableGeometry().height();

    for (unsigned int i = 0; i < obstacles.size() / 2; i++) {
        int newHeight;
        int newY;
        // Reset X position
        obstacles.at(2 * i)->setX(firstObstacleX + i * (distBetweenObstacles + obstacleWidth));
        obstacles.at(2 * i + 1)->setX(firstObstacleX + i * (distBetweenObstacles + obstacleWidth));

        // Randomize height of the top obstacle
        newHeight = rand() % (screenHeight - 300);
        obstacles.at(2 * i)->setHeight(newHeight);
        newY = newHeight + obstacleGap;
        obstacles.at(2 * i + 1)->setY(newY);
        obstacles.at(2 * i + 1)->setHeight(screenHeight - newY);
    }
}
