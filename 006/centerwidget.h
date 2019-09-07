#ifndef CENTERWIDGET_H
#define CENTERWIDGET_H

#include <QWidget>

namespace Ui {
class CenterWidget;
}

class CenterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CenterWidget(QWidget *parent = nullptr);
    ~CenterWidget();

private:
    Ui::CenterWidget *ui;
    QWidget *videoWidget;
    QWidget *vehInfoWidget;
    QWidget *functionWidget;
};

#endif // CENTERWIDGET_H
