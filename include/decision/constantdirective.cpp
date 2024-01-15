#include "constantdirective.h"

#include <iostream>

ConstantDirective::ConstantDirective(const QString& name,
                                     const QString& description,
                                     const Valence& valence,
                                     const double& threshold)
    : Directive{name, description, valence}
    , m_threshold(threshold < 0 ? 0 : (threshold > 1 ? 1 : threshold))
{

}

void ConstantDirective::setThreshold(double t)
{
    if (t >= 0.0 && t <= 1.0) {
        this->m_threshold = t;
    } else {
        std::cout << "[ConstantDirective::setThreshold]" << std::endl;;
        std::cout << "ERROR! Failed to set. Value out of range." << std::endl;
    }
}

QVariantMap ConstantDirective::writeSelfToMap() const
{
    QVariantMap map;

    map.insert("name", m_name);
    map.insert("description", m_description);
    map.insert("valence", (bool)m_valence);
    map.insert("threshold", m_threshold);

    return map;
}

void ConstantDirective::readMapToSelf(const QVariantMap& map)
{
    setName(map.value("name").toString());
    setDescription(map.value("description").toString());
    setValence(Valence(map.value("valence").toBool()));
    setThreshold(map.value("threshold").toDouble());

    return;
}

QMetaObject ConstantDirective::getStaticMetaObject() const
{
    return this->staticMetaObject;
}
