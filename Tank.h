#ifndef TANK_H
#define TANK_H

#include <QObject>
#include <QPainter>
#include <QPaintEvent>
#include <QGraphicsRectItem>
class Tank : public QObject
{
    Q_OBJECT
public:
    explicit Tank(QObject *parent = nullptr);

signals:

};

#endif // TANK_H
