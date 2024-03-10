#pragma once
#ifndef COLLIDABLEOBJECT_H
#define COLLIDABLEOBJECT_H
#include "headers/Object.h"

class CollidableObject : public Object {
public:
    CollidableObject(QPixmap sprMap, int x, int y, int width, int height, QWidget *parent = nullptr);
    bool collidesWith (Object otherObject);
private:
    void update();
};

#endif 