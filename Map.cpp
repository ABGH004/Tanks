#include "Map.h"

Map::Map(QGraphicsScene*scene, QString name)
{
    bool isNew = false;
    QFile file1(":/Maps/"+name+".txt");
    if(!file1.exists()){
        isNew = true;
    }
    QFile file2(name + ".txt");
    QString array[13][27];
    if(!isNew){
        if(file1.open(QIODevice::ReadOnly)){
            for(int j = 0; j < 13; ++j){
                QString line = file1.readLine();
                for(int i = 0; i < 54; ++++i){
                    array[j][i/2] = line[i];
                }
            }
        }
    }else{
        if(file2.open(QIODevice::ReadOnly)){
            for(int j = 0; j < 13; ++j){
                QString line = file2.readLine();
                for(int i = 0; i < 54; ++++i){
                    array[j][i/2] = line[i];
                }
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
            else if(array[i][j] == "3"){
                Forest *f = new Forest(j*60, 100 + i*60);
                scene->addItem(f);

            }
        }
    if(isNew){
        QFile::remove(name + ".txt");
    }
}


