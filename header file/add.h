#ifndef ADD_H
#define ADD_H

#include <QDialog>
#include <QtSql>
#include<QtDebug>
#include<QFileInfo>


namespace Ui {
class add;
}

class add : public QDialog
{
    Q_OBJECT

public:
    explicit add(QWidget *parent = nullptr);
    ~add();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::add *ui;
     QSqlDatabase mydb;
};

#endif // ADD_H
