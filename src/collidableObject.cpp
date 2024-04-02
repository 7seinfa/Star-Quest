/**
 * @file CollidableObject.cpp
 * @brief Implementation of the CollidableObject class.
 *
 * collidableObject class implements drectives, private, and public attributes and methods declared by CollidableObject.h
 *
 * @author Hussein Abdallah
 * @date March 11, 2024
 */

#include "headers/CollidableObject.h"
#include <QGuiApplication>
#include <QScreen>

/**
 * @brief Constructs a CollidableObject with specified attributes.
 *
 * constructor is used to create a collidable object with an image and geometry attributes
 *
 * @param sprMap The sprite image for the collidable object.
 * @param x The x-coordinate for the object's initial position.
 * @param y The y-coordinate for the object's initial position.
 * @param width The width of the collidable object.
 * @param height The height of the collidable object.
 * @param parent The parent QWidget for this object, if any (defaults to nullptr).
 *
 * @return none
 */
CollidableObject::CollidableObject(QPixmap sprMap, int x, int y, int width, int height, QWidget* parent)
    : Object(sprMap, x, y, width, height, parent){};


/**
 * @brief Determines if this object collides with another object.
 *
 * Checks for collision with another object by comparing their geometric bounds. A collision is detected if
 * there is any overlap between the two objects' positions and dimensions.
 *
 * @param otherObject A pointer to another object to check collision against.
 * @return bool True if a collision is detected, false otherwise.
 */
bool CollidableObject::collidesWith(Object* otherObject) {
    if (getX()+getWidth() >= otherObject->getX() && getX() <= otherObject->getX() + otherObject->getWidth() &&
        getY()+getHeight() >= otherObject->getY() && getY() <= otherObject->getY() + otherObject->getHeight()) {

        return true;
    }
    return false;
}
