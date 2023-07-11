#include "myBox.h"
#include <QGraphicsScene>
myBox::myBox(qreal x, qreal y)
{
    this->lives = 10;
    setPixmap(QPixmap(":/Images/box.jpg"));
    setPos(x, y);
    music = new QMediaPlayer();
    audio = new QAudioOutput();
    music->setSource(QUrl("qrc:/Sounds/boxCrashingSound.wav"));
    music->setAudioOutput(audio);
    audio->setVolume(0.8);

}

myBox::~myBox()
{
    delete music;
    delete audio;
}

void myBox::decrementLives(int strength){
    lives -= strength;

    music->play();
    if(lives <= 0){
        scene()->removeItem(this);
        delete this;
    }
}

