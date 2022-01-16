#ifndef OYUN_H
#define OYUN_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QTime>
#include <QTimer>
#include <QMovie>
#include <windows.h>
#include <iostream>
#include <QThread>


//#include "meyve.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Oyun; }
QT_END_NAMESPACE

class Oyun : public QMainWindow
{
    Q_OBJECT

public:
    Oyun(QWidget *parent = nullptr);
    ~Oyun();

    void Delay(int);
    void keyPressEvent(QKeyEvent *event);
    void Basla();

private slots:

    void on_koordinat_clicked();

private:
    Ui::Oyun *ui;

    int x_1,x_2,x_3,x_4,x_5;
    int y_1,y_2,y_3,y_4,y_5;
    QTime time;
    int seed;
    int hiz;
    int puan=0;



    QMovie *hayalet_sol = new QMovie(":/new/images/hayalet_sol.gif");
    QMovie *hayalet_sag = new QMovie(":/new/images/hayalet_sag.gif");
    QMovie *hayalet_sol_hasar = new QMovie(":/new/images/hayalet_sol_hasar.gif");
    QMovie *hayalet_sag_hasar = new QMovie(":/new/images/hayalet_sag_hasar.gif");
    QMovie *slash_sag = new QMovie(":/new/images/st_sag.gif");
    QMovie *slash_sol = new QMovie(":/new/images/st_sol.gif");
    QMovie *slash_yukari = new QMovie(":/new/images/st_yukari.gif");
    QMovie *dash_sag = new QMovie(":/new/images/dash_sag.gif");
    QMovie *dash_sol = new QMovie(":/new/images/dash_sol.gif");
    QMovie *dash_hakki= new QMovie(":/new/images/dash_hakki.gif");
    QMovie *kaybettin= new QMovie(":/new/images/kaybettin.gif");
    QMovie *hasar = new QMovie(":/new/images/hasar.gif");

};
#endif // OYUN_H
