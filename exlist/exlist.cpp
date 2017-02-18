#include <QtWidgets>
#include <QWidget>
#include <QDebug>
#include "exlist.h"
ExList::ExList(ExamStatus *examstatus)
{
    this->examstatus = examstatus;/*{{{*/
    this->setViewMode(QListView::IconMode);
    this->setIconSize(QSize(86, 64));
    this->setMovement(QListView::Free);
    this->setMaximumWidth(128);
    this->setMaximumHeight(3000);
    this->setSpacing(12);
    qDebug()<<examstatus;

    setExamPageButton = new QListWidgetItem(this);
    setExamPageButton->setIcon(QIcon(":/images/config.png"));
    setExamPageButton->setText(tr("考试维护"));
    setExamPageButton->setTextAlignment(Qt::AlignHCenter);
    setExamPageButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    SetExamKemuPage = new QListWidgetItem(this);
    if (!examstatus->GetStatus(KemuStatus)) {
        SetExamKemuPage->setIcon(QIcon(":/images/lock.png"));
    }
    else{
        SetExamKemuPage->setIcon(QIcon(":/images/kemu.png"));
    }

    SetExamKemuPage->setText(tr("考试科目管理"));
    SetExamKemuPage->setTextAlignment(Qt::AlignHCenter);
    SetExamKemuPage->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    KaoshengBaoMingPage = new QListWidgetItem(this);
    if (!examstatus->GetStatus(KaoshengBaomingStatus)) {
        KaoshengBaoMingPage->setIcon(QIcon(":/images/lock.png"));
    }
    else{
        KaoshengBaoMingPage->setIcon(QIcon(":/images/kaosheng.png"));
    }
    KaoshengBaoMingPage->setText(tr("考生报名管理"));
    KaoshengBaoMingPage->setTextAlignment(Qt::AlignHCenter);
    KaoshengBaoMingPage->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    KaoChangGuanLiPage = new QListWidgetItem(this);
    if (!examstatus->GetStatus(KaodianStatus)) {
        KaoChangGuanLiPage->setIcon(QIcon(":/images/lock.png"));
    }
    else{
        KaoChangGuanLiPage->setIcon(QIcon(":/images/kaodian.png"));
    }
    KaoChangGuanLiPage->setText(tr("考点管理"));
    KaoChangGuanLiPage->setTextAlignment(Qt::AlignHCenter);
    KaoChangGuanLiPage->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);/*}}}*/
}

void ExList::ChangeListImg()
{
    if (false == examstatus->GetStatus(SelectExamStatus)) {/*{{{*/
        SetExamKemuPage->setIcon(QIcon(":/images/lock.png"));
    }
    else{
        SetExamKemuPage->setIcon(QIcon(":/images/kemu.png"));
    }

    if (!examstatus->GetStatus(KemuStatus)) {
        KaoshengBaoMingPage->setIcon(QIcon(":/images/lock.png"));
    }
    else{
        KaoshengBaoMingPage->setIcon(QIcon(":/images/kaosheng.png"));
    }
    if (!examstatus->GetStatus(KaoshengBaomingStatus)) {
        KaoChangGuanLiPage->setIcon(QIcon(":/images/lock.png"));
    }
    else{
        KaoChangGuanLiPage->setIcon(QIcon(":/images/kaodian.png"));
    }/*}}}*/
}