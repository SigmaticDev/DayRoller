#ifndef DIRECTIVE_H
#define DIRECTIVE_H

#include <QDate>
#include <QDebug>
#include <QString>

#include "../serialization/serializable.h"

/*
 * =============================================================================
 * D  I  R  E  C  T  I  V  E     C  L  A  S  S
 * =============================================================================
 *
 * Summary:
 *     Represents a command from the application to the user to perform (in the
 *     case of Positive Directives) or not to perform (for Negative Directives)
 *     certain actions described by the Description. Every day, the application
 *     polls the Threshold of the Directive, comparing it against a randomized
 *     value to determine whether the application will prompt the user on that
 *     day to follow the Directive.
 *
 *     Subclasses Serializable class to enable storage in QVariant and on the
 *     disk.
 *
 * Subclassing:
 *     To subclass this class, the following MUST be implemented:
 *         From Directive:
 *             double threshold() const
 *             double getThresholdFromVariant(const QVariant& variant) const
 *         From Serializable:
 *             QVariant toVariant() const
 *             void fromVariant(const QVariant& variant)
 *     !IMPORTANT!
 *
 * =============================================================================
 */

class Directive : public Serializable
{
    Q_GADGET
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString description READ description WRITE setDescription)
    Q_PROPERTY(Valence valence READ valence WRITE setValence)
    Q_PROPERTY(double threshold READ threshold)
public:
    // -------------------------------------------------------------------------
    // [Directive]   V A L E N C E   D E F I N I T I O N
    // -------------------------------------------------------------------------
    enum class Valence : bool {
        NEGATIVE = false,
        POSITIVE = true
    };
    Q_ENUM(Valence)

    // -------------------------------------------------------------------------
    // [Directive]   L I F E - C Y C L E
    // -------------------------------------------------------------------------
    // Defaulted constructor, copy constructor, and destructor
    Directive() = default;
    Directive(const Directive& directive) = default;
    virtual ~Directive() = default;

protected:
    // Constructor for subclasses
    Directive(const QString& name,
              const QString& description,
              const Valence& valence);
public:

    // Copy assignment operator
    Directive& operator=(const Directive& directive) = default;

    // -------------------------------------------------------------------------
    // [Directive]   M E M B E R S
    // -------------------------------------------------------------------------
    // Accessors
    QString name() const {return m_name;}
    QString description() const {return m_description;}
    Valence valence() const {return m_valence;}
    virtual double threshold() const = 0;

    // Mutators
    void setName(QString n);
    void setDescription(QString d);
    void setValence(Valence v);

    // -------------------------------------------------------------------------
    // [Directive]   S T O R E D   Q V A R I A N T   H E L P E R S
    // -------------------------------------------------------------------------
    static QString nameOf(const QVariant& variant) {
        return variant.toMap().value("name").toString();
    }
    static QString descriptionOf(const QVariant& variant) {
        return variant.toMap().value("description").toString();
    }
    static Valence valenceOf(const QVariant& variant) {
        return Valence(variant.toMap().value("valence").toBool());
    }
    static double thresholdOf(const QVariant& variant);

protected:
    virtual QVariantMap writeSelfToMap(/*const QVariantMap& map*/) const = 0;
    virtual void readMapToSelf(const QVariantMap& map) = 0;
    virtual QMetaObject getStaticMetaObject() const = 0;
public:

    // -------------------------------------------------------------------------
    // [Serializable]   S E R I A L I Z A T I O N
    // -------------------------------------------------------------------------
    QVariant toVariant() const override;
    void fromVariant(const QVariant& variant) override;

protected:
    // --------------------------------------------------------------------------
    // [Directive]   D A T A   M E M B E R S
    // --------------------------------------------------------------------------
    QString m_name = "Default Directive Name";
    QString m_description = "Default directive description...";
    Valence m_valence = Valence::NEGATIVE;
};
Q_DECLARE_METATYPE(Directive*)

QDebug operator<<(QDebug debug, const Directive& directive);

#endif // DIRECTIVE_H
