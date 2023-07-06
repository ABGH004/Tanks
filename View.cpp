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
    playerB = new QLabel(this);
//    connect(Dialog, SIGNAL(textEdited(QString)), this, SLOT(playerA->setText("Test A")));
    playerB->setText("Test B");
    playerA->setFont(QFont("arial", 20));
    playerA->setAlignment(Qt::AlignHCenter | Qt::AlignLeft);
    playerB->setFont(QFont("arial", 20));
    playerB->setAlignment(Qt::AlignHCenter | Qt::AlignLeft);

    playerA->setGeometry(0, 0, 200, 100);
    playerB->setGeometry(1150, 0, 200, 100);
    playerA->setFixedWidth(200);
    playerB->setFixedWidth(200);
    scene->addItem(t1);
    scene->addItem(b);
    scene->addItem(bx);
    scene->addItem(f);
}
