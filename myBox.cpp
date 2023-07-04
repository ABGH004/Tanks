#include "myBox.h"
#include <QGraphicsScene>
myBox::myBox(qreal x, qreal y, int lives)
{
    this->lives = lives;
    setPixmap(QPixmap(":/Images/box.jpg"));
    setPos(x, y);
}

void myBox::decrementLives(){
    --lives;
    if(lives == 0){
        scene()->removeItem(this);
        delete this;
    }
}

