#ifndef INFOSIMWINDOW_H
#define INFOSIMWINDOW_H

#include <QWidget>

namespace Ui {
class infosimWindow;
}

class infosimWindow : public QWidget
{
    Q_OBJECT

public:
    explicit infosimWindow(QWidget *parent = nullptr);
    ~infosimWindow();
signals:
    void menuWindow();

private:
    Ui::infosimWindow *ui;
private slots:
    void on_menuExitButton_clicked();
};

#endif // INFOSIMWINDOW_H
