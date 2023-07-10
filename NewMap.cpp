#include "NewMap.h"
#include "MovableBox.h"
#include "MovableBricks.h"
#include "MovableForest.h"
#include <QFile>
NewMap::NewMap()
{
    scene = new GridScene();
    scene->setSceneRect(0, 0, 1620, 900);
    setScene(scene);

    setFixedSize(1620, 900);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    name = new QLabel(this);
    name->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    name->setFont(QFont("segoe UI", 15));
    name->setGeometry(90, 10, 100, 50);
    name->setText("Name: ");

    mapName = new QLineEdit(this);
    mapName->setGeometry(200, 20, 210, 30);

    wall = new QLabel(this);
    wall->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    wall->setFont(QFont("segoe UI", 15));
    wall->setGeometry(470, 10, 100, 50);
    wall->setText("Wall: ");

    box = new QLabel(this);
    box->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    box->setFont(QFont("segoe UI", 15));
    box->setGeometry(780, 10, 100, 50);
    box->setText("Box: ");

    forest = new QLabel(this);
    forest->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    forest->setFont(QFont("segoe UI", 15));
    forest->setGeometry(1090, 10, 100, 50);
    forest->setText("Forest: ");

    submit = new QPushButton(this);
    submit->setGeometry(1470, 20, 110, 30);
    submit->setFont(QFont("segoe UI", 15));
    submit->setText("Submit");

    connect(submit, &QPushButton::clicked, this, &NewMap::on_submit_clicked);

    MovableBricks *mb = new MovableBricks(560, 30);
    MovableBox *mbx = new MovableBox(870, 30);
    MovableForest *mf = new MovableForest(1180, 30);

    scene->addItem(mb);
    scene->addItem(mbx);
    scene->addItem(mf);

}

NewMap::~NewMap()
{
    delete name;
    delete wall;
    delete box;
    delete forest;
    delete submit;
    delete mapName;
    delete scene;

}

void NewMap::on_submit_clicked()
{
    QString fileName = mapName->text()+".txt";
    QFile file(fileName);
    QString str;

    if(file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)){
        QTextStream outStream(&file);
        for(int j = 120; j < 900; j+=60){
            for(int i = 0; i < 1620; i+=60){
                if(itemAt(i, j)){
                    if(typeid(*itemAt(i, j)) == typeid(MovableBricks)){
                        str += "1";
                    }
                    else if(typeid(*itemAt(i, j)) == typeid(MovableBox)){
                        str += "2";
                    }
                    else if(typeid(*itemAt(i, j)) == typeid(MovableForest)){
                        str += "3";
                    }
                }
                else{
                    str += "0";
                }
                str += " ";
            }
            str.chop(1);
            outStream << str + "\n";
            str = "";
        }

    }
    file.close();
    emit passMap(fileName);
    close();

}


