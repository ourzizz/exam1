#ifndef EXAMSTATUS_H
#define EXAMSTATUS_H
#include <QtSql>
#include <QList>
#include "../subject.h"
#include "../observer.h"
enum status{
    SelectExamStatus,/*{{{*/
    KemuStatus,
    KaoshengBaomingStatus,
    KaochangStatus,
    JaoshiStatus,
    KaodianStatus/*}}}*/
};
class ExamStatus:public SubJect
{
    //Q_OBJECT
    private:
        QString exam_name;
        QSqlQuery query;
    //public slots:
    public:
        void SelectExam(QString exam_name);
        ExamStatus();
        bool StatusArray[6];
        QString GetExamName();
        bool GetStatus(status set);
        void SetStatus(status set,bool stu);

        QList<Observer *> pagelist;
        void Attach(Observer *pObserver);
        void Detach(Observer *pObserver);
        void Notify(bool *StatusArray);
};
#endif // EXAMSTATUS_H
