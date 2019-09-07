#include "empwidget.h"
#include "mainwidget.h"
#include "widget1.h"
#include "widget2.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWidget w;
    EmpWidget w;
    w.show();

    return a.exec();
}
