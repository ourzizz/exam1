#include "statusbar.h"
StatusBar::StatusBar()
{
    //this->examstatus = examstatus;
    bartitle = new QLabel("当前考试------->");
    examnameLabel = new QLabel("当前没有选择考试");
    examkemuLabel = new QLabel("科目");
    kaoshengLabel = new QLabel("考生");
    examkaochangLabel = new QLabel("考场");
    bartitle->setMinimumSize(examnameLabel->sizeHint());
    examnameLabel->setIndent(3);

    this->addWidget(bartitle);
    this->addWidget(examnameLabel);
    this->addWidget(examkemuLabel);
    this->addWidget(kaoshengLabel);
    this->addWidget(examkaochangLabel);
}

void StatusBar::updateStatubar()
{
    //这是个废弃函数，moc非常烦人，报错只能先加进来
}
void StatusBar::loadpage(Status *sts)
{
    examnameLabel->setText(sts->ExamName);

    if(!sts->StatusArray[KemuStatus])
    {
        examkemuLabel->setText("未设置科目");
    }
    else
    {
        examkemuLabel->setText("科目已经设置");
    }

    if(!sts->StatusArray[KaoshengBaomingStatus])
    {
        kaoshengLabel->setText("没有报名数据");
    }
    else
    {
        kaoshengLabel->setText("已导入报名数据");
    }
    if(!sts->StatusArray[KaodianStatus])
    {
        examkaochangLabel->setText("没有可用的考点");
    }
    else
    {
        examkaochangLabel->setText("请设置考点");
    }
}
