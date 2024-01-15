#ifndef DAYFOCUS_H
#define DAYFOCUS_H

#include <QDate>
#include <QWidget>

class Profile;

class DayFocus : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QDate activeDate READ activeDate WRITE setActiveDate NOTIFY activeDateChanged)
public:
    explicit DayFocus(QSharedPointer<Profile> profile = nullptr,
                      QWidget *parent = nullptr);

    QDate activeDate() const {return m_activeDate;}
    QSharedPointer<Profile> activeProfile() const {return m_activeProfile;}
    // QList<QString> activePositiveDirectiveNames() const;
    // QList<QString> activeNegativeDirectiveNames() const;

    // void clearProfile();
    // void registerProfile(const QSharedPointer<Profile>& profile);

signals:
    void activeDateChanged(const QDate& newActiveDate);
    void activeProfileChanged(const QSharedPointer<Profile>& newActiveProfile);

public slots:
    void setActiveDate(const QDate& ad);
    void setActiveProfile(const QSharedPointer<Profile>& ap);

private:
    QDate m_activeDate;
    QSharedPointer<Profile> m_activeProfile;
};

#endif // DAYFOCUS_H
