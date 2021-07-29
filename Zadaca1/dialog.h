#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "qdebug.h"
#include "QString"
#include "QStringListModel"
#include "QStringList"
#include "QListView"
#include "QTreeView"
#include "QTableView"
#include "QLabel"
#include "QPushButton"
#include "QInputDialog"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();


private slots:


    void addclicked();
    void removeclicked();
    void btnclicked();


private:
    Ui::Dialog *ui;
    QStringListModel stringmodel;
    QStringList stringlist;

    QDialog *lwdialog;
    QDialog *tbdialog;
    QDialog *trdialog;
    QListView *lview;
    QTableView *tbview;
    QTreeView *trview;
    QLabel *listviewLabel;
    QLabel *tableviewLabel;
    QLabel *treeviewLabel;
    QPushButton *add;
    QPushButton *remove;
    QPushButton *add1;
    QPushButton *remove1;
    QPushButton *add2;
    QPushButton *remove2;




};

#endif // DIALOG_H
