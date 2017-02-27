#include <QtWidgets>
#include "mainpage.h"
#include "exlist/exlist.h"
#include <QDebug>
MainPage::MainPage()
{
    statusBar = new StatusBar;
    examstatus = new ExamStatus;
    contentsWidget = new ExList();

    pagesWidget = new QStackedWidget;
    setexampage = new SetExamPage(examstatus);
    setkemupage = new SetKemuPage(examstatus);
    setkspage = new SetksPage(examstatus);

    pagesWidget->addWidget(setexampage);
    pagesWidget->addWidget(setkemupage);
    pagesWidget->addWidget(setkspage);

    examstatus->Attach(setkemupage);
    examstatus->Attach(statusBar);
    examstatus->Attach(setkspage);
    examstatus->Attach(contentsWidget);

    connect(contentsWidget, &QListWidget::currentItemChanged, this, &MainPage::changePage);

    QPushButton *closeButton = new QPushButton(tr("Close"));
    contentsWidget->setCurrentRow(0);
    connect(closeButton, &QAbstractButton::clicked, this, &QWidget::close);
    QHBoxLayout *horizontalLayout = new QHBoxLayout;
    horizontalLayout->addWidget(contentsWidget);
    horizontalLayout->addWidget(pagesWidget, 1);

    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    buttonsLayout->addStretch(1);
    buttonsLayout->addWidget(closeButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(statusBar);
    mainLayout->addLayout(horizontalLayout);
    //mainLayout->addStretch(1);
    mainLayout->addSpacing(12);
    mainLayout->addLayout(buttonsLayout);
    setLayout(mainLayout);

    setWindowTitle(tr("欢迎使用"));/*}}}*/
    setWindowIcon(QIcon(":/images/icon.png")); //设置窗体标题上的图标
}

void MainPage::changePage(QListWidgetItem *current, QListWidgetItem *previous)
{
    if (!current)
        current = previous;
    pagesWidget->setCurrentIndex(contentsWidget->row(current));
}
