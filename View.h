#ifndef VIEW_H
#define VIEW_H
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QLabel>
#include <QMessageBox>
#include "Tank.h"
#include "Bricks.h"
#include "myBox.h"
#include "Forest.h"
class View : public QGraphicsView
{
    Q_OBJECT
private:
    QGraphicsScene * scene;
    QTimer* viewTimer;
    QLabel *playerA;
    QLabel *playerB;
    Tank *tankA;
    Tank *tankB;
public:

    explicit View();
public slots:
    void playerAWon();
    void playerBWon();
    void getText1(QString playerName);
    void getText2(QString playerName);
    void getInfo1(int info, QString color);
    void getInfo2(int info, QString color);
signals:
    void restartGame();
};
#endif // VIEW_H
