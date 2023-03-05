#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
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
    void take_from_file_pushButton_clicked();
    void save_in_file_pushButton_clicked();
    void show_to_index_pushButton_clicked();
    void delete_to_index_pushButton_clicked();
    void delete_to_data_pushButton_clicked();
    void delete_combo(int funk);
    void AddItem_pushButton_clicked();
    void summa_pushButton_clicked();
    void summa_task2_pushButton_clicked();
    void clear_collection_pushButton_clicked();
    QString convert_collection(QVector<double>& vec);
    void on_file_name_currentIndexChanged();
    void fill(QString data);
    void text_changed();

private:
    Ui::MainWindow *ui;
    QRegularExpressionValidator validator, validator2;

};
#endif // MAINWINDOW_H
