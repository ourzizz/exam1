#include "statusbar.h"
StatusBar::StatusBar(ExamStatus *examstatus)
{
    this->examstatus = examstatus;
    bartitle = new QLabel("状态导航");
    examnameLabel = new QLabel("当前没有选择考试");
    bartitle->setMinimumSize(examnameLabel->sizeHint());
    examnameLabel->setIndent(3);

    this->addWidget(bartitle);
    this->addWidget(examnameLabel);
}
void StatusBar::updateStatubar()
{
    if(examstatus->GetExamName() != "")
    {
        examnameLabel->setText(examstatus->GetExamName());
    }
    //examnameLabel->setText("Helloworld");
}
