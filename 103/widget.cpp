#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    timeCounter = new QTime();
    timer->stop();
    timer->setInterval(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(on_timer_timeout()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QDateTime curDateTime = QDateTime::currentDateTime();
    ui->timeEdit->setTime(curDateTime.time());
    ui->dateEdit->setDate(curDateTime.date());
    ui->dateTimeEdit->setDateTime(curDateTime);
}

void Widget::on_timer_timeout()
{
    QTime curTime = QTime::currentTime();
    ui->lcdHour->display(curTime.hour());
    ui->lcdMinute->display(curTime.minute());
    ui->lcdSecond->display(curTime.second());
    int val = ui->progressBar->value();
    val++;
    if (val > 100)
        val = 0;
    ui->progressBar->setValue(val);
    int tmMsec = timeCounter->elapsed();
    int sec = tmMsec / 1000;
    int ms = tmMsec % 1000;
    QString str = QString::asprintf("流逝时间：%d秒%d毫秒", sec, ms);
    ui->labelElapse->setText(str);
}

void Widget::on_pushButtonStart_clicked()
{
    timer->start();
    timeCounter->start();
    ui->pushButtonStart->setEnabled(false);
    ui->pushButtonStop->setEnabled(true);
}

void Widget::on_pushButtonStop_clicked()
{
    timer->stop();
    ui->pushButtonStart->setEnabled(true);
    ui->pushButtonStop->setEnabled(false);
}
