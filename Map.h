#ifndef MAP_H
#define MAP_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QGraphicsRectItem>

#include <QGraphicsScene>
class Map : public QWidget
{
    Q_OBJECT
public:
    Map(QGraphicsScene*);
};

#endif // MAP_H
