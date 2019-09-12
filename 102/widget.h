#ifndef WIDGET_H
#define WIDGET_H

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
private:
    void changeTextEditPalette();
private slots:
    void on_sliderRed_valueChanged(int value);

    void on_sliderGreen_valueChanged(int value);

    void on_sliderBlue_valueChanged(int value);

    void on_sliderAlpha_valueChanged(int value);

    void on_dial_valueChanged(int value);

    void on_radioButtonDec_clicked();

    void on_radioButtonBin_clicked();

    void on_radioButtonOct_clicked();

    void on_radioButtonHex_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
