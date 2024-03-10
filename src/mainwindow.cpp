#include "headers/mainwindow.h"
#include "headers/Background.h"
#include <QTimer>
#include <iostream>
#include <QGuiApplication>
#include <QScreen>

// the main window of the game
MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
    //setWindowState(Qt::WindowFullScreen);
    QPixmap bg("img/background.png");
    background = new Background(bg, 0, 0, QGuiApplication::screens()[0]->availableGeometry().width()*2,
        QGuiApplication::screens()[0]->availableGeometry().height(), this);
    //setCentralWidget(background);
    //background->show();

    QTimer *timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1);
}

void MainWindow::update(){
    background->update();
}