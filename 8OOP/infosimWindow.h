#ifndef INFOSIMWINDOW_H
#define INFOSIMWINDOW_H

#include <QWidget>
#include <myhashtable.h>
#include <clientstree.h>
#include <mylist.h>
#include <QMessageBox>
#include <addinhashdialog.h>
#include <myexception.h>
#include <searchengine.h>
#include <QShowEvent>

namespace Ui {
class infosimWindow;
}

class infosimWindow : public QWidget
{
    Q_OBJECT

public:
    explicit infosimWindow(clientsTree*& Root, myHashTable*& hashTable, mylist*& List, QWidget *parent = nullptr);
    ~infosimWindow();
    addinhashdialog* addDialog;

signals:
    void menuWindow();
    void toReloadTable();
    //for completers
    void addinList(QString);
    void removefromList(QString);
    void toClear();

private slots:
    void on_menuExitButton_clicked();
    void on_addButton_clicked();
    void on_editButton_clicked();
    void on_deleteButton_clicked();
    void on_clearButton_clicked();
    void editSIM();
    void on_searchEdit_textChanged();

    void showEvent(QShowEvent *event);

public slots:
    void addSIM();

private:
    Ui::infosimWindow *ui;
    myHashTable*& hashTable;
    mylist*& List;
    infosimObj* sim;
    infosimObj* processForm();
    clientsTree*& Root;
    void tableReload();
};

#endif // INFOSIMWINDOW_H
