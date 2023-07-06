#include "Tank.h"
#include "Bullet.h"
#include <QGraphicsScene>
Tank::Tank(qreal xPos, qreal yPos, int velocity)
{
    this->velocity = velocity;

    setFlags(ItemIsFocusable | ItemSendsScenePositionChanges);
    setFocus();
    QTimer * timer = new QTimer();
    setPos(xPos, yPos);
    setTransformOriginPoint(boundingRect().center() + QPoint(-20, -20));
    timer->start(10);
    connect(timer, SIGNAL(timeout()), this, SLOT(collision()));
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
    QList<QGraphicsItem*> collidingList = collidingItems();
    for(QGraphicsItem* t : collidingList){
        if(typeid(*t) == typeid(Bullet))
            continue;
        else
            setRotation(90);
    }
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
            bullet->setPos(mapToScene(85, 22.5));
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

QPainterPath Tank::shape() const
{
    QPainterPath path;
    path.setFillRule(Qt::WindingFill);
    path.addRect(15, 4, 48, 40);
    path.addRect(48, 19, 25, 10);
    path.addRect(25, 0, 30, 4);
    path.addRect(25, 44, 30, 4);
    return path;
}

void Tank::collision()
{
    QList<QGraphicsItem*> collidingList = collidingItems();

    for(QGraphicsItem* t : collidingList){

        if(typeid(*t) == typeid(Bullet))
            continue;//////TO DO
        else{
            if(x()+50 <= t->x()){
                setPos(x() - 20, y());
            }else if(x() >= t->x()){
                setPos(x() + 20, y());
            }else if(y() >= t->y()){
                setY(y() + 20);
            }else if(y() + 50 <= t->y()){
                setY(y() - 20);
            }
        }
//            setRotation(90);
    }

}
QVariant Tank::itemChange(GraphicsItemChange change, const QVariant &value)
{

    if (change == ItemPositionChange && scene()) {
        // value is the new position.
        QPointF newPos = value.toPointF();
        QRectF rect = scene()->sceneRect();
        if(x() < 20){
            newPos.setX(20);
            newPos.setY(newPos.y());
        }
        else if(x() + boundingRect().right() > scene()->width()+ 20){
            newPos.setX(scene()->width()+ 20 - boundingRect().width());
            newPos.setY(newPos.y());
        }
        else if(y() < 100){
            newPos.setX(newPos.x());
            newPos.setY(100);
        }
        else if(y()+ boundingRect().bottom() > scene()->height() + 20){
            newPos.setX(newPos.x());
            newPos.setY(scene()->height()+ 20 - boundingRect().height());
        }
        return newPos;
        //        if (!rect.contains(newPos)) {
//            // Keep the item inside the scene rect.
//            newPos.setX(qMin(rect.right(), qMax(newPos.x(), rect.left())));
//            newPos.setY(qMin(rect.bottom(), qMax(newPos.y(), rect.top())));
//            return newPos;
//        }
    }
    return QGraphicsItem::itemChange(change, value);
}

