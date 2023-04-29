#ifndef CLIENTSWINDOW_H
#define CLIENTSWINDOW_H

#include <QWidget>
#include <clientsobj.h>
#include <clientstree.h>
#include <addintreedialog.h>
#include <QMessageBox>
#include <QSortFilterProxyModel>

namespace Ui {
class clientsWindow;
}

class clientsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit clientsWindow(QWidget *parent = nullptr);
    ~clientsWindow();
    bool isEditing = false;
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
    void on_searchEdit_textChanged(const QString &searchText);
private:
    Ui::clientsWindow *ui;
    clientsObj* processForm();
    clientsObj* client;
    void addRow();
    QString series, number;
    void tableReload(clientsTree* Root, int count);
    addInTreeDialog *addDialog;
    clientsTree* Root;
};

#endif // CLIENTSWINDOW_H
