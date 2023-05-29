#include "issueorrefundsimobj.h"

issueorrefundsimObj::issueorrefundsimObj(QObject *parent)
    : QObject{parent}
{
    this->passportNumber = "dummy";
    this->simNumber = "-1";
    this->issueDate = "-1";
    this->endDate = "dummy";
}

issueorrefundsimObj::issueorrefundsimObj(const QString passportNumber, const QString simNumber, const QString issueDate, const QString endDate)
{
    this->passportNumber = passportNumber;
    this->simNumber = simNumber;
    this->issueDate = issueDate;
    this->endDate = endDate;
}

QString issueorrefundsimObj::getPassportNumber(){
    return this->passportNumber;
}

QString issueorrefundsimObj::getSimNumber(){
    return this->simNumber;
}

QString issueorrefundsimObj::getIssueDate(){
    return this->issueDate;
}

QString issueorrefundsimObj::getEndDate(){
    return this->endDate;
}

void issueorrefundsimObj::setIssueDate(QString IssueDate){
    this->issueDate = IssueDate;
}

void issueorrefundsimObj::setEndDate(QString EndDate){
    this->endDate = EndDate;
}

void issueorrefundsimObj::setPassportNumber(QString PassportNumber){
    this->passportNumber = PassportNumber;
}

