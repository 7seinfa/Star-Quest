#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include "headers/Background.h"

namespace Ui {
    class MainWindow;
}
 
// the main window of the game
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
private slots:
    void update();
private:
    Background* background;
};

#endif // MAINWINDOW_H