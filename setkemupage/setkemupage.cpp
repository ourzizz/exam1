#include <QtWidgets>
#include <QWidget>
#include <QMessageBox>
#include "setkemupage.h"

SetKemuPage::SetKemuPage(ExamStatus *examstatus,QWidget *parent)
    : QWidget(parent)
{
    this->examstatus = examstatus;
    KemuStatus=false;
    kemubox = new QGroupBox("hello");
    kemuModel = new QSqlRelationalTableModel(this);
    kemuModel->setTable("kemu");
    //kemuModel->setRelation(ex_name,
    // QSqlRelation("exam", "ex_name", "ex_name"));
    kemuModel->setHeaderData(km_name,Qt::Horizontal,tr("科目名称"));
    kemuModel->setHeaderData(ex_name,Qt::Horizontal,tr("考试名称"));
    kemuModel->setHeaderData(ks_start_time,Qt::Horizontal,tr("开始时间"));
    kemuModel->setHeaderData(ks_end_time,Qt::Horizontal,tr("结束时间"));
    kemuModel->setHeaderData(km_level,Qt::Horizontal,tr("考试级别"));
    kemuModel->setHeaderData(km_hegefenshu,Qt::Horizontal,tr("合格分数"));

    kemuView = new QTableView;
    kemuView->setModel(kemuModel);
    kemuView->setSelectionMode(QAbstractItemView::SingleSelection);
    kemuView->setSelectionBehavior(QAbstractItemView::SelectRows);
    kemuView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    kemuView->horizontalHeader()->setStretchLastSection(true);
    kemuView->setColumnHidden(km_rs, true);
    kemuView->setColumnHidden(km_sj_count, true);

    kemuLabel = new QLabel(tr("考试科目"));
    kemuLabel->setBuddy(kemuView);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(kemuLabel);
    layout->addWidget(kemuView);
    kemubox->setLayout(layout);
    setLayout(layout);
}

//void SetKemuPage::SubmitChange()/*{{{*/
//{
//model->database().transaction();
//if(model->submitAll())
//{
//model->database().commit();
//QMessageBox::critical(0,QObject::tr("Database success"), "submit成功");
//}
//else
//{
//model->database().rollback();
////QMessageBox::warning(0, QObject::tr("Database Error"), model->lastError().text());
//model->revertAll();//撤销修改
//}
//}
//void SetKemuPage::NewKemu()
//{
//int rowNum = model->rowCount();
//model->insertRow(rowNum);
////model->setData(model->index(rowNum,0));
//}
//void SetKemuPage::RemoveKemu()
//{
//int curRow = tableView->currentIndex().row();
//QString test =  "确定要删除<" + model->data(model->index(curRow,0)).toString()+">考试吗？";
//int ret = QMessageBox::warning(this, tr("要删除吗"),
////tr("本操作将删除当前选中的考试\n" "是否删除?"),
//test,
//QMessageBox::Yes | QMessageBox::Cancel, QMessageBox::Cancel);
//if(ret != QMessageBox::Cancel)
//{
//model->removeRow(curRow);
//}
//else
//{
//model->revertAll(); //如果不删除，则撤销
//}
//}/*}}}*/

void SetKemuPage::loadpage(Status *sts)
{
    if(this->KemuStatus != sts->StatusArray[KemuStatus])
    {
        //kemuModel->clear();
        QString exname = QString("ex_name = \"%1\"").arg(sts->ExamName);
        kemuModel->setFilter(exname);
        kemuModel->select();
        //kemuView->clearSpans();
        kemuView->setModel(kemuModel);
    }
}
