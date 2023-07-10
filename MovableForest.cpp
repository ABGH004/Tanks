#include "MovableForest.h"

MovableForest::MovableForest(qreal x, qreal y): Forest(x, y)
{
    setFlag(ItemIsMovable);
}
