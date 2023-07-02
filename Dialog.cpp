#include "Dialog.h"
#include "ui_Dialog.h"
#include "View.h"
Dialog::Dialog(QWidget *parent, QMediaPlayer* music) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    this->music = music;
    ui->setupUi(this);
    QPixmap bkgnd(":Images/gamemenu.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
    music = new QMediaPlayer();
    audio = new QAudioOutput();
    music->setSource(QUrl("qrc:/Sounds/backgroundMusic.mp3"));
    music->setAudioOutput(audio);
    connect(music, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    audio->setVolume(40);

    music->play();
    music->setLoops(QMediaPlayer::Infinite);
}

Dialog::~Dialog()
{
    delete ui;
    delete music;
    delete audio;
}

void Dialog::on_pushButton_clicked()
{

    auto gameView = new View();
    music->stop();
    gameView->show();
    close();
}

