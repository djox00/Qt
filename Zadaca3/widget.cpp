#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{



}

Widget::~Widget()
{
    delete ui;
}
void Widget::paintEvent(QPaintEvent *event){
    QPainter painter(this);

    QBrush mBrush;
    mBrush.setColor(Qt::yellow);
    mBrush.setStyle(Qt::SolidPattern);
    painter.setBrush(mBrush);
    painter.drawRect(0,0,2000,2000);

    QPen gume;
    gume.setBrush(Qt::black);
    gume.setWidth(3);           // za gume olovka

    QPen mainpen(Qt::black);
    mainpen.setWidth(2);


    QPen linepenwindow(Qt::black);
    linepenwindow.setWidth(2);
    mBrush.setColor(Qt::gray);

       // tocak 1
        QRectF guma1_xy(175.0, 273.5, 50.0, 50.0);
        QPainter guma1(this);
        guma1.setBrush(mBrush);
        guma1.drawEllipse(guma1_xy);

        QRectF felga1_xy(182.5, 281.0, 35.0, 35.0);
        QPainter felga1(this);
        felga1.setBrush(Qt::SolidPattern);
        felga1.drawEllipse(felga1_xy);


        // tocak2

        QRectF guma2_xy(323.0, 273.5, 50.0, 50.0);
        QPainter guma2(this);
        guma2.setBrush(mBrush);
        guma2.drawEllipse(guma2_xy);

        QRectF felga2_xy(330.0, 281.0, 35.0, 35.0);
        QPainter felga2(this);
        felga2.setBrush(Qt::SolidPattern);
        felga2.drawEllipse(felga2_xy);


        //blatobran1
        QRectF blatobran1_xy(170.0,267.0,60.0,70.0);
        int startAngleg = 20*16;
        int spanAngleg = 140*16;

        QPainter blatobran1(this);
        blatobran1.setPen(mainpen);
        blatobran1.drawArc(blatobran1_xy,startAngleg,spanAngleg);

        //Blatobran2
        QRectF blatobran2_xy(318.0,267.0,60.0,70.0);
        int startAnglegg = 20*16;
        int spanAnglegg = 140*16;

        QPainter blatobran2(this);
        blatobran2.setPen(mainpen);
        blatobran2.drawArc(blatobran2_xy,startAnglegg,spanAnglegg);



    QPainter painter5(this);
 painter5.setPen(mainpen);
  painter5.drawLine(170,290,140,290);
    painter5.drawLine(140,290,145,250);
      painter5.drawLine(145,250,202,242);


    QRectF rec(200.0,182.0,160.0,160.0);
    int startAnglee = 20*16;
    int spanAnglee = 145* 16;

    QPainter krov(this);
    krov.setPen(mainpen);
    krov.drawArc(rec,startAnglee,spanAnglee);

    painter5.drawLine(355,235,420,245);
    painter5.drawLine(420,245,435,290);
    painter5.drawLine(378,290,435,290);
    painter5.drawLine(320,290,230,290);
    painter5.drawLine(295,200,295,230);
    painter5.drawLine(270,200,270,230);
    painter5.drawLine(295,230,335,230);
    painter5.drawLine(270,230,230,230);



   QRectF Lprozor(270.0,200.0,65.0,65.0);
   int Lstart = 210*55;
   int Lspan = 115*14;
   QPainter Lprozor1(this);
   Lprozor1.setPen(mainpen);
   Lprozor1.drawArc(Lprozor,Lstart,Lspan);



   QRectF Dprozor(230.0,200.0,65.0,65.0);
   int Dstart = 231*55;
   int Dspan = 112*14;

   QPainter Dprozor1(this);
   Dprozor1.setPen(mainpen);
   Dprozor1.drawArc(Dprozor,Dstart,Dspan);














}
