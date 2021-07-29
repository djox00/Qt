#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QFont>
#include <QtCore>
#include <QtGui>
#include <QStringList>
#include <QString>
#include <QPixmap>
#include <QGraphicsEllipseItem>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;

    QGraphicsView *view;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *flag;
    QGraphicsLineItem *x;
    QGraphicsLineItem *y;
    QGraphicsLineItem *x1;
    QGraphicsLineItem *x2;
    QGraphicsLineItem *y1;
    QGraphicsLineItem *y2;

    QGraphicsLineItem *jun_x;
    QGraphicsLineItem *jul_x;
    QGraphicsLineItem *aug_x;
    QGraphicsLineItem *sep_x;
    QGraphicsLineItem *okt_x;
    QGraphicsLineItem *nov_x;
    QGraphicsLineItem *dec_x;
    QGraphicsLineItem *jan_x;
    QGraphicsLineItem *feb_x;
    QGraphicsLineItem *mart_x;
    QGraphicsLineItem *apr_x;
    QGraphicsLineItem *maj_x;

    QGraphicsLineItem *pod1;
    QGraphicsLineItem *pod2;
    QGraphicsLineItem *pod3;
    QGraphicsLineItem *pod4;
    QGraphicsLineItem *pod5;

    QGraphicsTextItem *pod_txt1;
     QGraphicsTextItem *pod_txt2;
      QGraphicsTextItem *pod_txt3;
       QGraphicsTextItem *pod_txt4;
        QGraphicsTextItem *pod_txt5;

          QGraphicsEllipseItem *junO;
           QGraphicsEllipseItem *julO;
           QGraphicsEllipseItem *augO;
           QGraphicsEllipseItem *sepO;
           QGraphicsEllipseItem *oktO;
           QGraphicsEllipseItem *novO;
           QGraphicsEllipseItem *decO;
           QGraphicsEllipseItem *janO;
           QGraphicsEllipseItem *febO;
           QGraphicsEllipseItem *martO;
           QGraphicsEllipseItem *aprO;
           QGraphicsEllipseItem *majO;

           QGraphicsTextItem *jun_txt;
            QGraphicsTextItem *jul_txt;
             QGraphicsTextItem *aug_txt;
              QGraphicsTextItem *sep_txt;
               QGraphicsTextItem *okt_txt;
                QGraphicsTextItem *nov_txt;
                 QGraphicsTextItem *dec_txt;
                  QGraphicsTextItem *jan_txt;
                   QGraphicsTextItem *feb_txt;
                    QGraphicsTextItem *mar_txt;
                     QGraphicsTextItem *apr_txt;
                      QGraphicsTextItem *maj_txt;
                      QFont *Def;

















};

#endif // WIDGET_H
