#include "meyve.h"
#include "ui_oyun.h"
#include <QDebug>
#include <cstdlib>

Meyve::Meyve()
{

}

int Meyve::GetTuru(){
    return tur;
}

int Meyve::GetKoordinat_x(Ui::Oyun *ui,int sayi){
    if (sayi==1)
        x=ui->meyve_1->x();
    else if (sayi==2)
        x=ui->meyve_2->x();
    else if (sayi==3)
        x=ui->meyve_3->x();
    else if (sayi==4)
        x=ui->meyve_4->x();
    else if (sayi==5)
        x=ui->meyve_5->x();
    return x;
}

int Meyve::GetKoordinat_y(Ui::Oyun *ui,int sayi){
    if (sayi==1)
        y=ui->meyve_1->y();
    else if (sayi==2)
        y=ui->meyve_2->y();
    else if (sayi==3)
        y=ui->meyve_3->y();
    else if (sayi==4)
        y=ui->meyve_4->y();
    else if (sayi==5)
        y=ui->meyve_5->y();
    return y;
}

void Meyve::Rastgele(int seed,Ui::Oyun *ui,int sayi){
    std::srand(seed);
    tur=std::rand() % ((4 + 1) - 0) + 0;
    x=std::rand() % ((1750 + 1) - 50) + 50;

    if (sayi==1){
        ui->meyve_1->move(x,-70);
        ui->meyve_1->setStyleSheet("image: url(:/new/images/"+QString::number(GetTuru())+".png)");

    }
    else if (sayi==2){
        ui->meyve_2->move(x,-100);
        ui->meyve_2->setStyleSheet("image: url(:/new/images/"+QString::number(GetTuru())+".png)");

    }
    else if (sayi==3){
        ui->meyve_3->move(x,-130);
        ui->meyve_3->setStyleSheet("image: url(:/new/images/"+QString::number(GetTuru())+".png)");

    }
    else if (sayi==4){
        ui->meyve_4->move(x,-160);
        ui->meyve_4->setStyleSheet("image: url(:/new/images/"+QString::number(GetTuru())+".png)");

    }
    else if (sayi==5){
        ui->meyve_5->move(x,-190);
        ui->meyve_5->setStyleSheet("image: url(:/new/images/"+QString::number(GetTuru())+".png)");

    }
}

bool Meyve::GetKesildi(){
    return kesildi;
}

void Meyve::SetKesildi(bool deger){
    kesildi=deger;
}
