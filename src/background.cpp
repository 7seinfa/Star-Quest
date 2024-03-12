/* Author: Hussein Abdallah
 * Description: background class implements drectives, private, and public attributes and methods declared by Background.h
 * Date: March 11, 2024
*/

#include "headers/Background.h"
#include <QGuiApplication>
#include <QScreen>
#include <QTimer>

/*
 * Function: Background Constructor
 * Description: constructor is used to create the background with an image and geometry attributes
 * Parameters:
 *   QPixmap sprMap - the sprite image to display and attach to this Background
 *   int x - the x location of the Background
 *   int y - the y location of the Background
 *   int width - the width of the Background
 *   int height - the height of the Background
 *   int timerDelay - delay to pass to the QTimer, to determine how often update() is run
 *   QWidget *parent - pointer for the parent QWidget for this widget
 * Return: no value returned
 */
Background::Background(QPixmap sprMap, int x, int y, int width, int height, int timerDelay, QWidget* parent)
        : Object(sprMap, x, y, width, height, parent){
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Background::update);
    timer->start(timerDelay);
};

/*
 * Function: update
 * Description: update function run periodically according to a QTimer declared in the constructor
 * Parameters: no parameter required
 * Return: no value returned
 */
void Background::update() {
    setX(getX()-1);
    if (getX() <= -getWidth()/2) setX(0);
}