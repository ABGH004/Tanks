#ifndef GRIDSCENE_H
#define GRIDSCENE_H
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QPainter>
#include <QVarLengthArray>
class GridScene : public QGraphicsScene
{
public:
    GridScene();
    void drawBackground(QPainter* painter, QRectF const &rect);
    void mousePressEvent(QGraphicsSceneMouseEvent*mouseEvent);
    void mouseMoveEvent(QGraphicsSceneMouseEvent* mouseEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* mouseEvent);
private:
    const QSize mCellSize;
    QGraphicsItem* mDragged;
    QPointF mDragOffset;
};

#endif // GRIDSCENE_H
