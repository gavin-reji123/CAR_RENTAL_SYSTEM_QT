#include "login.h"
#include "ui_login.h"
#include"signup.h"
login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
    mydb= QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/new/amma.db");
    if(!mydb.open())
       ui->label->setText("failed connection");
    else
      ui->label->setText("connected..");
    QMediaPlayer*player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/acer/Desktop/wet.mp3"));
    player->setVolume(50);
    player->play();

}

login::~login()
{
    delete ui;
}

void login::on_pushButton_2_clicked()
{
    this->destroy();
    this->hide();
    signup sign;
    sign.setModal(true);
    sign.exec();
}


void login::on_pushButton_clicked()
{
     QString name,email,username,password,state,country,temp,temp1;
     QSqlQuery qry;
     bool upper=0,lower=0,digit=0,symbol=0;
     int i;
     name=ui->lineEdit->text();
     email=ui->lineEdit_2->text();
     username=ui->lineEdit_3->text();
     password=ui->lineEdit_4->text();
     state=ui->lineEdit_5->text();
     country=ui->lineEdit_6->text();
     temp=ui->lineEdit_2->text();
     temp1=ui->lineEdit_6->text();
     bool a=temp.contains("@gmail.com");
     bool b=temp.contains("@hotmail.com");
     bool c=temp.contains("@yahoo.com");
     bool d=temp.contains("@cuchd.in");
     bool e=temp1.contains("usa");
     if(!mydb.isOpen()){
         qDebug()<<"daatabase failed ";
         return;
        }

         for(i=0;i<password.length();i++)
            {
                if(password[i]>=97 && password[i]<=122)
                    {
                       lower=1;
                    }
                else if(password[i]>=65 && password[i]<=90)
                   {
                       upper=1;
                   }
                else if(password[i]>=48 && password[i]<=57)
                   {
                        digit=1;
                   }
                else
                    symbol=1;
            }
         if(username==0 && name==0 && email==0 && password==0 && state==0 && country==0)
          {
               ui->label->setText("please enter all values !!!");
          }
         else if(e==0)
         {
             ui->label->setText("please enter country as usa!");
         }
         else if(a==0 && b==0 && c==0 && d==0)
         {
              ui->label->setText("please enter valid email id !!!");
         }
         else if(name==0)
         {
              ui->label->setText("please enter name !!!");
         }
         else if(email==0)
         {
              ui->label->setText("please enter email !!!");
         }
         else if(password==0)
         {
              ui->label->setText("please enter password !!!");
         }
         else if(state==0)
         {
              ui->label->setText("please enter state !!!");
         }
         else if(country==0)
         {
              ui->label->setText("please enter country !!!");
         }
         else if(password.length() < 4)
         {
             ui->label->setText("your pass must be atlest 4 charecter! ");
         }
         else if(upper==0)
         {
             ui->label->setText("Enter one upper case in password !!!");
         }
         else if(lower==0)
         {
             ui->label->setText("Enter one lower case in password !!!");
         }
         else if(digit==0)
         {
             ui->label->setText("Enter one digit in password !!!");
         }
         else if(symbol==0)
         {
             ui->label->setText("Enter one special charecter in password !!!");
         }
     else if(qry.exec("select * from amma where username='"+username+"'"))
     {
         if(qry.next()==true)
         {
             ui->label->setText("This user already exist");
         }
         QString strPw = ui->lineEdit_4->text();
         QByteArray baPw = strPw.toUtf8();
         for (int i = 0;i<baPw.size();i++)
         {
                  baPw [i] = baPw [i] + 2;
         }
         strPw = baPw;
         password = strPw;
         if(qry.next()==false)
         {
             if(qry.exec("insert into amma (name,email,username,password,state,country) values ('"+name+"','"+email+"','"+username+"','"+password+"','"+state+"','"+country+"')"))
                          {
                              ui->label->setText("thank you!!,go to sign in procedure");
                          }
         }

     }   



}



void login::on_pushButton_3_pressed()
{
    ui->lineEdit_4->setEchoMode(QLineEdit::Normal);
}


void login::on_pushButton_3_released()
{
    ui->lineEdit_4->setEchoMode(QLineEdit::Password);
}

