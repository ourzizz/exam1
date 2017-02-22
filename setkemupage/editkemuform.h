#ifndef ADDKEMUFORM_H
#define ADDKEMUFORM_H

#include <QDialog>
#include <QTimeEdit>

class QComboBox;
class QDataWidgetMapper;
class QDateEdit;
class QDialogButtonBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QSqlRelationalTableModel;


enum{
    km_name = 0,
    ex_name = 1,
    km_rs =2,
    km_sj_count =3,
    ks_start_time = 4,
    ks_end_time = 5,
    km_level = 6,
    km_hegefenshu = 7
};
class EditKemuForm : public QDialog
{
    Q_OBJECT

public:
    EditKemuForm(QString ExamName,QString kemuName, QWidget *parent=0);

    void done(int result);

private slots:
    void addEmployee();
    void deleteEmployee();

private:
    QSqlRelationalTableModel *tableModel;
    QDataWidgetMapper *mapper;
    QLabel *nameLabel;
    QLabel *exnameLabel;
    QLabel *hegeLabel;
    QLabel *levelLabel;
    QLabel *startTimeLabel;
    QLabel *endTimeLabel;
    QLineEdit *nameEdit;
    QComboBox *departmentComboBox;
    QLineEdit *hegeEdit;
    QLineEdit *levelEdit;
    QTimeEdit *startTimeEdit;
    QTimeEdit *endTimeEdit;
    QPushButton *firstButton;
    QPushButton *previousButton;
    QPushButton *nextButton;
    QPushButton *lastButton;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *closeButton;
    QDialogButtonBox *buttonBox;
};

#endif
