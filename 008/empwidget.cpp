#include "empwidget.h"

#include <QGridLayout>
#include <QLineEdit>
#include <QSqlQuery>
#include <QHeaderView>
#include <QDebug>
#include <QSqlRecord>

const QString CREAT_EMP_SQL = "create table %1(\
id integer primary key autoincrement,\
name char(10),\
age int,\
salary numeric(6,2),\
entime timestamp default (datetime(CURRENT_TIMESTAMP,'localtime')))";

QString tblname = "emp";

EmpWidget::EmpWidget(QWidget *parent) : QWidget(parent)
{
    tableView = new QTableView;
    lblName = new QLabel("姓名");
    txtName = new QLineEdit();
    lblAge = new QLabel("年龄");
    txtAge = new QLineEdit();
    lblEnTime = new QLabel("入职时间");
    txtEnTime = new QDateTimeEdit();
    btnShowAll = new QPushButton("显示全部");
    btnFilter = new QPushButton("筛选");
    btnAdd = new QPushButton("增加");
    btnDel = new QPushButton("删除");
    btnSave = new QPushButton("保存修改");
    QGridLayout *layout1 = new QGridLayout;
    layout1->addWidget(lblName, 0, 0);
    layout1->addWidget(txtName, 0, 1);
//    layout1->addWidget(lblAge, 1, 0);
//    layout1->addWidget(txtAge, 1, 1);
//    layout1->addWidget(lblEnTime, 2, 0);
//    layout1->addWidget(txtEnTime, 2, 1);
    layout1->addWidget(tableView, 1, 0, 12, 2);
    layout1->addWidget(btnShowAll, 0, 2);
    layout1->addWidget(btnFilter, 1, 2);
    layout1->addWidget(btnAdd, 2, 2);
    layout1->addWidget(btnDel, 3, 2);
    layout1->addWidget(btnSave, 4, 2);
    this->setLayout(layout1);
    db = new QSqlDatabase;
    *db = QSqlDatabase::addDatabase("QSQLITE", tblname+"_db");
    db->setDatabaseName("test.db");
    if (!db->open()) {
        qDebug()<<"open db error";
        return;
    }
    query = new QSqlQuery(*db);
    qDebug()<<CREAT_EMP_SQL;
    query->prepare(CREAT_EMP_SQL.arg(tblname));
    if (!db->tables().contains(tblname)) {
        if (!query->exec()) {
            qDebug()<<"create table error";
            return;
        }
    }
    model = new QSqlTableModel(this, *db);
    model->setTable(tblname);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    tableView->setModel(model);
    tableView->horizontalHeader()->setSectionsClickable(true);

    connect(tableView->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(sortByCol(int)));
    connect(btnShowAll, SIGNAL(clicked(bool)), this, SLOT(onClickBtnShowAll()));
    connect(btnFilter, SIGNAL(clicked(bool)), this, SLOT(onClickBtnFilter()));
    connect(btnAdd, SIGNAL(clicked(bool)), this, SLOT(onClickBtnAdd()));
    connect(btnSave, SIGNAL(clicked(bool)), this, SLOT(onClickBtnSave()));
    connect(btnDel, SIGNAL(clicked(bool)), this, SLOT(onClickBtnDel()));
}

void EmpWidget::onClickBtnShowAll()
{
    model->setTable(tblname);
    model->select();
}

void EmpWidget::onClickBtnFilter()
{
    QString name = txtName->text();
    model->setFilter(QString("name like '%%1%'").arg(name));
    model->select();
}

void EmpWidget::onClickBtnAdd()
{
    QSqlRecord record = model->record();
    record.setValue("entime", QDateTime::currentDateTime());
//    model->insertRow(model->rowCount());
    model->insertRecord(model->rowCount(), record);
}

void EmpWidget::onClickBtnDel()
{
    model->removeRow(tableView->currentIndex().row());
    model->submitAll();
}

void EmpWidget::onClickBtnSave()
{
    model->database().transaction();
    if (model->submitAll()) {
        model->database().commit();
        qDebug()<<"save ok";
    } else {
        model->database().rollback();
        qDebug()<<"save error";
    }
    model->revertAll();
}

void EmpWidget::sortByCol(int col)
{
    bool ascending = (tableView->horizontalHeader()->sortIndicatorSection()==col
                      && tableView->horizontalHeader()->sortIndicatorOrder()==Qt::DescendingOrder);
    Qt::SortOrder order = ascending ? Qt::AscendingOrder : Qt::DescendingOrder;
    model->sort(col, order);
}
