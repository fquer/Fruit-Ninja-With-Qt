#include "oyun.h"
#include "ui_oyun.h"
#include "karakter.h"
#include "meyve.h"

karakter Hayalet;

Meyve meyve_1;
Meyve meyve_2;
Meyve meyve_3;
Meyve meyve_4;
Meyve meyve_5;

Oyun::Oyun(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Oyun)
{
    ui->setupUi(this);

    ui->hayalet->setMovie(hayalet_sag);
    hayalet_sag->start();// baslangic olarak saga bakiyor

    ui->can->setStyleSheet("color: #FFFFFF");
    ui->skor->setStyleSheet("color: #FFFFFF");// beyaz renk

    ui->can->setText("x"+QString::number(Hayalet.CanGet())); // can degeri baslangic atamasi

    ui->dash_hakki_kapali->hide(); // dash hakki acik olarak geliyor
    ui->dash_hakki_acik->show();
    ui->dash_hakki_acik->setMovie(dash_hakki);
    dash_hakki->start();

    ui->koordinat->hide();
    ui->kontrol->setStyleSheet("image: url(:/new/images/kontrol.png)");

    ui->can->hide();
    ui->can_hayalet->hide();
    ui->skor->hide();
    ui->dash_hakki_acik->hide();
    ui->dash_hakki_kapali->hide();
}

Oyun::~Oyun()
{
    delete ui;
}

void Oyun::Delay(int msec)
{
    QTime dieTime= QTime::currentTime().addMSecs(msec);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void Oyun::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_W){
        Hayalet.HareketYukari(ui);
    }
    if (event->key() == Qt::Key_A){
        Hayalet.HareketSol(ui,hayalet_sol);
    }
    if (event->key() == Qt::Key_S){
        Hayalet.HareketAsagi(ui);  
    }
    if (event->key() == Qt::Key_D){
        Hayalet.HareketSag(ui,hayalet_sag);
    }
    if (event->key() == Qt::Key_L){
        Hayalet.KesSag(ui,meyve_1,meyve_2,meyve_3,meyve_4,meyve_5,puan,hayalet_sag,slash_sag);
    }
    if (event->key() == Qt::Key_J){
        Hayalet.KesSol(ui,meyve_1,meyve_2,meyve_3,meyve_4,meyve_5,puan,hayalet_sol,slash_sol);
    }
    if (event->key() == Qt::Key_I){
        Hayalet.KesYukari(ui,meyve_1,meyve_2,meyve_3,meyve_4,meyve_5,puan,slash_yukari);
    }
    if (event->key() == Qt::Key_P){
        Basla();
    }
    if (event->key() == Qt::Key_F){
        Hayalet.Dash(ui,dash_sag,dash_sol,hayalet_sol,hayalet_sag);
    }
}


void Oyun::Basla(){
    ui->can->show();
    ui->can_hayalet->show();
    ui->skor->show();
    ui->dash_hakki_acik->show();
    ui->dash_hakki_kapali->show();

    ui->kontrol->hide();

    puan=0;
    hiz=10;
    int devam=1;
    ui->kaybettin->hide();
    Hayalet.CanSet(10);
    while (Hayalet.CanGet()>0){

        meyve_1.SetKesildi(0); // Tur basi meyveler tekrar kesilmemis hale getirildi
        meyve_2.SetKesildi(0);
        meyve_3.SetKesildi(0);
        meyve_4.SetKesildi(0);
        meyve_5.SetKesildi(0);

        QTime time = QTime::currentTime(); // Seed alimi
        int seed =time.msec();

        meyve_1.Rastgele(seed,ui,1);    // X  ve Tur degerlerinin rastgele atanmasi
        seed++;
        meyve_2.Rastgele(seed,ui,2);
        seed+=2;
        meyve_3.Rastgele(seed,ui,3);
        seed+=5;
        meyve_4.Rastgele(seed,ui,4);
        seed+=9;
        meyve_5.Rastgele(seed,ui,5);

        while (true){
            if(meyve_1.GetKesildi()==0){            // Meyveler kesilmediyse asagi dogru indirmeye devam etmeli
                x_1 = ui->meyve_1->x();
                y_1 = ui->meyve_1->y();
                ui->meyve_1->move(x_1,y_1+1);
            }
            if (meyve_2.GetKesildi()==0){
                x_2 = ui->meyve_2->x();
                y_2 = ui->meyve_2->y();
                ui->meyve_2->move(x_2,y_2+1);
            }
            if (meyve_3.GetKesildi()==0){
                x_3 = ui->meyve_3->x();
                y_3 = ui->meyve_3->y();
                ui->meyve_3->move(x_3,y_3+1);
            }
            if (meyve_4.GetKesildi()==0){
                x_4 = ui->meyve_4->x();
                y_4 = ui->meyve_4->y();
                ui->meyve_4->move(x_4,y_4+1);
            }
            if (meyve_5.GetKesildi()==0){
                x_5 = ui->meyve_5->x();
                y_5 = ui->meyve_5->y();
                ui->meyve_5->move(x_5,y_5+1);
            }
            Delay(hiz);//hiz tanimi

            // Dash hakki mevcut ise
            if (Hayalet.DashHakki()==5){
                ui->dash_hakki_kapali->hide();
                ui->dash_hakki_acik->show();
                ui->dash_hakki_acik->setMovie(dash_hakki);
                dash_hakki->start();
            }//degil ise
            else{
                ui->dash_hakki_acik->hide();
                ui->dash_hakki_kapali->show();
            }

            // Can azaltmasi
            if ((meyve_1.GetKoordinat_y(ui,1) == 1050 && meyve_1.GetKesildi()==0) ||
                (meyve_2.GetKoordinat_y(ui,2) == 1050 && meyve_2.GetKesildi()==0) ||
                (meyve_3.GetKoordinat_y(ui,3) == 1050 && meyve_3.GetKesildi()==0) ||
                (meyve_4.GetKoordinat_y(ui,4) == 1050 && meyve_4.GetKesildi()==0) ||
                (meyve_5.GetKoordinat_y(ui,5) == 1050 && meyve_5.GetKesildi()==0)){
                Hayalet.CanAzalt(1);
                ui->hasar->setMovie(hasar);
                hasar->start();
            }

            ui->skor->setText("Skor : "+QString::number(puan)); // skor guncellemesi
            ui->can->setText("x"+QString::number(Hayalet.CanGet())); // can guncellemesi

            // Oyun hizlanmasi
            if((puan==100 && devam==1) ||
               (puan==200 && devam==2) ||
               (puan==300 && devam==3) ||
               (puan==400 && devam==4) ||
               (puan==500 && devam==5)){
                hiz--;
                devam++;
            }
            // Can bitti ise turu bitir
            if (Hayalet.CanGet()<=0){
                break;
            }
            // Tur bitimi
            if((meyve_1.GetKesildi()==1 || meyve_1.GetKoordinat_y(ui,1) > 1100) &&
               (meyve_2.GetKesildi()==1 || meyve_2.GetKoordinat_y(ui,2) > 1100) &&
               (meyve_3.GetKesildi()==1 || meyve_3.GetKoordinat_y(ui,3) > 1100) &&
               (meyve_4.GetKesildi()==1 || meyve_4.GetKoordinat_y(ui,4) > 1100) &&
               (meyve_5.GetKesildi()==1 || meyve_5.GetKoordinat_y(ui,5) > 1100)){
                Delay(600);
                break;
            }
        }
    }
    ui->kaybettin->show();
    ui->kaybettin->setMovie(kaybettin);
    kaybettin->start();// kaybettin yazisinin bastirilmasi
}

void Oyun::on_koordinat_clicked()
{
    int x = ui->hayalet->x();
    int y = ui->hayalet->y();

    ui->koordinat->setText("Hayalet X :"+QString::number(x)+"  Y :"+QString::number(y)+
                           "\nMeyve 1 X:"+QString::number(ui->meyve_1->x())+"  Y: "+QString::number(ui->meyve_1->y())+
                           "\nfark X : "+QString::number(x-ui->meyve_1->x())+" Y : "+QString::number(y-ui->meyve_1->y()));
}

