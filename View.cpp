#include "View.h"
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
    audio->setVolume(0.7);
    music->setAudioOutput(audio);
    music->play();

    tankA = new Tank(100, 100);
    tankB = new Tank(1200, 100);
    connect(tankA, SIGNAL(gameOver()), this, SLOT(playerBWon()));
    connect(tankB, SIGNAL(gameOver()), this, SLOT(playerAWon()));

    Bricks *b = new Bricks(1000, 500);
    myBox *bx = new myBox(500, 500);
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

    scene->addItem(tankA);
    scene->addItem(tankB);
    scene->addItem(b);
    scene->addItem(bx);
    scene->addItem(f);
}

void View::playerBWon()
{
    QMediaPlayer *music = new QMediaPlayer();
    QAudioOutput *audio = new QAudioOutput();
    music->setSource(QUrl("qrc:/Sounds/winnerMusic.wav"));
    audio->setVolume(1.0);
    music->setAudioOutput(audio);

    music->play();
    QMessageBox messageBox;
    messageBox.setMinimumSize(1600, 1300);
    messageBox.critical(0, "GAMEOVER", playerB->text() + " Won!!!");
    messageBox.setFixedSize(1600,1300);
    close();
    emit restartGame();

}

void View::playerAWon()
{
    QMediaPlayer *music = new QMediaPlayer();
    QAudioOutput *audio = new QAudioOutput();
    music->setSource(QUrl("qrc:/Sounds/winnerMusic.wav"));
    audio->setVolume(1.0);
    music->setAudioOutput(audio);
    music->play();
    QMessageBox messageBox;
    messageBox.critical(0, "GAMEOVER", playerA->text() + " Won!!!");
    messageBox.setFixedSize(600,300);
    close();
    emit restartGame();
}

void View::getText1(QString playerName)
{
    playerA->setText(playerName);
}
void View::getText2(QString playerName)
{
    playerB->setText(playerName);
}

void View::getInfo1(int info, QString color)
{

    int V = info%10;
    int Str = (info%100)/10;
    int HP = (info - Str*10 - V)/100;

    tankA->setInfo(HP, V, Str, color);
}

void View::getInfo2(int info, QString color)
{
    int V = info%10;
    int Str = (info%100)/10;
    int HP = (info - Str*10 - V)/100;

    tankB->setInfo(HP, V, Str, color);

}
