#ifndef TANK_H
#define TANK_H

#include <QObject>
#include <QPainter>
#include <QPaintEvent>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QWidget>
class Tank : public QGraphicsItem
{
public:
    Tank();
    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    void keyPressEvent(QKeyEvent* keyEvent);
signals:

};

#endif // TANK_H
