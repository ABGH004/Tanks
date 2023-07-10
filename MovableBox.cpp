#include "MovableBox.h"

MovableBox::MovableBox(qreal x, qreal y) : myBox(x, y)
{
    setFlag(ItemIsMovable);
}
