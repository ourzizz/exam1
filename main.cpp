#include <QApplication>
#include <QtSql>
#include <QMessageBox>
#include "mainpage.h"

bool connectiondatabes()  
{  
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");  
    //db.setHostName("192.168.1.107");
    db.setHostName("192.168.15.233");
    db.setDatabaseName("mydb");
    db.setUserName("root");  
    db.setPassword("123123");  
    if (!db.open()) {
        QMessageBox::warning(0, QObject::tr("Database Error"),
                             db.lastError().text());
        return false;
    }
    return true;
}  

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Q_INIT_RESOURCE(exampage);
    connectiondatabes();
    app.setApplicationDisplayName("毕节人事考试系统");
    MainPage mainpage;
    mainpage.showMaximized();
    return app.exec();
}

