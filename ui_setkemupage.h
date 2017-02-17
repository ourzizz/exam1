/********************************************************************************
** Form generated from reading UI file 'setkemupage.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETKEMUPAGE_H
#define UI_SETKEMUPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QGroupBox *kemuBox;
    QTableView *tableView;
    QPushButton *ExcelInputButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *newKemuButton;
    QPushButton *deleteKemuButton;
    QSpacerItem *verticalSpacer;
    QPushButton *submitButton;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(847, 727);
        kemuBox = new QGroupBox(Form);
        kemuBox->setObjectName(QStringLiteral("kemuBox"));
        kemuBox->setGeometry(QRect(70, 150, 701, 391));
        tableView = new QTableView(kemuBox);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(30, 70, 521, 192));
        ExcelInputButton = new QPushButton(kemuBox);
        ExcelInputButton->setObjectName(QStringLiteral("ExcelInputButton"));
        ExcelInputButton->setGeometry(QRect(30, 30, 75, 23));
        widget = new QWidget(kemuBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(580, 70, 77, 191));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        newKemuButton = new QPushButton(widget);
        newKemuButton->setObjectName(QStringLiteral("newKemuButton"));

        verticalLayout->addWidget(newKemuButton);

        deleteKemuButton = new QPushButton(widget);
        deleteKemuButton->setObjectName(QStringLiteral("deleteKemuButton"));

        verticalLayout->addWidget(deleteKemuButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        submitButton = new QPushButton(widget);
        submitButton->setObjectName(QStringLiteral("submitButton"));

        verticalLayout->addWidget(submitButton);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", Q_NULLPTR));
        kemuBox->setTitle(QApplication::translate("Form", "\347\247\221\347\233\256\350\256\276\347\275\256", Q_NULLPTR));
        ExcelInputButton->setText(QApplication::translate("Form", "\344\273\216excel\345\257\274\345\205\245", Q_NULLPTR));
        newKemuButton->setText(QApplication::translate("Form", "\346\226\260\345\242\236\347\247\221\347\233\256", Q_NULLPTR));
        deleteKemuButton->setText(QApplication::translate("Form", "\345\210\240\351\231\244\347\247\221\347\233\256", Q_NULLPTR));
        submitButton->setText(QApplication::translate("Form", "\346\217\220\344\272\244\344\277\256\346\224\271", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETKEMUPAGE_H
