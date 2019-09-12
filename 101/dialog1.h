#ifndef DIALOG1_H
#define DIALOG1_H

#include <QCheckBox>
#include <QDialog>
#include <QPlainTextEdit>
#include <QRadioButton>
#include <QWidget>

class Dialog1 : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog1(QWidget *parent = nullptr);

signals:

public slots:

private:
    QCheckBox   *chkBoxUnder;
    QCheckBox   *chkBoxItalic;
    QCheckBox   *chkBoxBold;
    QRadioButton    *rBtnBlack;
    QRadioButton    *rBtnRed;
    QRadioButton    *rBtnBlue;
    QPlainTextEdit  *txtEdit;
    QPushButton     *btnOK;
    QPushButton     *btnCancel;
    QPushButton     *btnClose;
    void    initUI();//UI 创建与初始化
    void    initSignalSlots();//初始化信号与槽的链接
private slots:
    void on_chkBoxUnder(bool checked); //Underline 的clicked(bool)信号的槽函数
    void on_chkBoxItalic(bool checked);//Italic 的clicked(bool)信号的槽函数
    void on_chkBoxBold(bool checked); //Bold 的clicked(bool)信号的槽函数
    void setTextFontColor(); //设置字体颜色
};

#endif // DIALOG1_H
