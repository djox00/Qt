#include "dialog.h"
#include "ui_dialog.h"


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);


lwdialog = new QDialog(this);
tbdialog = new QDialog(this);
trdialog = new QDialog(this);
lview = new QListView(lwdialog);        // deklaracija objekata
tbview = new QTableView(tbdialog);
trview = new QTreeView(trdialog);

lwdialog->setGeometry(1148,143,370,230);
lview->setGeometry(10,35,350,140);
lwdialog->setWindowTitle("ListView Dialog");
tbdialog->setGeometry(1148,667,370,230);
tbview->setGeometry(10,35,350,140);
tbdialog->setWindowTitle("TableView Dialog");                                                           // dimenzije prozora
trdialog->setGeometry(1148,405,370,230);
trview->setGeometry(10,35,350,140);
trdialog->setWindowTitle("TreeView Dialog");

listviewLabel = new QLabel(lwdialog);
listviewLabel->setText("ListView");
listviewLabel->setStyleSheet("font-size: 20px; font-weight: bold; color: black");
listviewLabel->setGeometry(10,5,130,30);

tableviewLabel = new QLabel(tbdialog);
tableviewLabel->setText("TableView");
tableviewLabel->setStyleSheet("font-size: 20px; font-weight: bold; color: black");       // natipisi u dialozima
tableviewLabel->setGeometry(10,5,130,30);

treeviewLabel = new QLabel(trdialog);
treeviewLabel->setText("TreeView");
treeviewLabel->setStyleSheet("font-size: 20px; font-weight: bold; color: black");
treeviewLabel->setGeometry(10,5,130,30);

add = new QPushButton(lwdialog);
remove = new QPushButton(lwdialog);
add->setText("add");
remove->setText("remove");                    // add remove buttoni
add->setGeometry(70,190,75,30);
remove->setGeometry(230,190,75,30);

add1 = new QPushButton(tbdialog);
remove1 = new QPushButton(tbdialog);
add1->setText("add");
remove1->setText("remove");
add1->setGeometry(70,190,75,30);
remove1->setGeometry(230,190,75,30);

add2 = new QPushButton(trdialog);
remove2 = new QPushButton(trdialog);
add2->setText("add");
remove2->setText("remove");
add2->setGeometry(70,190,75,30);
remove2->setGeometry(230,190,75,30);

remove->setObjectName("remove");
remove1->setObjectName("remove1");
remove2->setObjectName("remove2");


      stringlist.append("Djordje Djuric");
      stringlist.append("Berina Mrkonjic");
      stringlist.append("Semir Celikovic");
      stringlist.append("Dino Mocic");
      stringlist.append("Mirza Dizdarevic");
      stringlist.append("Dzeneta Gutic");
      stringlist.append("Silvio Marjanovic");
      stringlist.append("Ajla Halilovic");
      stringlist.append("Tarik Jasarevic");
      stringlist.append("Nermina Zukic");
      stringlist.append("Eldin Osmanovic");
      stringmodel.setStringList(stringlist);
      lview->setModel(&stringmodel);
      tbview->setModel(&stringmodel);
      trview->setModel(&stringmodel);




    connect(ui->List_button,QPushButton::clicked,this,&Dialog::btnclicked);
    connect(ui->Table_button,QPushButton::clicked,this,&Dialog::btnclicked);
    connect(ui->Tree_button,QPushButton::clicked,this,&Dialog::btnclicked);
    QObject::connect(add, SIGNAL(clicked()),this, SLOT(addclicked()));
    QObject::connect(remove, SIGNAL(clicked()),this, SLOT(removeclicked()));
    QObject::connect(add1, SIGNAL(clicked()),this, SLOT(addclicked()));
    QObject::connect(remove1, SIGNAL(clicked()),this, SLOT(removeclicked()));
    QObject::connect(add2, SIGNAL(clicked()),this, SLOT(addclicked()));
    QObject::connect(remove2, SIGNAL(clicked()),this, SLOT(removeclicked()));



}
Dialog::~Dialog()
{
    delete ui;
}

void Dialog::addclicked() {

    bool ok;
        QString temp = QInputDialog::getText(this,"Unos","Unesite studenta:",QLineEdit::Normal,QString(),&ok);


        if (ok) {
            if(temp.isEmpty()) return;
            if(stringmodel.insertRow(stringmodel.rowCount())){
                 QModelIndex index=stringmodel.index((stringmodel.rowCount()-1),0);
                 stringmodel.setData(index,temp);
                 lview->setModel(&stringmodel);
                 tbview->setModel(&stringmodel);
                 trview->setModel(&stringmodel);

               }
            }

}


void Dialog::removeclicked() {

     QPushButton *btn = qobject_cast<QPushButton*>(sender());
if (btn->objectName()=="remove") {

    QModelIndex index= lview->currentIndex();
    stringmodel.removeRow(index.row());
    }

if (btn->objectName()=="remove1") {

    QModelIndex index= tbview->currentIndex();
    stringmodel.removeRow(index.row());
    }

if (btn->objectName()=="remove2") {

    QModelIndex index= trview->currentIndex();
    stringmodel.removeRow(index.row());
    }


}





void Dialog::btnclicked () {

    QPushButton *btn = qobject_cast<QPushButton*>(sender());

if(btn->text()=="ListView") {

   lwdialog->setVisible(true);

}

if(btn->text()=="TableView") {
    tbdialog->setVisible(true);

}

if(btn->text()=="TreeView") {
trdialog->setVisible(true);

}
}


