#include "dialog.h"
#include "ui_dialog.h"
#include "consts.h"

char buffer[BufferSize];
QSemaphore slobodniBajti(BufferSize);
QSemaphore iskoristeniBajti;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    mProizvodjac=new Proizvodjac(this);
    mPotrosac=new Potrosac(this);

    mProizvodjac->start();
    mPotrosac->start();

    ProizvodjacT = new QTimer(this);
    PotrosacT = new QTimer(this);


connect(mPotrosac,SIGNAL(promjenaPotrosenih(int)),this,SLOT(promjenjenaVrijednostPotrosaca(int)));
connect(mProizvodjac,SIGNAL(promjenaProizvedenih(int)),this,SLOT(promjenjenaVrijednostProizvodjaca(int)));
connect(mProizvodjac,SIGNAL(promjenaNapunjenihBuffera(int)),this,SLOT(promjenjenaVrijednostBuffera(int)));
connect(mPotrosac,SIGNAL(promjenaNapunjenihBuffera(int)),this,SLOT(promjenjenaVrijednostBuffera(int)));
connect(mProizvodjac,SIGNAL(sendslovo(char)),this,SLOT(primislovo(char)));


}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::primislovo(char slovo){

    s = slovo;
    }
void Dialog::promjenjenaVrijednostBuffera(int broj)
{
broj_buffera = broj;

}

void Dialog::promjenjenaVrijednostProizvodjaca(int broj)
{



icount = broj;
if(broj_buffera<5) {

    int br=broj%5;
 QPixmap labelpixmap(50,50);
labelpixmap.fill(Qt::yellow);
labelPainter[br] = new QPainter(&labelpixmap);
labelPainter[br]->setPen(Qt::black);
label[br] = new QLabel(this);
labelPainter[br]->drawText(labelpixmap.rect(),Qt::AlignCenter,s);
label[br]->setPixmap(labelpixmap);
label[br]->setGeometry(50,50,50,50);
label[br]->show();
labelPainter[br]->end();




ProizvodjacT->singleShot(100,this,SLOT(pomjeriElementProizvodjaca()));



}
else {qDebug()<<"Buffer pun!";}
}


void Dialog::promjenjenaVrijednostPotrosaca(int broj)
{

PotrosacT->singleShot(9000,this,SLOT(pomjeriElementPotrosaca()));

}


 void Dialog::pomjeriElementProizvodjaca()
{

 if(icount%5==0){


     animation[0] = new QPropertyAnimation(label[0],"geometry");
     animation[0]->setDuration(3000);
     animation[0]->setStartValue(label[0]->geometry());
     animation[0]->setEndValue(QRect(155,300,50,50));
     animation[0]->start();



}

 if(icount%5==1){


     animation[1] = new QPropertyAnimation(label[1],"geometry");
     animation[1]->setDuration(3000);
     animation[1]->setStartValue(label[1]->geometry());
     animation[1]->setEndValue(QRect(215,300,50,50));
     animation[1]->start();


}

 if(icount%5==2){

     animation[2] = new QPropertyAnimation(label[2],"geometry");
     animation[2]->setDuration(3000);
     animation[2]->setStartValue(label[2]->geometry());
     animation[2]->setEndValue(QRect(275,300,50,50));
     animation[2]->start();

}

 if(icount%5==3){

     animation[3] = new QPropertyAnimation(label[3],"geometry");
     animation[3]->setDuration(3000);
     animation[3]->setStartValue(label[3]->geometry());
     animation[3]->setEndValue(QRect(335,300,50,50));
     animation[3]->start();


}
 if(icount%5==4){

     animation[4] = new QPropertyAnimation(label[4],"geometry");
     animation[4]->setDuration(3000);
     animation[4]->setStartValue(label[4]->geometry());
     animation[4]->setEndValue(QRect(395,300,50,50));
     animation[4]->start();

}



}
void Dialog::pomjeriElementPotrosaca()
{
    brojac++;
    if(brojac%5==1){

    animation[5] = new QPropertyAnimation(label[0],"geometry");
    animation[5]->setDuration(3000);
    animation[5]->setStartValue(label[0]->geometry());
    animation[5]->setEndValue(QRect(500,30,50,50));
    animation[5]->start();

}

    if(brojac%5==2){
    animation[6] = new QPropertyAnimation(label[1],"geometry");
    animation[6]->setDuration(3000);
    animation[6]->setStartValue(label[1]->geometry());
    animation[6]->setEndValue(QRect(500,30,50,50));
    animation[6]->start();

 }




    if(brojac%5==3){
    animation[7] = new QPropertyAnimation(label[2],"geometry");
    animation[7]->setDuration(3000);
    animation[7]->setStartValue(label[2]->geometry());
    animation[7]->setEndValue(QRect(500,30,50,50));
    animation[7]->start();


    }



    if(brojac%5==4){
    animation[8] = new QPropertyAnimation(label[3],"geometry");
    animation[8]->setDuration(3000);
    animation[8]->setStartValue(label[3]->geometry());
    animation[8]->setEndValue(QRect(500,30,50,50));
    animation[8]->start();


    }



    if(brojac%5==0){
    animation[9] = new QPropertyAnimation(label[4],"geometry");
    animation[9]->setDuration(3000);
    animation[9]->setStartValue(label[4]->geometry());
    animation[9]->setEndValue(QRect(500,30,50,50));
    animation[9]->start();

  }



}

void Dialog::paintEvent(QPaintEvent *event){
    QPainter painter(this);


    QPen Pen1;
    Pen1.setWidth(1);
    Pen1.setColor(Qt::blue);
    QPen Pen2;
    Pen2.setColor(Qt::black);

    painter.setPen(Pen1);
    painter.drawLine(150,350,450,350);
     painter.drawLine(150,350,150,300);
      painter.drawLine(210,350,210,300);
       painter.drawLine(270,350,270,300);
        painter.drawLine(330,350,330,300);
         painter.drawLine(390,350,390,300);
          painter.drawLine(450,350,450,300);
          painter.setPen(Pen2);
          painter.setFont(QFont("Times New Roman",9,QFont::Bold));
          painter.drawText(QRect(260,360,340,360),"B   U   F   F   E   R");

          QPainter painter2(this);
          QBrush zelena;
          QBrush crvena;
          zelena.setColor(Qt::green);
          zelena.setStyle(Qt::SolidPattern);
          crvena.setColor(Qt::red);
          crvena.setStyle(Qt::SolidPattern);

          painter2.setBrush(zelena);
          painter2.drawRoundedRect(QRectF(30.0,30.0,70.0,70.0),7.0,7.0);
          painter2.setBrush(crvena);
          painter2.drawRoundedRect(QRectF(500.0,30.0,70.0,70.0),7.0,7.0);
          QPen zuta;
          zuta.setColor(Qt::yellow);

           painter2.setFont(QFont("Times New Roman",10.5,QFont::Bold));
           painter2.setPen(zuta);
           painter2.drawText(QRect(33.0,50,99,50),"Proizvodjac");

           painter2.setFont(QFont("Times New Roman",10.5,QFont::Bold));
           painter2.setPen(zuta);
           painter2.drawText(QRect(511.0,50,599,50),"Potrosac");



    }
