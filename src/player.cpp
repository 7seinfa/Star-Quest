#include "headers/Player.h"
#include <QTimer>

Player::Player(QPixmap sprMap, int x, int y, int width, int height, qreal gravity, qreal yJump, QWidget *parent)
        : CollidableObject(sprMap, x, y, width, height, parent), yVelocity(0), gravityStrength(gravity), 
        jumpStrength(yJump), isSpacePressed(false) {
    raise();
    
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Player::update);
    timer->start(100);
}

void Player::jump() {
    // Trigger a jump if space is not pressed
    if (!isSpacePressed) {
        yVelocity = -jumpStrength;  // Strength of jump
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
    if (yVelocity+gravityStrength <= jumpStrength) yVelocity += gravityStrength;  
    setY(getY() + yVelocity);
    raise();
}
