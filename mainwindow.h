#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QMediaPlayer>
#include <QAudioOutput>
#include "Dialog.h"
#include "NewTank.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void passInfo(int HP, int Strength, int Velocity, QString name);
public slots:
    void restartGame();
    void getInf(int HP, int Strength, int Velocity, QString name);
private slots:

    void on_pushButton_clicked();
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    int HP;
    int Strength;
    int Velocity;
    QString name;
    Ui::MainWindow *ui;
    QMediaPlayer *music;
    QAudioOutput *audio;

};

#endif // MAINWINDOW_H
