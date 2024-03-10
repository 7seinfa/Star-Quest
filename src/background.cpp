#include "headers/Background.h"
#include <QGuiApplication>
#include <QScreen>

Background::Background(QPixmap sprMap, int x, int y, int width, int height, QWidget* parent)
        : Object(sprMap, x, y, width, height, parent){
};

void Background::update() {
    setX(getX()-1);
    if (getX() <= -getWidth()/2) setX(0);
}