#include "Bricks.h"
#include <QGraphicsScene>
Bricks::Bricks(qreal x, qreal y)
{
    setPixmap(QPixmap(":/Images/bricks.png"));
    setPos(x, y);
//    setShapeMode(QGraphicsPixmapItem::HeuristicMaskShape);
}
