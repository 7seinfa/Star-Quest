#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class Player : public QGraphicsPixmapItem {
public:
    Player(QPixmap spriteMap, int x, int y, int width, int height, QGraphicsItem *parent = nullptr);

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
