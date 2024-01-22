#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "persons.h"
#include <vector>
#include <QMainWindow>
#include <QCombobox.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_addStudentButton_clicked();

    void updateComboBox();

    //void on_comboBoxEdit_activated();

    void on_comboBoxInfo_activated(int comboIndex);

    void on_EditButton_clicked();

private:
    Ui::MainWindow *ui;

    int index = 0;
    int GroupSize = 1;

    std::vector<Students> studentsArray;

    QComboBox *studentComboBoxEdit;
    QComboBox *studentComboBoxInfo;
};
#endif // MAINWINDOW_H
