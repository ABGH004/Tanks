#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Dialog.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd(":Images/menu.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
    music = new QMediaPlayer();
    audio = new QAudioOutput();
    music->setSource(QUrl("qrc:/Sounds/backgroundMusic.mp3"));
    music->setAudioOutput(audio);
    audio->setVolume(20);

    music->play();
    music->setLoops(QMediaPlayer::Infinite);


}

MainWindow::~MainWindow()
{
    delete music;
    delete audio;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    auto optionView = new Dialog();

    optionView->show();

    close();
}


void MainWindow::on_pushButton_3_clicked()
{
    close();
}

