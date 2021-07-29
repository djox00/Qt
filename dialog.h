#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSemaphore>
#include "proizvodjac.h"
#include "potrosac.h"
#include <QPainter>
#include <QTimer>
#include <QtDebug>
#include <QLabel>
#include <QList>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <stdlib.h>
#include <QDebug>
#include <QPropertyAnimation>
#include <QRect>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
    Proizvodjac *mProizvodjac;
    Potrosac *mPotrosac;
    QTimer *PotrosacT;
    QTimer *ProizvodjacT;
    int broj_buffera;
    QLabel *label[5];
    QPixmap *m_pixmap;
    QPropertyAnimation *animation[10];
    int icount;
    int icount2;
    QPainter *labelPainter[5];
    QString s;
    int brojac = 0;





public slots:
    void promjenjenaVrijednostBuffera(int);
    void promjenjenaVrijednostProizvodjaca(int);
    void promjenjenaVrijednostPotrosaca(int);
    void pomjeriElementProizvodjaca();
    void pomjeriElementPotrosaca();
    void primislovo(char slovo);


protected:
    void paintEvent(QPaintEvent *event) override;

};

#endif // DIALOG_H
