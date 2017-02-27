#include <QWidget>
#include "setkspage.h"
SetksPage::SetksPage (ExamStatus *examstatus,QDialog *parent)
    : QDialog(parent)
{
    setupUi(this);
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(layoutWidget);
    setLayout(mainLayout);
}
void SetksPage::loadpage(Status *sts)
{
}
