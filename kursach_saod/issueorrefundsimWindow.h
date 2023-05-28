#ifndef ISSUEORREFUNDSIMWINDOW_H
#define ISSUEORREFUNDSIMWINDOW_H

#include <QWidget>
#include <clientsWindow.h>
#include <infosimWindow.h>

#include <addinlistdialog.h>
#include <addinhashdialog.h>
#include <addintreedialog.h>

#include <mylist.h>
#include <myhashtable.h>
#include <clientstree.h>

#include <myexception.h>
#include <searchengine.h>
#include <QMessageBox>

namespace Ui {
class issueorrefundsimWindow;
}

class issueorrefundsimWindow : public QWidget
{
    Q_OBJECT

public:
    explicit issueorrefundsimWindow(mylist*& List, clientsTree*& Root, myHashTable*& hashTable,
                                    clientsWindow*& clientsWindow_1, infosimWindow*& infosimWindow_1,
                                    addInTreeDialog*& addTreeDialog, addinhashdialog*& addHashDialog,
                                    QWidget *parent = nullptr);
    ~issueorrefundsimWindow();
signals:
    void menuWindow();

private slots:
    void on_menuExitButton_clicked();
    void addButtonClicked();
    void deleteButtonClicked(); // TODO: needs to be fixed inside the list
    void clearButtonClicked();
    void editButtonClicked();
    void addNote();
    void editNote();
    void searchTextChanged();
    //StringList moves for completer
    void addinClientsList(QString);
    void editClientsList();
    void addinInfoSimList(QString);
    void removefromClientsList(QString);
    void removefromInfoSimList(QString);
    void clearClientsList();
    void clearInfoSimList();

    void shakerSort(QVector<issueorrefundsimObj*>& arr);

private:
    Ui::issueorrefundsimWindow *ui;
    issueorrefundsimObj* processForm();
    void tableReload();
    // stuff for completers
    void setClientsCompleter();
    void setInfoSimCompleter();
    //
    clientsTree*& Root;
    myHashTable*& hashTable;
    mylist*& List;
    infosimWindow*& infosimWindow_1;
    clientsWindow*& clientsWindow_1;
    addinlistdialog* addNoteDialog;
    addInTreeDialog*& addTreeDialog;
    addinhashdialog*& addHashDialog;
    //new stuff here
    QStringList infosimList;
    QStringList clientsList;
    QCompleter* clientCompleter;
    QCompleter* infosimCompleter;
};

#endif // ISSUEORREFUNDSIMWINDOW_H
