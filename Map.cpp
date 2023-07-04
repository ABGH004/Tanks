#include "Map.h"
#include "Bricks.h"
//#include "Box.h"
//#include "Forest.h"
#include <iostream>
#include <fstream>
#include <string>
#include <QGraphicsScene>

Map::Map(char* mapName)
{
    this->mapName = mapName;
    std::ifstream file;
    file.open(mapName);
    std::string array[13][27];
    std::string x;
    if(file){
        for(int j = 0; j < 13; ++j){
            std::getline(file, x);
            for(int i = 0; i < 54; ++++i){
                array[j][i/2] = x[i];
            }
        }
    }
    for(int i = 0; i < 13; ++i)
        for(int j = 0; j < 27; ++j){
            if(array[i][j] == "1"){
                Bricks *bricks = new Bricks(i*50, 100 + j*50);
                scene()->addItem(bricks);
            }
        }

}
