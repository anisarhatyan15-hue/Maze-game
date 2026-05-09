// #include "player.h"

// Player::Player()
// {
//     setFlag(ItemIsFocusable);
//     setFocus();
// }

// QRectF Player::boundingRect() const
// {
//     return QRectF(-10, -20, 20, 40);
// }

// void Player::paint(QPainter *p, const QStyleOptionGraphicsItem *, QWidget *)
// {
//     p->setBrush(playerColor);
//     p->drawEllipse(-8, -20, 16, 16);
//     p->drawRect(-4, -4, 8, 20);

//     // gun
//     p->setBrush(Qt::green);

//     if(direction == 0)      p->drawRect(-3, -30, 6, 10);
//     else if(direction == 1) p->drawRect(10, -5, 10, 6);
//     else if(direction == 2) p->drawRect(-3, 20, 6, 10);
//     else if(direction == 3) p->drawRect(-20, -5, 10, 6);
// }
