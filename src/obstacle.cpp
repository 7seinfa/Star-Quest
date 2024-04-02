/**
 *  Author: Hussein Abdallah
 * Description: obstacle class implements drectives, private, and public attributes and methods declared by Obstacle.h
 * Date: March 11, 2024
*/

#include "headers/Obstacle.h"
#include <QGuiApplication>
#include <QScreen>
#include <stdlib.h>

/**
 * Function: Obstacle Constructor
 * Description: constructor is used to create an obstacle with an image and geometry attributes
 * Parameters:
 *   QPixmap sprMap - the sprite image to display and attach to this Obstacle
 *   int x - the x location of the Obstacle
 *   int y - the y location of the Obstacle
 *   int width - the width of the Obstacle
 *   QWidget *parent - pointer for the parent QWidget for this widget
 * Return: no value returned
 */
Obstacle::Obstacle(QPixmap sprMap, int x, int y, int width, QWidget* parent)
        : CollidableObject(sprMap, x, y, width, 0, parent){
    if (y==0) setHeight(rand()%(QGuiApplication::screens()[0]->availableGeometry().height()-300));
    else setHeight(QGuiApplication::screens()[0]->availableGeometry().height()-y);
};

/**
 * Function: update
 * Description: update function run periodically according to a QTimer declared in the main Game class
 * Parameters: 
 *   int newY - the new y location of the Object
 * Return: no value returned
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
