#ifndef BRICKS_H
#define BRICKS_H

#include <QObject>
#include <QGraphicsPixmapItem>
class Bricks : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bricks(qreal, qreal);
};

#endif // BRICKS_H
