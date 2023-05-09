#ifndef CLIENTSWINDOW_H
#define CLIENTSWINDOW_H

#include <QWidget>
#include <myhashtable.h>
#include <clientstree.h>
#include <addintreedialog.h>
#include <QMessageBox>
#include <searchengine.h>

namespace Ui {
class clientsWindow;
}

class clientsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit clientsWindow(clientsTree*& Root, myHashTable*& hashTable, QWidget *parent = nullptr);
    ~clientsWindow();
signals:
    void menuWindow();
private slots:
    void on_menuExitButton_clicked();
    void on_addButton_clicked();
    void on_editButton_clicked();
    void on_deleteButton_clicked();
    void on_clearButton_clicked();
    void addClient();
    void editClient();
    void on_searchEdit_textChanged();
private:
    Ui::clientsWindow *ui;
    clientsObj* processForm();
    clientsObj* client;
    void addRow();
    QString series, number;
    void tableReload(clientsTree* Root, int count);
    addInTreeDialog *addDialog;
    clientsTree* Root;
    myHashTable*& hashTable;
};

#endif // CLIENTSWINDOW_H
