/**
 * @file Obstacle.cpp
 * @brief Implementation of the Obstacle class.
 *
 * obstacle class implements drectives, private, and public attributes and methods declared by Obstacle.h
 *
 * @author Hussein Abdallah
 * @date March 11, 2024
 */

#include "headers/Obstacle.h"
#include <QGuiApplication>
#include <QScreen>
#include <stdlib.h>

/**
 * @brief Constructor for the Obstacle class.
 *
 * Initializes an Obstacle instance with specified image, position, and dimensions. Sets the obstacle's height dynamically if positioned at the top or bottom of the screen.
 *
 * @param sprMap Sprite image to display.
 * @param x Initial x-coordinate of the obstacle.
 * @param y Initial y-coordinate of the obstacle, used to determine if the obstacle is at the top or bottom.
 * @param width Width of the obstacle.
 * @param parent Pointer to the parent QWidget.
 */
Obstacle::Obstacle(QPixmap sprMap, int x, int y, int width, QWidget* parent)
    : CollidableObject(sprMap, x, y, width, 0, parent){
    if (y==0) setHeight(rand()%(QGuiApplication::screens()[0]->availableGeometry().height()-300));
    else setHeight(QGuiApplication::screens()[0]->availableGeometry().height()-y);
};

/**
 * @brief Updates the position and size of the obstacle.
 *
 * Periodically called to move the obstacle across the screen. Resets the obstacle's position and randomly adjusts its height when it moves off-screen.
 *
 * @param newY New y-coordinate for the obstacle, used in adjusting the height for bottom-placed obstacles.
 */
void Obstacle::update(int newY) {
    setY(newY);
    setX(getX()-1);
    if (getX() < 0-getWidth()*2){
        setX(QGuiApplication::screens()[0]->availableGeometry().width()+getWidth());
        if (getY() == 0) setHeight(rand()%(QGuiApplication::screens()[0]->availableGeometry().height()-300));
        else setHeight(QGuiApplication::screens()[0]->availableGeometry().height()-getY());
    }
}
