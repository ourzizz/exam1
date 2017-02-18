#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "examstatus/examstatus.h"
#include "statusbar/statusbar.h"
#include "setexampage/setexampage.h"
#include "setkemupage/setkemupage.h"
#include "exlist/exlist.h"

QT_BEGIN_NAMESPACE
class QListWidget;
class QListWidgetItem;
class QStackedWidget;
QT_END_NAMESPACE

class MainPage : public QWidget
{
    Q_OBJECT

public:
    MainPage();

public slots:
    void changePage(QListWidgetItem *current, QListWidgetItem *previous);

private:
    //void createIcons();
    ExList *contentsWidget;
    StatusBar *statusBar;
    QStackedWidget *pagesWidget;
    ExamStatus *examstatus;
};
#endif
