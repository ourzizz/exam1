#include <QtWidgets>
#include <QWidget>
#include <QMessageBox>
#include "setkemupage.h"

SetKemuPage::SetKemuPage(ExamStatus *examstatus,QWidget *parent)
    : QWidget(parent)
{
    this->examstatus = examstatus;
    this->ExamName="";
    Kemu_Status=false;
    kemubox = new QGroupBox("hello");
    kemuModel = new QSqlRelationalTableModel(this);
    kemuModel->setTable("kemu");
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
    
    editButton = new QPushButton("编辑科目",this);
    connect(editButton, SIGNAL(clicked()), this, SLOT(editKemu()));

    saveButton = new QPushButton("保存");
    connect(saveButton, SIGNAL(clicked()), this, SLOT(saveKemu()));

    kemuLabel = new QLabel(tr("考试科目"));
    kemuLabel->setBuddy(kemuView);

    QHBoxLayout *bottonlayout = new QHBoxLayout;
    QVBoxLayout *layout = new QVBoxLayout;

    bottonlayout->addStretch(1);
    bottonlayout->addWidget(editButton);
    bottonlayout->addWidget(saveButton);

    layout->addWidget(kemuLabel);
    layout->addWidget(kemuView);
    layout->addLayout(bottonlayout);
    kemubox->setLayout(layout);
    setLayout(layout);
}


void SetKemuPage::loadpage(Status *sts)
{

    if(this->ExamName != sts->ExamName)
    {
        this->ExamName = sts->ExamName;
        updatekemuView();
    }
}
/*slots fun define*/
void SetKemuPage::editKemu()
{
    QString kemuName="";
    QModelIndex index = kemuView->currentIndex();
    if (index.isValid()) {
        QSqlRecord record = kemuModel->record(index.row());
        kemuName = record.value(km_name).toString();
    }

    EditKemuForm form(this->ExamName,kemuName, this);
    form.exec();
    updatekemuView();
}

void SetKemuPage::updatekemuView()
{
    kemuModel->setFilter(QString("ex_name = \"%1\"").arg(this->ExamName));
    kemuModel->select();
    kemuView->setModel(kemuModel);
    kemuView->setCurrentIndex(kemuModel->index(0, 0));
}

void SetKemuPage::saveKemu()
{
    QSqlRecord record = kemuModel->record(0);
    if (record.value(km_name).toString() != "") {
        examstatus->SetStatus(KaoshengBaomingStatus,true);
        //examstatus->SetStatus(KemuStatus,true);
    }
    else{
        examstatus->SetStatus(KemuStatus,false);
    }
}
