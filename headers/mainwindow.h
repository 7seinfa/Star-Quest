/* Author: Laila El attar
 * Description: Game header defines/declares drectives, private, and public attributes and methods used by class game.cpp.
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

