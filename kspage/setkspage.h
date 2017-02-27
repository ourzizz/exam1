#ifndef SETKSPAGE_H
#define SETKSPAGE_H

#include "../observer.h"
#include "../examstatus/examstatus.h"
#include <QDialog>
#include "kspage.h"

class SetksPage:public QDialog,public Ui::Form,public Observer
{
    Q_OBJECT
public:
    SetksPage (ExamStatus *examstatus,QDialog *parent=0);
    void loadpage(Status *sts);
public slots:
private:
};

#endif
