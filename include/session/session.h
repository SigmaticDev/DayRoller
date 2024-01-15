#ifndef SESSION_H
#define SESSION_H

#include <QObject>

class Decider;
class Profile;

class Session : public QObject
{
    Q_OBJECT
public:
    explicit Session(QObject *parent = nullptr);

signals:

private:
    Profile* m_profile;
    Decider* m_decider;
};

#endif // SESSION_H
