/**
 * @file Player.h
 * @brief Defines the Player class, which handles player movements and interactions in the game.
 *
 * The Player class extends CollidableObject to include specific functionalities for player control, such as jumping and responding to key events. It incorporates physics elements like gravity and velocity for more dynamic movements.
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "CollidableObject.h"
#include <QKeyEvent>

class Player : public CollidableObject {
public:
    Player(QPixmap sprMap, int x, int y, int width, int height, qreal gravity, qreal yJump, QWidget *parent = nullptr);

    void jump();
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void resetVelocity();
private:
    qreal yVelocity;
    qreal gravityStrength;
    qreal jumpStrength;
    bool isSpacePressed;
    void update();
};

#endif // PLAYER_H
