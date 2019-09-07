#include "vehinfowidget.h"
#include "ui_vehinfowidget.h"

VehInfoWidget::VehInfoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VehInfoWidget)
{
    ui->setupUi(this);
}

VehInfoWidget::~VehInfoWidget()
{
    delete ui;
}
