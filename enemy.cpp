// #include "enemy.h"
// #include <QPainter>
// #include <QGraphicsScene>

// Enemy::Enemy()
// {
//     direction = rand() % 4;
//     setFlag(ItemIsFocusable, false);
// }

// QRectF Enemy::boundingRect() const
// {
//     return QRectF(-10, -10, 20, 20);
// }

// void Enemy::paint(QPainter *p, const QStyleOptionGraphicsItem *, QWidget *)
// {
//     p->setBrush(Qt::red);
//     p->drawRect(-10, -10, 20, 20);
// }

// void Enemy::chooseNewDirection()
// {
//     direction = rand() % 4;
// }

// void Enemy::advance(int phase)
// {
//     if (!phase) return;

//     int speed = 3;

//     QPointF newPos = pos();

//     switch(direction)
//     {
//     case 0: newPos.setY(y() - speed); break;
//     case 1: newPos.setX(x() + speed); break;
//     case 2: newPos.setY(y() + speed); break;
//     case 3: newPos.setX(x() - speed); break;
//     }

//     if (scene()->sceneRect().contains(newPos))
//         setPos(newPos);
//     else
//         chooseNewDirection();
// }
