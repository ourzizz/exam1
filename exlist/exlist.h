#ifndef EXQLISTWIDGET_H
#define EXQLISTWIDGET_H

#include <QWidget>
#include <QListWidgetItem>
#include <QListWidget>
#include "../examstatus/examstatus.h"
//QT_BEGIN_NAMESPACE
//class QListWidget;
//class QListWidgetItem;
//QT_END_NAMESPACE

class ExList : public QListWidget
{
    Q_OBJECT
public:
    ExList(ExamStatus *examstatus);

public slots:
    void ChangeListImg();//疑问从外面传过来的status指针是同步变化的吗,先用this里面的指针试试

private:
    QListWidgetItem *setExamPageButton;
    QListWidgetItem *SetExamKemuPage;
    QListWidgetItem *KaoshengBaoMingPage;
    QListWidgetItem *KaoChangGuanLiPage;
    ExamStatus *examstatus;
};
#endif
