/********************************************************************************
** Form generated from reading UI file 'ks.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KS_H
#define UI_KS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *manulButton;
    QPushButton *imgPathButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *inputButton;
    QLabel *label;
    QPushButton *findButton;
    QLineEdit *ksidEdit;
    QTableView *ksinfoView;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_5;
    QSpacerItem *horizontalSpacer_2;
    QTableView *whitouImgView;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_4;
    QSpacerItem *horizontalSpacer;
    QTableView *erroridView;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(1024, 878);
        widget = new QWidget(Form);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(21, 20, 891, 462));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        graphicsView = new QGraphicsView(widget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 1, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        manulButton = new QPushButton(widget);
        manulButton->setObjectName(QStringLiteral("manulButton"));

        horizontalLayout->addWidget(manulButton);

        imgPathButton = new QPushButton(widget);
        imgPathButton->setObjectName(QStringLiteral("imgPathButton"));

        horizontalLayout->addWidget(imgPathButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        inputButton = new QPushButton(widget);
        inputButton->setObjectName(QStringLiteral("inputButton"));

        horizontalLayout->addWidget(inputButton);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        findButton = new QPushButton(widget);
        findButton->setObjectName(QStringLiteral("findButton"));

        horizontalLayout->addWidget(findButton);

        ksidEdit = new QLineEdit(widget);
        ksidEdit->setObjectName(QStringLiteral("ksidEdit"));

        horizontalLayout->addWidget(ksidEdit);


        verticalLayout->addLayout(horizontalLayout);

        ksinfoView = new QTableView(widget);
        ksinfoView->setObjectName(QStringLiteral("ksinfoView"));

        verticalLayout->addWidget(ksinfoView);


        verticalLayout_4->addLayout(verticalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        horizontalLayout_3->addWidget(pushButton_5);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        whitouImgView = new QTableView(widget);
        whitouImgView->setObjectName(QStringLiteral("whitouImgView"));

        verticalLayout_2->addWidget(whitouImgView);


        horizontalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout_2->addWidget(pushButton_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_2);

        erroridView = new QTableView(widget);
        erroridView->setObjectName(QStringLiteral("erroridView"));

        verticalLayout_3->addWidget(erroridView);


        horizontalLayout_4->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_4);


        gridLayout->addLayout(verticalLayout_4, 0, 0, 1, 1);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(ksidEdit);
#endif // QT_NO_SHORTCUT

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", Q_NULLPTR));
        manulButton->setText(QApplication::translate("Form", "\346\211\213\345\267\245\350\276\223\345\205\245", Q_NULLPTR));
        imgPathButton->setText(QApplication::translate("Form", "\346\214\207\345\256\232\347\205\247\347\211\207\350\267\257\345\276\204", Q_NULLPTR));
        inputButton->setText(QApplication::translate("Form", "excel\345\257\274\345\205\245\350\200\203\347\224\237\346\225\260\346\215\256", Q_NULLPTR));
        label->setText(QApplication::translate("Form", "\350\276\223\345\205\245\345\247\223\345\220\215\346\237\245\346\211\276", Q_NULLPTR));
        findButton->setText(QApplication::translate("Form", "\346\237\245\346\211\276", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("Form", "\346\234\252\344\270\212\344\274\240\347\205\247\347\211\207\347\232\204\350\200\203\347\224\237", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Form", "\346\240\241\345\257\271\350\272\253\344\273\275", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KS_H
