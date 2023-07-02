#ifndef VIEW_H
#define VIEW_H
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>

#include "mainwindow.h"

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
