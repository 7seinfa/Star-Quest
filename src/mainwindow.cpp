/**
 * Author: Hussein Abdallah
 * CS3307B
 * This file is where the main window of the game exists.
*/


//header file for this
#include "headers/mainwindow.h"

//includes
#include "headers/Background.h"
#include <QTimer>
#include <iostream>
#include <QGuiApplication>
#include <QScreen>
#include <time.h>

// the main window of the game
MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
    srand(time(NULL)); //random seed for the random map later

    //create background object
    QPixmap bg("img/background.png");
    background = new Background(bg, 0, 0, QGuiApplication::screens()[0]->availableGeometry().width()*2,
        QGuiApplication::screens()[0]->availableGeometry().height(), this);
    
    //create obstacles
    firstObstacleX=300;
    distBetweenObstacles=300;
    obstacleGap=250;
    obstacleWidth=100;
    QPixmap obT("img/obstacleTop.png");
    QPixmap obB("img/obstacleBot.png");
    for (int i = 0; i < (QGuiApplication::screens()[0]->availableGeometry().width()/(distBetweenObstacles+obstacleWidth))+1; i++) {
        Obstacle* obTop = new Obstacle(obT, firstObstacleX+i*(distBetweenObstacles+obstacleWidth), 0, obstacleWidth, this);
        Obstacle* obBot = new Obstacle(obB, firstObstacleX+i*(distBetweenObstacles+obstacleWidth), obTop->getHeight()+obstacleGap, obstacleWidth, this);
        obstacles.push_back(obTop);
        obstacles.push_back(obBot);
    }

    //run update function every millisecond
    QTimer *timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1);
}

//run every millisecond
void MainWindow::update(){
    background->update();
    for (unsigned int i = 0; i < obstacles.size()/2; i++) {
        obstacles.at(2*i)->update(0);
        obstacles.at(2*i+1)->update(obstacles.at(2*i)->getHeight()+obstacleGap);
    }
}