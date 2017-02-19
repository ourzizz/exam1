#ifndef EXQLISTWIDGET_H
#define EXQLISTWIDGET_H

#include <QWidget>
#include <QListWidgetItem>
#include <QListWidget>
#include "../examstatus/examstatus.h"
#include "../observer.h"
//QT_BEGIN_NAMESPACE
//class QListWidget;
//class QListWidgetItem;
//QT_END_NAMESPACE

class ExList:public QListWidget,public Observer
{
    Q_OBJECT
public:
    void loadpage(bool *StatusArray);
    ExList();

//public slots:
    //void ChangeListImg();//疑问从外面传过来的status指针是同步变化的吗,先用this里面的指针试试

private:
    QListWidgetItem *setExamPageButton;
    QListWidgetItem *SetExamKemuPage;
    QListWidgetItem *KaoshengBaoMingPage;
    QListWidgetItem *KaoChangGuanLiPage;
};
#endif
