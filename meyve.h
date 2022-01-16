#ifndef MEYVE_H
#define MEYVE_H
#include "oyun.h"
#include <QTime>

class Meyve
{
public:
    Meyve();
    int  GetTuru();
    void Rastgele(int,Ui::Oyun *ui,int);
    int  GetKoordinat_x(Ui::Oyun *ui,int);
    int  GetKoordinat_y(Ui::Oyun *ui,int);
    bool GetKesildi();
    void SetKesildi(bool);

private:
    int tur;
    int x;
    int y;
    bool kesildi=0;
};

#endif // MEYVE_H
