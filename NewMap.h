#ifndef NEWMAP_H
#define NEWMAP_H

//#include <QGraphicsScene>
#include "GridScene.h"
#include <QGraphicsView>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>

class NewMap : public QGraphicsView
{
    Q_OBJECT

public:
    NewMap();
    ~NewMap();
signals:
    void passMap(QString);
private slots:
    void on_submit_clicked();
    void on_dismiss_clicked();
private:
    QLabel *name;
    QLabel *wall;
    QLabel *box;
    QLabel *forest;
    QLineEdit *mapName;
    QPushButton *submit;
    QPushButton *dismiss;
    GridScene *scene;
};

#endif // NEWMAP_H
