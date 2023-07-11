#ifndef MYBOX_H
#define MYBOX_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include <QAudioOutput>
class myBox : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int lives;
    QMediaPlayer *music;
    QAudioOutput *audio;
public:
    myBox(qreal, qreal);
    ~myBox();
    void decrementLives(int strength);
};

#endif // MYBOX_H
