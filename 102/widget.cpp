#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeTextEditPalette()
{
    QColor color;
    int R = ui->sliderRed->value();
    int G = ui->sliderGreen->value();
    int B = ui->sliderBlue->value();
    int alpha = ui->sliderAlpha->value();
    color.setRgb(R, G, B, alpha);
    QPalette pal = ui->textEdit->palette();
    pal.setColor(QPalette::Base, color);
    ui->textEdit->setPalette(pal);
}

void Widget::on_sliderRed_valueChanged(int value)
{
    Q_UNUSED(value);
    changeTextEditPalette();
}

void Widget::on_sliderGreen_valueChanged(int value)
{
    Q_UNUSED(value);
    changeTextEditPalette();
}

void Widget::on_sliderBlue_valueChanged(int value)
{
    Q_UNUSED(value);
    changeTextEditPalette();
}

void Widget::on_sliderAlpha_valueChanged(int value)
{
    Q_UNUSED(value);
    changeTextEditPalette();
}

void Widget::on_dial_valueChanged(int value)
{
    ui->lcdNumber->display(value);
}

void Widget::on_radioButtonDec_clicked()
{
    ui->lcdNumber->setDigitCount(3);
    ui->lcdNumber->setDecMode();
}

void Widget::on_radioButtonBin_clicked()
{
    ui->lcdNumber->setDigitCount(8);
    ui->lcdNumber->setBinMode();
}

void Widget::on_radioButtonOct_clicked()
{
    ui->lcdNumber->setDigitCount(4);
    ui->lcdNumber->setOctMode();
}

void Widget::on_radioButtonHex_clicked()
{
    ui->lcdNumber->setDigitCount(3);
    ui->lcdNumber->setHexMode();
}
