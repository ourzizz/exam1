#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <QtWidgets/QStatusBar>
#include <QLabel>
#include <QListWidget>
#include <QObject>
#include "../examstatus/examstatus.h"
class StatusBar:public QStatusBar
{
    Q_OBJECT
    public:
    StatusBar(ExamStatus *examstatus);
    public slots:
    //void updateStatubar(QListWidget *contentsWidget,ExamStatus *examstatus); 
    void updateStatubar(); 
    private:
    QLabel *bartitle;
    QLabel *examnameLabel;
    QLabel *examkaochangLabel;
    QLabel *examkemuLabel;
    ExamStatus *examstatus;
    QListWidget *contentsWidget;
};

#endif
