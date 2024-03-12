/* Author: Hussein Abdallah
 * Description: Object header defines/declares drectives, private, and public attributes and methods used by class object.cpp.
 * Date: March 11, 2024
*/

#pragma once
#ifndef OBJECT_H
#define OBJECT_H

#include <QLabel>
#include <QPixmap>

class Object : public QLabel
{
    Q_OBJECT
private:
    int x;
    int y;
    int width;
    int height;
    void update();
public:
    Object(QPixmap sprMap, int x, int y, int width, int height, QWidget *parent = nullptr);
    int getX(); 
    int getY(); 
    int getWidth(); 
    int getHeight(); 

    void setX(int newX); 
    void setY(int newY); 
    void setWidth(int newWidth); 
    void setHeight(int newHeight); 
};

#endif 