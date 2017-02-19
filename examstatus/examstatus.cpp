#include "examstatus.h"
#include <QMessageBox>
#include <QDebug>
ExamStatus::ExamStatus()
{
    exam_name = "";
    StatusArray[SelectExamStatus] = 0;
    StatusArray[KemuStatus] = 0;
    StatusArray[KaoshengBaomingStatus]=0;
    StatusArray[KaochangStatus]=0;
    StatusArray[JaoshiStatus] = 0;
    StatusArray[KaodianStatus] = 0;
}

void ExamStatus::SelectExam(QString exam_name)
{
    this->exam_name = exam_name;
    StatusArray[SelectExamStatus] = 1;
    query.clear();
    query.prepare("select count(*) from kemu where ex_name=?");
    query.addBindValue(exam_name);
    query.exec();
    query.next();
    if(0 == query.value(0))
    {//kemu还没有设置那考场这些信息就没有
        StatusArray[KemuStatus] = 0;
        StatusArray[KaoshengBaomingStatus]=0;
        StatusArray[KaochangStatus]=0;
        StatusArray[JaoshiStatus] = 0;
        return ;
    }
    else{
        StatusArray[KemuStatus] = 1;
    }

    query.clear();
    query.prepare("select count(*) from ksinfo_has_kemu where ex_name=?");
    query.addBindValue(exam_name);
    query.exec();
    query.next();
    if(0 == query.value(0).toInt())
    {
        StatusArray[KaoshengBaomingStatus]=0;
        StatusArray[KaochangStatus]=0;
        StatusArray[JaoshiStatus]= 0;
        return ;
    }
    else{
         StatusArray[KaoshengBaomingStatus]= 1;
    }

    query.clear();
    query.prepare("select count(*) from kaochang where ex_name=?");
    query.addBindValue(exam_name);
    query.exec();
    query.next();
    if(0 == query.value(0).toInt())
    {
        StatusArray[KaochangStatus]= 0;
        StatusArray[JaoshiStatus ]= 0;
        return ;
    }
    else{
        StatusArray[KaochangStatus] = 1;
    }


    query.clear();
    query.prepare("select count(*) from jiaoshi where ex_name=?");
    query.addBindValue(exam_name);
    query.exec();
    query.next();
    if(0 == query.value(0).toInt())
    {
        StatusArray[JaoshiStatus] = 0;
    }
    else{
        StatusArray[JaoshiStatus] = 1;
    }
    Notify(StatusArray);
}
bool ExamStatus::GetStatus(status set)
{
    return StatusArray[set];
}

void ExamStatus::SetStatus(status set,bool stu)
{
    StatusArray[set] = stu;
    Notify(StatusArray);
}
QString ExamStatus::GetExamName()
{
    return exam_name;
}

void ExamStatus::Attach(Observer *pObserver)
{
    pagelist.push_back(pObserver);
}

void ExamStatus::Detach(Observer *pObserver)
{
    pagelist.removeOne(pObserver);
}
void ExamStatus::Notify(bool *StatusArray)
{
    for (int i = 0; i < pagelist.size(); ++i) {
        (pagelist.at(i))->loadpage(StatusArray);
    }
}
