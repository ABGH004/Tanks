#include "Bricks.h"

Bricks::Bricks(qreal x, qreal y)
{
    setPixmap(QPixmap(":/Images/bricks.png"));
    setPos(x, y);
    setShapeMode(QGraphicsPixmapItem::HeuristicMaskShape);
}
