#include "bottomwidget.h"
#include "centerwidget.h"
#include "leftwidget.h"
#include "mainwidget.h"
#include "rightwidget.h"
#include "topwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    topWidget = new TopWidget(this);
    bottomWidget = new BottomWidget(this);
    leftWidget = new LeftWidget(this);
    centerWidget = new CenterWidget(this);
    rightWidget = new RightWidget(this);
    ui->headerLayout->addWidget(topWidget);
    ui->footerLayout->addWidget(bottomWidget);
    ui->leftLayout->addWidget(leftWidget);
    ui->centerLayout->addWidget(centerWidget);
    ui->rightLayout->addWidget(rightWidget);
}

MainWidget::~MainWidget()
{
    delete ui;
}
