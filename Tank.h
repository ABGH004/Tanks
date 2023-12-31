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
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QGraphicsScene>

class Tank : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int velocity;
    int HP;
    int strength;
    QString color;
    QTimer * timer;
    QMediaPlayer *music;
    QAudioOutput *audio;
public:
    Tank(qreal, qreal);
    ~Tank();
    void setInfo(int HP, int velocity, int strength, QString color);
    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    QPainterPath shape() const;
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    void getHit(int bulletStr);
signals:
    void gameOver();
public slots:
    void collision();
    void up();
    void down();
    void left();
    void right();
    void shoot();
signals:

};

#endif // TANK_H
