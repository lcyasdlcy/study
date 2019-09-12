#ifndef WIDGET_H
#define WIDGET_H

#include <QTimer>
#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();
    void on_timer_timeout();

    void on_pushButtonStart_clicked();

    void on_pushButtonStop_clicked();

private:
    Ui::Widget *ui;
    QTimer *timer;
    QTime *timeCounter;
};

#endif // WIDGET_H
