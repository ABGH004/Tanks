#include "Map.h"
#include "Bricks.h"
#include "myBox.h"
//#include "Forest.h"
#include <QFile>

Map::Map(QGraphicsScene*scene)
{
    QFile file1(":/Maps/map_3.txt");
    QString array[13][27];
    if(file1.open(QIODevice::ReadOnly)){
        for(int j = 0; j < 13; ++j){
            QString line = file1.readLine();
            for(int i = 0; i < 54; ++++i){
                array[j][i/2] = line[i];
            }
        }
    }
    for(int i = 0; i < 13; ++i)
        for(int j = 0; j < 27; ++j){
            if(array[i][j] == "1"){
                Bricks *b = new Bricks(j*60, 100 + i*60);
                scene->addItem(b);

            }
            else if(array[i][j] == "2"){
                myBox *bx = new myBox(j*60, 100 + i*60);
                scene->addItem(bx);

            }
        }
}
