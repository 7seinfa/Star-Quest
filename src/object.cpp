/**
 *  Author: Hussein Abdallah
 * Description: object class implements drectives, private, and public attributes and methods declared by Object.h
 * Date: March 11, 2024
*/

#include "headers/Object.h"

/**
 * Function: Object Constructor
 * Description: constructor is used to create an object with an image and geometry attributes
 * Parameters:
 *   QPixmap sprMap - the sprite image to display and attach to this Object
 *   int x - the x location of the Object
 *   int y - the y location of the Object
 *   int width - the width of the Object
 *   int height - the height of the Object
 *   QWidget *parent - pointer for the parent QWidget for this widget
 * Return: no value returned
 */
Object::Object(QPixmap sprMap, int x, int y, int width, int height, QWidget* parent)
: QLabel(parent), x(x), y(y), width(width), height(height) {
    setPixmap(sprMap);
    setGeometry(x,y,width,height);
    setScaledContents(true);
    setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
}

/**
 * Function: getX
 * Description: getter function for the x location of this Object
 * Parameters: no parameters required
 * Return: no value returned
 */
int Object::getX() {
    return pos().x();
}

/**
 * Function: getY
 * Description: getter function for the y location of this Object
 * Parameters: no parameters required
 * Return: no value returned
 */
int Object::getY() {
    return pos().y();
}

/**
 * Function: getWidth
 * Description: getter function for the width of this Object
 * Parameters: no parameters required
 * Return: no value returned
 */
int Object::getWidth() {
    return size().width();
}

/**
 * Function: getHeight
 * Description: getter function for the height of this Object
 * Parameters: no parameters required
 * Return: no value returned
 */
int Object::getHeight() {
    return size().height();
}


/**
 * Function: setX
 * Description: setter function for the x position of this Object
 * Parameters: 
 *   int newX - the new x location of the Object
 * Return: no value returned
 */
void Object::setX(int newX){
    x = newX;
    setGeometry(x,getY(),getWidth(),getHeight());
}

/**
 * Function: setY
 * Description: setter function for the y position of this Object
 * Parameters: 
 *   int newY - the new y location of the Object
 * Return: no value returned
 */
void Object::setY(int newY){
    y = newY;
    setGeometry(getX(),y,getWidth(),getHeight());
}

/**
 * Function: setWidth
 * Description: setter function for the y position of this Object
 * Parameters: 
 *   int newWidth - the new width of the Object
 * Return: no value returned
 */
void Object::setWidth(int newWidth){
    width = newWidth;
    setGeometry(getX(),getY(),newWidth,getHeight());
}

/**
 * Function: setHeight
 * Description: setter function for the y position of this Object
 * Parameters: 
 *   int newHeight - the new height of the Object
 * Return: no value returned
 */
void Object::setHeight(int newHeight){
    height = newHeight;
    setGeometry(getX(),getY(),getWidth(),newHeight);
}
