#ifndef EMPWIDGET_H
#define EMPWIDGET_H

#include <QDateTimeEdit>
#include <QLabel>
#include <QPushButton>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QTableView>
#include <QWidget>

class EmpWidget : public QWidget
{
    Q_OBJECT
public:
    explicit EmpWidget(QWidget *parent = nullptr);

signals:

public slots:
    void onClickBtnShowAll();
    void onClickBtnFilter();
    void onClickBtnAdd();
    void onClickBtnDel();
    void onClickBtnSave();
    void sortByCol(int col);

private://ui
    QTableView *tableView;
    QLabel *lblName;
    QLineEdit *txtName;
    QLabel *lblAge;
    QLineEdit *txtAge;
    QLabel *lblEnTime;
    QDateTimeEdit *txtEnTime;
    QPushButton *btnShowAll;
    QPushButton *btnFilter;
    QPushButton *btnAdd;
    QPushButton *btnDel;
    QPushButton *btnSave;
private:
    QSqlDatabase *db;
    QSqlQuery *query;
    QSqlTableModel *model;
};

#endif // EMPWIDGET_H
