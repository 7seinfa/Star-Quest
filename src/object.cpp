#include "headers/Object.h"

Object::Object(QPixmap sprMap, int x, int y, int width, int height, QWidget* parent)
: QLabel(parent), x(x), y(y), width(width), height(height) {
    setPixmap(sprMap);
    setGeometry(x,y,width,height);
    setScaledContents(true);
    setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
}

int Object::getX() {
    return pos().x();
}
int Object::getY() {
    return pos().y();
}
int Object::getWidth() {
    return size().width();
}
int Object::getHeight() {
    return size().height();
}

void Object::setX(int newX){
    x = newX;
    setGeometry(x,getY(),getWidth(),getHeight());
}
void Object::setY(int newY){
    y = newY;
    setGeometry(getX(),y,getWidth(),getHeight());
}