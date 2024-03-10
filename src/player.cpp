#include "headers/Player.h"

Player::Player(QPixmap sprMap, int x, int y, int width, int height, QWidget *parent)
        : CollidableObject(sprMap, x, y, width, height, parent), yVelocity(0), gravityStrength(0.5), isSpacePressed(false) {
    setWindowFlags(Qt::WindowStaysOnTopHint);
    raise();
    show();
}

void Player::jump() {
    // Trigger a jump if space is not pressed
    if (!isSpacePressed) {
        yVelocity = -10;  // Strength of jump
        isSpacePressed = true;
    }
}

void Player::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Space && !event->isAutoRepeat()) {
        jump();
    }
}

void Player::keyReleaseEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Space && !event->isAutoRepeat()) {
        isSpacePressed = false;
    }
}

void Player::update() {
    // Gravity 
    yVelocity += gravityStrength;  
    setY(getY() + yVelocity);
    raise();
    show();
}
