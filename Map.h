#ifndef MAP_H
#define MAP_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QWidget>
#include "Bricks.h"
#include "myBox.h"
#include "Forest.h"
#include <QFile>
#include <QGraphicsScene>


class Map : public QWidget
{
    Q_OBJECT
public:
    Map(QGraphicsScene*, QString);
    void setName(QString name);
private:
    QFile file1;
    QString name;
};

#endif // MAP_H
