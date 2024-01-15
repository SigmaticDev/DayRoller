#ifndef EDITHISTORY_H
#define EDITHISTORY_H

#include <QDate>
#include <QObject>
#include <QSharedPointer>

class Directive;

class EditHistory : public QObject
{
    Q_OBJECT
public:
    explicit EditHistory(QObject *parent = nullptr);

    // -------------------------------------------------------------------------
    // [EditHistory]   M E M B E R S
    // -------------------------------------------------------------------------
    // Accessors

    // Mutators

signals:

public slots:

private:
    // -------------------------------------------------------------------------
    // [EditHistory]   D A T A   M E M B E R S
    // -------------------------------------------------------------------------
    QSharedPointer<Directive> m_directive;
    QList<QPair<QDate, QVariant> > m_edits;
};

#endif // EDITHISTORY_H
