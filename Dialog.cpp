#include "Dialog.h"
#include "ui_Dialog.h"
#include "View.h"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QPixmap bkgnd(":Images/gamemenu.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
    connect(this, &Dialog::finished, this, [this](){
        emit passText1(ui->lineEdit_2->text());
    });

    connect(this, &Dialog::finished, this, [this](){
        emit passText2(ui->lineEdit->text());
    });
    connect(this, &Dialog::finished, this, [this](){
        emit passInfo1(tank1Info(), tank1Color());
    });
    connect(this, &Dialog::finished, this, [this](){
        emit passInfo2(tank2Info(), tank2Color());
    });
    connect(this, &Dialog::finished, this, [this](){
        emit passMap(ui->comboBox_3->currentText());
    });
    ui->label_9->setStyleSheet("QLabel{color:white;}");
}

Dialog::~Dialog()
{
    delete ui;
}

int Dialog::tank1Info()
{
    QList<QString> a = ui->comboBox_4->currentText().split(" ");
    QString number;
    foreach (QString b, a) {
        if(b.toInt())
            number += b;
    }
    int num = number.toInt();
    return num;
}

int Dialog::tank2Info()
{
    QList<QString> a = ui->comboBox_5->currentText().split(" ");
    QString number;
    foreach (QString b, a) {
        if(b.toInt())
            number += b;
    }
    int num = number.toInt();
    return num;

}

QString Dialog::tank1Color()
{
    return ui->comboBox->currentText();
}

QString Dialog::tank2Color()
{
    return ui->comboBox_2->currentText();
}

void Dialog::on_pushButton_clicked()
{
    if(ui->comboBox->currentText() == ui->comboBox_2->currentText()){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","You cannot pick the same color!!");
        messageBox.setFixedSize(500,200);
        return;
    }
    auto gameView = new View();
    gameView->show();
    connect(this, &Dialog::passText1, gameView, &View::getText1);
    connect(this, &Dialog::passText2, gameView, &View::getText2);
    connect(this, &Dialog::passInfo1, gameView, &View::getInfo1);
    connect(this, &Dialog::passInfo2, gameView, &View::getInfo2);
    connect(gameView, &View::restartGame, this, &Dialog::getRestart);
    connect(this, &Dialog::passMap, gameView, &View::getMap);
    close();
}

void Dialog::getInfo(int HP, int Strength, int Velocity, QString name)
{
    if(HP < 100 || HP > 150 || Velocity > 3 || Velocity < 1 || Strength > 5 || Strength < 1)
        return;
    ui->comboBox_4->addItem(name + " ( HP : " + QString::number(HP) + " , Str : " + QString::number(Strength) + " , V : " + QString::number(Velocity) + " )");
    ui->comboBox_5->addItem(name + " ( HP : " + QString::number(HP) + " , Str : " + QString::number(Strength) + " , V : " + QString::number(Velocity) + " )");
}

void Dialog::getRestart()
{
    emit restart();
}

void Dialog::getMap(QString mapName)
{
    if(mapName.isEmpty()){
        return;
    }
    mapName.chop(4);
    ui->comboBox_3->addItem(mapName);
}


void Dialog::on_pushButton_2_clicked()
{
    close();
    emit restart();
}

