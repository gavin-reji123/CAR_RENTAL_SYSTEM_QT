#include "signup.h"
#include "ui_signup.h"
#include"login.h"
#include "rent.h"
signup::signup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
    ui->label_7->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
    ui->label_7->setOpenExternalLinks(true);
    ui->label_7->setTextFormat(Qt::RichText);
    ui->label_7->setText("<a href=\"https://www.instagram.com\">Instagram</a>");

    ui->label_9->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
    ui->label_9->setOpenExternalLinks(true);
    ui->label_9->setTextFormat(Qt::RichText);
    ui->label_9->setText("<a href=\"https://www.youtube.com\">Youtube</a>");

    ui->label_11->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
    ui->label_11->setOpenExternalLinks(true);
    ui->label_11->setTextFormat(Qt::RichText);
    ui->label_11->setText("<a href=\"https://twitter.com\">Twitter</a>");

    mydb= QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/new/amma.db");
    if(!mydb.open())
       ui->label->setText("failed connection");
    else
      ui->label->setText("connected..");
}

signup::~signup()
{
    delete ui;
}

void signup::on_pushButton_clicked()
{
    QString username,password;
    username=ui->lineEdit_3->text();
    password=ui->lineEdit_2->text();
    if(!mydb.isOpen()){
        qDebug()<<"daatabase failed ";
        return;
       }
    QString strPw = ui->lineEdit_2->text();
    QByteArray baPw = strPw.toUtf8();
    for (int i = 0;i<baPw.size();i++)
    {
             baPw [i] = baPw [i] + 2;
    }
    strPw = baPw;
    password = strPw;
    if(username==NULL && password==NULL)
    {
      ui->label->setText("please enter username and password");
    }
    else
    {
        QSqlQuery qry;
        if(qry.exec("select * from amma where username='"+username+"'and password='"+password+"'"))
        {
           int count=0;
           while(qry.next())
           {
              count++;
           }
           if(count==1)
           {
             ui->label->setText("signed in sucessfully");
             this->destroy();
             this->hide();
             rent sign;
             sign.setModal(true);
             sign.exec();
           }
           if(count>1)
               ui->label->setText("duplicate username and password");
           if(count<1)
               ui->label->setText("username or pass not correct");

        }
    }

}


void signup::on_checkBox_stateChanged(int )
{
    ui->lineEdit_2->setEchoMode(ui->checkBox->checkState() == Qt::Checked ? QLineEdit::Normal : QLineEdit::Password );
}

