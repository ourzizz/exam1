#ifndef SETKEMUPAGE_H
#define SETKEMUPAGE_H
#include <QDialog>
#include <QGroupBox>
#include <QSqlTableModel>
#include <QLabel>
#include <QTableView>
//#include "ui_setkemupage.h"
#include "examstatus/examstatus.h"
#include "../observer.h"
#include "editkemuform.h"
//#include "statusbar/statusbar.h"

class SetKemuPage:public QWidget,public Observer
{
    Q_OBJECT
    public:
        void loadpage(Status *sts);
        SetKemuPage (ExamStatus *examstatus,QWidget *parent=0);
        public slots:
            //void SubmitChange();
            void editKemu();
            void updatekemuView();
            //void RemoveKemu();
    private:
            ExamStatus *examstatus;
            QString ExamName;
            bool KemuStatus;
            QLabel *kemuLabel;
            QGroupBox *kemubox;
            //QWidget kemuPanel;
            QTableView *kemuView;
            QSqlRelationalTableModel *kemuModel;
            QPushButton *editButton;
            //QPushButton closeButton;
};
#endif
