#ifndef CONSTANTDIRECTIVE_H
#define CONSTANTDIRECTIVE_H

#include "directive.h"

/*
 * =============================================================================
 * C  O  N  S  T  A  N  T  D  I  R  E  C  T  I  V  E     C  L  A  S  S
 * =============================================================================
 *
 * Summary:
 *     Like base class Directive, represents a command from the application to
 *     the user to perform or not to perform certain actions. For this class,
 *     the Threshold is constant regardless of date.
 *
 * =============================================================================
 */

class ConstantDirective : public Directive
{
    Q_GADGET
public:
    // -------------------------------------------------------------------------
    // [ConstantDirective]   L I F E - C Y C L E
    // -------------------------------------------------------------------------
    // Defaulted constructor, copy constructor, and destructor
    ConstantDirective() = default;
    ConstantDirective(const ConstantDirective& directive) = default;
    ~ConstantDirective() = default;

    // Usable constructor
    ConstantDirective(const QString& name,
                      const QString& description,
                      const Valence& valence,
                      const double& threshold);

    // Copy assignment operator
    ConstantDirective& operator=(const ConstantDirective& directive) = default;

    // -------------------------------------------------------------------------
    // [ConstantDirective]   M E M B E R S
    // -------------------------------------------------------------------------
    // Accessors
    double threshold() const override {return m_threshold;}

    // Mutators
    void setThreshold(double t);

protected:
    // -------------------------------------------------------------------------
    // [Directive]   S T O R E D   Q V A R I A N T   H E L P E R S
    // -------------------------------------------------------------------------
    QVariantMap writeSelfToMap() const override;
    void readMapToSelf(const QVariantMap& map) override;
    QMetaObject getStaticMetaObject() const override;

private:
    // -------------------------------------------------------------------------
    // [ConstantDirective]   D A T A   M E M B E R S
    // -------------------------------------------------------------------------
    double m_threshold = 50.0;
};
Q_DECLARE_METATYPE(ConstantDirective)

#endif // CONSTANTDIRECTIVE_H
