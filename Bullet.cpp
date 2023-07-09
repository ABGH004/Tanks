#include "Bullet.h"
#include "Bricks.h"
#include "myBox.h"
#include "Tank.h"
Bullet::Bullet(int strength)
{
    this->strength = strength;

    music = new QMediaPlayer();
    audio = new QAudioOutput();
    music->setSource(QUrl("qrc:/Sounds/shootingSound.wav"));
    music->setAudioOutput(audio);
    audio->setVolume(0.2);
    music->play();

    timer = new QTimer();
    timer->start(100);

    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
}

Bullet::~Bullet()
{
    delete music;
    delete audio;
    delete timer;
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
            dynamic_cast<myBox*>(collidingList[i])->decrementLives(strength);
            scene()->removeItem(this);
            delete this;
            return;

        }else if(typeid(*(collidingList[i])) == typeid(Tank)){
            dynamic_cast<Tank*>(collidingList[i])->getHit(strength);
            scene()->removeItem(this);
            delete this;
            return;
        }

    }

    setPos(mapToScene(50, 0));

    if(x() > 1620 || x() < 0 || y() < 0 || y() > 880){
        scene()->removeItem(this);
        delete this;
    }
}


