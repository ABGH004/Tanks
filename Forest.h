#ifndef FOREST_H
#define FOREST_H

#include <QObject>
#include <QGraphicsPixmapItem>
class Forest : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Forest(qreal, qreal);
};

#endif // FOREST_H
