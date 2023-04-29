#ifndef ISSUEORREFUNDSIMWINDOW_H
#define ISSUEORREFUNDSIMWINDOW_H

#include <QWidget>

namespace Ui {
class issueorrefundsimWindow;
}

class issueorrefundsimWindow : public QWidget
{
    Q_OBJECT

public:
    explicit issueorrefundsimWindow(QWidget *parent = nullptr);
    ~issueorrefundsimWindow();
signals:
    void menuWindow();

private:
    Ui::issueorrefundsimWindow *ui;
private slots:
    void on_menuExitButton_clicked();
};

#endif // ISSUEORREFUNDSIMWINDOW_H
