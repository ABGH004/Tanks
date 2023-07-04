#include "Bullet.h"
#include <QGraphicsScene>
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
    return QRectF(0,0,100,100);
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPainterPath body;

    body.moveTo(5, 0);
    body.lineTo(30, 0);
    body.lineTo(35, 5);
    body.lineTo(30, 10);
    body.lineTo(5, 10);

    QPainterPath bottom;
    bottom.addEllipse(0, 0, 10, 10);

    painter->setRenderHint(QPainter::Antialiasing);
    painter->fillPath(body, Qt::blue);
    painter->fillPath(bottom, Qt::blue);


}

void Bullet::move(){
    setPos(mapToScene(40, 0));
    if(x() > 1350 || x() < 0 || y() < 0 || y() > 750){
        scene()->removeItem(this);
        delete this;
    }
}


