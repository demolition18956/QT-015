#include "projectile.h"

Projectile::Projectile()
{
    color = QColor("yellow");
    dx = 0.00;
    dy = 2.50;
    x = 0.0;
    y = 0.0;
    w = 10.0;
    h = 20.0;
}

void Projectile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
// paint() paints item in local coord.
{
    painter->setBrush(color);
    painter->drawRect(-w/2,-h/2,w,h);
}

QRectF Projectile::boundingRect() const
// Determines bounds for repainting
{
    qreal adjust = 1.0;
    return QRectF(-w/2 - adjust, -h/2 - adjust, w + adjust, h + adjust);
}

void Projectile::advance(int step)
// advance() advances item by frame
{
    if (step == 0)
        return;

    x = this->pos().x();
    y = this->pos().y();

    x = x + dx;
    y = y + dy;

    setPos(x,y);            // Set item pos. in parent coord.
}

QPainterPath Projectile::shape() const
// Returns shape for collision detection
{
    QPainterPath path;
    path.addRect(-w/2, -h/2, w, h);
    return path;
}
