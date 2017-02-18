#ifndef EXAMSTATUS_H
#define EXAMSTATUS_H
#include <QtSql>
#include <Qlist>
enum status{
    SelectExamStatus,
    KemuStatus,
    KaoshengBaomingStatus,
    KaochangStatus,
    JaoshiStatus,
    KaodianStatus
};
class ExamStatus
{
    private:
        bool StatusArray[5];
        QString exam_name;
        QSqlQuery query;
    public:
        ExamStatus();
        void SelectExam(QString exam_name);
        bool GetStatus(status set);
        QString GetExamName();
        void SetStatus(status set,bool stu);
};
#endif // EXAMSTATUS_H
