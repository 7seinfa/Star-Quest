#include "headers/CollidableObject.h"
#include <QGuiApplication>
#include <QScreen>

CollidableObject::CollidableObject(QPixmap sprMap, int x, int y, int width, int height, QWidget* parent)
        : Object(sprMap, x, y, width, height, parent){};
