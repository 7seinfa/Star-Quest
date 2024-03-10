#ifndef PLAYER_H
#define PLAYER_H

#include "CollidableObject.h"
#include <QKeyEvent>

class Player : public CollidableObject {
public:
    Player(QPixmap sprMap, int x, int y, int width, int height, QWidget *parent = nullptr);

    void jump();
    void update(); 
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private:
    qreal yVelocity;
    qreal gravityStrength;
    bool isSpacePressed;
};

#endif // PLAYER_H
