#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QLocale>
#include <QWidget>
#include <QTextEdit>


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
    void on_PushButton_Clicked();
    void on_TextChange(QString);
private:
    Ui::MainWindow *ui;
    QRegularExpressionValidator validator;
};
#endif // MAINWINDOW_H
