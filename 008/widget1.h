#ifndef WIDGET1_H
#define WIDGET1_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QWidget>

namespace Ui {
class Widget1;
}

class Widget1 : public QWidget
{
    Q_OBJECT

public:
    explicit Widget1(QWidget *parent = nullptr);
    ~Widget1();

private slots:
    void sortByCol(int col);
    void on_pushButtonSave_clicked();

    void on_pushButtonAdd_clicked();

    void on_pushButtonDel_clicked();

private:
    Ui::Widget1 *ui;
    QSqlDatabase _db;
    QSqlQuery *_query;
};

#endif // WIDGET1_H
