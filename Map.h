#ifndef MAP_H
#define MAP_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPainter>
class Map : public QObject, public QGraphicsPixmapItem, public QPainter
{
    Q_OBJECT
private:
    char* mapName;
public:
    Map(char*);
};

#endif // MAP_H
