#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QLabel>
#include <QLineEdit>
#include <QTableWidget>
#include <QWidget>

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();
private slots:
    void getItem(QTableWidgetItem *item);
private:
    QLabel *label;
    QLineEdit *lineEdit;
    QTableWidget *tblWidget;
};

#endif // MAINWIDGET_H
