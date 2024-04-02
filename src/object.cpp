/**
 * @file Object.cpp
 * @brief Implementation of the Object class.
 *
 * object class implements drectives, private, and public attributes and methods declared by Object.h *
 *
 * @author Hussein Abdallah
 * @date March 11, 2024
 */

#include "headers/Object.h"

/**
 * @brief Constructor for the Object class.
 *
 * constructor is used to create an object with an image and geometry attributes *
 *
 * @param sprMap Sprite image to display.
 * @param x Initial x-coordinate of the object.
 * @param y Initial y-coordinate of the object.
 * @param width Width of the object.
 * @param height Height of the object.
 * @param parent Pointer to the parent QWidget.
 *
 * @return none
 */
Object::Object(QPixmap sprMap, int x, int y, int width, int height, QWidget* parent)
    : QLabel(parent), x(x), y(y), width(width), height(height) {
    setPixmap(sprMap);
    setGeometry(x,y,width,height);
    setScaledContents(true);
    setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
}
/**
 * @brief getter function for the x location of this Object
 * @param none
 * @return X-coordinate of the object.
 */
int Object::getX() {
    return pos().x();
}

/**
 * @brief getter function for the y location of this Object
 * @param none
 * @return Y-coordinate of the object.
 */
int Object::getY() {
    return pos().y();
}

/**
 * @brief getter function for the width of this Object
 * @param none
 * @return width of the object.
 */
int Object::getWidth() {
    return size().width();
}

/**
 * @brief getter function for the height of this Object
 * @param none
 * @return height of the object.
 */
int Object::getHeight() {
    return size().height();
}

/**
 * @brief setter function for the x position of this Object
 * @param newX New x-coordinate for the object.
 * @return none
 */
void Object::setX(int newX){
    x = newX;
    setGeometry(x,getY(),getWidth(),getHeight());
}

/**
 * @brief setter function for the y position of this Object
 * @param newY New y-coordinate for the object.
 * @return none
 */
void Object::setY(int newY){
    y = newY;
    setGeometry(getX(),y,getWidth(),getHeight());
}

/**
 * @brief setter function for the width of this Object
 * @param newWidth New width for the object.
 * @return none
 */
void Object::setWidth(int newWidth){
    width = newWidth;
    setGeometry(getX(),getY(),newWidth,getHeight());
}

/**
 * @brief setter function for the height of this Object
 * @param newHeight New height for the object.
 * @return none
 */
void Object::setHeight(int newHeight){
    height = newHeight;
    setGeometry(getX(),getY(),getWidth(),newHeight);
}
