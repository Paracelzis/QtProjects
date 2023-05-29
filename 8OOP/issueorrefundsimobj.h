#ifndef ISSUEORREFUNDSIMOBJ_H
#define ISSUEORREFUNDSIMOBJ_H

#include <QObject>
#include <myexception.h>

class issueorrefundsimObj: public QObject
{
    Q_OBJECT
public:
    explicit issueorrefundsimObj(QObject *parent = nullptr);
    issueorrefundsimObj(const QString passportNumber, const QString simNumber, const QString issueDate, const QString endDate);
    QString getPassportNumber();
    QString getSimNumber();
    QString getIssueDate();
    QString getEndDate();
    void setIssueDate(QString);
    void setEndDate(QString);
    void setPassportNumber(QString);

    QString simNumber;
private:
    QString passportNumber, issueDate, endDate;
};

#endif // ISSUEORREFUNDSIMOBJ_H
