#include "MovableBricks.h"

MovableBricks::MovableBricks(qreal x, qreal y) : Bricks(x, y)
{
    setFlag(ItemIsMovable);
}
