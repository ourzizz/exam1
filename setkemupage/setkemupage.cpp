#include <QtWidgets>
#include <QWidget>
#include <QMessageBox>
#include "setkemupage.h"

SetKemuPage::SetKemuPage(ExamStatus *examstatus,QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);
    this->examstatus = examstatus;
    model = new QSqlTableModel(this);
    model->setTable("kemu");
    QString query= "ex_name = "  + examstatus->GetExamName();
    model->setFilter(query);
    model->setHeaderData(km_name,Qt::Horizontal,tr("科目名称"));
    model->setHeaderData(ex_name,Qt::Horizontal,tr("考试名称"));
    model->setHeaderData(ks_start_time,Qt::Horizontal,tr("开始时间"));
    model->setHeaderData(ks_end_time,Qt::Horizontal,tr("结束时间"));
    model->setHeaderData(km_level,Qt::Horizontal,tr("考试级别"));
    model->setHeaderData(km_hegefenshu,Qt::Horizontal,tr("合格分数"));
    model->select();
    tableView->setModel(model);
    tableView->setColumnHidden(km_rs, true);
    tableView->setColumnHidden(km_sj_count, true);

    tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    //tableView->setColumnHidden(Scooter_Id, true);
    tableView->resizeColumnsToContents();
    //tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect(newKemuButton, SIGNAL(clicked()), this, SLOT(NewKemu()));
    connect(deleteKemuButton, SIGNAL(clicked()), this, SLOT(RemoveKemu()));
    connect(submitButton, SIGNAL(clicked()), this, SLOT(SubmitChange()));
}
void SetKemuPage::SubmitChange()
{
    model->database().transaction();
    if(model->submitAll())
    {
        model->database().commit();
        QMessageBox::critical(0,QObject::tr("Database success"), "submit成功");
    }
    else
    {
        model->database().rollback();
        //QMessageBox::warning(0, QObject::tr("Database Error"), model->lastError().text());
        model->revertAll();//撤销修改
    }
}
void SetKemuPage::NewKemu()
{
    int rowNum = model->rowCount();
    model->insertRow(rowNum);
    //model->setData(model->index(rowNum,0));
}
void SetKemuPage::RemoveKemu()
{
    int curRow = tableView->currentIndex().row();
    QString test =  "确定要删除<" + model->data(model->index(curRow,0)).toString()+">考试吗？";
    int ret = QMessageBox::warning(this, tr("要删除吗"),
                                   //tr("本操作将删除当前选中的考试\n" "是否删除?"),
                                   test,
                                   QMessageBox::Yes | QMessageBox::Cancel, QMessageBox::Cancel);
    if(ret != QMessageBox::Cancel)
    {
        model->removeRow(curRow);
    }
    else
    {
        model->revertAll(); //如果不删除，则撤销
    }
}
