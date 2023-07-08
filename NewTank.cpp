#include "NewTank.h"
#include "ui_NewTank.h"

NewTank::NewTank(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewTank)
{
    ui->setupUi(this);
    ui->spinBox->setRange(100, 150);
    ui->spinBox_2->setRange(1, 5);
    ui->spinBox_3->setRange(1, 3);
    connect(this, &NewTank::finished, this, [this](){
        emit passNew(ui->spinBox->value(), ui->spinBox_2->value(), ui->spinBox_3->value(), ui->lineEdit->text());
    });
}

NewTank::~NewTank()
{
    delete ui;
}

void NewTank::on_pushButton_clicked()
{
    close();
}

