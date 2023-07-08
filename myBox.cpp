#include "myBox.h"
#include <QGraphicsScene>
myBox::myBox(qreal x, qreal y)
{
    this->lives = 10;
    setPixmap(QPixmap(":/Images/box.jpg"));
    setPos(x, y);
}

void myBox::decrementLives(int strength){

    lives -= strength;
    if(lives <= 0){
        scene()->removeItem(this);
        delete this;
    }
}

