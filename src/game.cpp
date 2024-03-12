/* Author: Hussein Abdallah
 * Description: game class implements drectives, private, and public attributes and methods declared by Game.h
 * Date: March 11, 2024
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

/*
 * Function: Game Constructor
 * Description: constructor is used to set up the window of the game
 * Parameters:
 *   QWidget *parent - pointer for the parent QWidget for the Game instance
 * Return: no value returned
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
    //currently clears on exit
    //QLCDNumber *scoreDisplay = new QLCDNumber(3, parent);
    //scoreDisplay->resize(200, 100);
    //scoreDisplay->raise();
    //scoreDisplay->display("010");
    //scoreDisplay->move(0, 0);
    score = new HighScore(this);

    //run update function every millisecond
    QTimer *timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(10);

    QPixmap spaceshipPixmap("img/spaceship.png");
    int initialX = 100; // X position
    int initialY = QGuiApplication::screens()[0]->availableGeometry().height() / 2; // Y position
    int spaceshipWidth = 200; // Spaceship width
    int spaceshipHeight = 160; // Spaceship height
    qreal gravity = 1.0;
    qreal jump = 18;
    
    player = new Player(spaceshipPixmap, initialX, initialY, spaceshipWidth, spaceshipHeight, gravity, jump, this);
}

/*
 * Function: keyPressEvent
 * Description: used to receive key presses to notify player
 * Parameters:
 *   QKeyEvent *event - pointer for the event to send to the player
 * Return: no value returned
 */
void Game::keyPressEvent(QKeyEvent *event) {
    if (player) {
        player->keyPressEvent(event);
    }
}

/*
 * Function: keyReleaseEvent
 * Description: used to receive key releases to notify player
 * Parameters:
 *   QKeyEvent *event - pointer for the event to send to the player
 * Return: no value returned
 */
void Game::keyReleaseEvent(QKeyEvent *event) {
    if (player) {
        player->keyReleaseEvent(event);
    }
}

/*
 * Function: update
 * Description: runs periodically, time between each run set by QTimer in the constructor function
 * Parameters: no parameters
 * Return: no value returned
 */
void Game::update(){
    //background->update();
    for (unsigned int i = 0; i < obstacles.size()/2; i++) {
        obstacles.at(2*i)->update(0);
        obstacles.at(2*i+1)->update(obstacles.at(2*i)->getHeight()+obstacleGap);
        if (obstacles.at(2*i)->getX() + (obstacles.at(2*i)->getWidth() / 2) == player->getX()) {
            score->updateScore(score->getScore()+1);
        }
    }
    //player->update();
}
