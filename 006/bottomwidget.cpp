#include "bottomwidget.h"
#include "ui_bottomwidget.h"

BottomWidget::BottomWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BottomWidget)
{
    ui->setupUi(this);
}

BottomWidget::~BottomWidget()
{
    delete ui;
}
