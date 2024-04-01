
/* Author: Joud Al-lahham
 * Description: Manages the player character's movements, including jumping and gravity, processes input for jump actions through the space bar, and updates the player's vertical position based on velocity and gravity.
 * Date: March 11, 2024
*/

#include "headers/Player.h"
#include <QTimer>

/**
 * Description: Constructs a Player object. Initializes a player with a specified sprite, position, size, gravity, and jump strength.
 * Sets up a timer that triggers the update method at regular intervals.
 *
 * Parameters:
 * @param sprMap Sprite map for the player.
 * @param x Initial X position of player.
 * @param y Initial Y position of player.
 * @param width Width of the player.
 * @param height Height of the player.
 * @param gravity Gravity strength affecting the player.
 * @param yJump Jump strength of the player.
 * @param parent Pointer to the parent widget, defaulting to nullptr.
 * 
 * Return: none
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
 * Name: jump
 * Description: Triggers a jump action for the player. If the space bar is not pressed, applies a negative velocity to the player simulating a jump, and marks the space as pressed.
 * Parameter: none
 * Return: none
 */
void Player::jump() {
    // Trigger a jump if space is not pressed
    if (!isSpacePressed) {
        yVelocity = -jumpStrength;  // Strength of jump
        isSpacePressed = true;
    }
}

/**
 * Name: keyPressEvent
 * Description: Handles key press events for the player. Specifically looks for space bar presses to initiate a jump.
 * Parameter: event The key event captured by the Qt event system.
 * Return: none
 */
void Player::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Space && !event->isAutoRepeat()) {
        jump();
    }
}

/**
 * Name: keyReleaseEvent
 * Description: Handles key release events for the player.Resets the space bar pressed state, allowing for another jump.
 * Parameter: event The key event captured by the Qt event system.
 * Return: void
 */
void Player::keyReleaseEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Space && !event->isAutoRepeat()) {
        isSpacePressed = false;
    }
}

/**
 * Name: update
 * Description: Regularly updates the player's state. Applies gravity to the player and updates its Y position.
 * Parameters: none
 * Return: none
 */
void Player::update() {
    if (yVelocity+gravityStrength <= jumpStrength) yVelocity += gravityStrength;  
    setY(getY() + yVelocity);
    raise();
}

/**
 * Name: resetVelocity
 * Description: Resets the player's vertical velocity to zero. Used when restarting the game to ensure the player's state is reset.
 * Parameters: none
 * Return: none
 */
void Player::resetVelocity() {
    yVelocity = 0;
}