#include "headers/Obstacle.h"
#include <QGuiApplication>
#include <QScreen>
#include <stdlib.h>


Obstacle::Obstacle(QPixmap sprMap, int x, int y, int width, QWidget* parent)
        : CollidableObject(sprMap, x, y, width, 0, parent){
    if (y==0) setHeight(rand()%(QGuiApplication::screens()[0]->availableGeometry().height()-300));
    else setHeight(QGuiApplication::screens()[0]->availableGeometry().height()-y);
};

void Obstacle::update(int newY) {
    setY(newY);
    setX(getX()-1);
    if (getX() < 0-getWidth()){
        setX(QGuiApplication::screens()[0]->availableGeometry().width());
        if (getY() == 0) setHeight(rand()%(QGuiApplication::screens()[0]->availableGeometry().height()-300));
        else setHeight(QGuiApplication::screens()[0]->availableGeometry().height()-getY());
    }
}