#include "View.h"
#include "Tank.h"
#include "Bricks.h"
#include "myBox.h"
#include "Forest.h"
//#include "Map.h"
View::View()
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 1350, 750);
    setScene(scene);
    setFixedSize(1350, 750);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QMediaPlayer *music = new QMediaPlayer();
    QAudioOutput *audio = new QAudioOutput();
    music->setSource(QUrl("qrc:/Sounds/startsound.wav"));
    music->setAudioOutput(audio);
    music->play();

    Tank *t1 = new Tank(100, 100, 3);
    Bricks *b = new Bricks(1000, 500);
    myBox *bx = new myBox(500, 500, 5);
    Forest *f = new Forest(1000, 100);
    playerA = new QLabel(this);
    playerA->setFont(QFont("arial", 20));
    playerA->setAlignment(Qt::AlignHCenter | Qt::AlignLeft);
    playerA->setGeometry(0, 0, 200, 100);
    playerA->setFixedWidth(200);

    playerB = new QLabel(this);
    playerB->setFont(QFont("arial", 20));
    playerB->setAlignment(Qt::AlignHCenter | Qt::AlignLeft);
    playerB->setGeometry(1150, 0, 200, 100);
    playerB->setFixedWidth(200);

    scene->addItem(t1);
    scene->addItem(b);
    scene->addItem(bx);
    scene->addItem(f);
}

void View::getText1(QString playerName)
{
    qDebug() << playerName;
    playerA->setText(playerName);
}
void View::getText2(QString playerName)
{
    qDebug() << playerName;
    playerB->setText(playerName);
}

void View::getInfo1(int info, QString color)
{
    qDebug() << info << color;
}
