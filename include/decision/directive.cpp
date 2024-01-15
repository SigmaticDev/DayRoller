#include "directive.h"

Directive::Directive(const QString& name,
                     const QString& description,
                     const Valence& valence)
    : m_name(name)
    , m_description(description)
    , m_valence(valence)
{ }

void Directive::setName(QString n)
{
    m_name = n;
}

void Directive::setDescription(QString d)
{
    m_description = d;
}

void Directive::setValence(Valence v)
{
    m_valence = v;
}

double Directive::thresholdOf(const QVariant& variant)
{
    double result = 0;

    // TODO

    return result;
}

QVariant Directive::toVariant() const
{
    auto map = writeSelfToMap();
    map.insert("__className", getStaticMetaObject().className());
    return map;
}

void Directive::fromVariant(const QVariant& variant)
{
    auto map = variant.toMap();
    readMapToSelf(map);
}

QDebug operator<<(QDebug debug, const Directive& directive)
{
    debug << "Directive at addr `" << &directive << "`" << "\n";
    debug << "\tName:" << directive.name() << "\n";
    debug << "\tDescription:" << directive.description() << "\n";
    debug << "\tValence:" << (bool)directive.valence() << "\n";
    debug << "\tThreshold:" << directive.threshold();
    return debug;
}
