#include "headers/Background.h"
#include <QGuiApplication>
#include <QScreen>
#include <QTimer>

Background::Background(QPixmap sprMap, int x, int y, int width, int height, int timerSpeed, QWidget* parent)
        : Object(sprMap, x, y, width, height, parent){
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Background::update);
    timer->start(timerSpeed);
};

void Background::update() {
    setX(getX()-1);
    if (getX() <= -getWidth()/2) setX(0);
}