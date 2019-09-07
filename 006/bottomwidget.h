#ifndef BOTTOMWIDGET_H
#define BOTTOMWIDGET_H

#include <QWidget>

namespace Ui {
class BottomWidget;
}

class BottomWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BottomWidget(QWidget *parent = nullptr);
    ~BottomWidget();

private:
    Ui::BottomWidget *ui;
};

#endif // BOTTOMWIDGET_H
