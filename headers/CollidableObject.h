/**
 * @file CollidableObject.h
 * @brief Declaration of the CollidableObject class.
 *
 * CollidableObject header defines/declares drectives, private, and public attributes and methods used by class collidableObject.cpp.
 *
 * @author Hussein Abdallah
 * @date March 11, 2024
 */

#pragma once
#ifndef COLLIDABLEOBJECT_H
#define COLLIDABLEOBJECT_H
#include "headers/Object.h"

class CollidableObject : public Object {
public:

    CollidableObject(QPixmap sprMap, int x, int y, int width, int height, QWidget *parent = nullptr);

    bool collidesWith (Object* otherObject);
private:

    void update();
};

#endif
