#ifndef RENT_H
#define RENT_H

#include <QDialog>
#include<QMediaPlayer>
#include <QtSql>
#include<QtDebug>
#include<QFileInfo>

namespace Ui {
class rent;
}

class rent : public QDialog
{
    Q_OBJECT

public:
    explicit rent(QWidget *parent = nullptr);
    ~rent();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::rent *ui;
    QSqlDatabase mydb;
};

#endif // RENT_H
