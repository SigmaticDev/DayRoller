#include "variabledirective.h"

#include <iostream>

#include <QDateTime>
#include <QTime>

VariableDirective::VariableDirective(const QString& name,
                                     const QString& description,
                                     const Valence& valence,
                                     const QDate& startDate,
                                     const QDate& endDate,
                                     const double& startThreshold,
                                     const double& endThreshold)
    : Directive{name, description, valence}
    , m_startDate(startDate)
    , m_endDate(endDate)
    , m_startThreshold(startThreshold)
    , m_endThreshold(endThreshold)
{

}

double VariableDirective::threshold() const
{
    auto start = QDateTime(m_startDate, QTime(0, 0, 0));
    auto end = QDateTime(m_endDate, QTime(0, 0, 0));
    auto today = QDateTime::currentDateTime();
    today.setTime(QTime(0, 0, 0));

    double output;

    if (today <= start) {
        output = m_startThreshold;
    } else if (today >= end) {
        output = m_startThreshold;
    } else {
        auto elapsedDays = (double)(today - start).count() / 86400000;
        auto totalDays = (double)(end - start).count() / 86400000;

        output = m_endThreshold - m_startThreshold;
        output *= elapsedDays;
        output /= totalDays;
        output += m_startThreshold;
    }

    return output;
}

void VariableDirective::setStartDate(const QDate& d)
{
    m_startDate = d;
    return;
}

void VariableDirective::setEndDate(const QDate& d)
{
    m_endDate = d;
    return;
}

void VariableDirective::setStartThreshold(const double& t)
{
    if (t >= 0.0 && t <= 1.0) {
        m_startThreshold = t;
    } else {
        std::cout << "[VariableDirective::setStartThreshold]" << std::endl;
        std::cout << "ERROR! Failed to set. Value out of range." <<std::endl;
    }
    return;
}

void VariableDirective::setEndThreshold(const double& t)
{
    if (t >= 0.0 && t <= 1.0) {
        m_endThreshold = t;
    } else {
        std::cout << "[VariableDirective::setEndThreshold]" << std::endl;
        std::cout << "ERROR! Failed to set. Value out of range." <<std::endl;
    }
    return;
}

QVariantMap VariableDirective::writeSelfToMap() const
{
    QVariantMap map;

    map.insert("name", m_name);
    map.insert("description", m_description);
    map.insert("valence", (bool)m_valence);
    map.insert("startDate", m_startDate);
    map.insert("endDate", m_endDate);
    map.insert("startThreshold", m_startThreshold);
    map.insert("endThreshold", m_endThreshold);

    return map;
}

void VariableDirective::readMapToSelf(const QVariantMap& map)
{
    setName(map.value("name").toString());
    setDescription(map.value("description").toString());
    setValence(Valence(map.value("valence").toBool()));
    setStartDate(map.value("startDate").toDate());
    setEndDate(map.value("endDate").toDate());
    setStartThreshold(map.value("startThreshold").toDouble());
    setEndThreshold(map.value("endThreshold").toDouble());

    return;
}

QMetaObject VariableDirective::getStaticMetaObject() const
{
    return this->staticMetaObject;
}
