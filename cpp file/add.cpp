#include "add.h"
#include "ui_add.h"
#include<QMessageBox>
#include "signup.h"
#include "rent.h"

add::add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add)
{
    ui->setupUi(this);
    mydb= QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/new/pool.db");
    if(!mydb.open())
       ui->label_7->setText("failed connection");
    else
      ui->label_7->setText("connected...");
}

add::~add()
{
    delete ui;
}

void add::on_pushButton_clicked()
{
    QString name,car,capacity;
    name=ui->lineEdit->text();
    car=ui->lineEdit_2->text();
    capacity=ui->lineEdit_3->text();
    if(!mydb.isOpen()){
        qDebug()<<"daatabase failed ";
        return;
       }
    QSqlQuery qry;
    if(name==0 || car==0 || capacity==0  )
    {
         ui->label_7->setText("please enter all values !!!");
    }
    else if(qry.exec("select * from pool where car='"+car+"'"))
    {
        if(qry.next()==true)
        {
            ui->label_7->setText("This car already exist");
        }
        else if(qry.next()==false)
        {
            if(qry.exec("insert into pool (name,car,capacity) values ('"+name+"','"+car+"','"+capacity+"')"))
            {
             ui->label_7->setText("Thank you!");
             QMessageBox::information(this,tr("THANK YOU"),tr("thank you!\n we will look into the provided information and list out the car in 7 working days !!!"));
            }
        }

    }


}



void add::on_pushButton_2_clicked()
{
    QMessageBox::StandardButton reply;
    reply=QMessageBox::question(this,"Are you sure ?","Do You Want to Leave This Application ?",QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        this->destroy();
        this->hide();
    }
    if(reply == QMessageBox::No)
    {
        this->destroy();
        this->hide();
        signup sign;
        sign.setModal(true);
        sign.exec();
    }

}


void add::on_pushButton_3_clicked()
{
    QMediaPlayer*player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/acer/Desktop/renting.mp3"));
    player->play();
}


void add::on_pushButton_4_clicked()
{
    this->destroy();
    this->hide();
    rent sign;
    sign.setModal(true);
    sign.exec();
}

