#ifndef VEHINFOWIDGET_H
#define VEHINFOWIDGET_H

#include <QWidget>

namespace Ui {
class VehInfoWidget;
}

class VehInfoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit VehInfoWidget(QWidget *parent = nullptr);
    ~VehInfoWidget();

private:
    Ui::VehInfoWidget *ui;
};

#endif // VEHINFOWIDGET_H
