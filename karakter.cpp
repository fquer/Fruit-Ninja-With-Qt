#include "karakter.h"
#include "ui_oyun.h"
#include <QDebug>

karakter::karakter()
{

}

int karakter::Koordinat_x(Ui::Oyun *ui){
    x = ui->hayalet->x();
    return x;
}

int karakter::Koordinat_y(Ui::Oyun *ui){
    y = ui->hayalet->y();
    return y;
}

int karakter::CanGet(){
    return can;
}

void karakter::CanAzalt(int azalt){
    can=can-azalt;
}

void karakter::CanSet(int set)
{
    can=set;
}

void karakter::Delay(int msec)
{
    QTime dieTime= QTime::currentTime().addMSecs(msec);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

bool karakter::GetYon()
{
    return yon;
}

void karakter::HareketYukari(Ui::Oyun *ui){
    ui->hayalet->move(Koordinat_x(ui),Koordinat_y(ui)-30);
}

void karakter::HareketSol(Ui::Oyun *ui,QMovie *hayalet_sol){
    yon=0;
    ui->hayalet->setMovie(hayalet_sol);
    hayalet_sol->start();
    ui->hayalet->move(Koordinat_x(ui)-30,Koordinat_y(ui));
}

void karakter::HareketSag(Ui::Oyun *ui,QMovie *hayalet_sag){
    yon=1;
    ui->hayalet->setMovie(hayalet_sag);
    hayalet_sag->start();
    ui->hayalet->move(Koordinat_x(ui)+30,Koordinat_y(ui));
}

void karakter::HareketAsagi(Ui::Oyun *ui){
    ui->hayalet->move(Koordinat_x(ui),Koordinat_y(ui)+30);
}

void karakter::KesSag(Ui::Oyun *ui,Meyve & meyve_1,Meyve & meyve_2,Meyve & meyve_3,Meyve & meyve_4,Meyve & meyve_5,int &puan,QMovie *hayalet_sag,QMovie *slash_sag){
    yon=1;
    ui->hayalet->setMovie(hayalet_sag);
    hayalet_sag->start();

    ui->slash->setMovie(slash_sag);
    slash_sag->start();

    ui->slash->move(Koordinat_x(ui)+90,Koordinat_y(ui)-20);

    if (Koordinat_x(ui)-ui->meyve_1->x()<5 && Koordinat_x(ui)-ui->meyve_1->x()>-220 &&
            Koordinat_y(ui)-ui->meyve_1->y()<40 && Koordinat_y(ui)-ui->meyve_1->y()>-85 && meyve_1.GetKesildi()==0){
        meyve_1.SetKesildi(1);
        ui->meyve_1->setStyleSheet("image: url(:/new/images/trs.png)");
        QMovie *meyve_1_kesildi = new QMovie(":/new/images/"+QString::number(meyve_1.GetTuru())+"_k.gif");
        ui->meyve_1->setMovie(meyve_1_kesildi);
        meyve_1_kesildi->start();
        puan+=10;
        if(dash_hakki<5){
            dash_hakki++;
        }
    }
    if (Koordinat_x(ui)-ui->meyve_2->x()<5 && Koordinat_x(ui)-ui->meyve_2->x()>-220 &&
            Koordinat_y(ui)-ui->meyve_2->y()<40 && Koordinat_y(ui)-ui->meyve_2->y()>-85 && meyve_2.GetKesildi()==0){
        meyve_2.SetKesildi(1);
        ui->meyve_2->setStyleSheet("image: url(:/new/images/trs.png)");
        QMovie *meyve_2_kesildi = new QMovie(":/new/images/"+QString::number(meyve_2.GetTuru())+"_k.gif");
        ui->meyve_2->setMovie(meyve_2_kesildi);
        meyve_2_kesildi->start();
        puan+=10;
        if(dash_hakki<5){
            dash_hakki++;
        }
    }
    if (Koordinat_x(ui)-ui->meyve_3->x()<5 && Koordinat_x(ui)-ui->meyve_3->x()>-220 &&
            Koordinat_y(ui)-ui->meyve_3->y()<40 && Koordinat_y(ui)-ui->meyve_3->y()>-85 && meyve_3.GetKesildi()==0){
        meyve_3.SetKesildi(1);
        ui->meyve_3->setStyleSheet("image: url(:/new/images/trs.png)");
        QMovie *meyve_3_kesildi = new QMovie(":/new/images/"+QString::number(meyve_3.GetTuru())+"_k.gif");
        ui->meyve_3->setMovie(meyve_3_kesildi);
        meyve_3_kesildi->start();
        puan+=10;
        if(dash_hakki<5){
            dash_hakki++;
        }
    }
    if (Koordinat_x(ui)-ui->meyve_4->x()<5 && Koordinat_x(ui)-ui->meyve_4->x()>-220 &&
            Koordinat_y(ui)-ui->meyve_4->y()<40 && Koordinat_y(ui)-ui->meyve_4->y()>-85 && meyve_4.GetKesildi()==0){
        meyve_4.SetKesildi(1);
        ui->meyve_4->setStyleSheet("image: url(:/new/images/trs.png)");
        QMovie *meyve_4_kesildi = new QMovie(":/new/images/"+QString::number(meyve_4.GetTuru())+"_k.gif");
        ui->meyve_4->setMovie(meyve_4_kesildi);
        meyve_4_kesildi->start();
        puan+=10;
        if(dash_hakki<5){
            dash_hakki++;
        }
    }
    if (Koordinat_x(ui)-ui->meyve_5->x()<5 && Koordinat_x(ui)-ui->meyve_5->x()>-220 &&
            Koordinat_y(ui)-ui->meyve_5->y()<40 && Koordinat_y(ui)-ui->meyve_5->y()>-85 && meyve_5.GetKesildi()==0){
        meyve_5.SetKesildi(1);
        ui->meyve_5->setStyleSheet("image: url(:/new/images/trs.png)");
        QMovie *meyve_5_kesildi = new QMovie(":/new/images/"+QString::number(meyve_5.GetTuru())+"_k.gif");
        ui->meyve_5->setMovie(meyve_5_kesildi);
        meyve_5_kesildi->start();
        puan+=10;
        if(dash_hakki<5){
            dash_hakki++;
        }
    }
}

void karakter::KesSol(Ui::Oyun *ui,Meyve & meyve_1,Meyve & meyve_2,Meyve & meyve_3,Meyve & meyve_4,Meyve & meyve_5,int &puan,QMovie *hayalet_sol,QMovie *slash_sol){
    yon=0;
    ui->hayalet->setMovie(hayalet_sol);
    hayalet_sol->start();

    ui->slash->setMovie(slash_sol);
    slash_sol->start();

    ui->slash->move(Koordinat_x(ui)-175,Koordinat_y(ui)-20);

    if (Koordinat_x(ui)-ui->meyve_1->x()<200 && Koordinat_x(ui)-ui->meyve_1->x()>-40 &&
            Koordinat_y(ui)-ui->meyve_1->y()<40 && Koordinat_y(ui)-ui->meyve_1->y()>-85 && meyve_1.GetKesildi()==0){
        meyve_1.SetKesildi(1);
        ui->meyve_1->setStyleSheet("image: url(:/new/images/trs.png)");
        QMovie *meyve_1_kesildi = new QMovie(":/new/images/"+QString::number(meyve_1.GetTuru())+"_k.gif");
        ui->meyve_1->setMovie(meyve_1_kesildi);
        meyve_1_kesildi->start();
        puan+=10;
        if(dash_hakki<5){
            dash_hakki++;
        }
    }
    if (Koordinat_x(ui)-ui->meyve_2->x()<200 && Koordinat_x(ui)-ui->meyve_2->x()>-40 &&
            Koordinat_y(ui)-ui->meyve_2->y()<40 && Koordinat_y(ui)-ui->meyve_2->y()>-85 && meyve_2.GetKesildi()==0){
        meyve_2.SetKesildi(1);
        ui->meyve_2->setStyleSheet("image: url(:/new/images/trs.png)");
        QMovie *meyve_2_kesildi = new QMovie(":/new/images/"+QString::number(meyve_2.GetTuru())+"_k.gif");
        ui->meyve_2->setMovie(meyve_2_kesildi);
        meyve_2_kesildi->start();
        puan+=10;
        if(dash_hakki<5){
            dash_hakki++;
        }
    }
    if (Koordinat_x(ui)-ui->meyve_3->x()<200 && Koordinat_x(ui)-ui->meyve_3->x()>-40 &&
            Koordinat_y(ui)-ui->meyve_3->y()<40 && Koordinat_y(ui)-ui->meyve_3->y()>-85 && meyve_3.GetKesildi()==0){
        meyve_3.SetKesildi(1);
        ui->meyve_3->setStyleSheet("image: url(:/new/images/trs.png)");
        QMovie *meyve_3_kesildi = new QMovie(":/new/images/"+QString::number(meyve_3.GetTuru())+"_k.gif");
        ui->meyve_3->setMovie(meyve_3_kesildi);
        meyve_3_kesildi->start();
        puan+=10;
        if(dash_hakki<5){
            dash_hakki++;
        }
    }
    if (Koordinat_x(ui)-ui->meyve_4->x()<200 && Koordinat_x(ui)-ui->meyve_4->x()>-40 &&
            Koordinat_y(ui)-ui->meyve_4->y()<40 && Koordinat_y(ui)-ui->meyve_4->y()>-85 && meyve_4.GetKesildi()==0){
        meyve_4.SetKesildi(1);
        ui->meyve_4->setStyleSheet("image: url(:/new/images/trs.png)");
        QMovie *meyve_4_kesildi = new QMovie(":/new/images/"+QString::number(meyve_4.GetTuru())+"_k.gif");
        ui->meyve_4->setMovie(meyve_4_kesildi);
        meyve_4_kesildi->start();
        puan+=10;
        if(dash_hakki<5){
            dash_hakki++;
        }
    }
    if (Koordinat_x(ui)-ui->meyve_5->x()<200 && Koordinat_x(ui)-ui->meyve_5->x()>-40 &&
            Koordinat_y(ui)-ui->meyve_5->y()<40 && Koordinat_y(ui)-ui->meyve_5->y()>-85 && meyve_5.GetKesildi()==0){
        meyve_5.SetKesildi(1);
        ui->meyve_5->setStyleSheet("image: url(:/new/images/trs.png)");
        QMovie *meyve_5_kesildi = new QMovie(":/new/images/"+QString::number(meyve_5.GetTuru())+"_k.gif");
        ui->meyve_5->setMovie(meyve_5_kesildi);
        meyve_5_kesildi->start();
        puan+=10;
        if(dash_hakki<5){
            dash_hakki++;
        }
    }
}

void karakter::KesYukari(Ui::Oyun *ui,Meyve & meyve_1,Meyve & meyve_2,Meyve & meyve_3,Meyve & meyve_4,Meyve & meyve_5,int &puan,QMovie *slash_yukari){

    ui->slash->setMovie(slash_yukari);
    slash_yukari->start();

    ui->slash->move(Koordinat_x(ui),Koordinat_y(ui)-180);

    if (Koordinat_x(ui)-ui->meyve_1->x()<60 && Koordinat_x(ui)-ui->meyve_1->x()>-60 &&
            Koordinat_y(ui)-ui->meyve_1->y()<250 && Koordinat_y(ui)-ui->meyve_1->y()>-40 && meyve_1.GetKesildi()==0){
        meyve_1.SetKesildi(1);
        ui->meyve_1->setStyleSheet("image: url(:/new/images/trs.png)");
        QMovie *meyve_1_kesildi = new QMovie(":/new/images/"+QString::number(meyve_1.GetTuru())+"_k.gif");
        ui->meyve_1->setMovie(meyve_1_kesildi);
        meyve_1_kesildi->start();
        puan+=10;
        if(dash_hakki<5){
            dash_hakki++;
        }
    }
    if (Koordinat_x(ui)-ui->meyve_2->x()<60 && Koordinat_x(ui)-ui->meyve_2->x()>-60 &&
            Koordinat_y(ui)-ui->meyve_2->y()<250 && Koordinat_y(ui)-ui->meyve_2->y()>-40 && meyve_2.GetKesildi()==0){
        meyve_2.SetKesildi(1);
        ui->meyve_2->setStyleSheet("image: url(:/new/images/trs.png)");
        QMovie *meyve_2_kesildi = new QMovie(":/new/images/"+QString::number(meyve_2.GetTuru())+"_k.gif");
        ui->meyve_2->setMovie(meyve_2_kesildi);
        meyve_2_kesildi->start();
        puan+=10;
        if(dash_hakki<5){
            dash_hakki++;
        }
    }
    if (Koordinat_x(ui)-ui->meyve_3->x()<60 && Koordinat_x(ui)-ui->meyve_3->x()>-60 &&
            Koordinat_y(ui)-ui->meyve_3->y()<250 && Koordinat_y(ui)-ui->meyve_3->y()>-40 && meyve_3.GetKesildi()==0){
        meyve_3.SetKesildi(1);
        ui->meyve_3->setStyleSheet("image: url(:/new/images/trs.png)");
        QMovie *meyve_3_kesildi = new QMovie(":/new/images/"+QString::number(meyve_3.GetTuru())+"_k.gif");
        ui->meyve_3->setMovie(meyve_3_kesildi);
        meyve_3_kesildi->start();
        puan+=10;
        if(dash_hakki<5){
            dash_hakki++;
        }
    }
    if (Koordinat_x(ui)-ui->meyve_4->x()<60 && Koordinat_x(ui)-ui->meyve_4->x()>-60 &&
            Koordinat_y(ui)-ui->meyve_4->y()<250 && Koordinat_y(ui)-ui->meyve_4->y()>-40 && meyve_4.GetKesildi()==0){
        meyve_4.SetKesildi(1);
        ui->meyve_4->setStyleSheet("image: url(:/new/images/trs.png)");
        QMovie *meyve_4_kesildi = new QMovie(":/new/images/"+QString::number(meyve_4.GetTuru())+"_k.gif");
        ui->meyve_4->setMovie(meyve_4_kesildi);
        meyve_4_kesildi->start();
        puan+=10;
        if(dash_hakki<5){
            dash_hakki++;
        }
    }
    if (Koordinat_x(ui)-ui->meyve_5->x()<60 && Koordinat_x(ui)-ui->meyve_5->x()>-60 &&
            Koordinat_y(ui)-ui->meyve_5->y()<250 && Koordinat_y(ui)-ui->meyve_5->y()>-40 && meyve_5.GetKesildi()==0){
        meyve_5.SetKesildi(1);
        ui->meyve_5->setStyleSheet("image: url(:/new/images/trs.png)");
        QMovie *meyve_5_kesildi = new QMovie(":/new/images/"+QString::number(meyve_5.GetTuru())+"_k.gif");
        ui->meyve_5->setMovie(meyve_5_kesildi);
        meyve_5_kesildi->start();
        puan+=10;
        if(dash_hakki<5){
            dash_hakki++;
        }
    }
}

void karakter::Dash(Ui::Oyun *ui, QMovie *dash_sag, QMovie *dash_sol,QMovie *hayalet_sol,QMovie *hayalet_sag){
    if (yon==1 && dash_hakki==5){
        ui->dash->setMovie(dash_sag);
        dash_sag->start();
        ui->dash->move(Koordinat_x(ui),Koordinat_y(ui)-40);

        ui->hayalet->setMovie(hayalet_sag);
        hayalet_sag->start();
        ui->hayalet->move(Koordinat_x(ui)+250,Koordinat_y(ui));

        dash_hakki=0;
    }
    if(yon==0 && dash_hakki==5){
        ui->dash->setMovie(dash_sol);
        dash_sol->start();
        ui->dash->move(Koordinat_x(ui)-160,Koordinat_y(ui)-40);

        ui->hayalet->setMovie(hayalet_sol);
        hayalet_sol->start();
        ui->hayalet->move(Koordinat_x(ui)-250,Koordinat_y(ui));

        dash_hakki=0;
    }

}

int karakter::DashHakki(){
    return dash_hakki;
}
