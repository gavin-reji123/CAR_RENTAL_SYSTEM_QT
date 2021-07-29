#include "rent.h"
#include "ui_rent.h"
#include<QMessageBox>
#include"add.h"
#include"info.h"
rent::rent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rent)
{
    ui->setupUi(this);
    QSqlQueryModel *modal=new QSqlQueryModel();
    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/new/pool.db");
    if(!mydb.open())
         ui->label_9->setText("Failed to connect");
    else
         ui->label_9->setText("connected....");
    QSqlQuery* qry=new QSqlQuery(mydb);
    qry->prepare("select car from pool");
    qry->exec();
    modal->setQuery(*qry);
    ui->comboBox->setModel(modal);
    ui->label_3->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
    ui->label_3->setOpenExternalLinks(true);
    ui->label_3->setTextFormat(Qt::RichText);
    ui->label_3->setText("<a href=\"https://paytm.com\">Paytm</a>");
}

rent::~rent()
{
    delete ui;
}

void rent::on_pushButton_4_clicked()
{
   QMessageBox msg;
   if(ui->lineEdit->text()==0)
   {
      ui->label_9->setText("please enter the number of days !!");
   }
   else if(ui->lineEdit->text()>=97 && ui->lineEdit->text()<=122)
   {
       ui->label_9->setText("please enter valid number of days!!");
   }
   else if(ui->lineEdit->text()>=65 && ui->lineEdit->text()<=90)
   {
       ui->label_9->setText("please enter valid number of days!!");
   }
   else if(ui->comboBox->currentText()=="Audi")
   {
        ui->label_9->setText("thank you!!");
        int audi = 50;
        QString str = ui->lineEdit->text();
        float no = str.toFloat();
        audi = audi * no;
        QString status = QString("Total rent is $%1 ").arg(audi);
        QMessageBox::information(this,tr("TOTAL AMOUNT !!"),status);
        QMessageBox::information(this,tr("PAYMENT"),tr("thank you! , please Paytm in { +1 898665443 }\nuse the link below\nyou will recive mail to provide the address detail after payment\nthank you for choosing luca rental!"));
   }
   else if(ui->comboBox->currentText()=="BMW")
   {
        ui->label_9->setText("thank you!!");
        int bmw=40;
        QString str = ui->lineEdit->text();
        float no = str.toFloat();
        bmw = bmw * no;
        QString status = QString("Total rent is $%1 ").arg(bmw);
        QMessageBox::information(this,tr("TOTAL AMOUNT !!"),status);
        QMessageBox::information(this,tr("PAYMENT"),tr("thank you! , please Paytm in { +1 898665443 }\nuse the link below\nyou will recive mail to provide the address detail after payment\nthank you for choosing luca rental!"));
   }
   else if(ui->comboBox->currentText()=="Honda city")
   {
        ui->label_9->setText("thank you!!");
        int honda=30;
        QString str = ui->lineEdit->text();
        float no = str.toFloat();
        honda = honda * no;
        QString status = QString("Total rent is $%1 ").arg(honda);
        QMessageBox::information(this,tr("TOTAL AMOUNT !!"),status);
        QMessageBox::information(this,tr("PAYMENT"),tr("thank you! , please Paytm in { +1 898665443 }\nuse the link below\nyou will recive mail to provide the address detail after payment\nthank you for choosing luca rental!"));
   }
   else if(ui->comboBox->currentText()=="Rover")
   {
        ui->label_9->setText("thank you!!");
        int rover=45;
        QString str = ui->lineEdit->text();
        float no = str.toFloat();
        rover = rover * no;
        QString status = QString("Total rent is $%1 ").arg(rover);
        QMessageBox::information(this,tr("TOTAL AMOUNT !!"),status);
        QMessageBox::information(this,tr("PAYMENT"),tr("thank you! , please Paytm in { +1 898665443 }\nuse the link below\nyou will recive mail to provide the address detail after payment\nthank you for choosing luca rental!"));
   }
   else if(ui->comboBox->currentText()!="Audi" || ui->comboBox->currentText()!="BMW" || ui->comboBox->currentText()!="Honda city" || ui->comboBox->currentText()!="Rover" )
   {
       ui->label_9->setText("thank you!!");
       QMessageBox::information(this,tr("CAR"),tr("this car was recently added in luca rental\nit will take 7 days for availablity ,please choose car from the list available in :: car detail ::\nThank You!!"));

   }
}


void rent::on_pushButton_clicked()
{
    this->destroy();
    this->hide();
    add a;
    a.setModal(true);
    a.exec();
}


void rent::on_pushButton_2_clicked()
{
    info i;
    i.setModal(true);
    i.exec();
}


void rent::on_pushButton_3_clicked()
{
    QMediaPlayer*player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/acer/Desktop/weep.mp3"));
    player->play();
}




