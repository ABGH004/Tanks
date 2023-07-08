#ifndef NEWTANK_H
#define NEWTANK_H

#include <QDialog>

namespace Ui {
class NewTank;
}

class NewTank : public QDialog
{
    Q_OBJECT

public:
    explicit NewTank(QWidget *parent = nullptr);
    ~NewTank();

signals:
    void passNew(int HP, int Strength, int Velocity, QString name);
private slots:
    void on_pushButton_clicked();

private:
    Ui::NewTank *ui;
};

#endif // NEWTANK_H
