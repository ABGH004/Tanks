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
#include <QKeyEvent>
#include <QSet>
#include "Map.h"

class View : public QGraphicsView
{
    Q_OBJECT
private:
    QGraphicsScene * scene;
    QTimer *timer;
    QTimer *bulletTimer;
    QLabel *playerA;
    QLabel *playerB;
    QMediaPlayer* music1;
    QAudioOutput* audio1;
    QSet<int> keysPressed;
    QMediaPlayer* music2;
    QAudioOutput* audio2;
    Tank *tankA;
    Tank *tankB;
    Map *map;
public:
    explicit View();
    void keyPressEvent(QKeyEvent*);
    void keyReleaseEvent(QKeyEvent*);
    ~View();
public slots:
    void getMap(QString mapName);
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
