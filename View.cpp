#include "View.h"
#include "Map.h"
View::View()
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 1620, 880);
    setScene(scene);
    setFixedSize(1620, 880);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    music1 = new QMediaPlayer();
    audio1 = new QAudioOutput();
    music1->setSource(QUrl("qrc:/Sounds/startsound.wav"));
    audio1->setVolume(0.7);
    music1->setAudioOutput(audio1);
    music1->play();

    tankA = new Tank(200, 400);
    tankB = new Tank(1200, 100);
    connect(tankA, SIGNAL(gameOver()), this, SLOT(playerBWon()));
    connect(tankB, SIGNAL(gameOver()), this, SLOT(playerAWon()));

    playerA = new QLabel(this);
    playerA->setFont(QFont("arial", 20));
    playerA->setAlignment(Qt::AlignHCenter | Qt::AlignLeft);
    playerA->setGeometry(0, 20, 200, 100);
    playerA->setFixedWidth(200);

    playerB = new QLabel(this);
    playerB->setFont(QFont("arial", 20));
    playerB->setAlignment(Qt::AlignHCenter | Qt::AlignLeft);
    playerB->setGeometry(1420, 20, 200, 100);
    playerB->setFixedWidth(200);

    scene->addItem(tankA);
    scene->addItem(tankB);





    Map *m = new Map(scene);


}

View::~View()
{
    delete scene;
    delete playerA;
    delete playerB;
    delete tankA;
    delete tankB;
    delete music1;
    delete music2;
    delete audio1;
    delete audio2;

}

void View::playerBWon()
{
    music2 = new QMediaPlayer();
    audio2 = new QAudioOutput();
    music2->setSource(QUrl("qrc:/Sounds/winnerMusic.wav"));
    audio2->setVolume(1.0);
    music2->setAudioOutput(audio2);

    music2->play();
    QMessageBox messageBox;
    messageBox.setMinimumSize(1600, 1300);
    messageBox.critical(0, "GAMEOVER", playerB->text() + " Won!!!");
    messageBox.setFixedSize(1600,1300);
    close();
    emit restartGame();

}

void View::playerAWon()
{
    music2 = new QMediaPlayer();
    audio2 = new QAudioOutput();
    music2->setSource(QUrl("qrc:/Sounds/winnerMusic.wav"));
    audio2->setVolume(1.0);
    music2->setAudioOutput(audio2);
    music2->play();
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
