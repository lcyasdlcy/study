#include "mywidget.h"
#include <QApplication>
#include <QCloseEvent>
#include <QMenu>

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(400, 300);
    this->setWindowTitle("测试系统托盘");
    tray = new QSystemTrayIcon(this);
    tray->setIcon(QIcon(QPixmap(":/image/1.jpg")));
    tray->show();
    connect(tray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(onTrayAction(QSystemTrayIcon::ActivationReason)));
    menu = new QMenu(this);
    restore = new QAction(this);
    restore->setText("显示窗口");
    menu->addAction(restore);
    connect(restore, SIGNAL(triggered()), this, SLOT(show()));
    quit = new QAction(this);
    quit->setText("退出程序");
    menu->addAction(quit);
    connect(quit, 	SIGNAL(triggered(bool)), qApp, SLOT(quit()));
    tray->setContextMenu(menu);
}

void MyWidget::closeEvent(QCloseEvent *event)
{
    this->hide();
    event->ignore();
}

void MyWidget::onTrayAction(QSystemTrayIcon::ActivationReason reason)
{
    if (reason == QSystemTrayIcon::DoubleClick)
        this->show();
}
