#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private:
    Ui::MainWidget *ui;
    QWidget *topWidget;
    QWidget *bottomWidget;
    QWidget *leftWidget;
    QWidget *centerWidget;
    QWidget *rightWidget;
};

#endif // MAINWIDGET_H
