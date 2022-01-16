#ifndef KARAKTER_H
#define KARAKTER_H
#include "oyun.h"
#include "meyve.h"
#include <QTimer>

class karakter: public QObject
{
public:
    karakter();
    int  Koordinat_x(Ui::Oyun *ui);
    int  Koordinat_y(Ui::Oyun *ui);

    int  CanGet();
    void CanAzalt(int);
    void CanSet(int);

    void Delay(int);

    bool GetYon();

    void HareketSol(Ui::Oyun *ui,QMovie *);
    void HareketSag(Ui::Oyun *ui, QMovie *);
    void HareketAsagi(Ui::Oyun *ui);

    void KesSag(Ui::Oyun *ui,Meyve &,Meyve &,Meyve &,Meyve &,Meyve &,int &puan,QMovie *,QMovie *);
    void KesSol(Ui::Oyun *ui,Meyve &,Meyve &,Meyve &,Meyve &,Meyve &,int &puan,QMovie *,QMovie *);
    void KesYukari(Ui::Oyun *ui,Meyve &,Meyve &,Meyve &,Meyve &,Meyve &,int &puan,QMovie *);

    void Dash(Ui::Oyun *ui,QMovie *,QMovie *,QMovie *,QMovie *);
    int  DashHakki();

public slots:
    void HareketYukari(Ui::Oyun *ui);

private:
    int x,y,can=10;
    int dash_hakki=5;
    bool yon=1;

};

#endif // KARAKTER_H
