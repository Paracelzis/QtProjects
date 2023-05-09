#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include <QObject>

class searchEngine : public QObject
{
    Q_OBJECT
public:
    explicit searchEngine(QObject *parent = nullptr);
    static QVector<int> directSearch(QString text, QString pattern);
};

#endif // SEARCHENGINE_H
