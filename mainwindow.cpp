#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Dialog.h"
#include "NewTank.h"
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
    audio->setVolume(0.4);

    music->play();
    music->setLoops(QMediaPlayer::Infinite);

}

MainWindow::~MainWindow()
{
    delete music;
    delete audio;
    delete ui;
}

void MainWindow::restartGame()
{
    show();
}

void MainWindow::on_pushButton_clicked()
{
    auto optionView = new Dialog();

    connect(this, &MainWindow::passInfo, optionView, &Dialog::getInfo);
    connect(optionView, &Dialog::restart, this, &MainWindow::restartGame);
    emit passInfo(HP, Strength, Velocity, name);
    optionView->show();
    hide();
}

void MainWindow::getInf(int HP, int Strength, int Velocity, QString name)
{
    this->HP = HP;
    this->Strength = Strength;
    this->Velocity = Velocity;
    this->name = name;
}


void MainWindow::on_pushButton_3_clicked()
{
    close();
}


void MainWindow::on_pushButton_2_clicked()
{
    auto newTank = new NewTank();
    connect(newTank, &NewTank::passNew, this, &MainWindow::getInf);
    newTank->show();
}

