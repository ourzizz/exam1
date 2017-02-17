#include "statusbar.h"
StatusBar::StatusBar(ExamStatus *examstatus)
{
    this->examstatus = examstatus;
    bartitle = new QLabel("当前考试------->");
    examnameLabel = new QLabel("当前没有选择考试");
    examkemuLabel = new QLabel("当前考试未设置科目");
    bartitle->setMinimumSize(examnameLabel->sizeHint());
    examnameLabel->setIndent(3);

    this->addWidget(bartitle);
    this->addWidget(examnameLabel);
    this->addWidget(examkemuLabel);
}
void StatusBar::updateStatubar()
{
    if(examstatus->GetExamName() != "")
    {
        examnameLabel->setText(examstatus->GetExamName());
    }
    else
    {
        return ;
    }
    if(examstatus->GetStatus(KemuStatus) != false)
    {
        examkemuLabel->setText("科目已经设置");
    }
    else
    {
        examkemuLabel->setText("当前考试未设置科目");
    }
}
