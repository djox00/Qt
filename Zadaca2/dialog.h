#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtSql>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QFileInfo>
#include <QStringListModel>
#include <QStringList>
#include <QSqlQueryModel>
#include <QModelIndex>
#include <QLabel>
#include <QSpinBox>
#include <QString>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void update_tables();


private:
    Ui::Dialog *ui;
    QSqlDatabase mydb;
    QDialog *Dialog2;
    QLabel *Serijski;
    QLabel *Mjesec;
    QLabel *Godina;
    QLabel *Stranice;
    QLabel *Serijski_value;
    QLabel *Mjesec_value;
    QLabel *Godina_value;
    QSpinBox *Stranice_value;
    QPushButton *Unosbtn;
    QString Serijskiqryval ;
    QString broj;
    int br;
    QDate date;




private slots:
    void rowclicked(const QModelIndex &index);
    void zavrsi_clicked();
    void next_clicked();
};

#endif // DIALOG_H
