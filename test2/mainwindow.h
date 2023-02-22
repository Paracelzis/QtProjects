#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qcheckbox.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_CheckBox_Clicked();
private:
    QVector<QCheckBox*> boxes;
    bool prov();
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
