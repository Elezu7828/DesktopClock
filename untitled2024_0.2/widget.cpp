#include "widget.h"
#include "ui_widget.h"
#include<QMessageBox>
#include<QCloseEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("NwafuClock");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{

}

void Widget::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButtons button;
    button = QMessageBox::question(this,"tip","exit?",QMessageBox::Yes|QMessageBox::No);
    if(button == QMessageBox::Yes)
    {
        event -> accept();
    }
    else {
        event -> ignore();
    }

}
