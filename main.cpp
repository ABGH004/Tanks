#include <QApplication>
#include "View.h"
#include "mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    View* myView = new View();
    myView->show();



    return a.exec();
}
