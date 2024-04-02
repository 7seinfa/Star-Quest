/**
 * @file Background.cpp
 * @brief Implementation of the Background class.
 *
 * background class implements drectives, private, and public attributes and methods declared by Background.h
 *
 * @author Hussein Abdallah
 * @date March 11, 2024
 */

#include "headers/Background.h"
#include <QGuiApplication>
#include <QScreen>
#include <QTimer>

/**
 * @brief Constructs a Background object with an image, location, dimensions, and update interval.
 *
 * constructor is used to create the background with an image and geometry attributes
 *
 * @param sprMap the sprite image to display and attach to this Background
 * @param x The x-coordinate for background
 * @param y The y-coordinate for background
 * @param width The width of the background.
 * @param height The height of the background.
 * @param timerDelay The delay in milliseconds between updates to animate the background.
 * @param parent The parent QWidget for this background, if any (default is nullptr).
 *
 * @return none
 */
Background::Background(QPixmap sprMap, int x, int y, int width, int height, int timerDelay, QWidget* parent)
    : Object(sprMap, x, y, width, height, parent){
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Background::update);
    timer->start(timerDelay);
};

/**
 * @brief Updates the background's position to simulate motion.
 *
 * update function run periodically according to a QTimer declared in the constructor
 *
 * @param none
 * @return none
 */

void Background::update() {
    setX(getX()-1);
    if (getX() <= -getWidth()/2) setX(0);
}
