/**
 * @file Obstacle.h
 * @brief Defines the Obstacle class, responsible for creating and managing obstacles in the game.
 *
 * The Obstacle class extends CollidableObject, allowing obstacles to interact with the player and other objects within the game environment. It supports dynamic positioning and sizing to enhance game complexity and variation.
 * @author: Hussein Abdallah
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
