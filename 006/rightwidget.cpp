#include "historywidget.h"
#include "logwidget.h"
#include "rightwidget.h"
#include "ui_rightwidget.h"

RightWidget::RightWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RightWidget)
{
    ui->setupUi(this);
    logWidget = new LogWidget(this);
    historyWidget = new HistoryWidget(this);
    ui->firstLayout->addWidget(logWidget);
    ui->secondLayout->addWidget(historyWidget);
}

RightWidget::~RightWidget()
{
    delete ui;
}
