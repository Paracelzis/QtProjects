#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QLocale>

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
    void on_TextChange(QString);
    void on_RadioButton_Clicked();
private:
    Ui::MainWindow *ui;
    bool prov();
    QRegularExpressionValidator validator;
};
#endif // MAINWINDOW_H
