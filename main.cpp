#include <QApplication>
#include "mainwindow.h"
#include "View.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    View *v = new View();
//    v->show();
    return a.exec();
}
