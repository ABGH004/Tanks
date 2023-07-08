#ifndef VIEW_H
#define VIEW_H
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QLabel>
#include "MyLabel.h"
class View : public QGraphicsView
{
    Q_OBJECT
private:
    QGraphicsScene * scene;
    QTimer* viewTimer;
    QLabel *playerA;
    QLabel *playerB;
public:

    explicit View();
public slots:
    void getText1(QString playerName);
    void getText2(QString playerName);
    void getInfo1(int info, QString color);
signals:

};
#endif // VIEW_H
