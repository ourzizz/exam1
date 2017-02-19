#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <QtWidgets/QStatusBar>
#include <QLabel>
#include <QListWidget>
#include <QObject>
#include "../examstatus/examstatus.h"
#include "../observer.h"

class StatusBar:public QStatusBar,public Observer
{
    Q_OBJECT

    public:
    StatusBar();
    void loadpage(bool *StatusArray);
    public slots:
    //void updateStatubar(QListWidget *contentsWidget,ExamStatus *examstatus); 
    void updateStatubar(); 
    private:
    QLabel *bartitle;
    QLabel *examnameLabel;
    QLabel *examkaochangLabel;
    QLabel *examkemuLabel;
    QListWidget *contentsWidget;

};

#endif
