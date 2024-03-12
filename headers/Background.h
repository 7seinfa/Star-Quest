/* Author: Hussein Abdallah
 * Description: Background header defines/declares drectives, private, and public attributes and methods used by class background.cpp.
 * Date: March 11, 2024
*/

#pragma once
#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "headers/Object.h"

class Background : public Object {
public:
    Background(QPixmap sprMap, int x, int y, int width, int height, int timerDelay, QWidget *parent = nullptr);
private:
    void update();
};

#endif 