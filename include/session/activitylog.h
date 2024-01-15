#ifndef ACTIVITYLOG_H
#define ACTIVITYLOG_H

#include <QDate>
#include <QObject>

class Directive;

class ActivityLog : public QObject
{
    Q_OBJECT
public:
    explicit ActivityLog(QObject *parent = nullptr);

signals:

private:
    QSharedPointer<Directive> m_directive;
    QDate m_date;
    bool m_isActive;
    bool m_isEnforced;
    bool m_isFollowed;
};

#endif // ACTIVITYLOG_H
