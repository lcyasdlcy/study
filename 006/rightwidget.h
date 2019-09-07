#ifndef RIGHTWIDGET_H
#define RIGHTWIDGET_H

#include <QWidget>

namespace Ui {
class RightWidget;
}

class RightWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RightWidget(QWidget *parent = nullptr);
    ~RightWidget();

private:
    Ui::RightWidget *ui;
    QWidget *logWidget;
    QWidget *historyWidget;
};

#endif // RIGHTWIDGET_H
