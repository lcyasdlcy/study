#include "widget1.h"
#include "ui_widget1.h"
#include <QDebug>
#include <QSqlTableModel>

Widget1::Widget1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget1)
{
    ui->setupUi(this);
    _db = QSqlDatabase::addDatabase("QSQLITE");
    _db.setDatabaseName("demo.db");
    if (!_db.open()) {
        qDebug()<<"open db error";
        return;
    }
    _query = new QSqlQuery(_db);
    QString tblname = "student";
    QList<QString> tables = _db.tables();
    if (!tables.contains(tblname)) {
        QString creatsql = QString("create table %1(id integer primary key autoincrement,name char(10),age int)").arg(tblname);
        if (!_query->exec(creatsql)) {
            qDebug()<<"creat table error";
            return;
        }
        if (!_query->exec("insert into student(name,age) values('aaa',11),('bbb',12),('ccc',13)")) {
            qDebug()<<"insert table error";
            return;
        }
    }
    QSqlTableModel *model = new QSqlTableModel(this, _db);
    model->setTable(tblname);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
//    model->setHeaderData(0, Qt::Horizontal, "ID");
//    model->setHeaderData(1, Qt::Horizontal, "姓名");
//    model->setHeaderData(2, Qt::Horizontal, "年龄");
    model->sort(0, Qt::DescendingOrder);
    model->removeColumn(1);
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionsClickable(true);
    connect(ui->tableView->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(sortByCol(int)));
}

Widget1::~Widget1()
{
    delete ui;
}

void Widget1::sortByCol(int col)
{
    QSqlTableModel *model = dynamic_cast<QSqlTableModel *>(ui->tableView->model());
    bool ascending = (ui->tableView->horizontalHeader()->sortIndicatorSection()==col
                      && ui->tableView->horizontalHeader()->sortIndicatorOrder()==Qt::DescendingOrder);
    Qt::SortOrder order = ascending ? Qt::AscendingOrder : Qt::DescendingOrder;
    model->sort(col, order);
}

void Widget1::on_pushButtonSave_clicked()
{
    QSqlTableModel *model = dynamic_cast<QSqlTableModel*>(ui->tableView->model());
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

void Widget1::on_pushButtonAdd_clicked()
{
    QSqlTableModel *model = dynamic_cast<QSqlTableModel*>(ui->tableView->model());
    model->insertRow(model->rowCount());
}

void Widget1::on_pushButtonDel_clicked()
{
    QSqlTableModel *model = dynamic_cast<QSqlTableModel*>(ui->tableView->model());
    model->removeRow(ui->tableView->currentIndex().row());
    model->submitAll();
}
