#ifndef MYBOX_H
#define MYBOX_H

#include <QObject>
#include <QGraphicsPixmapItem>
class myBox : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    int lives;
public:
    myBox(qreal, qreal, int);
    void decrementLives();
};

#endif // MYBOX_H
