#include "dialog1.h"
#include <QApplication>
#include <QColorDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog1 w;
//    QColorDialog w;
    w.show();

    return a.exec();
}
