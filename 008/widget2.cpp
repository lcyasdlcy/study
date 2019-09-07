#include "widget2.h"
#include "ui_widget2.h"
#include <QDebug>

Widget2::Widget2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget2)
{
    ui->setupUi(this);
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    qDebug()<<ui->dateTimeEdit->dateTime();
}

Widget2::~Widget2()
{
    delete ui;
}
