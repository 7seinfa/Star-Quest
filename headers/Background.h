#pragma once
#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "headers/Object.h"

class Background : public Object {
public:
    Background(QPixmap sprMap, int x, int y, int width, int height, int timerSpeed, QWidget *parent = nullptr);
private:
    void update();
};

#endif 