#include "mainwidget.h"
#include "ui_mainwidget.h"

#include <QStandardItemModel>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    model = new QStandardItemModel;
    model->setHorizontalHeaderItem(0, new QStandardItem("姓名"));
    model->setHorizontalHeaderItem(1, new QStandardItem("年龄"));
    model->setHorizontalHeaderItem(2, new QStandardItem("分数"));
    ui->tableView->setModel(model);
    model->setItem(0, 0, new QStandardItem("小明"));
    model->setItem(0, 1, new QStandardItem("11"));
    model->setItem(0, 2, new QStandardItem("88.8"));
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::on_pushButtonAdd_clicked()
{
    int cnt = model->rowCount();
    model->setItem(cnt, 0, new QStandardItem(ui->lineEditName->text()));
    model->setItem(cnt, 1, new QStandardItem(ui->lineEditAge->text()));
    model->setItem(cnt, 2, new QStandardItem(ui->lineEditScore->text()));
}

void MainWidget::on_pushButtonDel_clicked()
{
    QItemSelectionModel *selections = ui->tableView->selectionModel();
    QModelIndexList selected = selections->selectedIndexes();
    QMap<int, int> rowMap;
    foreach (QModelIndex index, selected)
    {
        rowMap.insert(index.row(), 0);
    }
    int rowToDel;
    QMapIterator<int, int> rowMapIterator(rowMap);
    rowMapIterator.toBack();
    while (rowMapIterator.hasPrevious())
    {
        rowMapIterator.previous();
        rowToDel = rowMapIterator.key();
        model->removeRow(rowToDel);
    }
}
