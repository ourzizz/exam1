#include <QtGui>
#include <QtSql>
#include <QLineEdit>
#include <QLabel>
#include <QTimeEdit>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QDataWidgetMapper>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QMessageBox>

#include "editkemuform.h"

EditKemuForm::EditKemuForm(QString ExamName,QString kemuName, QWidget *parent)
    : QDialog(parent)
{
    nameEdit = new QLineEdit;

    nameLabel = new QLabel(tr("Na&me:"));
    nameLabel->setBuddy(nameEdit);

    departmentComboBox = new QComboBox;

    exnameLabel = new QLabel(tr("Depar&tment:"));
    exnameLabel->setBuddy(departmentComboBox);

    hegeEdit = new QLineEdit;
    hegeEdit->setValidator(new QIntValidator(0, 99999, this));

    hegeLabel = new QLabel(tr("E&xtension:"));
    hegeLabel->setBuddy(hegeEdit);

    levelEdit = new QLineEdit;

    levelLabel = new QLabel(tr("&Email:"));
    levelLabel->setBuddy(levelEdit);

    startTimeEdit = new QTimeEdit;
    startTimeEdit->setCalendarPopup(true);

    endTimeEdit = new QTimeEdit;
    endTimeEdit->setCalendarPopup(true);

    //QTime today = QTime::currentTime();
    //startTimeEdit->setTimeRange(today.addDays(-90), today.addDays(90));

    startTimeLabel = new QLabel(tr("开始时间:"));
    startTimeLabel->setBuddy(startTimeEdit);

    endTimeLabel = new  QLabel(tr("结束时间:"));
    startTimeLabel->setBuddy(endTimeEdit);

    firstButton = new QPushButton(tr("<< 第一科目"));
    previousButton = new QPushButton(tr("< 上一科目"));
    nextButton = new QPushButton(tr("上一科目 >"));
    lastButton = new QPushButton(tr("最后一科>>"));

    addButton = new QPushButton(tr("&Add"));
    deleteButton = new QPushButton(tr("&Delete"));
    closeButton = new QPushButton(tr("&Close"));

    buttonBox = new QDialogButtonBox;
    buttonBox->addButton(addButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(deleteButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(closeButton, QDialogButtonBox::AcceptRole);

    tableModel = new QSqlRelationalTableModel(this);
    tableModel->setTable("kemu");
    //tableModel->setRelation(Employee_DepartmentId,
            //QSqlRelation("department", "id", "name"));
    tableModel->setFilter(QString("ex_name = \"%1\"").arg(ExamName));
    tableModel->setSort(ks_start_time, Qt::AscendingOrder);
    tableModel->select();

    QSqlTableModel *relationModel =
        tableModel->relationModel(ex_name);
    departmentComboBox->setModel(relationModel);
    departmentComboBox->setModelColumn(
            relationModel->fieldIndex("ex_name"));

    mapper = new QDataWidgetMapper(this);
    mapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);
    mapper->setModel(tableModel);
    mapper->setItemDelegate(new QSqlRelationalDelegate(this));
    mapper->addMapping(nameEdit, km_name);
    //mapper->addMapping(departmentComboBox, Employee_DepartmentId);
    mapper->addMapping(hegeEdit, km_hegefenshu);
    mapper->addMapping(levelEdit, km_level);
    mapper->addMapping(startTimeEdit, ks_start_time);
    mapper->addMapping(startTimeEdit, ks_end_time);

    if (ExamName != "") {
        for (int row = 0; row < tableModel->rowCount(); ++row) {
            QSqlRecord record = tableModel->record(row);
            if (record.value(km_name).toString() == ExamName) {
                mapper->setCurrentIndex(row);
                break;
            }
        }
    } else {
        mapper->toFirst();
    }

    connect(firstButton, SIGNAL(clicked()), mapper, SLOT(toFirst()));
    connect(previousButton, SIGNAL(clicked()),
            mapper, SLOT(toPrevious()));
    connect(nextButton, SIGNAL(clicked()), mapper, SLOT(toNext()));
    connect(lastButton, SIGNAL(clicked()), mapper, SLOT(toLast()));
    connect(addButton, SIGNAL(clicked()), this, SLOT(addEmployee()));
    connect(deleteButton, SIGNAL(clicked()),
            this, SLOT(deleteEmployee()));
    connect(closeButton, SIGNAL(clicked()), this, SLOT(accept()));

    QHBoxLayout *topButtonLayout = new QHBoxLayout;/*{{{*/
    topButtonLayout->setContentsMargins(20, 0, 20, 5);
    topButtonLayout->addStretch();
    topButtonLayout->addWidget(firstButton);
    topButtonLayout->addWidget(previousButton);
    topButtonLayout->addWidget(nextButton);
    topButtonLayout->addWidget(lastButton);
    topButtonLayout->addStretch();

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addLayout(topButtonLayout, 0, 0, 1, 3);
    mainLayout->addWidget(nameLabel, 1, 0);
    mainLayout->addWidget(nameEdit, 1, 1, 1, 2);
    mainLayout->addWidget(exnameLabel, 2, 0);
    mainLayout->addWidget(departmentComboBox, 2, 1, 1, 2);
    mainLayout->addWidget(hegeLabel, 3, 0);
    mainLayout->addWidget(hegeEdit, 3, 1);
    mainLayout->addWidget(levelLabel, 4, 0);
    mainLayout->addWidget(levelEdit, 4, 1, 1, 2);
    mainLayout->addWidget(startTimeLabel, 5, 0);
    mainLayout->addWidget(startTimeEdit, 5, 1);
    mainLayout->addWidget(endTimeLabel, 5, 0);
    mainLayout->addWidget(endTimeEdit, 5, 1);
    mainLayout->addWidget(buttonBox, 7, 0, 1, 3);
    mainLayout->setRowMinimumHeight(6, 10);
    mainLayout->setRowStretch(6, 1);
    mainLayout->setColumnStretch(2, 1);
    setLayout(mainLayout);/*}}}*/

    if (ExamName != "") {
        nextButton->setFocus();
    } else {
        nameEdit->setFocus();
    }

    setWindowTitle(tr("hello"));
}

void EditKemuForm::done(int result)
{
    mapper->submit();
    QDialog::done(result);
}

void EditKemuForm::addEmployee()
{
    int row = mapper->currentIndex();
    mapper->submit();
    tableModel->insertRow(row);
    mapper->setCurrentIndex(row);

    nameEdit->clear();
    hegeEdit->clear();
    startTimeEdit->setTime(QTime::currentTime());
    nameEdit->setFocus();
}

void EditKemuForm::deleteEmployee()
{
    int row = mapper->currentIndex();
    tableModel->removeRow(row);
    mapper->submit();
    mapper->setCurrentIndex(qMin(row, tableModel->rowCount() - 1));
}

