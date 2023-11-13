#ifndef BASIC_H
#define BASIC_H

#include <QDialog>

namespace Ui {
class basic;
}

class basic : public QDialog
{
    Q_OBJECT

public:
    explicit basic(QWidget *parent = nullptr);
    ~basic();

private:
    Ui::basic *ui;
};

#endif // BASIC_H
