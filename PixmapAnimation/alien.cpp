#include "alien.h"

Alien::Alien()
{
    dx = 0.00;
    dy = 2.50;
    x = 0.0;
    y = 0.0;
    w = 100.0;
    h = 72.0;
    index = 0;
    pmaps[0] = QPixmap(":/images/invader1.png").scaled(w,h);
    pmaps[1] = QPixmap(":/images/invader1.png").scaled(w,h);
    pmaps[2] = QPixmap(":/images/invader1.png").scaled(w,h);
    pmaps[3] = QPixmap(":/images/invader1.png").scaled(w,h);
    pmaps[4] = QPixmap(":/images/invader2.png").scaled(w,h);
    pmaps[5] = QPixmap(":/images/invader2.png").scaled(w,h);
    pmaps[6] = QPixmap(":/images/invader2.png").scaled(w,h);
    pmaps[7] = QPixmap(":/images/invader2.png").scaled(w,h);
}

void Alien::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
// paint() paints item in local coord.
{
    index = (index + 1) % 8;
    painter->drawPixmap(-w/2,-h/2,pmaps[index]);
}

QRectF Alien::boundingRect() const
// Determines bounds for repainting
{
    qreal adjust = 1.0;
    return QRectF(-w/2 - adjust, -h/2 - adjust, w + adjust, h + adjust);
}

void Alien::advance(int step)
// advance() advances item by frame
{
    if (step == 0)
        return;

    x = this->pos().rx();
    y = this->pos().ry();

    x = x + dx;
    y = y + dy;

    setPos(x,y);            // Set item pos. in parent coord.
}

QPainterPath Alien::shape() const
// Returns shape for collision detection
{
    QPainterPath path;
    path.addRect(-w/2, -h/2, w, h);
    return path;
}

