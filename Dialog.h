#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMediaPlayer>
#include <QAudioOutput>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr, QMediaPlayer* music = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

private:
    QMediaPlayer* music;
    QAudioOutput * audio;
    Ui::Dialog *ui;
};

#endif // DIALOG_H
