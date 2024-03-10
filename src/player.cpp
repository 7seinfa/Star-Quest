#include "headers/Player.h"

Player::Player(QPixmap spriteMap, int x, int y, int width, int height, QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent), yVelocity(0), gravityStrength(0.5), isSpacePressed(false) {
    setPixmap(spriteMap.scaled(width, height, Qt::KeepAspectRatio));
    setPos(x, y);
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
    setPos(x(), y() + yVelocity);
}
