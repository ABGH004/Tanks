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
    //why qpainter does not detect collision with pixmap
    for(int i = 0; i < collidingList.size(); ++i){
        qDebug() << "collision accuared";
        if(typeid(*(collidingList[i])) == typeid(Bricks)){
            scene()->removeItem(this);
            delete this;
            qDebug() << "collision accuared";
            return;
        }

        else if(typeid(*(collidingList[i])) == typeid(myBox)){
            dynamic_cast<myBox*>(collidingList[i])->decrementLives();
            scene()->removeItem(this);
            delete this;
            qDebug() << "collision accuared";
            return;
        }
    }
    setPos(mapToScene(35, 0));
    if(x() > 1350 || x() < 0 || y() < 0 || y() > 750){
        scene()->removeItem(this);
        delete this;
    }
}


