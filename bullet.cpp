// #include "bullet.h"
// #include <QPainter>
// #include <QGraphicsScene>

// Bullet::Bullet(int dir)
// {
//     direction = dir;
//     setRotation(direction * 90);
// }

// QRectF Bullet::boundingRect() const
// {
//     return QRectF(-3, -3, 6, 6);
// }

// void Bullet::paint(QPainter* p, const QStyleOptionGraphicsItem*, QWidget*)
// {
//     p->setBrush(Qt::yellow);
//     p->drawEllipse(boundingRect());
// }

// void Bullet::advance(int phase)
// {
//     if(!phase) return;

//     int speed = 10;

//     if(direction == 0)      setY(y() - speed);
//     else if(direction == 1) setX(x() + speed);
//     else if(direction == 2) setY(y() + speed);
//     else if(direction == 3) setX(x() - speed);

//     if(!scene()->sceneRect().contains(pos()))
//         scene()->removeItem(this);
// }
