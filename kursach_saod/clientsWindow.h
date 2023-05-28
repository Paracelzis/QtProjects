#ifndef CLIENTSWINDOW_H
#define CLIENTSWINDOW_H

#include <QWidget>
#include <myhashtable.h>
#include <clientstree.h>
#include <mylist.h>
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
    explicit clientsWindow(clientsTree*& Root, myHashTable*& hashTable, mylist*& List,  QWidget *parent = nullptr);
    ~clientsWindow();
    addInTreeDialog *addDialog;

signals:
    void menuWindow();
    void toReloadTable();
    //New stuff works fine
    void addtoStringList(QString);
    void editClientList();
    void removefromStringList(QString);
    void toClear();

private slots:
    void on_menuExitButton_clicked();
    void on_addButton_clicked();
    void on_editButton_clicked();
    void on_deleteButton_clicked();
    void on_clearButton_clicked();
    void editClient();
    void on_searchEdit_textChanged();

public slots:
    void addClient();

private:
    Ui::clientsWindow *ui;
    clientsObj* processForm();
    clientsObj* client;
    void addRow();
    QString why;
    QString series, number;
    void tableReload(clientsTree* Root, int count);
    clientsTree*& Root;
    myHashTable*& hashTable;
    mylist*& List;
};

#endif // CLIENTSWINDOW_H
