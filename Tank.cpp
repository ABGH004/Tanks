#include "Tank.h"
#include "Bullet.h"
#include <QGraphicsScene>
Tank::Tank(qreal xPos, qreal yPos, int velocity)
{
    this->velocity = velocity;

    setFlag(ItemIsFocusable);
    setFocus();

    setPos(xPos, yPos);
    setTransformOriginPoint(boundingRect().center() + QPoint(-20, -20));
}

QRectF Tank::boundingRect() const
{
// outer most edges
    return QRectF(0,0,100,100);
}

void Tank::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPainterPath body;
    body.setFillRule(Qt::WindingFill);

    body.addRect(15, 4, 48, 40);

    QPainterPath canon;
    canon.addRect(48, 19, 25, 10);
    QPainterPath wheel1;
    wheel1.addRect(25, 0, 30, 4);
    QPainterPath wheel2;
    wheel2.addRect(25, 44, 30, 4);

    painter->setRenderHint(QPainter::Antialiasing);
    painter->fillPath(body, Qt::red);
    painter->fillPath(canon, Qt::black);
    painter->fillPath(wheel1, Qt::black);
    painter->fillPath(wheel2, Qt::black);
    painter->strokePath(body.simplified(), QPen(Qt::black, 1));
    painter->strokePath(canon, QPen(Qt::black, 1));


}

void Tank::keyPressEvent(QKeyEvent* keyEvent){
    switch(keyEvent->key()){
        case(Qt::Key_D):
            setPos(x() + velocity*3, y());
            setRotation(360);
            break;
        case(Qt::Key_A):
            setPos(x() - velocity*3, y());
            setRotation(180);
            break;

        case(Qt::Key_W):
            setPos(x(), y() - velocity*3);
            setRotation(270);
            break;
        case(Qt::Key_S):
            setPos(x(), y() + velocity*3);
            setRotation(90);
            break;
        case(Qt::Key_C):
            Bullet *bullet = new Bullet();
            bullet->setPos(mapToScene(70, 22.5));
            bullet->setRotation(rotation());
            scene()->addItem(bullet);
    }
//    if(keyEvent->key() == Qt::Key_Right){
//        setPos(x() + velocity*3, y());
//        setRotation(180);
//    }
//    if(keyEvent->key() == Qt::Key_Left){
//        setPos(x() - velocity*3, y());
//        setRotation(360);
//    }
//    if(keyEvent->key() == Qt::Key_Up){
//        setPos(x(), y() - velocity*3);
//        setRotation(90);
//    }
//    if(keyEvent->key() == Qt::Key_Down){
//        setPos(x(), y() + velocity*3);
//        setRotation(270);
//    }
}
