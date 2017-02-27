/********************************************************************************
** Form generated from reading UI file 'ksHp2484.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef KSHP2484_H
#define KSHP2484_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_5;
    QTableView *whitouImgView;
    QLineEdit *ksidEdit;
    QPushButton *findButton;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_4;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *inputButton;
    QPushButton *imgPathButton;
    QPushButton *manulButton;
    QSpacerItem *horizontalSpacer_3;
    QTableView *ksinfoView;
    QTableView *erroridView;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(1025, 885);
        layoutWidget = new QWidget(Form);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 30, 931, 821));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_5 = new QPushButton(layoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 2, 1, 1, 1);

        whitouImgView = new QTableView(layoutWidget);
        whitouImgView->setObjectName(QStringLiteral("whitouImgView"));

        gridLayout->addWidget(whitouImgView, 3, 1, 1, 3);

        ksidEdit = new QLineEdit(layoutWidget);
        ksidEdit->setObjectName(QStringLiteral("ksidEdit"));

        gridLayout->addWidget(ksidEdit, 0, 2, 1, 1);

        findButton = new QPushButton(layoutWidget);
        findButton->setObjectName(QStringLiteral("findButton"));

        gridLayout->addWidget(findButton, 0, 3, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_3, 2, 2, 1, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout_2->addWidget(pushButton_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        inputButton = new QPushButton(layoutWidget);
        inputButton->setObjectName(QStringLiteral("inputButton"));

        horizontalLayout->addWidget(inputButton);

        imgPathButton = new QPushButton(layoutWidget);
        imgPathButton->setObjectName(QStringLiteral("imgPathButton"));

        horizontalLayout->addWidget(imgPathButton);

        manulButton = new QPushButton(layoutWidget);
        manulButton->setObjectName(QStringLiteral("manulButton"));

        horizontalLayout->addWidget(manulButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        ksinfoView = new QTableView(layoutWidget);
        ksinfoView->setObjectName(QStringLiteral("ksinfoView"));

        gridLayout->addWidget(ksinfoView, 1, 0, 1, 4);

        erroridView = new QTableView(layoutWidget);
        erroridView->setObjectName(QStringLiteral("erroridView"));

        gridLayout->addWidget(erroridView, 3, 0, 1, 1);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(ksidEdit);
#endif // QT_NO_SHORTCUT

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("Form", "\346\234\252\344\270\212\344\274\240\347\205\247\347\211\207\347\232\204\350\200\203\347\224\237", Q_NULLPTR));
        findButton->setText(QApplication::translate("Form", "\346\237\245\346\211\276", Q_NULLPTR));
        label->setText(QApplication::translate("Form", "\350\276\223\345\205\245\345\247\223\345\220\215\346\237\245\346\211\276", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Form", "\346\240\241\345\257\271\350\272\253\344\273\275", Q_NULLPTR));
        inputButton->setText(QApplication::translate("Form", "excel\345\257\274\345\205\245\350\200\203\347\224\237\346\225\260\346\215\256", Q_NULLPTR));
        imgPathButton->setText(QApplication::translate("Form", "\346\214\207\345\256\232\347\205\247\347\211\207\350\267\257\345\276\204", Q_NULLPTR));
        manulButton->setText(QApplication::translate("Form", "\346\211\213\345\267\245\350\276\223\345\205\245", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // KSHP2484_H
