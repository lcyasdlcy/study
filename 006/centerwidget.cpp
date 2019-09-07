#include "centerwidget.h"
#include "functionwidget.h"
#include "ui_centerwidget.h"
#include "vehinfowidget.h"
#include "videowidget.h"

CenterWidget::CenterWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CenterWidget)
{
    ui->setupUi(this);
    videoWidget = new VideoWidget;
    vehInfoWidget = new VehInfoWidget;
    functionWidget = new FunctionWidget;
    ui->firstLayout->addWidget(videoWidget);
    ui->secondLayout->addWidget(vehInfoWidget);
    ui->thridLayout->addWidget(functionWidget);
}

CenterWidget::~CenterWidget()
{
    delete ui;
}
