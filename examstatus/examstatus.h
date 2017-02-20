#ifndef EXAMSTATUS_H
#define EXAMSTATUS_H
#include <QtSql>
#include <QList>
#include "../subject.h"
#include "../observer.h"
class ExamStatus:public SubJect
{
    private:
        QSqlQuery query;
    public:
        ExamStatus();
        Status *status;
        QString GetExamName();
        void SelectExam(QString exam_name);
        bool StatusArray[6];
        bool GetStatus(mystatus set);
        void SetStatus(mystatus set,bool stu);

        QList<Observer *> pagelist;
        void Attach(Observer *pObserver);
        void Detach(Observer *pObserver);
        void Notify();
};
#endif // EXAMSTATUS_H
