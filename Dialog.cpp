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

    close();
}

void Dialog::getInfo(int HP, int Strength, int Velocity, QString name)
{
    if(HP == 0)
        return;
    ui->comboBox_4->addItem(name + " ( HP : " + QString::number(HP) + " , Str : " + QString::number(Strength) + " , V : " + QString::number(Velocity) + " )");
    ui->comboBox_5->addItem(name + " ( HP : " + QString::number(HP) + " , Str : " + QString::number(Strength) + " , V : " + QString::number(Velocity) + " )");
}

void Dialog::getRestart()
{
    emit restart();
}
