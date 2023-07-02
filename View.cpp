#include "View.h"
#include "Tank.h"
View::View()
{

    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 1350, 750);
    setScene(scene);
    setFixedSize(1320, 720);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    Tank *t1 = new Tank();

    scene->addItem(t1);
}
