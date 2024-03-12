/* Author: Hussein Abdallah
 * Description: Game header defines/declares drectives, private, and public attributes and methods used by class game.cpp.
 * Date: March 11, 2024
*/
#pragma once
#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QWidget>
#include <vector>
#include "headers/Background.h"
#include "headers/Obstacle.h"
#include "headers/Player.h"
#include "Player.h"

namespace Ui {
    class Game;
}
 
// the main window of the game
class Game : public QMainWindow
{
    Q_OBJECT
public:
    explicit Game(QWidget *parent = nullptr);

// handle key events
protected:
    void keyPressEvent(QKeyEvent *event) override; 
    void keyReleaseEvent(QKeyEvent *event) override; 

private slots:
    void update();

private:
    Background* background;
    Player* player;
    std::vector<Obstacle*> obstacles;
    int firstObstacleX;
    int distBetweenObstacles;
    int obstacleGap;
    int obstacleWidth;
};

#endif // GAME_H