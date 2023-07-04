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
    Forest *f = new Forest(1000, 50);

    scene->addItem(t1);
    scene->addItem(b);
    scene->addItem(bx);
    scene->addItem(f);
}
