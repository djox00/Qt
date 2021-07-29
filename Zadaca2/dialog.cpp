#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/privatni/CLCHARGE.db");
    if(!mydb.open()){
        qDebug() <<"konekcija nije uspjesna";
    }
    else{
        qDebug() <<"konekcija uspjesna"; }




      Dialog::update_tables(); // osvjezi tabele



     ui->label->setStyleSheet("border: 1px solid black");
     ui->label->setAlignment(Qt::AlignCenter);
     ui->label_2->setStyleSheet("border: 1px solid black");
     ui->label_2->setAlignment(Qt::AlignCenter);
     ui->label_3->setStyleSheet("border: 1px solid black");
     ui->label_3->setAlignment(Qt::AlignCenter);


     ui->dateEdit->setDisabled(true);
     ui->pushButton->setDisabled(true);
     ui->lineEdit->setText(("0.0075"));

     date.setDate(2019,1,1);
     ui->dateEdit->setDate(date);

     QSqlQuery qry;
     qry.prepare("SELECT Ispunjeno FROM PRINTERI WHERE Ispunjeno='0'");
     qry.exec();
     if(qry.next()==NULL){
     ui->pushButton->setEnabled(true);

     }





    connect(ui->tableView, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(rowclicked(const QModelIndex &)));
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(next_clicked()));





}

Dialog::~Dialog()
{
    delete ui;
    mydb.close();
}

void Dialog::rowclicked(const QModelIndex &index) {



    if (index.isValid()) {

        Dialog::update_tables();
        QSqlQuery qry ;

             qry.prepare("SELECT Serijski FROM PRINTERI WHERE Serijski='"+index.data().toString()+"'OR PocetnoStanje "
            "='"+index.data().toString()+"' OR Tip ='"+index.data().toString()+"' OR Toner='"+index.data().toString()+"'");
             qry.exec();
             while(qry.next()) {

             Dialog::Serijskiqryval = qry.value(0).toString();


}
            Dialog2 = new QDialog(this);
            Dialog2->show();
            Dialog2->setGeometry(50,50,600,150);

           Serijski = new QLabel(Dialog2);
           Serijski->setText("Serijski");
           Serijski->setStyleSheet("font-weight: bold; font-size:10pt;");
           Serijski->setGeometry(50,25,60,20);
           Serijski->setVisible(true);


           Mjesec = new QLabel(Dialog2);
           Mjesec->setText("Mjesec");
           Mjesec->setStyleSheet("font-weight: bold; font-size:10pt;");
           Mjesec->setGeometry(200,25,60,20);
           Mjesec->setVisible(true);


           Godina = new QLabel(Dialog2);
           Godina->setText("Godina");
           Godina->setStyleSheet("font-weight: bold; font-size:10pt;");
           Godina->setGeometry(350,25,60,20);
           Godina->setVisible(true);


           Stranice = new QLabel(Dialog2);
           Stranice->setText("Stranice");
           Stranice->setStyleSheet("font-weight: bold; font-size:10pt;");
           Stranice->setGeometry(500,25,60,20);
           Stranice->setVisible(true);

           Serijski_value = new QLabel (Dialog2);
           Serijski_value->setStyleSheet("font-weight: bold; font-size:9pt;");
           Serijski_value->setGeometry(30,90,110,20);
           Serijski_value->setVisible(true);
           Serijski_value->setText(Serijskiqryval);

           Mjesec_value = new QLabel (Dialog2);
           Mjesec_value->setStyleSheet("font-weight: bold; font-size:9pt;");
           Mjesec_value->setGeometry(215,90,100,20);
           Mjesec_value->setVisible(true);
           Mjesec_value->setText(QString::number(ui->dateEdit->date().month()));

           Godina_value = new QLabel (Dialog2);
           Godina_value->setStyleSheet("font-weight: bold; font-size:9pt;");
           Godina_value->setGeometry(355,90,100,20);
           Godina_value->setVisible(true);
           Godina_value->setText(QString::number(ui->dateEdit->date().year()));


           Stranice_value = new QSpinBox(Dialog2);
           Stranice_value->setGeometry(480,90,110,20);
           Stranice_value->setVisible(true);
           Stranice_value->setMaximum(999999999);
           qry.prepare("SELECT PocetnoStanje FROM PRINTERI WHERE SERIJSKI='"+Serijskiqryval+"' ");
           qry.exec();
           while(qry.next()) {
           Stranice_value->setValue(qry.value(0).toInt());
           Stranice_value->setMinimum(qry.value(0).toInt());
           qDebug()<<qry.value(0).toInt();

}
           Unosbtn = new QPushButton(Dialog2);
           Unosbtn->setGeometry(10,120,580,22);
           Unosbtn->setText("Završi Unos");
           Unosbtn->setStyleSheet("font-weight: bold; font-size: 9pt;");
           Unosbtn->setVisible(true);


 QObject::connect(Unosbtn, SIGNAL(clicked()), this, SLOT(zavrsi_clicked()));



}
}

void Dialog::zavrsi_clicked() {
    int mj = ui->dateEdit->date().month();
    int god = ui->dateEdit->date().year();

QSqlQuery qry;
qry.prepare("INSERT INTO STAMPA (Serijski,Godina,Mjesec,Stranice) VALUES ('"+Serijskiqryval+"',"
"'"+QString::number(god)+"','"+QString::number(mj)+"','"+QString::number(Stranice_value->value())+"')");
qry.exec();


qry.prepare("UPDATE PRINTERI "
" SET Ispunjeno=Ispunjeno+1 "
" WHERE Serijski='"+Serijskiqryval+"' ");
qry.exec();

qry.prepare("SELECT Ispunjeno FROM PRINTERI WHERE Ispunjeno='0'");
qry.exec();

if(qry.next()==NULL){
ui->pushButton->setEnabled(true);
}

Dialog::update_tables(); // osvjezi tabele
}


void Dialog::next_clicked() {
    int god = ui->dateEdit->date().year();
    int mj = ui->dateEdit->date().month();

QSqlQuery qry;
qry.prepare("SELECT SUM(STAMPA.Stranice-PRINTERI.PocetnoStanje)FROM PRINTERI,STAMPA WHERE PRINTERI.Serijski=STAMPA.Serijski");
qry.exec();
while(qry.next()) {
    br = qry.value(0).toInt();

}

float cijena = ui->lineEdit->text().toFloat();
float ukupnacijena = br*ui->lineEdit->text().toFloat();
QSqlQuery qry2;
qry2.prepare("insert into fakture (Godina,Mjesec,Stranice,Cijena,UkupnaCijena) VALUES('"+QString::number(god)+"',"
 "'"+QString::number(mj)+"','"+QString::number(br)+"','"+QString::number(cijena)+"','"+QString::number(ukupnacijena)+"')");
qry2.exec();


date = date.addMonths(1);
ui->dateEdit->setDate(date);
qry.prepare("UPDATE PRINTERI SET Ispunjeno = '0'");
qry.exec();

ui->pushButton->setDisabled(true);



Dialog::update_tables();


 }


void Dialog::update_tables(){

    QSqlQueryModel * sqlModel1= new QSqlQueryModel();
    QSqlQuery qry1;
    qry1.prepare("select * from printeri");
    qry1.exec();
    sqlModel1->setQuery(qry1);
    ui->tableView->setModel(sqlModel1);

    QSqlQueryModel * sqlModel2= new QSqlQueryModel();
    QSqlQuery qry2;
    qry2.prepare("select * from stampa");
    qry2.exec();
    sqlModel2->setQuery(qry2);
    ui->tableView_2->setModel(sqlModel2);

    QSqlQueryModel * sqlModel3= new QSqlQueryModel();
    QSqlQuery qry3;
    qry3.prepare("select * from fakture");
    qry3.exec();
    sqlModel3->setQuery(qry3);
    ui->tableView_3->setModel(sqlModel3);

}



