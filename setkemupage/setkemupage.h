#ifndef SETKEMUPAGE_H
#define SETKEMUPAGE_H
#include <QDialog>
#include <QSqlTableModel>
#include "ui_setkemupage.h"
#include "examstatus/examstatus.h"
#include "../observer.h"
//#include "statusbar/statusbar.h"

class SetKemuPage:public QDialog,public Ui::Form,public Observer
{
    Q_OBJECT
    public:
        SetKemuPage (ExamStatus *examstatus,QWidget *parent=0);
    public slots:
        void SubmitChange();
        void NewKemu();
        void RemoveKemu();
    private:
        void loadpage(bool *StatusArray);
        ExamStatus *examstatus;
        QSqlTableModel *model;
        enum{
            km_name = 0,
            ex_name = 1,
            km_rs =2,
            km_sj_count =3,
            ks_start_time = 4,
            ks_end_time = 5,
            km_level = 6,
            km_hegefenshu = 7
        };
};
#endif
