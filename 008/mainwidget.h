#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

namespace Ui {
class MainWidget;
}
class QStandardItemModel;
class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private slots:
    void on_pushButtonAdd_clicked();

    void on_pushButtonDel_clicked();

private:
    Ui::MainWidget *ui;
    QStandardItemModel *model;
};

#endif // MAINWIDGET_H
