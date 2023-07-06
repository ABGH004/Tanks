#include "Bullet.h"
#include <QGraphicsScene>
#include "Bricks.h"
#include "myBox.h"
#include "Forest.h"
#include "Tank.h"
#include <QDebug>
Bullet::Bullet()
{
    QMediaPlayer *music = new QMediaPlayer();
    QAudioOutput *audio = new QAudioOutput();
    music->setSource(QUrl("qrc:/Sounds/shootingSound.wav"));
    music->setAudioOutput(audio);
    audio->setVolume(40);

    music->play();
    QTimer *timer = new QTimer();
    timer->start(100);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
}
QPainterPath Bullet::shape() const{
    QPainterPath path;
    path.moveTo(2.5, 0);
    path.lineTo(15, 0);
    path.lineTo(17.5, 2.5);
    path.lineTo(15, 5);
    path.lineTo(2.5, 5);
    path.addEllipse(0, 0, 5, 5);
    return path;
}
QRectF Bullet::boundingRect() const
{
    // outer most edges
    return QRectF(0,0,15,5);
}
void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPainterPath body;

    body.setFillRule(Qt::WindingFill);
    body.moveTo(2.5, 0);
    body.lineTo(15, 0);
    body.lineTo(17.5, 2.5);
    body.lineTo(15, 5);
    body.lineTo(2.5, 5);

    QPainterPath bottom;
    bottom.addEllipse(0, 0, 5, 5);

    painter->setRenderHint(QPainter::Antialiasing);
    painter->fillPath(body, Qt::blue);
    painter->fillPath(bottom, Qt::blue);


}

void Bullet::move(){

    QList<QGraphicsItem*> collidingList = collidingItems();

    for(int i = 0; i < collidingList.size(); ++i){
        if(typeid(*(collidingList[i])) == typeid(Bricks)){
            scene()->removeItem(this);
            delete this;
            return;
        }

        else if(typeid(*(collidingList[i])) == typeid(myBox)){
            dynamic_cast<myBox*>(collidingList[i])->decrementLives();
            scene()->removeItem(this);
            delete this;
            return;
        }
        else{
            qDebug() << "collision occured";

        }
    }
    setPos(mapToScene(35, 0));
    if(x() > 1350 || x() < 0 || y() < 0 || y() > 750){
        scene()->removeItem(this);
        delete this;
    }
}


