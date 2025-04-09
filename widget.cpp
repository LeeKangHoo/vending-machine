#include "widget.h"
#include "ui_widget.h"

#include <QMessageBox>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::changeMoney(int n){
    money += n;
    ui->lcdNumber->display(money);
    if (100 <= money){
        ui->pbCoffee->setEnabled(true);
    }
    else{
        ui->pbCoffee->setEnabled(false);
    }
    if (150 <= money){
        ui->pbTea->setEnabled(true);
    }
    else{
        ui->pbTea->setEnabled(false);
    }
    if (200 <= money){
        ui->pbMilk->setEnabled(true);
    }
    else{
        ui->pbMilk->setEnabled(false);
    }

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



