#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QMessageBox>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    int tank1Info();
    int tank2Info();
    QString tank1Color();
    QString tank2Color();
signals:
    void passText1(QString playerName);
    void passText2(QString playerName);
    void passInfo1(int info, QString color);
    void passInfo2(int info, QString color);
    void restart();
public slots:
    void getInfo(int HP, int Strength, int Velocity, QString name);
    void getRestart();
private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
