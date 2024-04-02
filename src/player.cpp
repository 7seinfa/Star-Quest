/**
 * @file Player.cpp
 * @brief Manages the player character's movements in the game.
 *
 * Implements the Player class functionalities as defined in Player.h. This includes processing input for jump actions,
 * applying gravity, and updating the player's vertical position. A timer triggers periodic updates to simulate continuous motion.
 *
 * @author Joud Al-lahham
 * @date March 11, 2024
 */

#include "headers/Player.h"
#include <QTimer>

/**
 * @brief Constructs a Player object with specified parameters.
 *
 * Initializes player attributes including sprite, position, size, gravity, and jump strength. Sets up a timer for periodic updates.
 *
 * @param sprMap Sprite image for the player.
 * @param x Initial X-coordinate of the player.
 * @param y Initial Y-coordinate of the player.
 * @param width Width of the player sprite.
 * @param height Height of the player sprite.
 * @param gravity Gravity effect on the player.
 * @param jumpStrength Jump strength of the player.
 * @param parent Pointer to the parent QWidget.
 * @return none
 */
Player::Player(QPixmap sprMap, int x, int y, int width, int height, qreal gravity, qreal yJump, QWidget *parent)
    : CollidableObject(sprMap, x, y, width, height, parent), yVelocity(0), gravityStrength(gravity),
    jumpStrength(yJump), isSpacePressed(false) {
    raise();

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Player::update);
    timer->start(100);
}

/**
 * @brief Initiates a jump for the player.
 *
 * Applies an upward velocity to the player to simulate a jump. The function ensures the jump can only be initiated if the space bar is not already pressed.
 */
void Player::jump() {
    // Trigger a jump if space is not pressed
    if (!isSpacePressed) {
        yVelocity = -jumpStrength;  // Strength of jump
        isSpacePressed = true;
    }
}

/**
 * @brief Handles key press events for initiating a jump.
 *
 * Listens for space bar presses to trigger a jump. Prevents jump spamming by checking if the key is already pressed.
 *
 * @param event Captured key event.
 */
void Player::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Space && !event->isAutoRepeat()) {
        jump();
    }
}

/**
 * @brief Handles key release events.
 *
 * Resets the state to allow for subsequent jumps when the space bar is released.
 *
 * @param event Captured key event.
 */
void Player::keyReleaseEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Space && !event->isAutoRepeat()) {
        isSpacePressed = false;
    }
}

/**
 * @brief Updates the player's state.
 *
 * Applies gravity to the player and updates the Y position accordingly. This method is called periodically by a timer.
 */
void Player::update() {
    if (yVelocity+gravityStrength <= jumpStrength) yVelocity += gravityStrength;
    setY(getY() + yVelocity);
    raise();
}

/**
 * @brief Resets the player's vertical velocity.
 *
 * Ensures the player's velocity is reset to zero, typically called when restarting the game.
 */
void Player::resetVelocity() {
    yVelocity = 0;
}
