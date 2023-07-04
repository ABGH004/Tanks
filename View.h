#ifndef VIEW_H
#define VIEW_H
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QMediaPlayer>
#include <QAudioOutput>

class View : public QGraphicsView
{
    Q_OBJECT
private:
    QGraphicsScene * scene;
    QTimer* viewTimer;
public:

    explicit View();
signals:

};
#endif // VIEW_H
