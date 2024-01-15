#ifndef PROFILEQUERY_H
#define PROFILEQUERY_H

#include <QObject>

class ProfileQuery : public QObject
{
    Q_OBJECT
public:
    explicit ProfileQuery(QObject *parent = nullptr);

signals:
};

#endif // PROFILEQUERY_H
