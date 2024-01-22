#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "persons.h"
#include <QIntValidator>
using namespace std;

 Students student;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QIntValidator *validator = new QIntValidator(1, std::numeric_limits<int>::max(), this);
    ui->lineGroupSize->setValidator(validator);

    studentComboBoxEdit = ui->comboBoxEdit;
    studentComboBoxInfo = ui->comboBoxInfo;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if (!ui->lineGroupSize->text().isEmpty() && ui->lineGroupSize->text().toInt() <= 100)
    {
        GroupSize = ui->lineGroupSize->text().toInt();

        if(GroupSize > 0)
        {
            studentsArray.resize(GroupSize);
            ui->labelError->setText("");
            ui->labelGroupSize->setText("-----------------------------------------------------------------[" + QString::number(index) + "/" + QString::number(GroupSize) + "]------------------------------------------------------------------");
            ui->tabWidget->setEnabled(true);
            ui->pushButton->setEnabled(false);
            ui->lineGroupSize->setEnabled(false);
        }
    }
    else if (ui->lineGroupSize->text().toInt() > 100)
    {
        ui->labelError->setText("Помилка. Кількість осіб в групі не може бути більшою за 100 студентів.");
    }
    else
    {
        ui->labelError->setText("Помилка. Введіть кількість осіб в групі.");
    }
}

void MainWindow::on_addStudentButton_clicked()
{
    if (index < GroupSize)
    {
        Students student;

        student.set_ID(ui->lineEdit_ID->text().toLong());
        student.set_Sname(ui->lineEdit_Sname->text().toStdString());
        student.set_Name(ui->lineEdit_Name->text().toStdString());
        student.set_Fname(ui->lineEdit_Fname->text().toStdString());
        student.set_DateOfBirth(ui->dateEdit->date());
        student.set_School(ui->lineEdit_School->text().toStdString());
        student.set_Speciality(ui->lineEdit_Speciality->text().toStdString());
        student.set_Group(ui->lineEdit_Group->text().toStdString());
        student.set_MoreInfo(ui->lineEdit_MoreInfo->text().toStdString());

        studentsArray[index] = student;
        index++;
        ui->labelGroupSize->setText("-----------------------------------------------------------------[" + QString::number(index) + "/" + QString::number(GroupSize) + "]------------------------------------------------------------------");

        updateComboBox();
    }
}

void MainWindow::updateComboBox()
{
    studentComboBoxEdit->clear();
    studentComboBoxInfo->clear();

    for (int a = 0; a < index; a++)
    {
        studentComboBoxEdit->addItem(QString::fromStdString(studentsArray[a].get_Sname()));
        studentComboBoxInfo->addItem(QString::fromStdString(studentsArray[a].get_Sname()));
    }
}

void MainWindow::on_comboBoxInfo_activated(int comboIndex)
{
    if (comboIndex >= 0 && comboIndex < studentsArray.size())
    {
        ui->label_get_ID->setText(QString::number(studentsArray[comboIndex].get_ID()));
        ui->label_get_Sname->setText(QString::fromStdString(studentsArray[comboIndex].get_Sname()));
        ui->label_get_Name->setText(QString::fromStdString(studentsArray[comboIndex].get_Name()));
        ui->label_get_Fname->setText(QString::fromStdString(studentsArray[comboIndex].get_Fname()));
        ui->label_get_Date->setText(QString::fromStdString(studentsArray[comboIndex].get_DateOfBirth()));
        ui->label_get_School->setText(QString::fromStdString(studentsArray[comboIndex].get_School()));
        ui->label_get_Speciality->setText(QString::fromStdString(studentsArray[comboIndex].get_Speciality()));
        ui->label_get_Group->setText(QString::fromStdString(studentsArray[comboIndex].get_Group()));
        ui->label_get_MoreInfo->setText(QString::fromStdString(studentsArray[comboIndex].get_MoreInfo()));
    }
}


void MainWindow::on_EditButton_clicked()
{
    int selectedIndex = ui->comboBoxEdit->currentIndex();

    if (selectedIndex >= 0 && selectedIndex < studentsArray.size())
    {
        Students &student = studentsArray[selectedIndex];

        if (!ui->lineEdit_ID_2->text().isEmpty())
        {
            student.set_ID(ui->lineEdit_ID_2->text().toLong());
        }
        if (!ui->lineEdit_Sname_2->text().isEmpty())
        {
            student.set_Sname(ui->lineEdit_Sname_2->text().toStdString());
        }
        if (!ui->lineEdit_Name_2->text().isEmpty())
        {
            student.set_Name(ui->lineEdit_Name_2->text().toStdString());
        }
        if (!ui->lineEdit_Fname_2->text().isEmpty())
        {
            student.set_Fname(ui->lineEdit_Fname_2->text().toStdString());
        }
        if (!ui->dateEdit_2->text().isEmpty())
        {
            student.set_DateOfBirth(ui->dateEdit_2->date());
        }
        if (!ui->lineEdit_School_2->text().isEmpty())
        {
            student.set_School(ui->lineEdit_School_2->text().toStdString());
        }
        if (!ui->lineEdit_Speciality_2->text().isEmpty())
        {
            student.set_Speciality(ui->lineEdit_Speciality_2->text().toStdString());
        }
        if (!ui->lineEdit_Group_2->text().isEmpty())
        {
            student.set_Group(ui->lineEdit_Group_2->text().toStdString());
        }
        if (!ui->lineEdit_MoreInfo_2->text().isEmpty())
        {
            student.set_MoreInfo(ui->lineEdit_MoreInfo_2->text().toStdString());
        }

        updateComboBox();
    }
}

