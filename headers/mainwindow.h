#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <vector>
#include "headers/Background.h"
#include "headers/Obstacle.h"
#include "headers/Player.h"
#include "Player.h"

namespace Ui {
    class MainWindow;
}
 
// the main window of the game
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

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

#endif // MAINWINDOW_H