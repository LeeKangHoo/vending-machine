#include "widget.h"
#include "ui_widget.h"

#include <QMessageBox>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    changeMoney(0);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::changeMoney(int n){
    money += n;
    ui->lcdNumber->display(money);

    ui->pbCoffee->setEnabled(100 <= money);
    ui->pbTea->setEnabled(150 <= money);
    ui->pbMilk->setEnabled(200 <= money);

}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}


void Widget::on_pb50_clicked()
{
    changeMoney(50);
}


void Widget::on_pb100_clicked()
{
    changeMoney(100);
}


void Widget::on_pb500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbReset_clicked()
{
    QString msg = QString("500won:%1\n100won:%2\n50won:%3\n10won:%4").arg(money/500).arg((money%500)/100).arg((money%100)/50).arg((money%50)/10);
    QMessageBox::information(nullptr,"Reset",msg);
    changeMoney(-money);
}



