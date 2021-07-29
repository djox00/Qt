#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);




    view = new QGraphicsView(this);
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,600);
    scene->setBackgroundBrush(Qt::gray);
    view->setScene(scene);

    flag = new QGraphicsPixmapItem ;
    flag->setPixmap(QPixmap(":/rumunija.png"));
    flag->setScale(0.25);
    flag->setOffset(50,50);
    scene->addItem(flag);


    QGraphicsTextItem *ime = new QGraphicsTextItem("Djordje Djuric");
    ime->setParent(this);
    ime->setFont(QFont("Times New Roman",16,QFont::Bold));
    ime->setDefaultTextColor(Qt::black);
    ime->setPos(27,115);
    scene->addItem(ime);


    QBrush grafpen (Qt::red,Qt::Dense5Pattern);
    QPen blackpen(Qt::black);
    blackpen.setWidth(3);
    QPainter painter;
    painter.setPen(blackpen);

    QPen bluepen (Qt::blue);
     QPolygonF pol;
     pol << QPointF(50,500) << QPointF(50,480) << QPointF(108.3,453)
              << QPointF(166.6,430) << QPointF(224.9,423)
              << QPointF(282.2,281) << QPointF(341.5,52)
              << QPointF(395,200) << QPointF(449.8,318)
              << QPointF(508.1,359) << QPointF(566.4,208)
              << QPointF(624.7,311) << QPointF(682,458)
              << QPointF(682,500) << QPointF(50,500);


     scene->addPolygon(pol);

     QPainterPath path;
     path.addPolygon(pol);

   scene->addPath(path,bluepen,grafpen);



    QPen pen1;
    pen1.setBrush(Qt::black);
    pen1.setWidth(3);

    QPen pen2;
    pen2.setBrush(Qt::yellow);
    pen2.setWidth(3);

    x = new QGraphicsLineItem;
    x->setLine(QLineF(0,500,800,500));
    x->setPen(pen1);
    scene->addItem(x);

    y = new QGraphicsLineItem;
    y->setLine(QLineF(400,0,400,600));
    y->setPen(pen1);
    scene->addItem(y);

    x1 = new QGraphicsLineItem;
    x1->setLine(QLineF(800,500,780,480));
    x1->setPen(pen1);
    scene->addItem(x1);

    x2 = new QGraphicsLineItem;
    x2->setLine(QLineF(800,500,780,520));
    x2->setPen(pen1);
    scene->addItem(x2);


    y1 = new QGraphicsLineItem;
    y1->setLine(QLineF(400,0,420,20));
    y1->setPen(pen1);
    scene->addItem(y1);


    y2 = new QGraphicsLineItem;
    y2->setLine(QLineF(400,0,380,20));
    y2->setPen(pen1);
    scene->addItem(y2);



    jun_x = new QGraphicsLineItem;
    jun_x->setLine(QLineF(50,497,50,485));
    jun_x->setPen(pen2);
    scene->addItem(jun_x);

    jul_x = new QGraphicsLineItem;
    jul_x->setLine(QLineF(108.3,497,108.3,453));
    jul_x->setPen(pen2);
    scene->addItem(jul_x);

    aug_x = new QGraphicsLineItem;
    aug_x->setLine(QLineF(166.6,497,166.6,430));
    aug_x->setPen(pen2);
    scene->addItem(aug_x);

    sep_x = new QGraphicsLineItem;
    sep_x->setLine(QLineF(224.9,497,224.9,423));
    sep_x->setPen(pen2);
    scene->addItem(sep_x);

    okt_x = new QGraphicsLineItem;
    okt_x->setLine(QLineF(283.2,497,283.2,281));
    okt_x->setPen(pen2);
    scene->addItem(okt_x);

    nov_x = new QGraphicsLineItem;
    nov_x->setLine(QLineF(341.5,497,341.5,52));
    nov_x->setPen(pen2);
    scene->addItem(nov_x);

    dec_x = new QGraphicsLineItem;
    dec_x->setLine(QLineF(400,497,400,201));
    dec_x->setPen(pen2);
    scene->addItem(dec_x);

    jan_x = new QGraphicsLineItem;
    jan_x->setLine(QLineF(449.8,497,449.8,318));
    jan_x->setPen(pen2);
    scene->addItem(jan_x);

    feb_x = new QGraphicsLineItem;
    feb_x->setLine(QLineF(508.1,497,508.1,359));
    feb_x->setPen(pen2);
    scene->addItem(feb_x);

    mart_x = new QGraphicsLineItem;
    mart_x->setLine(QLineF(566.4,497,566.4,208));
    mart_x->setPen(pen2);
    scene->addItem(mart_x);

    apr_x = new QGraphicsLineItem;
    apr_x->setLine(QLineF(624.7,497,624.7,311));
    apr_x->setPen(pen2);
    scene->addItem(apr_x);

    maj_x = new QGraphicsLineItem;
    maj_x->setLine(QLineF(683,497,683,458));
    maj_x->setPen(pen2);
    scene->addItem(maj_x);

   pod1 = new QGraphicsLineItem;
   pod1->setLine(QLineF(385,402.16,415,402.16));
   pod1->setPen(pen2);
   scene->addItem(pod1);

   pod2 = new QGraphicsLineItem;
   pod2->setLine(QLineF(385,304.32,415,304.32));
   pod2->setPen(pen2);
   scene->addItem(pod2);

   pod3 = new QGraphicsLineItem;
   pod3->setLine(QLineF(385,206.48,415,206.48));
   pod3->setPen(pen2);
   scene->addItem(pod3);

   pod4 = new QGraphicsLineItem;
   pod4->setLine(QLineF(385,108.64,415,108.64));
   pod4->setPen(pen2);
   scene->addItem(pod4);

   pod5 = new QGraphicsLineItem;
   pod5->setLine(QLineF(385,49.91,415,49.91));
   pod5->setPen(pen2);
   scene->addItem(pod5);



        pod_txt1 = new QGraphicsTextItem("50 000");
        pod_txt1->setParent(this);
        pod_txt1->setFont(QFont("Times New Roman",9,QFont::Bold));
        pod_txt1->setDefaultTextColor(Qt::black);
        pod_txt1->setPos(402,402.16);
        scene->addItem(pod_txt1);


        pod_txt2 = new QGraphicsTextItem("100 000");
        pod_txt2->setParent(this);
        pod_txt2->setFont(QFont("Times New Roman",9,QFont::Bold));
        pod_txt2->setDefaultTextColor(Qt::black);
        pod_txt2->setPos(402,304.32);
        scene->addItem(pod_txt2);


        pod_txt3 = new QGraphicsTextItem("150 000");
        pod_txt3->setParent(this);
        pod_txt3->setFont(QFont("Times New Roman",9,QFont::Bold));
        pod_txt3->setDefaultTextColor(Qt::black);
        pod_txt3->setPos(402,206.48);
        scene->addItem(pod_txt3);


        pod_txt4 = new QGraphicsTextItem("200 000");
        pod_txt4->setParent(this);
        pod_txt4->setFont(QFont("Times New Roman",9,QFont::Bold));
        pod_txt4->setDefaultTextColor(Qt::black);
        pod_txt4->setPos(402,108.64);
        scene->addItem(pod_txt4);


        pod_txt5 = new QGraphicsTextItem("230 000");
        pod_txt5->setParent(this);
        pod_txt5->setFont(QFont("Times New Roman",9,QFont::Bold));
        pod_txt5->setDefaultTextColor(Qt::black);
        pod_txt5->setPos(402,49.91);
        scene->addItem(pod_txt5);


       junO = new QGraphicsEllipseItem;
       junO->setRect(45,475,10,10);
       junO->setBrush(QBrush(Qt::red));
       scene->addItem(junO);

       julO = new QGraphicsEllipseItem;
       julO->setRect(103.3,448,10,10);
       julO->setBrush(QBrush(Qt::red));
       scene->addItem(julO);

       augO = new QGraphicsEllipseItem;
       augO->setRect(161.6,425,10,10);
       augO->setBrush(QBrush(Qt::red));
       scene->addItem(augO);

       sepO = new QGraphicsEllipseItem;
       sepO->setRect(219.9,418,10,10);
       sepO->setBrush(QBrush(Qt::red));
       scene->addItem(sepO);

       oktO = new QGraphicsEllipseItem;
       oktO->setRect(278.2,276,10,10);
       oktO->setBrush(QBrush(Qt::red));
       scene->addItem(oktO);

       novO = new QGraphicsEllipseItem;
       novO->setRect(336.5,47,10,10);
       novO->setBrush(QBrush(Qt::red));
       scene->addItem(novO);

       decO = new QGraphicsEllipseItem;
       decO->setRect(395,196,10,10);
       decO->setBrush(QBrush(Qt::red));
       scene->addItem(decO);

       janO = new QGraphicsEllipseItem;
       janO->setRect(444.8,313,10,10);
       janO->setBrush(QBrush(Qt::red));
       scene->addItem(janO);

       febO = new QGraphicsEllipseItem;
       febO->setRect(503.1,354,10,10);
       febO->setBrush(QBrush(Qt::red));
       scene->addItem(febO);

       martO = new QGraphicsEllipseItem;
       martO->setRect(561.4,203,10,10);
       martO->setBrush(QBrush(Qt::red));
       scene->addItem(martO);

       aprO = new QGraphicsEllipseItem;
       aprO->setRect(619.7,306,10,10);
       aprO->setBrush(QBrush(Qt::red));
       scene->addItem(aprO);

       majO = new QGraphicsEllipseItem;
       majO->setRect(678,453,10,10);
       majO->setBrush(QBrush(Qt::red));
       scene->addItem(majO);

       Def = new QFont("Times New Roman");
       Def->setPixelSize(9);
       Def->setBold(true);


       QGraphicsTextItem *junt = scene->addText("Jun",QFont("Times New Roman",9,QFont::Bold));
       junt->setDefaultTextColor(Qt::yellow);
       junt->setPos(33, 505);
       QGraphicsTextItem *jult = scene->addText("Jul",QFont("Times New Roman",9,QFont::Bold));
       jult->setDefaultTextColor(Qt::yellow);
       jult->setPos(94,505);
       QGraphicsTextItem *augt = scene->addText("Aug",QFont("Times New Roman",9,QFont::Bold));
       augt->setDefaultTextColor(Qt::yellow);
       augt->setPos(149,505);
       QGraphicsTextItem *sept = scene->addText("Sep",QFont("Times New Roman",9,QFont::Bold));
       sept->setDefaultTextColor(Qt::yellow);
       sept->setPos(209,505);
       QGraphicsTextItem *oktt = scene->addText("Okt",QFont("Times New Roman",9,QFont::Bold));
       oktt->setDefaultTextColor(Qt::yellow);
       oktt->setPos(267,505);
       QGraphicsTextItem *novt = scene->addText("Nov",QFont("Times New Roman",9,QFont::Bold));
       novt->setDefaultTextColor(Qt::yellow);
       novt->setPos(329, 505);
       QGraphicsTextItem *dect = scene->addText("Dec",QFont("Times New Roman",9,QFont::Bold));
       dect->setDefaultTextColor(Qt::yellow);
       dect->setPos(370, 505);
       QGraphicsTextItem *jant = scene->addText("Jan",QFont("Times New Roman",9,QFont::Bold));
       jant->setDefaultTextColor(Qt::yellow);
       jant->setPos(433, 505);
       QGraphicsTextItem *febt = scene->addText("Feb",QFont("Times New Roman",9,QFont::Bold));
       febt->setDefaultTextColor(Qt::yellow);
       febt->setPos(495, 505);
       QGraphicsTextItem *mart = scene->addText("Mart",QFont("Times New Roman",9,QFont::Bold));
       mart->setDefaultTextColor(Qt::yellow);
       mart->setPos(546, 505);
       QGraphicsTextItem *aprt = scene->addText("Apr",QFont("Times New Roman",9,QFont::Bold));
       aprt->setDefaultTextColor(Qt::yellow);
       aprt->setPos(610, 505);
       QGraphicsTextItem *majt = scene->addText("Maj",QFont("Times New Roman",9,QFont::Bold));
       majt->setDefaultTextColor(Qt::yellow);
       majt->setPos(670, 505);

       QGraphicsTextItem *junbr = scene->addText("7,572",QFont("Times New Roman",9,QFont::Bold));
       junbr->setDefaultTextColor(Qt::blue);
       junbr->setPos(33, 445);
       QGraphicsTextItem *julbr = scene->addText("23,590",QFont("Times New Roman",9,QFont::Bold));
       julbr->setDefaultTextColor(Qt::blue);
       julbr->setPos(94,420);
       QGraphicsTextItem *augbr = scene->addText("35,429",QFont("Times New Roman",9,QFont::Bold));
       augbr->setDefaultTextColor(Qt::blue);
       augbr->setPos(149,400);
       QGraphicsTextItem *sepbr = scene->addText("38,979",QFont("Times New Roman",9,QFont::Bold));
       sepbr->setDefaultTextColor(Qt::blue);
       sepbr->setPos(209,392);
       QGraphicsTextItem *oktbr = scene->addText("111,681",QFont("Times New Roman",9,QFont::Bold));
       oktbr->setDefaultTextColor(Qt::blue);
       oktbr->setPos(267,245);
       QGraphicsTextItem *novbr = scene->addText("228,699",QFont("Times New Roman",9,QFont::Bold));
       novbr->setDefaultTextColor(Qt::blue);
       novbr->setPos(319, 23);
       QGraphicsTextItem *decbr = scene->addText("152,629",QFont("Times New Roman",9,QFont::Bold));
       decbr->setDefaultTextColor(Qt::blue);
       decbr->setPos(405, 180);
       QGraphicsTextItem *janbr = scene->addText("92,542",QFont("Times New Roman",9,QFont::Bold));
       janbr->setDefaultTextColor(Qt::blue);
       janbr->setPos(440, 287);
       QGraphicsTextItem *febbr = scene->addText("71,938",QFont("Times New Roman",9,QFont::Bold));
       febbr->setDefaultTextColor(Qt::blue);
       febbr->setPos(495, 330);
       QGraphicsTextItem *marbr = scene->addText("148,713",QFont("Times New Roman",9,QFont::Bold));
       marbr->setDefaultTextColor(Qt::blue);
       marbr->setPos(546, 182);
       QGraphicsTextItem *aprbr = scene->addText("96,347",QFont("Times New Roman",9,QFont::Bold));
       aprbr->setDefaultTextColor(Qt::blue);
       aprbr->setPos(610, 275);
       QGraphicsTextItem *majbr = scene->addText("21,165",QFont("Times New Roman",9,QFont::Bold));
       majbr->setDefaultTextColor(Qt::blue);
       majbr->setPos(670, 420);


       QGraphicsTextItem *sluc = scene->addText("Slučajevi",QFont("Times New Roman",13,QFont::Bold));
       sluc->setDefaultTextColor(Qt::blue);
       sluc->setPos(405, 20);
       QGraphicsTextItem *mjes = scene->addText("Mjesec",QFont("Times New Roman",13,QFont::Bold));
       mjes->setDefaultTextColor(Qt::blue);
       mjes->setPos(730, 450);

       QGraphicsTextItem *god2020 = scene->addText("2020",QFont("Times New Roman",20,QFont::Bold));
       god2020->setDefaultTextColor(Qt::red);
       god2020->setPos(180, 550);

       QGraphicsTextItem *god2021 = scene->addText("2021",QFont("Times New Roman",20,QFont::Bold));
       god2021->setDefaultTextColor(Qt::red);
       god2021->setPos(580, 550);

















































}

Widget::~Widget()
{
    delete ui;
}



