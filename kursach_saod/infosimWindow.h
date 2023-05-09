#ifndef INFOSIMWINDOW_H
#define INFOSIMWINDOW_H

#include <QWidget>
#include <myhashtable.h>
#include <clientstree.h>
#include <QMessageBox>
#include <addinhashdialog.h>
#include <myexception.h>
#include <searchengine.h>

namespace Ui {
class infosimWindow;
}

class infosimWindow : public QWidget
{
    Q_OBJECT

public:
    explicit infosimWindow(clientsTree*& Root, myHashTable*& hashTable,QWidget *parent = nullptr);
    ~infosimWindow();

signals:
    void menuWindow();

private slots:
    void on_menuExitButton_clicked();
    void on_addButton_clicked();
    void on_editButton_clicked();
    void on_deleteButton_clicked();
    void on_clearButton_clicked();
    void addSIM();
    void editSIM();
    void on_searchEdit_textChanged();

private:
    Ui::infosimWindow *ui;
    myHashTable*& hashTable;
    infosimObj* sim;
    infosimObj* processForm();
    clientsTree*& Root;
    void tableReload();
    addinhashdialog* addDialog;
};

#endif // INFOSIMWINDOW_H
