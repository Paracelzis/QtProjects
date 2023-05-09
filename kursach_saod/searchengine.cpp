#include "searchengine.h"

searchEngine::searchEngine(QObject *parent)
    : QObject{parent}
{

}

// Функция для поиска подстроки в строке с использованием прямого алгоритма

QVector<int> searchEngine::directSearch(QString text, QString pattern)
{
    QVector<int> occurrences;
    int n = text.length();
    int m = pattern.length();
    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m)
            occurrences.append(i);
    }
    return occurrences;
}
