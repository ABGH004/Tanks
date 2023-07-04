#include "View.h"
#include "Tank.h"
#include "Bullet.h"
View::View()
{

    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 1350, 750);
    setScene(scene);
    setFixedSize(1350, 750);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    Tank *t1 = new Tank(100, 100, 3);

    scene->addItem(t1);
//    Bullet *b1 = new Bullet();
//    scene->addItem(b1);
}
