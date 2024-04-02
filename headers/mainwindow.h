/**
 * @file MainWindow.h
 * @brief Declares the MainWindow class for the game's main menu interface.
 *
 * This header file contains the declaration of the MainWindow class, which manages the game's main menu, including the setup of the UI and handling user interactions.
 *
 * @author: Laila El attar
 * Date: February 6th, 2024
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H


// directives required for program operation
#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QDebug>
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QString>
#include <QWidget>
#include <QGraphicsProxyWidget>

class MainWindow: public QGraphicsView{
    Q_OBJECT

public:
    // public constructor
    MainWindow(QWidget* parent=NULL);

    // public methods
    void displayMainMenu();

    // public attributes
    QGraphicsScene* scene;

private slots:
    // private methods
    void handlePlayButton();
    void handleQuitButton();

private:
    // private attributes
    QPushButton *playButton;
    QPushButton *quitButton;
    QPushButton *soundButton;


};

#endif // MAINWINDOW_H

