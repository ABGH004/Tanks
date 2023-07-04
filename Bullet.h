#ifndef BULLET_H
#define BULLET_H

#include <QPainter>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QAudioOutput>
#include <QMediaPlayer>
class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet();
    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
public slots:
    void move();
};

#endif // BULLET_H
