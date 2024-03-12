/* Author: Hussein Abdallah
 * Description: Obstacle header defines/declares drectives, private, and public attributes and methods used by class obstacle.cpp.
 * Date: March 11, 2024
*/

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