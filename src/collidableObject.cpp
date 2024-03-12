/* Author: Hussein Abdallah
 * Description: collidableObject class implements drectives, private, and public attributes and methods declared by CollidableObject.h
 * Date: March 11, 2024
*/

#include "headers/CollidableObject.h"
#include <QGuiApplication>
#include <QScreen>

/*
 * Function: CollidableObject Constructor
 * Description: constructor is used to create a collidable object with an image and geometry attributes
 * Parameters:
 *   QPixmap sprMap - the sprite image to display and attach to this CollidableObject
 *   int x - the x location of the CollidableObject
 *   int y - the y location of the CollidableObject
 *   int width - the width of the CollidableObject
 *   int height - the height of the CollidableObject
 *   QWidget *parent - pointer for the parent QWidget for this widget
 * Return: no value returned
 */
CollidableObject::CollidableObject(QPixmap sprMap, int x, int y, int width, int height, QWidget* parent)
        : Object(sprMap, x, y, width, height, parent){};
