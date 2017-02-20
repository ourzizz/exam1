#include "examstatus.h"
#include <QMessageBox>
#include <QDebug>
ExamStatus::ExamStatus()
{
    status = new Status;
    status->ExamName = "";
    status->StatusArray[SelectExamStatus] = 0;
    status->StatusArray[KemuStatus] = 0;
    status->StatusArray[KaoshengBaomingStatus]=0;
    status->StatusArray[KaochangStatus]=0;
    status->StatusArray[JaoshiStatus] = 0;
    status->StatusArray[KaodianStatus] = 0;
}

void ExamStatus::SelectExam(QString exam_name)
{
    status->ExamName = exam_name;
    status->StatusArray[SelectExamStatus] = 1;
    query.clear();
    query.prepare("select count(*) from kemu where ex_name=?");
    query.addBindValue(exam_name);
    query.exec();
    query.next();
    if(0 == query.value(0))
    {//kemu还没有设置那考场这些信息就没有
        status->StatusArray[KemuStatus] = 0;
        status->StatusArray[KaoshengBaomingStatus]=0;
        status->StatusArray[KaochangStatus]=0;
        status->StatusArray[JaoshiStatus] = 0;
        Notify();
        return ;
    }
    else{
        status->StatusArray[KemuStatus] = 1;
        Notify();
    }

    query.clear();
    query.prepare("select count(*) from ksinfo_has_kemu where ex_name=?");
    query.addBindValue(exam_name);
    query.exec();
    query.next();
    if(0 == query.value(0).toInt())
    {
        status->StatusArray[KaoshengBaomingStatus]=0;
        status->StatusArray[KaochangStatus]=0;
        status->StatusArray[JaoshiStatus]= 0;
        return ;
    }
    else{
         status->StatusArray[KaoshengBaomingStatus]= 1;
    }

    query.clear();
    query.prepare("select count(*) from kaochang where ex_name=?");
    query.addBindValue(exam_name);
    query.exec();
    query.next();
    if(0 == query.value(0).toInt())
    {
        status->StatusArray[KaochangStatus]= 0;
        status->StatusArray[JaoshiStatus ]= 0;
        return ;
    }
    else{
        status->StatusArray[KaochangStatus] = 1;
    }


    query.clear();
    query.prepare("select count(*) from jiaoshi where ex_name=?");
    query.addBindValue(exam_name);
    query.exec();
    query.next();
    if(0 == query.value(0).toInt())
    {
        status->StatusArray[JaoshiStatus] = 0;
    }
    else{
        status->StatusArray[JaoshiStatus] = 1;
    }
}
bool ExamStatus::GetStatus(mystatus set)
{
    return status->StatusArray[set];
}

void ExamStatus::SetStatus(mystatus set,bool stu)
{
    status->StatusArray[set] = stu;
    Notify();
}

void ExamStatus::Attach(Observer *pObserver)
{
    pagelist.push_back(pObserver);
}

void ExamStatus::Detach(Observer *pObserver)
{
    pagelist.removeOne(pObserver);
}
void ExamStatus::Notify()
{
    for (int i = 0; i < pagelist.size(); ++i) {
        (pagelist.at(i))->loadpage(status);
    }
}
QString ExamStatus::GetExamName()
{
    return status->ExamName;
}


