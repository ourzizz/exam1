#ifndef SETEXAMPAGE
#define SETEXAMPAGE

#include <QWidget>
#include <QPushButton>
#include <QtWidgets>
#include <QtSql>
#include <QTableView>
#include "examstatus/examstatus.h"
//#include "../observer.h"
//#include "statusbar/statusbar.h"
//#include "exlist/exlist.h"

class SetExamPage : public QWidget
{
    Q_OBJECT

public:
    SetExamPage(ExamStatus *examstatus,QWidget *parent=0);
    void InitPage();

public slots:
    void SubmitChange();
    void NewExam();
    void RemoveExam();
    void SelectExamForGlobal();

private:
    ExamStatus *examstatus;
    QSqlTableModel *model;
    QTableView *view;
    QComboBox *serverCombo;
    QLabel *serverLabel;
    QGroupBox *configGroup;
    QPushButton *okButton;
    QPushButton *selectExamButton;
    QPushButton *newExamButton;
    QPushButton *deleteExamButton;
    enum{
        Exam_Code = 0,
        Exam_Name = 1,
        Exam_Leibie = 2,
        Exam_Date = 3,
        Exam_Ducument = 4
    };
};

#endif
