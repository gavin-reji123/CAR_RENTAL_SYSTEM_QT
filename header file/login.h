#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QtSql>
#include<QtDebug>
#include<QFileInfo>
#include<QMediaPlayer>

QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class login : public QMainWindow
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    ~login();

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_pressed();

    void on_pushButton_3_released();

private:
    Ui::login *ui;
    QSqlDatabase mydb;
};
#endif // LOGIN_H
