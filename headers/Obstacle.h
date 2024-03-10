#pragma once
#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "headers/CollidableObject.h"

class Obstacle : public CollidableObject {
public:
    Obstacle(QPixmap sprMap, int x, int y, int width, QWidget *parent = nullptr);
    void update(int newY);
};

#endif 