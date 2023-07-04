#ifndef MAP_H
#define MAP_H
#include <QGraphicsPixmapItem>
#include <QObject>
class Map : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    char* mapName;
public:
    Map(char*);
};

#endif // MAP_H
