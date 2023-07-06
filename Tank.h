#ifndef TANK_H
#define TANK_H

#include <QObject>
#include <QPainter>
#include <QPaintEvent>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QWidget>
#include <QTransform>
#include <QTimer>
class Tank : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int velocity;
    int HP;
    int strength;
public:
    Tank(qreal, qreal, int);
    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    void keyPressEvent(QKeyEvent* keyEvent);
    QPainterPath shape() const;
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
public slots:
    void collision();
signals:

};

#endif // TANK_H
