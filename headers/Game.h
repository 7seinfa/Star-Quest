/**
 * @file Game.h
 * @brief Game class declaration.
 *
 * Game header defines/declares drectives, private, and public attributes and methods used by class game.cpp.
 *
 * @author Hussein Abdallah
 * @date March 11, 2024
 */

#pragma once
#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QWidget>
#include <vector>
#include "headers/Background.h"
#include "headers/Obstacle.h"
#include "headers/HighScore.h"
#include "headers/Player.h"
#include "Player.h"

namespace Ui {
class Game;
}

/**
 * @class Game
 * @brief the main window of the game
 *
 * The Game class extends QMainWindow to provide a main application window for the game. It is responsible for initializing
 * the game environment, processing player inputs, and managing game states such as playing, paused, and game over.
 */
class Game : public QMainWindow
{
    Q_OBJECT
public:

    explicit Game(QWidget *parent = nullptr);
    void gameOver();
    void restartGame();
    void resetObstacles();
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
    HighScore* score;
    int firstObstacleX;
    int distBetweenObstacles;
    int obstacleGap;
    int obstacleWidth;
};

#endif // GAME_H
