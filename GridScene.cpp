#include "GridScene.h"

#include "MovableBox.h"
#include "MovableBricks.h"
#include "MovableForest.h"
GridScene::GridScene() :mCellSize(60, 60){}

void GridScene::drawBackground(QPainter *painter,QRectF const &rect)
{
    qreal left = int(rect.left()) - (int(rect.left()) % mCellSize.width());
    qreal top = 120;

    QVarLengthArray<QLineF, 100> lines;

    for (qreal x = left; x < rect.right(); x += mCellSize.width())
        lines.append(QLineF(x, rect.top(), x, rect.bottom()));
    for (qreal y = top; y < rect.bottom(); y += mCellSize.height())
        lines.append(QLineF(rect.left(), y, rect.right(), y));
    painter->setPen(QPen(Qt::white));

    painter->drawLines(lines.data(), lines.size());
}

void GridScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    mDragged = qgraphicsitem_cast<QGraphicsItem*>(itemAt(mouseEvent->scenePos(), QTransform()));
    if (mDragged) {
        if(typeid(*mDragged) == typeid(MovableBricks)){

            addItem(new MovableBricks(560, 30));
        }
        else if(typeid(*mDragged) == typeid(MovableBox)){

            addItem(new MovableBox(870, 30));
        }
        else if(typeid(*mDragged) == typeid(MovableForest)){

            addItem(new MovableForest(1180, 30));
        }
        mDragOffset = mouseEvent->scenePos() - mDragged->pos();
    } else
        QGraphicsScene::mousePressEvent(mouseEvent);
}

void GridScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (mDragged) {
        // Ensure that the item's offset from the mouse cursor stays the same.
        mDragged->setPos(mouseEvent->scenePos() - mDragOffset);
    } else
        QGraphicsScene::mouseMoveEvent(mouseEvent);

}

void GridScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (mDragged) {
        if(mDragged->y() < 100 || mDragged->y() > 900 || mDragged->x() > 1620 || mDragged->x() < 0){

            removeItem(mDragged);
            delete mDragged;
        }
        int x = floor(mouseEvent->scenePos().x() / mCellSize.width()) * mCellSize.width();
        int y = floor(mouseEvent->scenePos().y() / mCellSize.height()) * mCellSize.height();
        mDragged->setPos(x, y);
        mDragged = 0;
    } else
        QGraphicsScene::mouseReleaseEvent(mouseEvent);

}
