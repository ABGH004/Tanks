#include "Tank.h"

//    QPainterPath OuterPath;
//    OuterPath.setFillRule(Qt::WindingFill);
//    OuterPath.addEllipse(QPointF(60, 60), 50, 50);
//    OuterPath.addRect(60, 10, 50, 50);

//    QPainterPath InnerPath;
//    InnerPath.addEllipse(QPointF(60, 60), 20, 20);

//    QPainterPath FillPath = OuterPath.subtracted(InnerPath);

//    QPainter Painter(this);
//    Painter.setRenderHint(QPainter::Antialiasing);

//    Painter.fillPath(FillPath, Qt::blue);
//    Painter.strokePath(OuterPath.simplified(), QPen(Qt::black, 1));
//    Painter.strokePath(InnerPath, QPen(Qt::black, 3));


Tank::Tank()
{
    setFlag(ItemIsMovable);
    setFlag(ItemIsFocusable);
    setFocus();
}

QRectF Tank::boundingRect() const
{
// outer most edges
    return QRectF(0,0,100,100);
}

void Tank::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QPainterPath body;
    body.setFillRule(Qt::WindingFill);
    body.addRect(30, 20, 50, 50);

    QPainterPath canon;
    canon.addRect(20, 35, 25, 15);
    QPainterPath wheel1;
    wheel1.addRect(42.5, 15, 25, 5);
    QPainterPath wheel2;
    wheel2.addRect(42.5, 70, 25, 5);
    QPainterPath FillPath = body.subtracted(canon).subtracted(wheel1).subtracted(wheel2);

    painter->setRenderHint(QPainter::Antialiasing);

    painter->fillPath(body, Qt::red);
    painter->fillPath(canon, Qt::black);
    painter->fillPath(wheel1, Qt::black);
    painter->fillPath(wheel2, Qt::black);
    painter->strokePath(body.simplified(), QPen(Qt::black, 1));
    painter->strokePath(canon, QPen(Qt::black, 3));


}

void Tank::keyPressEvent(QKeyEvent* keyEvent){
    if(keyEvent->key() == Qt::Key_Right){
        setPos(x() + 10, y());
    }
    if(keyEvent->key() == Qt::Key_Left){
        setPos(x() - 10, y());
    }
    if(keyEvent->key() == Qt::Key_Up){
        setPos(x(), y() - 10);
    }
    if(keyEvent->key() == Qt::Key_Down){
        setPos(x(), y() + 10);
    }
}
