#ifndef STATUS_H
#define STATUS_H
#include <QString>
enum mystatus{
    SelectExamStatus,/*{{{*/
    KemuStatus,
    KaoshengBaomingStatus,
    KaochangStatus,
    JaoshiStatus,
    KaodianStatus/*}}}*/
};
struct Status{
    QString ExamName;
    bool StatusArray[6];
};
#endif // STATUS_H
